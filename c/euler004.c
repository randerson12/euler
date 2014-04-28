/**
 * PROJECT EULER
 * Exercise 004
 * Time: 0.003295s
 *
 * Problem:
 * A palindromic number reads the same both ways. The largest palindrome made
 * from the product of two 2-digit numbers is 9009 = 91 x 99. Find the
 * largest palindrome made from the product of two 3-digit numbers.
 *
 * Solution:
 * Since there isn't an elegant mathematical formula to solve this particular
 * problem, we must iterate through all products of 3 digit numbers and check
 * each of them to see if it is a palindrome. If so, we store that product in
 * the 'max' variable. If a product is both a palindrome and is higher than
 * the current max, it becomes the current max.
 *
 * In any factor pair of i and j, i must be larger than the square root of
 * the palindrome number, and as a result j must be lower. Therefore, we
 * can limit our search for i knowing that we only have to check numbers
 * between 999 and the square root of the palindrome number. Furthermore,
 * we can limit our search by checking that j = max/i < 1000, since it
 * means that the proposed solution no longer consists of two 3-digit
 * numbers, which was one of the requirements.
 *
 * We can use a mathematical formula to derive the palindrome p of a given
 * number n. As long as n is nonzero, we may create p from the following
 * formula:
 * (1) Multiply p by 10 and add the remainder of n/10
 * (2) Divide n by 10
 * Then we simply check if p = n. If so, n is a palindrome.
 */

#include "helper.h"

/**
 * Determines if n is a palindrome; returns 0 if false or 1 if true
 */
int isPalindrome(unsigned int n)
{
    unsigned int reversed = 0;
    unsigned int original = n;

    if (n < 10) {
        return 1;
    }

    if (n % 10 == 0) {
        return 0;
    }

    while (n >= 1) {
        reversed = (reversed * 10) + (n % 10);
        n = n / 10;
    }

    if (original == reversed) {
        return 1;
    }
    
    return 0;
}

/**
 * Returns the largest palindrome made from the product of two 3-digit numbers
 */
unsigned int maxPalindrome()
{
    unsigned int max,prod = 0;
    unsigned int i,j;

    for (i = 999; i > 99; i--)
    {
        for (j = 999; j > 99; j--)
        {
            prod = i * j;
            if (isPalindrome(prod) && (prod > max))
            {
                max = i * j;
            }
            if (max > i*i || (max/i) > 999) {
                break;
            }
        }
    }

    return max;
}

int main(void)
{
    startTimer();
    unsigned int max = maxPalindrome();
    stopTimer();
    result(max, 906609);

    return 0;
}

