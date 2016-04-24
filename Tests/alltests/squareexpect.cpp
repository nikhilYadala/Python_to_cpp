#include "supporting_libs.h"

int main( )
{
long int n = 676;
long int flag = 0;
for(long int i=1;i<=n;i++)
{
                                if((i*i==n))
                                {
                                                                std::cout<<i;
                                                                 flag = 1;
                                }
}
if((flag==0))
{
                                std::cout<<"no";
}
 
return 0;
}

