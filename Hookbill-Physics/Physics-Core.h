#include <precision.h>



namespace HookBill_Physics
{
   class Vector3
   {
      real x;
      real y;
      real z;
      real padding; // for padding

      Vector3();
      Vector3(const real x_, const real y_, const real z_);
      void invert();
   };

}
