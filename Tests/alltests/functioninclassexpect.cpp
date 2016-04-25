#include "supporting_libs.h"

class counter
{
 public: 
              
    long int count = 0;
void inc()
{
         count = count+1;

}

};
int main( )
{
counter cc = counter();
cc.inc();
std::cout<<cc.count;
 
return 0;
}

