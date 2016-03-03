#ifndef _FIBONACCI_ENDS_H_
#define _FIBONACCI_ENDS_H_

#include <stdbool.h>
#include <stdio.h>
#include <gmp.h>
#include <math.h>

unsigned int comptDigits(mpz_t *n);
bool pandigitalFibonacciEnds(mpz_t *n);
bool pandigitalFibonacciFirst(mpz_t *n);
bool pandigitalFibonacciLast(mpz_t *n);

#endif
