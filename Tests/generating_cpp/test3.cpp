/** @file test3.cpp
 *  @brief Test the render_code and generate_cpp_code function 
 *   We are testing functionize function on various inputs and comparing its expected output
 *  @bug No known bugs.
 */

#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#define chunk 1024		//Chunk of bytes to be read at a time from file(source code)

#include "../../Source/Header/supporting_libs/supporting_libs.h"
#include "../../Source/Header/include/function_struct.h"
#include "../../Source/Header/include/source_code.h"
//#include "../../Source/src/main.cpp"
#include <limits.h>
//#include "../../Source/src/functionize.cpp"
#include "../../Source/src/render_code.cpp"
#include "../../Source/src/generate_cpp_code.cpp"
#include "../../Source/src/convert_to_cpp.cpp"
#include "gtest/gtest.h"
#include<string>

/** @brief This is a Test function to check 
 *         if-else conditional branch is translated as expected
 *
 *  It defines a class of source code and runs translator only to match it with the expected output later on.
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */
TEST (render_code, ifelsecondition ){
	std::string input_src;
	if (FILE *fp = fopen("generating_cpp/p.py","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src.insert(input_src.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (main.cpp)\n";
	exit(0);
	}
	
	system("../translator  generating_cpp/p.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("generating_cpp/p.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (main.cpp)\n";
	exit(0);
	}
	

	std::string input_src2;
	if (FILE *fp = fopen("generating_cpp/pexpect.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src2.insert(input_src2.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (main.cpp)\n";
	exit(0);
	}
	
	EXPECT_STREQ(input_src2.c_str(),input_src1.c_str());	
}
//============================================================================================================================================================
/** @brief This is a Test function to check 
 *         while loop is translated as expected
 *
 *  It defines a class of source code and runs translator only to match it with the expected output later on.
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */

TEST (render_code, whileloop ){
	std::string input_src;
	system("../translator  generating_cpp/q.py");
	
	

	std::string input_src1;
	if (FILE *fp = fopen("generating_cpp/q.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (main.cpp)\n";
	exit(0);
	}
	

	std::string input_src2;
	if (FILE *fp = fopen("generating_cpp/qexpect.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src2.insert(input_src2.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (main.cpp)\n";
	exit(0);
	}
	EXPECT_STREQ(input_src2.c_str(),input_src1.c_str());	
}
//============================================================================================================================================================
/** @brief This is a Test function to check 
 *         if a trivial program  is translated as expected
 *
 *  It defines a class of source code and runs translator only to match it with the expected output later on.
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */

TEST (render_code, trivialconstant ){
	std::string input_src;
	if (FILE *fp = fopen("generating_cpp/r.py","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src.insert(input_src.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (main.cpp)\n";
	exit(0);
	}
	
	
	system("../translator generating_cpp/r.py");
	
	

	std::string input_src1;
	if (FILE *fp = fopen("generating_cpp/r.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (main.cpp)\n";
	exit(0);
	}
	

	std::string input_src2;
	if (FILE *fp = fopen("generating_cpp/rexpect.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src2.insert(input_src2.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (main.cpp)\n";
	exit(0);
	}
	
	EXPECT_STREQ(input_src2.c_str(),input_src1.c_str());	
}
//=============================================================================================================================================================
