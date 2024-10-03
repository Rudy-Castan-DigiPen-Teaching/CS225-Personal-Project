#include "Physics-Core.h"
namespace HookBill_Physics
{

    Vector3::Vector3() : x{0}, y{0}, z{0}, padding{0}
    {
    }
    Vector3::Vector3(const real x_, const real y_, const real z_)
        : x{x_}, y{y_}, z{z_}, padding{0} {}
    void Vector3::invert()
    {
        x *= -1;
        y *= -1;
        z *= -1;
    }

}