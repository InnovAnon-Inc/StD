#if HAVE_CONFIG_H
#include <config.h>
#endif

#define _POSIX_C_SOURCE 200112L
#define __STDC_VERSION__ 200112L

/*#define NDEBUG 1*/

#ifndef NDEBUG
#include <stdio.h>
#endif
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/*#include <math.h>*/
#include <swap.h>

#include <simon.h>

TODO (struct std with RNG + seed etc)

__attribute__ ((const, leaf, nothrow, warn_unused_result))
int range_int (int min, int max) {
	return max - min + 1;
}

/* https://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range */

__attribute__ ((leaf, nothrow, warn_unused_result))
int random_range_off_naive1 (int r, int off) {
	TODO (allow other RNGs)
	return off + (rand () % r);
}

/* probabilities are slightly skewed */
__attribute__ ((nothrow, warn_unused_result))
int random_range_naive1 (int min, int max) {
	TODO (allow other RNGs)
	return random_range_off_naive1 (range (min, max), min);
}

/* the "skew" is a bit better distributed here */
__attribute__ ((leaf, nothrow, warn_unused_result))
int random_range_naive2 (int min, int max) {
	int     n  = range (min, max);
	int    tmp = rand ();
	double ret = (double) tmp / (double) RAND_MAX * (double) n;
	return (int) ret;
}

/* warning: there's some sort of effect due to the interaction of this algo
 * and some pRNGs */
__attribute__ ((leaf, nothrow, warn_unused_result))
int random_range_off_java (int n, int off) {
	int r = RAND_MAX % n;
	int d = RAND_MAX - r;
	int x;
	do x = rand ();
	while (x >= d);
	return off + x % n;
}
__attribute__ ((nothrow, warn_unused_result))
int random_range_java (int min, int max) {
	return random_range_off_java (range (min, max), min);
}

__attribute__ ((nonnull (1, 3), nothrow))
void random_ranges (int dest[], size_t n,
	random_range_t cb, int min, int max) {
	size_t k;
	for (k = 0; k != n; k++)
		dest[k] = cb (min, max);
}

__attribute__ ((nonnull (1, 3), nothrow))
void random_ranges_uniq_knuth (int dest[], size_t n,
	random_range_t cb, int min, int max, int tmp[]) {
	size_t k;
	for (k = 0; k != n; k++)
		dest[k] = cb (0, max - min);
	#pragma GCC ivdep
	for (k = 0; k != n; k++)
		dest[k] += min;
}

__attribute__ ((nonnull (1), nothrow))
void ez_random_ranges (int dest[], size_t n,
	int min, int max) {
	random_ranges (dest, n, random_range_java, min, max);
}

__attribute__ ((const, leaf, nothrow, warn_unused_result))
ssize_t range_ssize_t (ssize_t min, ssize_t max) {
	return max - min + 1;
}

__attribute__ ((const, leaf, nothrow, warn_unused_result))
size_t range_size_t (size_t min, size_t max) {
	return max - min + 1;
}

TODO (this algorihtm is probably seriously flawed)
__attribute__ ((nothrow, warn_unused_result))
size_t random_range_java_size_t (size_t min, size_t max) {
	size_t n = range_size_t (min, max);
	size_t r = n % (size_t) RAND_MAX;
	size_t d = abs ((int) ((size_t) RAND_MAX - r));
	/* assumes sizeof (size_t) % sizeof (char) == 0 */
	char x[sizeof (size_t) / sizeof (char)];
	do ez_random_ranges (x, sizeof (size_t), 0, CHAR_MAX);
	while (*(size_t *) x >= d);
	return min + *(size_t *) x % n;
}

__attribute__ ((nonnull (1, 3, 4, 5), nothrow))
void random_range_naive_generic (void *restrict dest, size_t esz,
	cmp_t cmp, void const *restrict min, void const *restrict max) {
	do ez_random_ranges (dest, esz, 0, CHAR_MAX);
	while (cmp (dest, min) < 0 || cmp (dest, max) > 0) ;
}





/*
__attribute__ ((leaf, nonnull (1, 2, 3), nothrow, warn_unused_result))
int init_struct (init_struct_field_t const cbs[],
	void *restrict const fields[],
	void const *restrict const args[], size_t ncb) {
	size_t i;
	for (i = 0; i != ncb; i++)
		error_check (cbs[i] (fields[i], args[i]) != 0)
			return -1;
	return 0;
}
*/
/*
void *restrict random_element () {

}
*/
/*
int random_operation (void *restrict ds, stdcb_t cbs[], void *restrict args[], size_t ncb) {
	size_t i = random_range_java_size_t (0, ncb - 1);
	return cbs[i] (ds, args[i]);
}
*/
/*
int random_operation (void *restrict ds, stdcb_t cbs[], void *restrict args[], size_t ncb) {
	size_t i = random_range_java_size_t (0, ncb - 1);
	return cbs[i] (ds, args[i]);
}
*/

/* init
 * vs
 * alloc + free
 */
/* insert + bulk
 * remove + bulk
 */





TODO (print_cb instead of hardcoded type and format string)
TODO (snprintf)
/*
static void data_print (void const *restrict data,
   size_t i, size_t j) {
   fprintf (stderr, "["); fflush (stderr);
   / *if (array->n != 0) {* /
   if (i != j) {
      fprintf (stderr, "%d", ((int const *restrict) data)[i]); fflush (stderr);
      for (i++; i != j; i++)
         fprintf (stderr, ", %d", ((int const *restrict) data)[i]); fflush (stderr);
   }
   fprintf (stderr, "]\n"); fflush (stderr);
}
*/