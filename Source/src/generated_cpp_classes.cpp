//this function, sends the code to convert to cpp,and keeps in all the details regarding the classes
#include<vector>
#include<string>
#include<string.h>
#include<iostream>	
#include<map>

#include "function_struct.h"
#include "source_code.h"
#include "function_struct.h"

//this following may not be implementing the classes rendering correctly,
//the implementer of the following function needs to take care of classes rendering too
void convert_to_cpp_classes(unsigned long int start,unsigned long int end,std::vector< line_pair >& lines,std::string& converted_code,function_declaration* _function,std::map< std::string,std::string >& variables );
void source_code::generated_cpp_classes() //declard in source_code.h
{
    	generated_cpp_classes.resize(classes.size()+1);

       std::vector< std::pair< std::string,classes_declaration > >::iterator classes_itr=generated_cpp_classes.begin();
       std::string converted_code;
       

     
       converted_code.clear();
       classes_declaration final_class;

     //each of the element in the classes list is considered and the final cpp code for the
     //classes is rendererd in generated_cpp_classes.

     for(std::vector < int_pair >::iterator itr=classes.begin();itr!=classes.end();itr++)
     {
       convert_to_cpp_classes(itr->first,itr->second,lines,&converted_code,&final_class);
        //the last argument is missing.
       classes_itr->first=converted_code;
       classes_itr->second=final_class;
       classes_itr++;
      }

}

