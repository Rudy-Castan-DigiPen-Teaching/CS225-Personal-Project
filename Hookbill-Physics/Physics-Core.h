/**
 * @file Physics-Core.h
 * @author Jinseok Son
 * @brief  Physics core header file
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "precision.h"

namespace HookBill_Physics
{
   class Vector3
   {
      public:
      real x;
      real y;
      real z;
      private:
      real padding; // for padding

      /**
       * @brief Construct a new Vector 3 object
       *
       */
      public:
      Vector3();

      /**
       * @brief Construct a new Vector 3 object
       *
       * @param x_
       * @param y_
       * @param z_
       */
      Vector3(const real x_, const real y_, const real z_);

      /**
       * @brief  invert given vector's x y z value
       *
       */
      void invert();
      /**
       * @brief calculate magnitude of this vector
       *
       * @return real
       */
      real magnitude() const;
      /**
       * @brief calculate length of this vector
       * 
       * @return real 
       */
      real SquareMagnitude() const;

      /**
       * @brief normalize this vector
       * 
       */
      void normalize();
      
      /**
       * @brief multiply give vlaue to each component
       * 
       * @param value 
       */
      void operator*=(const real value);
      
      /**
       * @brief 
       * @param  value
       * @return new vector
       */
      Vector3 operator*(const real value) const;
       
      /**
       * @brief add two vector
       * 
       * @param v new vector
       * @return * void 
       */
      void operator+=(const Vector3&v);
    
      /**
       * @brief add two vector and make new vecotkr
       * 
       * @param v 
       * @return new Vector3 
       */
      Vector3 operator+(const Vector3&v);
      
      /**
       * @brief subtract two vector 
       * 
       * @param v 
       */
      void operator-=(const Vector3&v);
      
      /**
       * @brief subtract two vector and make new one
       * 
       * @param v given vector
       * @return Vector3 
       */
      Vector3 operator-(const Vector3&v) const;
      
      /**
       * @brief calculate DotProduct
       * 
       * @param v given vector
       * @return  return result of Dot Product
       */
      static real DotProduct(const Vector3& v1, const Vector3& v2);
      /**
       * @brief 
       * 
       * @param v1 vector 1 
       * @param v2 vector 2
       * @return return result of Cross Product
       */
      static Vector3 CrossProduct(const Vector3&v1, const Vector3&v2);
   }; 

}
