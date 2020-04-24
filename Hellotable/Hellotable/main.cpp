//
//  main.cpp
//  Hellotable
//
//  Created by ben haywood on 4/23/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>

#define SAMPLING_RATE 44100
#define PI 3.141569265

#define TABLE_LEN 512
#define SINE 0
#define SQUARE 1
#define SAW 2
#define TRIANGLE 3

float table[TABLE_LEN]; //arry (table) to be filled with a wave form

void fill_sine() // fills the table with a single cycle of a sine wave
{
    int j;
    for (j = 0; j < TABLE_LEN; j++)
    {
        table[j] = (float) sin(2 * PI * j/TABLE_LEN);
        
    }
}

void fill_square()
{
    
    int j;
    for (j = 0; j < TABLE_LEN/2; j++)
    {
        table[j] = 1;
        
    }
    for (j = TABLE_LEN/2; j < TABLE_LEN; j++)
    {
        table[j] = -1;
        
    }
}

void fill_saw()
{
    int j;
    for (j  = 0; j < TABLE_LEN; j++)
    {
        table[j] = 1 - (2 * (float) j / (float) TABLE_LEN);
    }
}

void fill_triangle()
{
    int j;
    for (j = 0; j < TABLE_LEN/2; j++)
    {
        table[j] = 2 * (float) j / (float) (TABLE_LEN/2) - 1;
        
    }
    
    for (j = TABLE_LEN/2; j < TABLE_LEN; j++)
    {
        table[j] = 1 - (2 * (float) (j - TABLE_LEN/2) / (float) (TABLE_LEN/2));
    }
}


#ifdef REALTIME // use tiny audio library
#include "tinyAudioLib.h"
#elif defined(BINARY_RAW_FILE)
FILE* file;
#elif defined(WAVE_FILE) // uses protsf library
PSF_PROPS props;
int ofd;


#endif



void outSample(float sample)
{
#ifdef REALTIME // uses tiny audio library
outSampleMono(sample);
#elif defined(BINARY_RAW_FILE)
short isample = (short) (sample * 32000);
fwrite(&isample, sizeof(short), 1 , file);
#elif defined(WAVE_FILE) // uses protsf library
psf_sndWriteFloatFrames(ofd, &sample, 1);
#else //stanard output
printf("%f\n", sample);
#endif
}


void init()
{
#ifdef REALTIME // uses Tiny audio library
    tinyInit();
#elif defined(BINARY_RAW_FILE)
    file = fopen("hellotable.raw", "wb");
#elif defined(WAVE_FILE) //uses portsf library
    props.srate = 44100;
    props.chans = 1;
    props.samptype = PSF_SAMP_16;
    props.format = PSF_STDWAVE;
    props.chformat = STDWAVE;
    psf_init();
    ofd= psf_sndCreate("hellotable.wave", &props, 0 , 0, PSF_CREATE_RDWR);
#else //standard output
    printf("\n. . . Nothing to initialize. . . \n");
#endif
}

void cleanup()
{
    printf("cleaning up. . . ");
#ifdef REALTIME //uses tiny audio library
    tinyExit();
#elif defined(BINARY_RAW_FILE)
    fclose(file);
#elif defined(WAVE_FILE) // uses portsf library
    {
        int err1, err2;
        err1 = psf_sndClose(ofd);
        err2 = psf_finish();
        if (err1 || err2)
            printf("\nWarning! An error occurred writing WAVE_FILE file.\n");
    
    }
#else // standard output
    printf("nothing to clean up. . ." );
    
#endif
    
}
//======================================================================
//float table[TABLE_LEN]; //arry (table) to be filled with a wave form

int main()
{
    
    
    int waveform;
    float frequency, duration;
    
    printf("Type the frequency of the wave to output in Hz, and press ENTER: ");
    scanf("%f", &frequency);
    
    printf("\nType the duration of tone in seconds, and press ENTER: ");
    scanf("%f", &duration);
    
    wrong_waveform:
    printf("\nType a number from 0 to 3 corresponding to the waveform you intend to choose\n");
    printf("(0 = sine, 1 = square, 2 = sawtooth, 3 = triangle), and press ENTER: ");
    scanf("%d", &waveform);
    if (waveform < 0 || waveform > 3)
    {
        printf("\nwrong number for waveform, try again!\n");
        goto wrong_waveform;
    }
    
    //===========fill the table==============================
    switch (waveform){
        case SINE:
            printf("\nYou've chosen a SINE wave\n");
            fill_sine();
            break;
        
        case SQUARE:
            printf("\nYou've chosen a SQUARE wave\n");
            fill_square();
            break;
            
        case SAW:
            printf("\nYou've chosen a SAW wave\n");
            fill_saw();
            break;
        
        case TRIANGLE:
            printf("\nYou've chosen a TRIANGLE wave\n");
            fill_triangle();
            break;
        default: //impossible!
            printf("\nWrong wave! Ending program. \n");
            return -1;
    }
    
    


init();


    int j;
    double sample_increment = frequency * TABLE_LEN / SAMPLING_RATE;
    double phase = 0;
    float sample;
    
    for (j = 0; j < duration * SAMPLING_RATE; j++)
    {
        sample = table[(long) phase];
        outSample(sample);
        phase += sample_increment;
        if (phase > TABLE_LEN) phase -= TABLE_LEN;
    }
    

cleanup();
printf("End of process\n");
    return 0;
}
