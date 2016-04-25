#include "supporting_libs.h"

void print_multi(artificial_string s,long int n)
{
    for(long int i=1;i<=n;i++)
    {
        std::cout<<s;
    }

}

void g(long int n,float u)
{
    std::cout<<n*u;

}

int main( )
{
g(10,2);
artificial_string ss = artificial_string("abhishek");
print_multi(ss.upper(),12);
 
return 0;
}

