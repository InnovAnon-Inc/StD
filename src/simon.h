#ifndef _SIMON_H_
#define _SIMON_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

typedef __attribute__ ((warn_unused_result))
int (*random_range_t) (int min, int max) ;

int range_int (int min, int max)
__attribute__ ((const, leaf, nothrow, warn_unused_result)) ;

int random_range_naive1 (int min, int max)
__attribute__ ((leaf, nothrow, warn_unused_result)) ;

int random_range_naive2 (int min, int max)
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

TODO (this algorihtm is probably seriously flawed)
size_t random_range_java_size_t (size_t min, size_t max)
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

#ifdef __cplusplus
}
#endif

#endif /* _SIMON_H_ */