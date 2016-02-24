#ifndef supporting_libs
#define supporting_libs

#include<vector>
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
    string str;
    
    bool captialize()    //String function for finding whether first letter is capital.
    {

        if (str.size())
        {

            str[0] = toupper(str[0]);

           return TRUE;
        }
        else
        	return false;
    }


    int len(artificial_string s)
    {
        return s.str.size();   //To return the sting length
    }


   bool upper()
   {
    if(str.size())
    {int i=0;
        while(str[i]!='\0')
        {str[i]=toupper(str[i]);            //To convert a string to capital character
            i++;
        }             
        return true;
    }
    else return false;

   }

char max(artificial_string s)
{int i=0,max=95;
    char c=NULL;
    if(s.str.size())
   { while(str[i]!='\0')                        // To find maximum alphabetical character 
   {
    if('str[i]' > max && 'str[i]'< 123)
    {
        c=str[i];
        max='str[i]';
    }
    i++;
}return c;
}
else return NULL;
}


};


#endif