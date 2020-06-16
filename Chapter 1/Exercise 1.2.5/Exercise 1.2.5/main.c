//
//  main.c
//  Exercise 1.2.5
//
//  Created by ben haywood on 6/15/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    double semitone_ratio;
    double c0;
    double c4;
    double frequency;
    int StringLengthNote;
    
    
    semitone_ratio = pow(2, 1/12.0);
    c4 = 660 * pow(semitone_ratio, 3);
    return 0;
}
