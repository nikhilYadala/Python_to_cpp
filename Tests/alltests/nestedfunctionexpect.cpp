#include "supporting_libs.h"

void f(long int n)
{
    std::cout<<n;

}

long int p(long int x,long int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n==1)
    {
        return x;
    }
    else
    {
        long int r = p(x,n/2);
        return r*r*p(x,n%2);
    }

}

int main( )
{
std::cout<<p(2,8);
 
return 0;
}

