#include "supporting_libs.h"

class counter
{
 public: 
              
    long int c = 0;
counter(long int n)
{
         c = n;

}

};
int main( )
{
counter cc = counter(2);
std::cout<<cc.c;
 
return 0;
}

