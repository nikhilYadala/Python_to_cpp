 #include <vector>
#include <string>
#include <string.h>
#include <iostream>

#include "../Header/include/function_struct.h"
#include "../Header/include/source_code.h"
#define max_line_length 500


void source_code::functionize()
{
	code.push_back('\n');
	// std::cout<<code;
		
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

	    //for(std::vector< line_pair >::iterator itr=lines.begin();itr!=lines.end();++itr)
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
					functions.push_back(int_pair(i1,i2));
				}
				else{
					only_functions=0;
					int i1=itr-lines.begin(),i2=lines.size()-1;
					functions[0]=int_pair(i1,i2);	
					break;	
				}
		}

		number_of_functions=(functions.end()-functions.begin())-!(only_functions);  //Remove the sparse(outside of functions) code part


		  // for(std::vector< int_pair >::iterator itr=functions.begin();itr!=functions.end();++itr)
			   // std::cout<<"Function: "<<itr-functions.begin()<<"\n"<<itr->first<<"-----"<<itr->second<<"\n\n";			

}