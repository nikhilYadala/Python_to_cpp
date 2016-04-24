#include "supporting_libs.h"

int main( )
{
for(long int i=1;i<=100;i++)
{
    long int n = i-1;
    long int f = 1;
    while(n>1)
    {
        if(i%n==0)
        {
             f = 0;
        }
         n = n-1;
    }
    if(f)
    {
        std::cout<<i		;
    }
}
 
return 0;
}

