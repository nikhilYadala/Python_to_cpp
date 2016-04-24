#include "supporting_libs.h"

void pr(long int n)
{
    while(n>0)
    {
        std::cout<<n<<"\n";
         n = n-1;
    }

}

int main( )
{
pr(10);
 
return 0;
}

