/** @file supporting_libs.h
 *  @brief All the string library functions form python translated to cpp
 *
 *  @bug No known bugs.
 */


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


/**
*Its not working!!
*/

class artificial_string : public std::string
{
public:
    std::string str;


    artificial_string operator+(const artificial_string& s)
    {
        return artificial_string(this->str.append(s.str));
    }

    artificial_string operator+(const std::string& s)
    {
        return artificial_string(this->str.append(s));
    }
    artificial_string operator+(const char* s)
    {
        return artificial_string(this->str.append(s));
    }

    friend std::ostream &operator<<( std::ostream &output, 
                                       const artificial_string &context )
      { 
         output << context.str;
         return output;            
      }

    friend std::istream &operator>>( std::istream  &input, artificial_string &context )
      { 
         input >> context.str;
         return input;            
      }


    artificial_string(std::string s){
        str = s;
    }

/** @brief This is a string function to find if the first
 *         letter is capital in the artificial string
 *
 *  @param Works on artificial string str
 *  @return True or False
 */
    artificial_string capitalize()    //String function for finding whether first letter is capital.
    {

        if (str.size())
        {

            str[0] = toupper(str[0]);

           return artificial_string(str);
        }
        else return artificial_string("");

    }

/** @brief This is a string function to find the string length of artificial string
 *
 *  @param Works on artificial string str
 *  @return size of the artificial string
 */
    int len()
    {
        return str.size();   //To return the sting length
    }

/** @brief This is a string function to convert the artificial string 
 *         to all capital
 *
 *  @param Works on artificial string str
 *  @return string str which is in all CAPITAL
 */

   artificial_string upper()
   {
    if(str.size())
    {
        int i=0;
        while(str[i]!='\0')
        {
            str[i]=toupper(str[i]);            //To convert a string to capital character
            i++;
        }             

        return artificial_string(str);
    }
    else return artificial_string("");

   }


/** @brief This is a string function to convert the artificial string 
 *         to small letters
 *
 *  @param Works on artificial string str
 *  @return string str which is in all small characters
 */
artificial_string lower()
{
    int l = str.length();
    for (int i = 0; i < l; i++)
        str[i] = tolower(str[i]);

    return artificial_string(str);
}

/** @brief This is a string function to find the alphabetically maximum  
 *         character in string str
 *
 *  @param Works on artificial string str
 *  @return maximum alphabetical character in string str
 */
    

char max()      
{
    int i=0,max=95;
    char c=' ';
    if(str.size())
    {
        while(str[i]!='\0')                        // To find maximum alphabetical character 
        {
            if(str[i] > max && str[i]< 123)
            {
                c=str[i];
                max=str[i];
            }
            i++;
        }
        return c;
    }
    else return ' ';
}

/** @brief This is a string function to find the alphabetically minimum  
 *         character in string str
 *
 *  @param Works on artificial string str
 *  @return minimum alphabetical character in string str
 */
char min()      
{
    int i=0,min=123;
    char c=' ';
    if(str.size())
    {
        while(str[i]!='\0')                        // To find maximum alphabetical character 
        {
            if(str[i] < min && str[i]> 95)
            {
                c=str[i];
                min=str[i];
            }
            i++;
        }
        return c;
    }
    else return ' ';
}
/** @brief This is a string function to swapcase a given string str
 *  Basically a capital alphabet converts to small alphabet and a small alphabet to capital.
 *  @param Works on artificial string str
 *  @return a string str in swapped alphabet character
 */

std::string swapcase()
{
if(str.size())
    {int i=0;
        while(str[i]!='\0')
        {
        if(isupper(str[i]))
            str[i]=tolower(str[i]);             //function to swapcase a given string
        else str[i]=toupper(str[i]); 
        i++; 
        }
return str;
    }
else return std::string("") ;
}

};

#endif
