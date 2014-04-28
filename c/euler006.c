/**
 * PROJECT EULER
 * Exercise 006
 * Time: 0.000003s
 *
 * Problem:
 * The sum of the squares of the first ten natural numbers is:
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is:
 * (1+2+...+10)^2 = 55^2 = 3025
 * Hence, the difference between the sum of the squares of the first ten
 * natural numbers and the square of the sum is 3025 - 385 = 2640.
 * Find the difference between the sum of the squares of the first one hundred
 * natural numbers and the square of the sum.
 *
 * Solution:
 * Although the brute-force solution is adequate for this small-scale problem,
 * it does not scale well with larger N values as it is complexity O(n). A more
 * elegant solution requires two formulas: the sum of natural numbers and the
 * sum of squares of natural numbers.
 *
 * The sum of natural numbers can be expressed as S_n = (n*(n+1)) / 2
 * Proofs for this formula may be found at the following link:
 * http://www.9math.com/book/sum-first-n-natural-numbers
 *
 * The sum of squares of natural numbers can be expressed as the following:
 * S^2_n = (n*(n+1)*(2n+1)) / 6. A proof for this formula may be found at
 * http://www.trans4mind.com/personal_development/mathematics/series/sumNaturalSquares.htm
 *
 * Now that we have the formulas, we can derive an infinitely scalable algorithm
 * to solve the problem in O(1) time.
 */

#include "helper.h"

/**
 * Returns difference between sum of squares of all natural numbers up to n and the square of the sum
 */
long diffSumSquares(int n)
{
    long sum = 0;
    long squared = 0;
    long result = 0;

    sum = (n*(n+1)) / 2;
    squared = (n*(n+1)*(2*n+1)) / 6;
    result = sum * sum - squared;

    return result;
}

int main(void)
{
    const int limit = 100;

    long diff = diffSumSquares(limit);
    result(diff, 25164150);

    return 0;
}

