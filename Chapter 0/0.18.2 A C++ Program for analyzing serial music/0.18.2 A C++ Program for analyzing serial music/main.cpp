//
//  main.cpp
//  0.18.2 A C++ Program for analyzing serial music
//
//  Created by ben haywood on 6/10/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <iostream>

class Dodecaphonic{
    
protected:
    int series[12]; // the tone row, hidden from outside
    int mod12(int note) // the modulus as an interal method
    {
        while(note >= 12) note -= 12;
        while(note < 0) note += 12;
        return note;
    }
    
public:
    Dodecaphonic() // default constructor
    {
        for (int i = 0; i < 12; ++i) series[i] = 0;
    }
    
    Dodecaphonic(int *notes) // constructor from an array
    {
        for (int i = 0; i < 12; ++i) series[i] = mod12(notes[i]);
    }
    
    int get(int index) { return series[mod12(index)]; } // get & set notes
    
    void set(int note, int index)
    {
        series[mod12(index)] = mod12(note);
    }
    
    Dodecaphonic transpose(int interval); // the three basic operations
    
    Dodecaphonic invert();
    
    Dodecaphonic retrograde();
    
};

// defining the operations. all of them return a dodecaphonic object

Dodecaphonic Dodecaphonic::transpose(int interval)
{
    Dodecaphonic transp;
    for (int i = 0; i < 12; ++i)
    {
        transp.set(mod12(series[i] + interval), i);
        
        
        
        
    }
    
    
    return transp;
}

//========================================================================

Dodecaphonic Dodecaphonic::invert()
{
    Dodecaphonic inv;
    
    inv.set(series[0], 0);
    
    for (int i = 1; i < 12; ++i)
    {
        inv.set(mod12(inv.get(i-1) + series[i-1] - series[i]), i);
        
    }
    return inv;
}

//=========================================================================

Dodecaphonic Dodecaphonic::retrograde()
{
    Dodecaphonic retr;
    for (int i = 0; i < 12; ++i)
    {
        retr.set(series[i], 11-i);
        
    }
    return retr;
}


//=========================================================================

int main(int argc, const char * argv[]) {
    // insert code here...
    Dodecaphonic row, res;
    int interval, n;
    
    if(argc != 14 || argv[1][0] != '-')
    {
        printf("usage: %s [-oN | -rN | -iN] note1 note2 ... note12\n", argv[0]);
        
        return -1;
    }
    
    for (n = 0; n < 12; n++) // initialize the row object
    {
        row.set(atoi(argv[n+2]), n);
    }
    switch(argv[1][1])
    {
        case 'o': // original transposed
            interval = atoi(argv[1] + 2);
            res = row.transpose(interval);
            break;
            
        case 'r': // retrograde
            interval = atoi(argv[1]+2);
            res = row.retrograde().transpose(interval);
            break;
            
        case 'i': //inverted
            if (argv[1][3] != 'r')
            {
                interval = atoi(argv[1] + 2);
                res = row.invert().transpose(interval);
                
            }
            else //inverted retrograde
            {
                interval = atoi(argv[1]+3);
                res = row.invert().retrograde().transpose(interval);
                
            }
            break;
        default:
            printf("unrecognized option \n");
            return -1;
    }
        
        
        
    
    for (n = 0; n < 12; n++)
    {
        printf("%d", res.get(n));
    
    }
    printf("\n"); //newline
    
    return 0;
}
