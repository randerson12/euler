/**
 * PROJECT EULER
 * Exercise 009
 * Time: 0.000001s 
 *
 * Problem:
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which
 * a^2 + b^2 = c^2. For example, 3^2 + 4^2 = 9+16 = 25 = 5^2.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 *
 * Solution:
 * We can use Euclid's Formula to generate Pythagorean triples given an arbitrary
 * pair of positive integers m and n with m>n. The formula states that the
 * integers a = m^2 - n^2, b = 2mn, c = m^2 + n^2 form a Pythagorean triple. These
 * equations can be used to solve this problem.
 *
 * Furthermore, we need to prove that the Pythagorean triplet is primitive. By
 * definition, a Pythagorean Triplet is called primitive if a,b,c are coprime.
 * That means that the greatest common divisor (gcd) of the set {a,b,c} is 1.
 *
 * Assume that gcd(n,m)=d>1. This menas that d^2 is a common divisor for {a,b,c}
 * and if both n and m are odd then a,b,c are even; thus, 2 is a common divisor.
 * Now assume that exactly one of m and n is even and the triplet is not primitive.
 * Since the triplet is not primitive, a prime p is divisible with a,b,c. From the
 * condition that exactly one of m and n is odd, it follows that a,c, and p are
 * also odd. Any odd prime that divides b must also divide m and/or n. Without
 * generality, assume that it divides m; thus, it must also divide m^2. Since the
 * prime is also a divisor of c=m^2+n^2, then it follows that it must divide n^2
 * and n as well. Thus, p is a divisor of m and n, meaning that m and n are not
 * coprimes.
 */

#include "helper.h"
#include <math.h>

/**
 * Returns greatest common divisor of a and b using Euclidean algorithm
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
 * Finds triplets a,b,c for which a+b+c = s and returns product a*b*c
 */
int tripletProd(int s)
{
    int a,b,c,m,k,n,d = 0;
    int found = 0;
    int product;

    for (m = 2; m <= sqrt(s/2); m++) {
        if ((s/2) % m == 0) {
            if (m % 2 == 0) {
                k = m+1;
            } else {
                k = m+2;
            }
            while (k < 2*m && k <= s/(2*m)) {
                if (s/(2*m) % k == 0 && gcd(k,m) == 1) {
                    d = s/2/(k*m);
                    n = k-m;
                    a = d*(m*m-n*n);
                    b = 2*d*n*m;
                    c = d*(m*m+n*n);
                    found = 1;
                    break;
                }
                k += 2;
            }
        }
        if (found == 1) {
            break;
        }
    }

    product = a*b*c;
    return product;
}

int main(void)
{
    const int sum = 1000;

    startTimer();
    int product = tripletProd(sum);
    stopTimer();
    result(product, 31875000);

    return 0;
}

