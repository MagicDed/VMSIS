#include <stdio.h>                                                                          // Library which add life functions

int Screamtime(int);
void Scream(int*);                                                                          // Void scream function prototype

int main(void)
{
        int Seconds = 0;
        int *Canned;                                                                        // Pointer on Canned
        char x;                                                                             // Variable for program repeating
        do                                                                                  // Cycle of the program which continues while x = 'y'
        {   
            Seconds = Screamtime(Seconds);                                                  // The time when hourse will be out of home
            for(int i = 0; i < Seconds; i++)                                                // Cycle to scream
            {
                Scream(Canned);                                                             // Scream
            }
            printf("\nDo you want to continue to scream? y/n \n");                          // If horse come home you will be asked do continue your screaming or not
            rewind(stdin);
            scanf_s("%c", &x);                                                              // Scanning your answer
        } while (x == 'y');                                                                 // If y then Canned will scream with horse at home
        return 0;
}

int Screamtime(int Seconds)                                                                 // Function to set the time
{
    printf("How long is horse going to be not home in minutes? ");
    scanf_s("%d", &Seconds);
    Seconds = Seconds * 200 * 60 * 60;                                                      // idk how to really measure the time in C
    return Seconds;
}

void Scream(int *Canned)                                                                    // Void scream function
{
        printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");                                          // Print aaaa if function is called
}