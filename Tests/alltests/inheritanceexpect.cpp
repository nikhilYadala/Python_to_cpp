#include "supporting_libs.h"

class person
{
 public: 
             
    long int gender = 0;
person(long int s)
{
         gender = s;

}

};
int main( )
{
long int gen;
std::cout<<"Enter Gender?";
std::cin>>gen;
std::cout<<person(gen).gender;
 
return 0;
}

