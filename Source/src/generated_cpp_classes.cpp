/** @file generated_cpp_classes.cpp
 *  @brief This function, sends the code to convert to cpp,and keeps in all the details regarding the classes
 *  @bug No known bugs.
 */
 #include <vector>
#include <string>
#include <string.h>
#include <iostream>	
#include <map>

#include "../Header/include/function_struct.h"
#include "../Header/include/source_code.h"
#include "../Header/include/class_struct.h"

//this following may not be implementing the classes rendering correctly,
//the implementer of the following function needs to take care of classes rendering too

void convert_to_cpp_classes(unsigned long int start,unsigned long int end,std::vector< line_pair >& lines,std::string& converted_code,class_declaration* final_class,std::map< std::string,std::string >& variables );

/** @brief Sends all classes to convert_to_cpp_classes.cpp
 *
 *  It takes in the classes from python code and send it convert_to_cpp_classes.cpp to make classes in C++.    
 *  @param NIL
 *  @return NIL 
 */
void source_code::generate_cpp_classes() //declard in source_code.h
{
    	generated_cpp_classes.resize(classes.size()+1);

       std::vector< std::pair< std::string,class_declaration > >::iterator classes_itr=generated_cpp_classes.begin();
       std::string converted_code;
       

     
       converted_code.clear();
       class_declaration final_class;
            std::map< std::string,std::string > variables;  //name,pair(value,type)

     //each of the element in the classes list is considered and the final cpp code for the
     //classes is rendererd in generated_cpp_classes.
      std::cout<<"the classes size is"<<classes.size()<<"\n";

     for(std::vector < int_pair >::iterator itr=classes.begin();itr!=classes.end();itr++)
     {
      converted_code.clear();
       convert_to_cpp_classes(itr->first,itr->second,lines,converted_code,&final_class,variables);
        //removing the class name from the converted code.

         for(int j=0;j<converted_code.size();j++)
             {
              if(converted_code[j]!='\n')
                converted_code[j]=' ';
              else
                break;
             }
       classes_itr->first=converted_code;


       classes_itr->second=final_class;
       classes_itr++;
      }

}

