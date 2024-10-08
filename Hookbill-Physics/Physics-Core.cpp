#include"Physics-Core.h"
#include <cmath>
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

    real Vector3::magnitude() const
    {
       return x*x + y*y+ z*z;
    }

    real Vector3::SquareMagnitude() const
    {
       return std::sqrt(magnitude());
    }

    void Vector3::normalize()
    {
        real l= magnitude();
        *(this)*=(l/1);
    }
    
    void Vector3::operator*=(real value)
    {
        this->x*=value;
        this->y*=value;
        this->z*=value;
    }

     Vector3 Vector3::operator*(const real value) const
     {
        return Vector3(x*value,y*value,z*value);
     }

     void Vector3::operator+=(const Vector3&v) 
     {
        this->x+=v.x;
        this->y+=v.y;
        this->z+=v.z;
     }

     Vector3 Vector3::operator+(const Vector3&v)
     {
        return Vector3(x+=v.x,y+=v.y,z+=v.z);
     }

     void Vector3::operator-=(const Vector3&v)
     {
        this->x-=v.x;
        this->y-=v.y;
        this->z-=v.z;
     }

     Vector3 Vector3::operator-(const Vector3&v) const
     {
        return Vector3(x-v.x,y-v.y,z-v.z);
     }

    real Vector3::DotProduct(const Vector3& v1, const Vector3& v2) {
        return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
    }

    Vector3 Vector3::CrossProduct(const Vector3&v1, const Vector3&v2)
    {
        return Vector3( (v1.y*v2.z-v1.z*v2.y), (v1.z*v2.z - v1.x*v2.z),(v1.x*v2.y -v1.y*v2.x));
    }
}