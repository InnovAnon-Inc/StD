#ifndef _SIMON_H_
#define _SIMON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

typedef __attribute__ ((warn_unused_result))
int (*random_range_t) (int min, int max) ;

unsigned range_int (int min, int max)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

int random_range_off_naive1 (unsigned int r, int off)
__attribute__ ((leaf, nothrow, warn_unused_result)) ;

int random_range_naive1 (int min, int max)
__attribute__ ((leaf, nothrow, warn_unused_result)) ;

int random_range_naive2 (int min, int max)
__attribute__ ((leaf, nothrow, warn_unused_result)) ;

int random_range_off_java (unsigned int n, int off)
__attribute__ ((leaf, nothrow, warn_unused_result)) ;

int random_range_java (int min, int max)
__attribute__ ((leaf, nothrow, warn_unused_result)) ;

void random_ranges (int dest[], size_t n,
	random_range_t cb, int min, int max)
__attribute__ ((nonnull (1, 3), nothrow)) ;

void random_ranges_uniq_knuth (int dest[], size_t n,
	random_range_t cb, int min, int max, int tmp[])
__attribute__ ((nonnull (1, 3), nothrow)) ;

void ez_random_ranges (int dest[], size_t n,
	int min, int max)
__attribute__ ((nonnull (1), nothrow)) ;

ssize_t range_ssize_t (ssize_t min, ssize_t max)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

size_t range_size_t (size_t min, size_t max)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

TODO (this algorithm is probably seriously flawed)
size_t random_range_java_size_t (size_t min, size_t max)
__attribute__ ((nothrow, warn_unused_result)) ;

size_t random_range_java_size_t2 (size_t min, size_t max)
__attribute__ ((nothrow, warn_unused_result)) ;

ssize_t random_range_java_ssize_t2 (ssize_t min, ssize_t max)
__attribute__ ((nothrow, warn_unused_result)) ;

typedef __attribute__ ((nonnull (1, 2), warn_unused_result))
int (*cmp_t) (void const *restrict, void const *restrict) ;

void random_range_naive_generic (void *restrict dest, size_t esz,
	cmp_t cmp, void const *restrict min, void const *restrict max)
__attribute__ ((nonnull (1, 3, 4, 5), nothrow)) ;

/*
typedef __attribute__ (())
int (*init_struct_field_t) (void *restrict field, void *restrict arg) ;

int init_struct (init_struct_field_t cbs[], size_t ncb) ;
*/

int range_int2 (int min, int max)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

int random_range_java2 (int min, int max)
__attribute__ ((leaf, nothrow, warn_unused_result)) ;

int random_range_off_java2 (unsigned int n, int off)
__attribute__ ((leaf, nothrow, warn_unused_result)) ;

#define TEST_NA (10)

int random_op (void *restrict ds, stdcb_t const tests[], size_t ntest)
__attribute__ ((nonnull (1, 2), nothrow, warn_unused_result)) ;

int random_ops (void *restrict ds, stdcb_t const tests[], size_t ntest,
	unsigned int n)
__attribute__ ((nonnull (1, 2), nothrow, warn_unused_result)) ;

void random_ops2 (void *restrict ds, stdcb_t const tests[], size_t ntest)
__attribute__ ((nonnull (1, 2), nothrow)) ;

#ifdef __cplusplus
}
#endif

#endif /* _SIMON_H_ */