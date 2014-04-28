/**
 * PROJECT EULER
 * Exercise 005
 * Time: 0.000003s
 *
 * Problem:
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder. What is the smallest positive number that is
 * evenly divisible by all of the numbers from 1 to 20?
 *
 * Solution:
 * By using the following algorithm, we can efficiently determine the least common
 * multiple of any sequence of positive numbers.
 *
 * Assign the least common multiple of the first number F_1 in the sequence to lcm.
 * For successive number in the sequence starting at F_2, determine the greatest common divisor
 * between F_n and the current lcm value. Multiply the value F_n/gcd by the lcm value
 * and store the result in lcm.
 */

#include "helper.h"

/**
 * Returns greatest common divisor of a and b using Euclidean Algorithm
 */
int gcd(int a, int b)
{
    int c;

    while (a != 0) {
        c = a;
        a = b % a;
        b = c;
    }

    return b;
}

/**
 * Returns least common multiple evenly divisible by all numbers 1 through p
 */
int leastCommonMultiple(int p)
{
    int lcm = 1;
    int i;

    for (i = 2; i <= p; i++) {
        lcm *= i / gcd(i, lcm);
    }

    return lcm;
}

int main(void)
{
    const int limit = 20;

    int lcm = leastCommonMultiple(limit);
    result(lcm, 232792560);

    return 0;
}

