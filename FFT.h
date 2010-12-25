/* FFT.h
   Types and prototypes for FFT functions.
*/

#include <math.h>

#ifndef FFT_H_
#define FFT_H_

struct complex_s {
  double real, imag;
};
typedef struct complex_s complex_t;

#define M_2PI    6.2831853071795864769E0  /*Hex  2^ 2 * 1.921FB54442D18 */

/* Complex addition of z = x + y. */
#define COMPLEX_ADD(z, x, y)			\
{						\
  (z).real = (x).real + (y).real;		\
  (z).imag = (x).imag + (y).imag;		\
}

/* Complex subtraction of z = x - y. */
#define COMPLEX_SUB(z, x, y)			\
{						\
  (z).real = (x).real - (y).real;		\
  (z).imag = (x).imag - (y).imag;		\
}

/* Complex multiplication of z = x * y. */
#define COMPLEX_MULT(z, x, y)					\
{								\
  register double temp;						\
  temp = ((x).real * (y).real) - ((x).imag * (y).imag);		\
  (z).imag = ((x).real * (y).imag) + ((x).imag * (y).real);	\
  (z).real = temp;						\
}

/* Compute complex value of omega_sub^super. */
#define COMPLEX_ROOT(omega, sub, super)			\
{							\
  register double arg = (super) * M_2PI / (sub);	\
  (omega).real = cos(arg);				\
  (omega).imag = sin(arg);				\
}

#endif
