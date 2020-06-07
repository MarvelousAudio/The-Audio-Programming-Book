//
//  main.c
//  0.6.4 a simple example
//
//  Created by ben haywood on 6/7/20.
//  Copyright © 2020 ben haywood. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a,b,c;
    
    printf("\n Please enter a number: ");
    scanf("%d", &a);
    
    printf(" Please enter a scond number: ");
    scanf("%d", &b);
    
    c = a + b;
    printf("%d + %d = %d \n" ,a,b,c);
    
    return 0;
}
