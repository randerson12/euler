/**
 * PROJECT EULER
 * Exercise 003
 * Time: 0.000018s
 *
 * Problem:
 * The prime factors of 13195 are 5,7,13, and 29.
 * What is the largest prime factor of the number 600851475143?
 *
 * Solution:
 * We may use the Fundamental Theorem of Arithmetic to solve this problem.
 * This theorem states that any integer greater than 1 is either a prime number,
 * or it can be written as a unique product of prime numbers.
 *
 * Since all non-prime factors will already be factorized into primes,
 * we can create a complete factorization by enumerating though a small
 * subset of numbers starting at 2.
 *
 * We start with 2 and check how many times that number is divisible with
 * the remainder we have. Once 2 is not a divisor to the remainder, we 
 * increase the counter (i) by one and check 3. Because of the fact that
 * all even numbers greater than 2 cannot be primes, we then increment i
 * by 2, checking only the next odd number. We continue until i is larger
 * than the square root of the remainder.
 *
 * If the remainder is not 1, then the remainder is also a prime factor.
 * Since we're only looking for the largest prime factor, however, we
 * only need to check if it is larger than the largest factor found (maxFac).
 *
 * Because it checks a much smaller pool of numbers then the brute-force solution,
 * this solution is measurably faster and much less resource-intensive.
 */

#include "helper.h"

/**
 * Returns largest prime factor of n
 */
long maxPrimeFactor(long n)
{
    long curNum = n;
    long maxFac = 0;
    int i = 2;

    while (i*i < curNum) {
        if (curNum % i == 0) {
            curNum = curNum / i;
            maxFac = i;
        } else {
            i = (i == 2) ? 3 : i + 2;
        }
    }

    if (curNum > maxFac) {
        maxFac = curNum;
    }

    return maxFac;
}

int main(void)
{
    const long n = 600851475143;

    long factor = maxPrimeFactor(n);
    result(factor, 6857);

    return 0;
}

