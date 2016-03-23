#include <vector>
#include <string>
#include <iostream>
#include <string.h>      
#include "class_struct.h"
#include "function_struct.h"
#include "source_code.h"

// all these include< > statements are to be binded in a sigle header file and linked later

void source_code::make_classes()
{
 //splitting of the code into lines has already been done while functionizing
	make_classes.resize(1); 

	for(std::vector <line_pair>::iterator classes_itr=lines.begin();classes_itr!=lines.end();)
	{
		//itr incrementing to be done in the following code.
		if(classes_itr->first[0]=='c'&&classes_itr->first[1]=='l'&&classes_itr->first[2]=='a'&&classes_itr->first[3]=='s'&&classes_itr->first[4]==':')
	        {

	            //classes inherited are taken care off in convert_to_cpp_classes.cpp
	            
	        	int space_count=classes_itr->second;
	        	int i,j;
	        	i=itr-lines.begin();
	        	while(((++classes_itr)->second)) > space_count);
					i2=itr-lines.begin()-1;
				classes.push_code(int_pair(i,j));

            }
        else
           {
                   classes_itr++;
           }
	}
}