//
//  main.cpp
//  Listing 1.7.4:The "breakdur"
//
//  Created by ben haywood on 6/23/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

//#include <iostream>
#include <stdlib.h>
#include <stdio.h>


void free(void *p);

typedef struct breakpoint{
    double time;
    double value;
} BREAKPOINT;


BREAKPOINT* get_breakpoints(FILE* fp, long* psize)
{
    int got;
    long npoints = 0, size = 64;
    double lasttime = 0.0;
    BREAKPOINT* points = NULL;
    char line[80];
    
    if (fp == NULL)
        return NULL;
    
    points = (BREAKPOINT*) malloc(sizeof(BREAKPOINT) * size);
    if (points == NULL)
        return NULL;
    
    while (fgets(line, 80, fp))
    {
        got = sscanf(line, "%lf%lf", &points[npoints].time, &points[npoints].value);
        
        if(got < 0)
            continue; //empty line
        
        if (got == 1)
        {
            printf("Line %d has non-numeric data\n", npoints+1);
            break;
        }
        
        if (got == 1)
        {
            printf("Incomplete breakpoint found at point %d\n", npoints+1);
            break;
        }
        
        lasttime = points[npoints].time;
        
        if (++npoints == size)
        {
            BREAKPOINT* tmp;
            size += npoints;
            tmp=(BREAKPOINT*)realloc(points, sizeof(BREAKPOINT) * size);
            if (tmp == NULL)
            {
                npoints = 0;
                free(npoints);
                points = NULL;
                break;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
