/** @file functionize.cpp
 *  @brief This file sends the python code broken into functions
 *  @bug No known bugs.
 */
#include <vector>
#include <string>
#include <string.h>
#include <iostream>

#include "../Header/include/function_struct.h"
#include "../Header/include/source_code.h"
#define max_line_length 500

void self_sanitize(std::string* code) {
	int itr = code->find("self.", 0);
    while(itr != std::string::npos) {
        code->replace(itr, 5, ""); 
        itr = code->find("self.", itr);
    }

    itr = code->find("self", 0);
    while(itr != std::string::npos) {
        code->replace(itr, 4, ""); 
        itr = code->find("self", itr);
    }

    itr = code->find("import re", 0);
    while(itr != std::string::npos) {
        code->replace(itr, 9, ""); 
        itr = code->find("self", itr);
    }

    int rem = code->find("re.search(");
    if(rem!=std::string::npos){
    itr =  code->find("re.search(")+10;
    	// std::cout<<">>>>>>>>>>>"<<itr<<"  "<<"\n";
    while(*(code->begin()+itr)==' ')
    	itr++;


    std::string s ="",r="";
    while(*(code->begin()+itr)!=','){
    	r.push_back(*(code->begin()+itr));
    	itr++;
    }
    itr++;

    while(*(code->begin()+itr)!=')'){
    	s.push_back(*(code->begin()+itr));
    	itr++;
    }
    rem=itr-rem+1;
       itr = code->find("re.search(", 0);
    while(itr != std::string::npos) {
        code->replace(itr, rem, "std::regex_match("+s+",std::regex("+r+"))"); 
        itr = code->find("re.search(", itr);
    	}
	}
	// if(std::find(tokens.begin(), tokens.end(),"re.search")!=tokens.end())
	// {
	// 	converted_code.append((size_t)lines[i].second*tab_size,' ');	
	// 	converted_code.append("bool "+v+" = std::regex_match("+*(itr+8)+", std::regex_match("+*(itr+6)+"))"+"\n");		

	// }

}

/** @brief Evaluate the python code to break into functions
 *   This function takes out the function from python code by undrstanding the length of code that belongs to each function.
 *  @param NIL
 *  @return functions to convert_to_cpp
 */

void source_code::functionize()
{

	code.push_back('\n');
	self_sanitize(&code);
	std::cout<<code<<"\n\n\n";
	for(std::string::iterator itr=code.begin();itr!=code.end();)   //This for loop has no increment part to provide flexibility to inner code 
	{
		
		int i=0,space_count=0;
		
		if(*itr=='\n'){		//skips an empty line or a comment line
			itr++;
			continue;
		}

		if(*itr=='#')
		{
			while(*itr!='\n')
				itr++;	
		}


		while(*(itr)==' '||*itr=='	'){
				if(*itr=' ')
					space_count++;
				else space_count+=tab_size;
				itr++;
		} 
				
		int flag = 0;
		std::string buff;
		while(!(*itr=='\n'||*itr=='#' && flag%2==0)){			//This doesn't supports yet #,key words,etc. in strings ... small feature to implement later
			if(*itr=='"')
				flag+=1;
			buff.push_back(*itr);
			itr++;
		}
			
		
		if(buff.size())							//If line isn't empty 
			lines.push_back(line_pair(buff,space_count));
	}

	    // for(std::vector< line_pair >::iterator itr=lines.begin();itr!=lines.end();++itr)
		   // std::cout<<"lin"<<itr-lines.begin()<<": "<<itr->second<<"          "<<itr->first<<"\n"; 

	functions.resize(1);//Add sparse code here later
	only_functions=1;

	for(std::vector< line_pair >::iterator itr=lines.begin();itr!=lines.end();)
		{
			if(itr->first[0]=='d'&&itr->first[1]=='e'&&itr->first[2]=='f')
				{
					int space_count=itr->second;
					int i1=itr-lines.begin(),i2;
					while((++itr)->second>space_count);
					i2=itr-lines.begin()-1; 	
					std::cout<<"Fucntion -> "<<i1<<"   "<<i2<<"\n";	
					functions.push_back(int_pair(i1,i2));
				}

			else if(itr->first[0]=='c'&&itr->first[1]=='l'&&itr->first[2]=='a'&&itr->first[3]=='s'&&itr->first[4]=='s')
	        {

	            //classes inherited are taken care off in convert_to_cpp_classes.cpp
	            
	        	int space_count=itr->second;
	        	int i1,i2;
	        	i1=itr-lines.begin();
	        	while((++itr)->second > space_count);
				i2=itr-lines.begin()-1;
					std::cout<<"Classes -> "<<i1<<"   "<<i2<<"\n";	

				classes.push_back(int_pair(i1,i2));

            }
			else 
				{
					only_functions=0;
					int i1=itr-lines.begin(),i2=lines.size()-1;
					functions[0]=int_pair(i1,i2);	
					std::cout<<"Main -> "<<i1<<"   "<<i2<<"\n";	

					break;	
				}
		}

		number_of_functions=(functions.end()-functions.begin())-!(only_functions);  //Remove the sparse(outside of functions) code part


		  // for(std::vector< int_pair >::iterator itr=functions.begin();itr!=functions.end();++itr)
			   // std::cout<<"Function: "<<itr-functions.begin()<<"\n"<<itr->first<<"-----"<<itr->second<<"\n\n";			

}