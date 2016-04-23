/** @file function_struct.h
* @ brief Structure declaration containing details of functions returned by convert_to_cpp function
*/

#ifndef function_struct_def
#define function_struct_def
#define string_pair std::pair< std::string,std::string >	//function args name and type

struct function_declaration{
	std::string name;
	std::string return_type;
	std::vector< string_pair > args;	//name,type
};


#endif