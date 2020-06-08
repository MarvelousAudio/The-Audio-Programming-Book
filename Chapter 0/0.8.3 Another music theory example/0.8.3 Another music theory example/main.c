//
//  main.c
//  0.8.3 Another music theory example
//
//  Created by ben haywood on 6/7/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
   
    int note, i;
    
    printf("Please enter the key (in pitch-class number, 0-11): ");
    scanf("%d", &note);
    /*
     make sure start note is not negative
     */
    
    while (note < 0)
    {
        note += 12;
    }
    
    /*
     build the scale
     */
    
    for ( i = 0; i < 7; ++i)
    {
        if (note % 12 == 0) printf("C ");
        else if (note % 12 == 1) printf("Db ");
        else if (note % 12 == 2) printf("D ");
        else if (note % 12 == 3) printf("Eb ");
        else if (note % 12 == 4) printf("E ");
        else if (note % 12 == 5) printf("F ");
        else if (note % 12 == 6) printf("Gb ");
        else if (note % 12 == 7) printf("G ");
        else if (note % 12 == 8) printf("Ab ");
        else if (note % 12 == 9) printf("A ");
        else if (note % 12 == 10) printf("Bb ");
        else printf("B ");
        
        //find the next pitch class, jump a semitone only after 3rd step
        
        if (i != 2) note += 2;
        else note++;
    }
    
    printf("\n");  //newline
    
    return 0;
}
