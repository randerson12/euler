/**
 * PROJECT EULER
 * Exercise 001
 * Time: 0.000001s
 *
 * Problem:
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, 
 * we get 3, 5, 6, and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Solution:
 * Given finite arithmetic progression, we can create a function that calculates the sum
 * of numbers divisible by n up to limit p. By calling that function with n values 3 & 5
 * and removing duplicate numbers (divisible by 15) from the resulting sum, we may reach
 * a solution with complexity O(1) instead of the brute-force solution's complexity O(n).
 *
 * In order to determine the sum of all numbers divisible by n, we need to first express
 * the sum as 1+2+3+4+..+N = (N*(N+1)/2). Thus, sequences for any number divisible by n
 * can be written as n*N*(N+1)/2. N is the highest number less than p divisible by n.
 * In the case of 5, this is 995; with integer division, N may be expressed as N = p/n.
 * Hence, we may calculate the sum of numbers divisible by n with n*(p/n)*((p/n)+1)/2.
 *
 * A formal mathematical proof for (N*(N+1)/2) may be found at the following link:
 * http://www.ugrad.math.ubc.ca/coursedoc/math101/notes/integration/sums.html
 */

#include "helper.h"

/**
 * Returns the sum of all multiples of n below limit p
 */
int sumDivisible(int n, int p)
{
    return n*(p/n)*((p/n)+1)/2;
}

int main(void)
{
    const int limit = 999;

    startTimer();
    int sum = (sumDivisible(3, limit) + sumDivisible(5, limit)) - sumDivisible(15, limit);
    stopTimer();
    result(sum, 233168);

    return 0;
}

