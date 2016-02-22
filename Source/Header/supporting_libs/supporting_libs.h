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

};

#endif