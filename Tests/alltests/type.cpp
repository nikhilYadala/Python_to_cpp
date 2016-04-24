#include "supporting_libs.h"

void f(float a,long int b,artificial_string c)
{
    for(long int i=1;i<=b;i++)
    {
        std::cout<<a-i<<"  "<<c;
    }

}

int main( )
{
artificial_string s = artificial_string("Happy");
double cc = 123.9876;
long int bb = 10;
f(cc,bb,s);
 
return 0;
}

