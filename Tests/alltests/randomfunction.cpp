#include "supporting_libs.h"

void printinfo(artificial_string name,long int age)
{
            std::cout<<"Name: "<<"  "<<name;
            std::cout<<"Age "<<"  "<<age;
            return ;;

}

int main( )
{
artificial_string s = artificial_string("Miki");
printinfo(s,60);
 
return 0;
}

