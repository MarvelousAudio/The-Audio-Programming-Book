//
//  main.c
//  listing 1.3
//
//  Created by ben haywood on 6/16/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    double c5, c0, semitone_ratio, frequency;
    int midiNote;
    char message[256];
    char* result;
    
    semitone_ratio = pow(2, 1.0/12); //calc semitone
    c5 = 220.0 * pow(semitone_ratio, 3); //calcs middle C
    c0 = c5 * pow(0.5, 5); //calcs c0
    
    printf("Enter MIDI note (0 - 127): "); // gets input of MIDI note
    result = gets(message);
    
    
    if (result == NULL)
    {
        printf("There was an error reading the input.\n");
        return 1;
    }
    
    if (message[0] == '\0')
    {
        printf("Have a nice day!\n");
        return 1;
    }
    
    midiNote = atoi(message);
    
    if(midiNote < 0 ) // out of range check
    {
        printf("Sorry - %s is a bad MIDI note number\n", message);
        return 1;
    }
    
    if (midiNote > 127) // out of range check
    {
        printf("SOrry - %s is beyond the MIDI range!\n", message);
        return 1;
    }
    
    frequency = c0 * pow(semitone_ratio, midiNote);
    printf("frequency of MIDI note %d = %f\n", midiNote, frequency);
    
    return 0;
}
