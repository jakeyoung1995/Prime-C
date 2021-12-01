/////////////////////////////////////////////////////////////////
//
// What are the prime numbers up to the number entered? Let's find out.
//
// Compile:  gcc Prime.c -o  Prime -lpthread
// 
// Run:      ./Prime  <enter number>
//
///////////////////////////////////////////////////////////////

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void *Prime_Thread(void *val) {
    int *pointer = (int*) val;
    int value = *pointer;
    int i = 2, j, sum;

    printf("\n The prime numbers of a given number %d are: " , value);

    // Loop to find prime numbers
    for(sum = 2; i <= value; i++) {
        for(j = 2; j <= i - 1; j++) {
            if(i % j == 0) // Not Prime! 
            break;
        }
        if(j == i) {
            printf("%d, ", i); // Print prime numbers seperated by commas
            sum++;
        } 
    }
}

// Main function that takes 2 arguments
int main(int argc, char *argv[]) {
    pthread_t Threads;

    int value; // Variable declaration

    // Allow user to enter a number
    printf("Enter a number to find the primes: ");
    scanf("%d", &value);

    if(argc > 1) { // Check to see if there are more than 1 numbers entered
        printf("\n This is not a valid number. Please try again!");
        return 0;
    }

    // Check to see that the number entered is not less than 2
    if(value < 2) {
        printf("\n This is not a valid number. Please enter a positive integer no less than 2!");
        return 0;
    }

    pthread_create(&Threads, NULL, Prime_Thread, &value);
    pthread_join(Threads, NULL);
    pthread_exit(NULL);

    return 0;
}