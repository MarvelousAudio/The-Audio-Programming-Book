//
//  main.c
//  listing 1.2 calculate frequency of a midi note number
//
//  Created by ben haywood on 6/15/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    double semitone_ratio;
    double c0; //for frequency of midi note 0
    double c5; // for frequency of middle c
    double frequency; // which we waant to find
    int midinote; //given this note
    
    
    //calculate required numbers
    
    semitone_ratio = pow(2,1/12.0); // approx 1.0594631
    //find middle C, three semitones above low A = 220;
    c5 = 220.0 * pow(semitone_ratio,3);
    //midi note 0 is C, 5 octaves below middle c
    c0 = c5 * pow(0.5, 5);
    
    
    //calcualte a frequency for a given midi note number
    midinote = 73; //C# above A = 440
    frequency = c0 * pow(semitone_ratio, midinote);
    
    printf("MIDI Note %d has frequency %f\n", midinote, frequency);
    
    
    return 0;
}
