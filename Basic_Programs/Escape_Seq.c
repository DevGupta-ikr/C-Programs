// Program to implement escape sequences
#include<stdio.h>

int main()
{
    printf("My mobile number is 7873923408\a");  // My mobile number is 7873923408
                                                   // Gives an notification ring

    printf("\nHello Friends\b\b\b\bE");          // Hello FriEnds
                                                  // Backspace: Goes to e and puts the Character E in place of e

    printf("\nHello fri\rends");                 // Output:  endso fri
                                                  // Carriage return

    printf("\nHello\\World");                   // Implementing Backslash

    printf("\n\' Hello Friends");             //Implementing Single Quote

    printf("\n\" Hello Friends\n");                  // Implementing Double Quote

    return (0);
}
