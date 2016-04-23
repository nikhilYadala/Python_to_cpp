/** @file class_struct.h
 *  @brief This file defines the structure for storing the classes.
 *  @bug No known bugs.
 */



#ifndef class_struct_def
#define class_struct_def

struct class_declaration{
	std::string name;
	int num_base_func;//stores num of base functions (inheritance)
    std::vector< std::string > base_functions;

};


#endif