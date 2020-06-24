//
//  main.c
//  Listing 1.6.1
//
//  Created by ben haywood on 6/18/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    double buffer[1024];
    double* ptr = buffer + 1024; // point to last element
    double maxval = 0.0;
    unsigned long pos = 0;
    
    while(--ptr != buffer)
    {
        if (*ptr >= maxval)
        {
            maxval = *ptr;
            pos = ptr - buffer;
        }
    }
    
    printf("the maximum sample is %f, at position %lu\n", maxval,pos);
    
    return 0;
}
