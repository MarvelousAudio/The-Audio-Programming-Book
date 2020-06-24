//
//  main.c
//  Listing 1.5.3
//
//  Created by ben haywood on 6/18/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
   
    int notes, i, midinote;
    double frequency, ratio;
    double c0, c5;
    double intervals[24];
    
    if (argc != 3)
    {
        printf("Usage: nscale notes miditnote\n");
        return 1;
    }
    
    notes = atoi(argv[1]);
    if (notes < 1)
    {
        printf("Error: notes must be postitive\n");
        return 1;
    }
    
    if (notes > 24)
    {
        printf("Error: maxium value for notes is 24\n");
        return 1;
    }
    
    midinote = atoi(argv[2]);
    if (midinote < 0)
    {
        printf("Error: cannot have negative MIDI notes!\n");
        return 1;
    }
    
    if (midinote > 127)
    {
        printf("Error: maxium midinote is 127\n");
        return 1;
    }
    
    // find the frequency of the MIDI note
    
    //calc stanard E.T. semitone ratio
    ratio = pow(2.0, 1.0/ 12.0);
    
    //find middle c, three semitones about low A = 220
    c5 = 220 * pow(ratio, 3);
    
    //MIDI note 0 is C, 5 ocative below middle C
    
    c0 = c5 * pow(0.5, 5);
    
    frequency = c0 * pow(ratio, midinote);
    
    //calc ratio from notes, and fill the frequency array
    ratio = pow(2.0, 1.0/notes);
    
    for (i = 0; i < notes; ++i)
    {
        printf("%f\n", intervals[i]);
    }

    return 0;
}
