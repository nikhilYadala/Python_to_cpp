#include "supporting_libs.h"

long int addi(long int a,long int b)
{
    return a+b;

}

long int subt(long int a,long int b)
{
    return a-b;

}

long int mult(long int a,long int b)
{
    return a*b;

}

long int divi(long int a,long int b)
{
    return a/b;

}

int main( )
{
std::cout<<addi(10,20);
std::cout<<subt(20,10);
std::cout<<mult(2,27);
std::cout<<divi(50,25);
 
return 0;
}

