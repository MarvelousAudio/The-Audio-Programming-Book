//
//  main.c
//  Listing 1.4
//
//  Created by ben haywood on 6/17/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    double c5, c0, semitoneratio;
    double frequency;
    int midinote;
    
    semitoneratio = pow(2, 1.0/12);
    c5 = 220 * pow(semitoneratio, 3);
    
    c0 = c5 * pow(0.5, 5);
    
    //if the program is not called csmidi either change the lines below
    
    if (argc != 2)
    {
        printf("Listing 1.4 : converts MIDI note to frequency.\n" /*argv[0]*/);
        printf(" range: 0 <= MIDInote <= 127 \n");
        return 1;
    }
    midinote = atoi(argv[1]);
    
    // use argv[1] to echo a bad argument string to the user
    if (midinote < 0)
    {
        printf("Bad MIDI note value: %s\n", argv[1]);
        return 1;
    }
    
    if (midinote > 127)
    {
        printf("%s is beyond the MIDI range!\n", argv[1]);
        return 1;
    }
    
    frequency = c0 * pow(semitoneratio, midinote);
    printf("frequency of MIDI note %d = %f\n", midinote, frequency);

    return 0;
}
