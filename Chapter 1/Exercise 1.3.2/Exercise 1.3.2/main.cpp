//
//  main.cpp
//  Exercise 1.3.2
//
//  Created by ben haywood on 6/17/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//


//need to finish!
#include <iostream>
#include <math.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    double c5;
    double c0;
    int midinote;
    double frequency;
    double semitone;
    
    semitone = pow(2, 1.0/12);
    
    c5 = 220 + pow(semitone,3);
    
    c0 = c5  * pow(0.5, 5);
    
    midinote = 75;
    
    frequency = c0 * pow(semitone, midinote);
    return 0;
}
