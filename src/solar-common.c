#include <math.h>

#include <solar-common.h>

__attribute__ ((const, leaf, nothrow, warn_unused_result))
double get_PI (void) {
#ifdef __asm
   double pi;
   __asm
   {
      fldpi
      fstp pi
   }
   return pi;
#else
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
   return acos (-1.0);
	#pragma GCC diagnostic pop
#endif
}
