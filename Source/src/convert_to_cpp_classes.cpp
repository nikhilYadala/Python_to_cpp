//this function is called from generated cpp_classes function which was called fr_om the main function after functionazing and make_classes class
/** @file convert_to_cpp_classes.cpp
 *  @brief The helper functions in this file help converting python classes to its equivalent cpp version
 *  @bug No known bugs.
 */
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <map>

#include "../Header/include/function_struct.h"
#include "../Header/include/source_code.h"
#include "../Header/include/function_struct.h"
//responds for the following function call from generated_cpp_classes()
//convert_to_cpp_classes(itr->first,itr->second,lines,&converted_code,&final_class);

/** @brief The functions defined in a class are sent into this functio
 *
 * @param starting line of the python code of a funciton
 * @param ending line of the python code of a function
 * @param all the lines of the python code
 * @param string into which the converted_Cpp_code is returned
 * @param function_declaration stores all the properties of the concerned function
 * @param variables structure to deal with the variables declared and intialised
 *               in this function
 * @return NIL
 */
void convert_to_cpp(unsigned long int start,unsigned long int end,std::vector< line_pair >& lines,std::string& converted_code,function_declaration* _function,std::map< std::string,std::string >& variables );

/** @brief Evaluate the python code to C++ code 
 *
 *  @param python expression
 *  @return converted C++ expression.
 */
std::string eval_expr_(std::string& s)
{
	std::string evaled = "";
	if(*s.begin()=='"') {
		std::string subject = "";
		std::string::iterator itr = s.begin()+1;
		for(;*itr!='"';++itr)
			subject.push_back(*itr);

		evaled.append("artificial_string(\""+subject+"\")");

		itr++;
		for(;itr!=s.end();++itr)
			evaled.push_back(*itr);
	}
	if(evaled == "")
		evaled  = s;

	return evaled;
}


/** @brief Checks the special symbols used 
 *   
 *   It reads the character and checks if it is a special symbol used in python 
 *  @param character c
 *  @return Tells if the read symbol is special or not.
 */
bool is_symbol_(char c){
	char symbols[]=" =:;(){}[]|,.&+-<>*/'\n#";

	for(int i=0;symbols[i]!='#';++i)
		if(symbols[i]==c)
			return 1;
	return 0;

}

std::string expr_type_(std::string& expr,std::map< std::string,std::string >& variables)
{	
	if(expr[0]=='"')
		return "artificial_string";
	if(isdigit(expr[0]) || expr[0]=='-')
	{
		for(std::string::iterator i=expr.begin();i!=expr.end();++i)
			if(*i=='.')
				return "double";
		return "long int";
	}	
	std::string::iterator itr=expr.begin();
	std::string first_variable;
	while(itr!=expr.end()){
		if(is_symbol_(*itr)&&*itr!='.')
			break;
		first_variable.push_back(*(itr++));
	}
	
	if(variables.count(first_variable))
		return variables[first_variable];	//Implicit type casting to be taken care of later on(small fix)
	else return "";
}

/** @brief Breaks the python string to words 
 *
 *   It breaks the python string into words and breaks into token   
 *  @param the python line to be tokenised
 *  @param pointer to the template where the tokens are stored
 *  @return NIL
 */
void break_into_words_(std::string& line,std::vector< std::string >& tokens)
{
	int flag=1;	//to check if a symbol has been pushed and tokens.end()-1 isn't a continuing token
	for(std::string::iterator itr=line.begin();itr!=line.end();++itr)
	{   
		if(*itr=='"'){
			tokens.push_back("");
			(tokens.end()-1)->push_back('"');
			while(*(++itr)!='"')
				(tokens.end()-1)->push_back(*itr);
			(tokens.end()-1)->push_back('"');
			continue;
			flag=1;
		}
		if(is_symbol_(*itr))
		{
			if(*itr!=' '&&*itr!='\n')
			{
				std::string emp(1,*itr);	
				tokens.push_back(emp);
			}
			flag=1;
			continue;
		}	
		if(flag)
			tokens.push_back("");
		(tokens.end()-1)->push_back(*itr);
		flag=0;
	}
	
}


/** @brief The function to identify all the properties of class 
 *          in concern and to convert to cpp
 *
 * @param starting line of the python code of a class
 * @param ending line of the python code of a class
 * @param all the lines of the python code
 * @param string into which the converted_Cpp_code is returned
 * @param class_declaration stores all the properties of the concerned class
 *         also stores the inherieted functions
 * @param variables structure to deal with the variables declared and intialised
 *               in this class
 * @return NIL
 */

