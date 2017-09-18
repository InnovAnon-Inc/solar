#include <solar-common.h>

__attribute__ ((const, leaf, nothrow, warn_unused_result))
double get_PI (void) {
   /*
   double pi;
   __asm
   {
      fldpi
      fstp pi
   }
   return pi;
   */
   return acos (-1.0f);
}
