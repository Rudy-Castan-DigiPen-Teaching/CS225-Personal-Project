/**
 * @file particle.h
 * @author Jinseok Son
 * @brief  Particle header file
 * @version 0.1
 * @date 2024-10-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "Physics-Core.h"
namespace HookBill_Physics
{
    class Particle
    {
    protected:
    Vector3 position;

    Vector3 velocity;

    Vector3 accleration;
    
    real inverseMass;
    };
}