
#include <vector>
#include <string>
#include <string.h>
#include <iostream>
#include <ctype.h>
#include <map>
#include <stdlib.h>
#include <iostream>
#include <sstream>


#include "../Header/include/function_struct.h"
#include "../Header/include/source_code.h"

std::string eval_expr(std::string& s)
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

bool is_symbol(char c){
	char symbols[]=" =:;(){}[]|,.&+-<>*/'\n#";

	for(int i=0;symbols[i]!='#';++i)
		if(symbols[i]==c)
			return 1;
	return 0;

}

std::string expr_type(std::string& expr,std::map< std::string,std::string >& variables)
{	
	if(expr.substr(0,17)=="artificial_string")
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
		if(is_symbol(*itr)&&*itr!='.')
			break;
		first_variable.push_back(*(itr++));
	}
	
	if(variables.count(first_variable))
		return variables[first_variable];	//Implicit type casting to be taken care of later on(small fix)
	else return "";
}


void break_into_words(std::string& line,std::vector< std::string >& tokens)
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
		if(is_symbol(*itr))
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

std::string map_type(std::string s, int l)
{
	if(s=="int")
		return "long int";
	if(s=="float")
		return "float";
	if(s=="s")
		return "artificial_string";
	else {
		std::cout<<"[ WARNING ] Bad type name "<<s<<"!! on line "<<l<<std::endl;
	}
}


std::string itoa(int number)
{
std::ostringstream oss;
  oss<< number;
  return oss.str();
}

