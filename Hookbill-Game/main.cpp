#include<iostream>
#include<Physics-Core.h>
int main()
{
    std::cout<<"Hello Mother Fucker" <<'\n';
    HookBill_Physics::Vector3 vec_1(1.0,2.0,3.0);
    HookBill_Physics::Vector3 vec_2(3.0,4.0,5.0); 
   
    HookBill_Physics::Vector3 vec_3= HookBill_Physics::Vector3::CrossProduct(vec_1,vec_2);
    std::cout<<vec_3.x<<'\n';
    std::cout<<vec_3.y<<'\n';
    std::cout<<vec_3.z<<'\n';
 

}