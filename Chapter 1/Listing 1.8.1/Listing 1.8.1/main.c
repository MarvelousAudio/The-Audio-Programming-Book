//
//  main.c
//  Listing 1.8.1
//
//  Created by ben haywood on 6/24/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int i, nsteps;
    double step, x, a, T, k;
    double dur;
    
    if (argc != ARG_NARGS) // what is ARG_NARGS?
    {
        printf("usage: expdecay dur T steps\n");
        return 1;
    }
    
    dur = atof(argv[1]);
    T = atof(argv[2]);
    nsteps = atoi(argv[3]);
    
    k = dur/nsteps; // the constant time increment
    a = exp(-k/T); // calc the constant ratio value
    x = 1.0; // starting value for the decay
    
    step = 0.0;
    for (i = 0; i < nsteps; i++)
    {
        printf("%.4lf\t%.8lf\n", step, x);
        x *= a;
        step += k;
    }
    return 0;
}
