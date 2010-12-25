/*
 * fft.h
 * alex iliev, feb 2003
 * some declarations for the cilk fft program
 */

#include <stdlib.h>


/* oh what to give for generic types in C! */

typedef struct {
    complex_t * data;		/* the actual array */
    size_t start, stride;
} stride_array_t;


/*
 * a few helper operations for the stride arrays
*/


/*
  complex_t & STRIDE_IDX (stride_array_t * A, size_t i)
*/
#define STRIDE_IDX(A,i) \
    (A)->data [ (A)->start + (A)->stride * (i) ]


/* void STRIDE_MAKE (const stride_array_t * a,
                     stride_array_t * b,
		     size_t start_,
		     size_t stride_);

 make a new stride subarray 'b', starting with 'a', and with the specified
 stride and index
*/
#define STRIDE_INIT(b,a,start_,stride_) \
{ \
    (b)->data   = (a)->data; \
    (b)->start  = (a)->start + (a)->stride * (start_); \
    (b)->stride = (a)->stride * (stride_); \
}


/*
  STRIDE_INIT_RAW (stride_array_t * b, complex_t * raw);
   
  this one just initilizes with a raw array, and start=0 stride=1
*/
#define STRIDE_INIT_RAW(b,raw) \
{ \
    (b)->data   = (raw); \
    (b)->start  = 0; \
    (b)->stride = 1; \
} 


/*
  some functions
*/


/* Y is where the answer goes */
cilk void fft_main (complex_t * Y, stride_array_t * A, int N);


cilk void cilk_recombine (complex_t * Y,
			  size_t N,
			  int k, size_t size);

void recombine (complex_t * Y,
		size_t N,
		int k_start, size_t size);

/* cilky memcpy */
cilk void cilk_memcpy(void *dest, const void *src, size_t n);
