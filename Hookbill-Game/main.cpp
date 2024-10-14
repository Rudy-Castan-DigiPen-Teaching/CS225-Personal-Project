#include"Physics-Core.h"
#include<vector>
#include<iostream>
void print_vector(std::span<int>test);

int main()
{
   
   HookBill_Physics::Vector3 vector{1.0,2.0,3.0};

   std::cout<< vector <<'\n';
   
   gsl::owner<int*>ptr= new int(3);
   gsl::not_null<int*>ptr1= new int(3);
   

   std::vector<int>test{1,2,3,4,5,6,7,8,9};
   

   int array[9]={1,2,3,4,5,6,7,8,9};
   print_vector(test);
   print_vector(array);



   

}

//if memory is adjacent we can use span 
void print_vector(std::span<int>test)
{
    for(auto it=test.begin(); it!=test.end(); it++)
    {
      std::cout<<*(it)<<" ";
    }
    std::cout<<'\n';
}

// void print_string(std::string_view&view)
// {

// }