#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

/*#define NDEBUG 1*/

#ifndef NDEBUG
#include <stdio.h>
#endif
#include <stdlib.h>
#include <string.h>

/*#include <math.h>*/
#include <swap.h>

#include <std.h>

__attribute__ ((const, leaf, nothrow, warn_unused_result))
int range (int min, int max) {
	return max - min + 1;
}

/* https://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range */

__attribute__ ((leaf, nothrow, warn_unused_result))
int random_range_naive1 (int min, int max) {
	TODO (allow other RNGs)
	return min + (rand () % range (min, max));
}

__attribute__ ((leaf, nothrow, warn_unused_result))
int random_range_naive2 (int min, int max) {
	int     n  = range (min, max);
	double tmp = (double) rand ();
	double ret = tmp / RAND_MAX * n;
	return (int) ret;
}

__attribute__ ((leaf, nothrow, warn_unused_result))
int random_range_java (int min, int max) {
	int n = range (min, max);
	int r = RAND_MAX % n;
	int x;
	do x = rand ();
	while (x >= RAND_MAX - r);
	return min + x % n;
}

__attribute__ ((nonnull (1, 3), nothrow))
void random_ranges (int dest[], size_t n,
	random_range_t cb, int min, int max) {
	size_t k;
	for (k = 0; k != n; k++)
		dest[k] = cb (min, max);
}

__attribute__ ((nonnull (1), nothrow))
void ez_random_ranges (int dest[], size_t n,
	int min, int max) {
	random_ranges (dest, n, random_range_java, min, max);
}