void convert_to_cpp_classes(unsigned long int start,
							unsigned long int end,
							std::vector< line_pair >& lines,
							std::string& converted_code,
							class_declaration* final_class,
							std::map< std::string,
							std::string >& variables )
   {

     	// if(start == end)
     	// 	std::cout<<"-------------\n\n\n\n"<<lines[start].first<<"\n\n-----------------"
        std ::vector < std::string > tokens;
        tokens.resize(1);
        break_into_words_(lines[start].first,tokens);//the lines get tokenized,inherited function

        if(tokens[1]=="class")
        {
            final_class->name=tokens[2];


            if(tokens[3]==":")
            	final_class->num_base_func=0;
            else if (tokens[3]=="(")
            {
                 std::vector<std::string>::iterator tokens_itr =tokens.begin()+3;
                 while(*(++tokens_itr)!=")")
                 {  
                 	if(*tokens_itr==",")
                 		continue;  //delimeter for inherited list of functions

                 	(final_class->base_functions).push_back(*tokens_itr);
                 	(final_class->num_base_func)++;//incremented each time a base func is found
                 	//tokens_itr++; //to bypass the commas after each base function

                 }



            }//all the base classes(if any)are noted till here;
        
          }
          /*while(*tokens_itr=="\n")
          	tokens_itr++; //gets rid of all the new lines, infact only one new line char would be there
           */
          	//the above block is now no more required as, tokens no more store '\n'

          /************THE FOLLOWING LINES FILL std::string converted_code *******************/
          	//converted_code.append("{\npublic:\n");

           
             for(unsigned long int i=start;i<=end;)
	            {	
		             tokens.clear();
		              break_into_words_(lines[i].first,tokens);
		              std::vector< std::string >::iterator itr=tokens.begin();

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
			convert_to_cpp_classes(st+1,i-1,lines,snippet,final_class,variables);
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


		//handle functionn definition inside the classes
		else if(*itr=="def")
		{
			long int space_count=lines[i].second;
			long int st=i;
			std::vector< std::string >::iterator itr1=tokens.begin();

			while(lines[++i].second>space_count); //upto i-1, we have to consider func
			std::string converted_function;
			function_declaration converted_function_declaration;
			convert_to_cpp(st,i-1,lines,converted_function,&converted_function_declaration,variables);

			//rendering the code for function
			if(converted_function_declaration.return_type == "")
				converted_function_declaration.return_type = "void";
			//the funciton can be a constructor
			if(converted_function_declaration.name=="__init__")
				converted_code.append(final_class->name).append("(");
			else{
			converted_code.append(converted_function_declaration.return_type).append(" ");
			//the funciton can be a constructor
			if(converted_function_declaration.name=="__init__")
				converted_code.append(final_class->name).append("(");
			else
			converted_code.append(converted_function_declaration.name).append("(");
			}
			 for(std::vector< string_pair >::iterator j=converted_function_declaration.args.begin();j!=converted_function_declaration.args.end();++j)
			 {
			 	converted_code.append(j->second).append(" "); //arg datatype
			 	converted_code.append(j->first).append(","); // arg name
			 
			 }
			 if(*(converted_code.end()-1) == ',')
			 	*(converted_code.end()-1)=')';
			 else  converted_code.append(")");
			 
			converted_code.append("\n{\n").append(converted_function).append("\n}\n");
			//i already got incremented while checking for the function block
			continue;

		}//end elif statement for functions inside the class




		else if (*itr!="def")	//variable declaration
		{
			std::string v=*itr;
			std::string expr="";
			bool is_function_call=1;
			if(*(itr+1)=="="){
				is_function_call=0;
				itr=itr+2;	//skip = sign
			}
			while(itr!=tokens.end())
				expr.append(*itr++);
    		expr = eval_expr_(expr);

			if(!is_function_call){
				variables[v]=expr_type_(expr,variables);
			
			converted_code.append((size_t)lines[i].second*tab_size,' ');
			if(!variables.count(v))
				converted_code.append(variables[v]);
			converted_code.append(expr_type_(v,variables));	
			converted_code.append(" ");
			converted_code.append(v);
			converted_code.append(" = ");
			    		std::cout<<"Evaled  -- "<<expr<<"\n";

			converted_code.append(expr);
			converted_code.append(";\n");
			}
			else{
				converted_code.append((size_t)lines[i].second*tab_size,' ');
				converted_code.append(expr);
				converted_code.append(";\n");

			}

			i++;
			continue;

		}	

      //At the the end, the closing lines of the classe in c++ is written
 }
     // the above step to be taken care off in rendering the cpp code
   
 std::cout<<"printing the converted class code\n"<<converted_code <<"haha\n";

     }//end of convert_to_cpp_classes
