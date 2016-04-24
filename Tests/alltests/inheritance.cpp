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
class emp
{
 public: 
                      

};
int main( )
{
long int gen = int(raw_input("Enter Gender?"));
std::cout<<person(gen).gender;
 
return 0;
}

