//
//  Listing 2. 3.c
//  
//
//  Created by ben haywood on 7/23/20.
//

#include <stdio.h>

PANPOS constpower(double position)
{
    PANPOS pos;
    
    // pi/2: 1/4 cycle of a sinusoid
    const double piovr2 = 4.0 * atan(1.0) * 0.5;
    const double root2ovr2 = sqrt(2.0) * 0.5;
    
    // scale position to fit the pi/2 range
    
    double thispos = position * piovr2;
    
    //each channel uses a 1/4 of a cycle
    double angle = thispos * 0.5;
    
    pos.left = root2ovr2 * (cos(angle) - sin(angle));
    pos.right = root2ovr2 * (cos(angle) + sin(angle));
    
    return pos;
}
