#ifndef supporting_libs
#define supporting_libs

#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<ctype.h>
#include<map>
#include<stdlib.h>

/*  under dev
template<class key_type, class value_type>
class hash_tables
{
	std::vector < value_type > (max_number_of_variables);

public:

	bool insert(value_type);
	bool is_present(value_type);
	bool delete_elem(value_type);

};



bool hash_tables::insert(value_type &v)
{
	if()
}
*/

class artificial_string : public std::string
{
    std::string str;
    
    string captialize()    //String function for finding whether first letter is capital.
    {

        if (str.size())
        {

            str[0] = toupper(str[0]);

           return true;

        }
        else
        	return false;
    }


    int len()
    {
        return str.size();   //To return the sting length
    }


   string upper()
   {
    if(str.size())
    {
        int i=0;
        while(str[i]!='\0')
        {
            str[i]=toupper(str[i]);            //To convert a string to capital character
            i++;
        }             
        return str;
    }
    else return false;

   }

void lower()
{
    int l = str.length();
    for (int i = 0; i < l; i++)
        str[i] = tolower(str[i]);
}
    


// char max()		
// {
//     int i=0,max=95;                  //This function is grossly insane(assigning NULL to char ) , correct it
//     char c=NULL;
//     if(str.size())
//     {
//         while(str[i]!='\0')                        // To find maximum alphabetical character 
//         {
//             if(str[i] > max && str[i]< 123)
//             {
//                 c=str[i];
//                 max=str[i];
//             }
//             i++;
//         }
//         return c;
//     }
//     else return NULL;
// }

int min()
{
    return *min_element(str.begin(), str.end());
}

string swapcase()
{if(str.size())
    {int i=0;
        while(str[i]!='\0')
            {if(str[i]==isupper(s[i]))
                str[i]=tolower(s[i]);             //function to swapcase a given string
             else str[i]=toupper(s[i]); 
             i++; 
            }
return str;
    }
else return false;
}

bool islower()
{ if(str.size())
    {int i=0,flag=0;
         while(str[i]!='\0')
            {if(str[i]==islower(str[i]))
                i++;
            else {flag=1;
                break;}
             }

            if(flag==1) return false;
            else return true;
        }
        else return false;
    }

    bool isupper()
    { if(str.size())
        {int i=0,flag=0;
             while(str[i]!='\0')
                {if(str[i]==isupper(str[i]))
                    i++;
                else {flag=1;
                    break;}
                 }

                if(flag==1) return false;
                else return true;
            }
            else return false;
        }
       
bool isalpha()
    { if(str.size())
        {int i=0,flag=0;
             while(str[i]!='\0')
                {if(str[i]==isalpha(str[i]))
                    i++;
                else {flag=1;
                    break;}
                 }

                if(flag==1) return false;
                else return true;
            }
            else return false;
        }
};

#endif
