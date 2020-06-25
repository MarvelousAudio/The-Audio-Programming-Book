//
//  main.c
//  Listing 1.9.1: Generate single-cycle sine wave
//
//  Created by ben haywood on 6/24/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// conditional compiliation - is M_PI defined?
#ifndef M_PI
#define M_PI (3.14592654)
#endif

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int i, nsamps;
    double samp;
    double twopi = 2.0 * M_PI;
    double angleincr;
    
    // set number of points to create
    nsamps = 50;
    
    // make one complete cycle
    angleincr = twopi / nsamps;
    for (i = 0; i < nsamps; i++)
    {
        samp = sin(angleincr * i);
        fprintf(stdout, "%.8lf\n", samp);
        
    }
    
    fprintf(stderr, "done\n");
    return 0;
}
