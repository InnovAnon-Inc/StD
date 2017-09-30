#ifndef _STD_H_
#define _STD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>

#include <glitter.h>

typedef __attribute__ ((warn_unused_result))
int (*random_range_t) (int min, int max) ;

int range (int min, int max)
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

void ez_random_ranges (int dest[], size_t n,
	int min, int max)
__attribute__ ((nonnull (1), nothrow)) ;

typedef __attribute__ (())
int (*init_struct_field_t) (void *restrict field, void *restrict arg) ;

int init_struct (init_struct_field_t cbs[], size_t ncb) ;

#ifdef __cplusplus
}
#endif

#endif /* _STD_H_ */