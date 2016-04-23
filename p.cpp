#include "supporting_libs.h"

class counter
{
 public: 
              
    long int c = 0;
void inc()
{
         c = c+1;

}

};
int main( )
{
counter cc = counter();
std::cout<<cc.c;
cc.inc();
std::cout<<cc.c;
 
return 0;
}

