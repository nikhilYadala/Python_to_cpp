/** @file functionize.cpp
 *  @brief The code after being broken into lines is sent here
 *          This function then identifies all the lines that belong to 
 *           its corresponding class 
 *  @bug No known bugs.
 */

#include <vector>
#include <string>
#include <iostream>
#include <string.h>      
#include "../Header/include/class_struct.h"
#include "../Header/include/function_struct.h"
#include "../Header/include/source_code.h"

// all these include< > statements are to be binded in a sigle header file and linked later

void source_code::make_classes()
{
 //splitting of the code into lines has already been done while functionizing
	classes.resize(0); 

	for(std::vector <line_pair>::iterator classes_itr=lines.begin();classes_itr!=lines.end();)
	{

		//itr incrementing to be done in the following code.
		if(classes_itr->first[0]=='c'&&classes_itr->first[1]=='l'&&classes_itr->first[2]=='a'&&classes_itr->first[3]=='s'&&classes_itr->first[4]=='s')
	        {

	            //classes inherited are taken care off in convert_to_cpp_classes.cpp
	            
	        	int space_count=classes_itr->second;
	        	int i1,i2;
	        	i1=classes_itr-lines.begin();
	        	while((((++classes_itr)->second)) > space_count)
					i2=classes_itr-lines.begin()-1;
				classes.push_back(int_pair(i1,i2));

            }
        else
           {
                   classes_itr++;
           }
	}

}