void convert_to_cpp(unsigned long int start,
					unsigned long int end,
					std::vector< line_pair >& lines,
					std::string& converted_code,
					function_declaration* _function,
					std::map< std::string,std::string >& variables )
{


// std::cout<<src.lines[itr1->first].first;
	std::vector< std::string > tokens;

	//std::string res_code;
	//break_into_words(lines[start].first,tokens);
	// for(std::vector< std::string >::iterator itr=tokens.begin();itr!=tokens.end();++itr)
	// 	std::cout<<*itr<<"--";

///////////////////////////////////////Function conversion starts/////////////////////////////////////
	
	
	break_into_words(lines[start].first,tokens);
	

	if(tokens[0]=="def")
	{

		_function->name=tokens[1];	
		std::vector< std::string >::iterator itr,itr1=tokens.begin();


		while(*(itr1++)!=":");

		for(itr=tokens.begin()+3;;itr++){
			if(*itr == ",")
				continue;
			if(*(itr)==")")
				break;
			_function->args.push_back(std::pair< std::string,std::string >(*itr,map_type(*itr1,start)));
			itr1++;
		}

		while(*(itr++)!=":");	//skip ':' of function declaration
		

	}
	for(std::vector< string_pair >::iterator itr=_function->args.begin();itr!=_function->args.end();++itr)
			variables[itr->first]=itr->second;
	
		

	for(unsigned long int i=start;i<=end;)						//start from start only not +1 as it will miss cases of outside															 
	{	
		tokens.clear();
		break_into_words(lines[i].first,tokens);
				// for(std::vector< std::string >::iterator itr=tokens.begin();itr!=tokens.end();itr=itr+1)
		// 		std::	cout<<"---"<<*itr<<"-----";
		// 	std::cout<<"\n\n";

		std::vector< std::string >::iterator itr=tokens.begin();		
		if(*itr=="if" || *itr == "elif")
		{
			std::vector< std::string >::iterator if_or_elif = itr; 
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
			
			converted_code.append((size_t)lines[i].second*tab_size,' ');
			if( *if_or_elif == "if")
				converted_code.append("if(");
			else converted_code.append("else if(");		
			converted_code.append(expr);
			converted_code.append(")\n");
			converted_code.append((size_t)lines[i].second*tab_size,' ');
			int spaces = (size_t)lines[i].second;
			converted_code.append("{\n");
			
			int space_count=lines[i].second,st=i;
			
			while(lines[++i].second>space_count);
				
			std::string snippet;
			convert_to_cpp(st+1,i-1,lines,snippet,_function,variables);
			converted_code.append(snippet);
			
			converted_code.append(spaces*tab_size,' ');
			converted_code.append("}\n");
			//i already incremented while changing lines
			continue;

		}
		
		////NOTE:- Every section puts \n at its end so no need to put one in each section's beginning

		if(*itr=="print")
		{
			itr++;
			converted_code.append((size_t)lines[i].second*tab_size,' ');
			converted_code.append("std::cout<<");
			int f=1;
			while(itr!=tokens.end())
			{
				if(*itr=="("||*itr==")")
					f=!f;

				if(!f||*itr!=",")
					converted_code.append(*itr);
				if(f&&*itr==",")
					converted_code.append("<<");
				itr++;
			}
			converted_code.append(";\n");
			i++;
			continue;
		}

		if(*itr=="return")
		{
			converted_code.append((size_t)lines[i].second*tab_size,' ');
			converted_code.append("return ");
			std::string expr="";
			while((++itr)!=tokens.end())
				expr.append(*itr);
			
			
			converted_code.append(expr);
			converted_code.append(";\n");
			// std::cout<<"OKK";
			if(expr_type(expr,variables)!=""){
				_function->return_type=expr_type(expr,variables);
			}
			break;	//break in return as must be last line of every sensible function  
		}

		if(*itr=="else")
		 {
		 	converted_code.append((size_t)lines[i].second*tab_size,' ');
			converted_code.append("else\n");
		 	converted_code.append((size_t)lines[i].second*tab_size,' ');
		 	converted_code.append("{\n");
		 	int spaces = (size_t)lines[i].second;

		 	int space_count=lines[i].second,st=i;			
			while(lines[++i].second>space_count);				
			std::string snippet;
			convert_to_cpp(st+1,i-1,lines,snippet,_function,variables);
			converted_code.append(snippet);
			
			converted_code.append(spaces*tab_size,' ');
			converted_code.append("}\n");
			////NOTE:- Every section puts \n at its end so no need to put one in each section's beginning
		 	continue;
		 }

		else if (*itr=="while")
		{

		// for(std::vector< std::string >::iterator itr=tokens.begin();itr!=tokens.end();itr=itr+1)
		// 		std::	cout<<"---"<<*itr<<"-----\n";
			itr++;
			bool is_not=0;
			if(*itr=="not")
				{
					is_not=1;
					itr++;
				}
			converted_code.append((size_t)lines[i].second*tab_size,' ');
			converted_code.append("while(");
			if(is_not) converted_code.append("!");
			while(*itr!=":"){
				converted_code.append(*itr);
				itr++;
			}

			converted_code.append(")\n");
					
			converted_code.append((size_t)lines[i].second*tab_size,' ');
			int spaces = (size_t)lines[i].second;
			converted_code.append("{\n");
			
			int space_count=lines[i].second,st=i;
			
			while(lines[++i].second>space_count);
				
			std::string snippet;
			convert_to_cpp(st+1,i-1,lines,snippet,_function,variables);
			converted_code.append(snippet);
			
			converted_code.append(spaces*tab_size,' ');
			converted_code.append("}\n");
			//i already incremented while changing lines
			continue;
		}

	//code for converting for loops in python to cpp
		else if(*itr=="for")
		{
			converted_code.append((size_t)lines[i].second*tab_size,' ');
			int spaces=(size_t)lines[i].second;
			converted_code.append("for(long int ");
			converted_code.append(*(++itr)); 
			std::string var=*(itr); 

			std::string start_range="0";std::string end_range="";

			std::vector< std::string >::iterator itr2;
			itr2=++itr;//bypassing "in"

			if(*(++itr2)=="range")
			{
				if(*(++itr2)=="(")            //the case of range(3,5)
				{
					start_range = *(++itr2);
					
					if(*(++itr2)==",")
					{
						end_range=*(++itr2);
					}
					else						//the case of range(100)
					{
						end_range=start_range.append("-1");
						start_range="0";
					}

				} //end evaluating the expression in range()

				
			}//end the range()


			converted_code.append("=");
			converted_code.append((start_range));
			converted_code.append(";").append(var).append("<=").append((end_range)).append(";");
			converted_code.append(var).append("++)\n");//starting the for loop with {
				// i++;  //to go next line
			spaces = (size_t)lines[i].second;
			converted_code.append(spaces*tab_size,' ');
			converted_code.append("{\n");

			int space_count=lines[i].second,st=i;

			while(lines[++i].second>space_count); //to find the complete for block
			std::string snippet;
			convert_to_cpp(st+1,i-1,lines,snippet,_function,variables);
			converted_code.append(snippet);
			converted_code.append(spaces*tab_size,' ');
			converted_code.append("}\n");
			//i already incremented while changing lines
			continue;


	}//end elseif statement for for loop

		else if (*itr!="def")	//treat every foreign token as variable name or function
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
    		expr = eval_expr(expr);

			if(!is_function_call){
				bool not_decl = (variables.find(v) != variables.end());
				variables[v]=expr_type(expr,variables);
			
			converted_code.append((size_t)lines[i].second*tab_size,' ');
			if(!variables.count(v))

			{//this bracket to be closed
			   if(variables[v]!="list" &&variables[v]!="map" && variables[v]!="dict")
				converted_code.append(variables[v]);
			}

			// else if(variable[v]=="list")
			// {

			// }


			else if(!not_decl) converted_code.append(expr_type(v,variables));	
			converted_code.append(" ");
			converted_code.append(v);
			converted_code.append(" = ");
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
		i++;							// if nothing gets caught
	
	}		

}

