/*
Class definition to break source code into functions and return them in a vector of strings
*/

#ifndef function_break
#define function_break 

#define max_number_of_variables 100
#define tab_size 4
#define line_pair std::pair<std::string,int>
#define int_pair std::pair<int,int>

#include "class_struct.h"
#include "function_struct.h"

class source_code{

std::string code;
unsigned long int number_of_functions;
bool only_functions; 

public:

char *file_name;
std::vector< line_pair > lines;
std::vector< int_pair > functions;
std::vector< int_pair > classes; //each value gives the start and the end line of a given class
std::vector< std::pair< std::string,function_declaration > > generated_cpp_code;
std::vector< std::pair< std::string,class_declaration > > generated_cpp_classes;


	 source_code(std::string& st) : code(st){
	}
	 void functionize();
	 void make_classes();       //separating classes from the python code.
	 void generate_cpp_code();
	 void generate_cpp_classes();
	 void render_code();	//write the generated cpp code to file
	// const bool is_valid(source_code &);
};


#endif