#include "supporting_libs.h"

void printinfo(artificial_string name,long int age)
{
            std::cout<<"Name: "<<"  "<<name;
            std::cout<<"Age "<<"  "<<age;
            return ;

}

int main( )
{
artificial_string nm = artificial_string("Miki");
printinfo(nm,50);
 
return 0;
}
