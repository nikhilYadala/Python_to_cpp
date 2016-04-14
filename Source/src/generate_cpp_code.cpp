#include <vector>
#include <string>
#include <string.h>
#include <iostream>	
#include <map>

#include "../Header/include/function_struct.h"
#include "../Header/include/source_code.h"

//convert_to_cpp is defined in convert_to_cpp file
void convert_to_cpp(unsigned long int start,unsigned long int end,std::vector< line_pair >& lines,std::string& converted_code,function_declaration* _function,std::map< std::string,std::string >& variables );


void main_func(source_code& src)
{
	function_declaration _function;
	_function.name="main";
	_function.return_type="int";
	_function.args.push_back(string_pair("",""));
	
	std::string converted_code;
	std::map< std::string,std::string > variables;	//name,pair(value,type)
	convert_to_cpp(src.functions[0].first,src.functions[0].second,src.lines,converted_code,&_function,variables);
	converted_code.append(" \nreturn 0;");
	src.generated_cpp_code[0].first=converted_code;	//Only 1 line of sparse code maybe extend later
	src.generated_cpp_code[0].second=_function;	
}


void source_code::generate_cpp_code()
{

	generated_cpp_code.resize(functions.size());
	main_func(*this);
	std::string converted_code;
	std::vector< std::pair< std::string,function_declaration > >::iterator itr2=generated_cpp_code.begin()+1;
	for(std::vector< int_pair >::iterator itr1=functions.begin()+1;itr1!=functions.end();++itr1,++itr2)
		{
			converted_code.clear();
			function_declaration _function;
			std::map< std::string,std::string > variables;	//name,pair(value,type)
			convert_to_cpp(itr1->first,itr1->second,lines,converted_code,&_function,variables);
			if(_function.return_type=="")
					_function.return_type="void";		
			
			itr2->second=_function;
			itr2->first=converted_code;	
			
		}

	// for(std::vector< std::pair< std::string,function_declaration > >::iterator itr=generated_cpp_code.begin();itr!=generated_cpp_code.end();++itr)
	// 	{
	// 		std::cout<<itr->first<<"\n";
	// 		std::cout<<"name-"<<itr->second.name<<"  return_type-"<<itr->second.return_type<<"args-\n";
			
	// 		for(std::vector< string_pair >::iterator itr1=itr->second.args.begin();itr1!=itr->second.args.end();++itr1)
	// 			std::cout<<itr1->first<<"   "<<itr1->second<<"\n";
				
	// 			std::cout<<"\n\n";						
	// 	}

}