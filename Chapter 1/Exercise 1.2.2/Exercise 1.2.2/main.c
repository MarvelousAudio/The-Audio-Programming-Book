//
//  main.c
//  Exercise 1.2.2
//
//  Created by ben haywood on 6/15/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    double fracsamp = 0.5;
    short samp = (short) (fracsamp * 32767);
    
    printf("samp: %hd\n", samp);
    
    return 0;
}
