/**
 * PROJECT EULER
 * Helper File
 * Compares attempt against answer and returns appropriate message
 */

#include "helper.h"
#include <stdio.h>
#include <time.h>

clock_t begin, end;
double time_spent;

long result(long attempt, long ANSWER)
{
    if (attempt == ANSWER) {
        printf("Success!\nTotal Time:\n");
        printf("%fs\n", time_spent);
        return 0;
    }

    printf("Keep trying.\n%ld\n", attempt);
    return 1;
}

void startTimer(void)
{
    begin = clock();
}

void stopTimer(void)
{
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
}

