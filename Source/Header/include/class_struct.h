//this file defines the structure for storing the classes.


#ifndef class_struct_def
#define class_struct_def

struct class_declaration{
	std::string name;
	int num_base_func;//stores num of base functions (inheritance)
    std::vector< std::string > base_functions;

};


#endif