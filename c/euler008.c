/**
 * PROJECT EULER
 * Exercise 008
 * Time: 0.000022s 
 *
 * Problem:
 * Find the greatest product of five consecutive digits in the 1000-digit number:
 * 73167176531330624919225119674426574742355349194934
 * 96983520312774506326239578318016984801869478851843
 * 85861560789112949495459501737958331952853208805511
 * 12540698747158523863050715693290963295227443043557
 * 66896648950445244523161731856403098711121722383113
 * 62229893423380308135336276614282806444486645238749
 * 30358907296290491560440772390713810515859307960866
 * 70172427121883998797908792274921901699720888093776
 * 65727333001053367881220235421809751254540594752243
 * 52584907711670556013604839586446706324415722155397
 * 53697817977846174064955149290862569321978468622482
 * 83972241375657056057490261407972968652414535100474
 * 82166370484403199890008895243450658541227588666881
 * 16427171479924442928230863465674813919123162824586
 * 17866458359124566529476545682848912883142607690042
 * 24219022671055626321111109370544217506941658960408
 * 07198403850962455444362981230987879927244284909188
 * 84580156166097919133875499200524063689912560717606
 * 05886116467109405077541002256983155200055935729725
 * 71636269561882670428252483600823257530420752963450
 *
 * Solution:
 * First, store this number as one long one-dimensional array. Then, rather
 * than multiplying out every single set of consecutive integers, we can look
 * at 6 numbers at a time. For example, let's look at the first 6 numbers:
 * 731671. If we were to examine the first 5 numbers (73167) and then compare
 * it to the second 5 numbers (31671), we would notice that four of the numbers
 * are identical. Since those 4 numbers are the same in both cases, we can
 * conclude that the highest unique number (far left or far right) will produce
 * the highest product of 5 consecutive numbers; thus, we only need to perform
 * half the number of multiplication operations. We then compare the result of
 * our product to the current maximum product and store it if it's greater.
 *
 * If any of the 6 numbers contain a zero, we skip all numbers unti the zero has
 * passed. By adding j-1 to i, we skip to the index just before the zero; the
 * loop then increments by i+2, which moves the counter to the number just past
 * the zero.
 *
 * With these optimizations, we can produce an algorithm with complexity O(n/2),
 * whereas a less-optimized solution would have complexity O(n).
 */

#include "helper.h"
#include <stdlib.h>

/**
 * Return the greatest product of five consecutive digits in numString
 */
int maxProd(const char *numString)
{
    int numArray[1000] = {0};
    int i;
    int high_index = 0;
    int high_sum = 0;
    int result = 1;

    for (i=0; i<1000; i++) {
        numArray[i] = *(numString + i) - '0';
    }

    for (i=0; i<995; i+=2) {
        int j = 0;
        int sum = 0;
        int temp_high_index = i;
        int left = numArray[i];
        int right = numArray[i+5];

        for (j=0; j<6; j++) {
            if (numArray[i+j] == 0) {
                i += j-1;
                continue;
            }
        }

        if (left >= right) {
            for (j=0; j<5; j++) {
                sum += numArray[i+j];
            }
        } else {
            temp_high_index++;
            for (j=0; j<5; j++) {
                sum += numArray[i+j+1];
            }
        }

        if (sum >= high_sum) {
            high_sum = sum;
            high_index = temp_high_index;
        }
    }

    for (i=high_index; i<high_index+5; i++) {
        result *= numArray[i];
    }

    return result;
}

int main(void)
{
    const char *numString = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

    startTimer();
    int maxProduct = maxProd(numString);
    stopTimer();
    result(maxProduct, 40824);

    return 0;
}

