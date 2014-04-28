/**
 * PROJECT EULER
 * Exercise 007
 * Time: 0.002562s
 *
 * Problem:
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, 
 * we can see that the sixth prime is 13. What is the 10001st prime number?
 *
 * Solution:
 * No mathematical forumula exists to find the nth prime number, but we can
 * quickly find the desired prime number by using the Sieve of Eratosthenes.
 *
 * This is a simple algorithm that iteratvely marks as composite (not prime)
 * the multiples of each prime, starting with multiples of 2. The multiples
 * of a given prime are generated as a sequence of numbers starting from that
 * prime, with constant difference between them which is equal to that prime.
 *
 * The sieve of Eratosthenes is one of the most efficient ways to find all of
 * the smaller primes (below 10 million or so).
 */

#include "helper.h"

#define MAX 125000

/**
 * Returns the nth prime number
 */
long prime(int n)
{
    unsigned int primes[MAX];
    int lastFound = 1;
    int primesFound = 1;
    int i,j;

    for (i = 0; i < MAX; i++) {
        primes[i] = i;
    }

    while (primesFound <= n) {
        for (i = 1; i <= MAX; i++) {
            if (primes[lastFound + i] != 0) {
                lastFound += i;
                break;
            }
        }
        for (j = 2; j < MAX; j++) {
            if (lastFound * j > MAX) {
                break;
            }
            primes[lastFound * j] = 0;
        }
        primesFound++;
    }

    return lastFound;
}

int main(void)
{
    const int target = 10001;

    startTimer();
    int nPrime = prime(target);
    stopTimer();
    result(nPrime, 104743);

    return 0;
}

