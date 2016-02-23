//this function is called from generated cpp_classes function which was called fr_om the main function after functionazing and make_classes class

#include<vector>
#include<string>
#include<string.h>
#include<iostream>	
#include<map>

#include "function_struct.h"
#include "source_code.h"
#include "function_struct.h"
//responds for the following function call from generated_cpp_classes()
//convert_to_cpp_classes(itr->first,itr->second,lines,&converted_code,&final_class);

class classes_covertor: public func_convertor
{
public:
void convert_to_cpp_classes(unsigned long int start,unsigned long int end,std::vector< line_pair >& lines,std::string& converted_code,function_declaration* _function,std::map< std::string,std::string >& variables );
     {

        std ::vector < std::string > tokens;
        tokens.resize(1);
        break_into_words(lines[start].first,tokens);//the lines get tokenized,inherited function

        if(tokens[0]=="class")
        {
            final_class->name=token[1];

            if(tokens[3]==":")
            	final_class.num_base_func=0;
            else(tokens[3]=="(")
            {
                 std::vector<std::string>::tokens_itr =tokens.begin()+3;
                 while(*(++tokens_itr)!=")")
                 {
                 	(final_class.base_functions).pushback(*tokens_itr);
                 	(final_class.num_base_func)++;//incremented each time a base func is found
                 	tokens_itr++; //to bypass the commas after each base function

                 }



            }//all the base classes(if any)are noted till here;
        
          }
          /*while(*tokens_itr=="\n")
          	tokens_itr++; //gets rid of all the new lines, infact only one new line char would be there
           */
          	//the above block is now no more required as, tokens no more store '\n'

          /************THE FOLLOWING LINES FILL std::string converted_code *******************/
          	converted_code.append("{\npublic:\n");

           
             for(unsigned long int i=start+1;i<=end;)
	            {	
		             tokens.clear();
		              break_into_words(lines[i].first,tokens);
		              std::vector< std::string >::iterator tokens_itr=tokens.begin();

		 if(*itr=="if")
		{

			itr++;
			bool is_not=0;
			if(*itr=="not")
				{
					is_not=1;
					itr++;
				}	
			std::string expr="";
			
			if(is_not)
				expr.append("!");

			while(*itr!=":")
				expr.append(*(itr++));
			
			converted_code.append((size_t)lines[i].second,' ');
			converted_code.append("if(");
			converted_code.append(expr);
			converted_code.append(")\n");
			converted_code.append((size_t)lines[i].second,' ');
			converted_code.append("{\n");
			
			int space_count=lines[i].second,st=i;
			
			while(lines[++i].second>space_count);
				
			std::string snippet;
			convert_to_cpp(st+1,i-1,lines,snippet,_function,variables);
			converted_code.append(snippet);
			
			converted_code.append((size_t)lines[st].second,' ');
			converted_code.append("}\n");
			//i already incremented while changing lines
			continue;

		}
		
		////NOTE:- Every section puts \n at its end so no need to put one in each section's beginning

		if(*itr=="print")
		{

			itr++;
			converted_code.append((size_t)lines[i].second,' ');
			converted_code.append("std::cout<<");
			int f=1;
			while(itr!=tokens.end())
			{
				if(*itr=="("||*itr==")")
					f=!f;

				if(!f||*itr!=",")
					converted_code.append(*itr);
				itr++;
			}
			converted_code.append(";\n");
			i++;
			continue;
		}



		/***** SOME MORE CASES HAVE TO BE TAKEN CARE OF HERE.*****/
		/***** Variables have to be explicitly taken care off.
      
      //At the the end, the closing lines of the classe in c++ is written
         converted_code.(append("\n};\n"));
    


     }//end of convert_to_cpp_classes
 };//end of the class named classes_convertor