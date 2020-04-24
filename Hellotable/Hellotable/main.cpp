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
    
}
//======================================================================
//float table[TABLE_LEN]; //arry (table) to be filled with a wave form

void main()
{
    
    
    int waveform;
    const float frequency, duration;
    
    printf("Type the frequency of the wave to output in Hz, and press ENTER: ");
    scanf("%f", &frequency)
}
