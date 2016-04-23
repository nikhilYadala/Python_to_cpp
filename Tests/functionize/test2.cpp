/** @file test2.cpp
 *  @brief Test the functionize function 
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

#include <limits.h>
#include "../../Source/src/functionize.cpp"
#include "gtest/gtest.h"
#include<string>

/** @brief This is a Test function to check 
 *         boundary conditions of the functionize function
 *
 *  It defines a class of source code and runs functionize function only to match it with the expected output later on.
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */
TEST (functionize,boundaryconditions){
		std::string input_src;
	if (FILE *fp = fopen("functionize/f.py","r"))
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
	source_code input_code(input_src);
	input_code.functionize();
	std::vector<line_pair>::iterator itr=input_code.lines.begin();
EXPECT_STREQ("s1=012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890",itr->first.c_str());
itr++;
EXPECT_STREQ("s2=0678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890",itr->first.c_str());
}

/** @brief This is a Test function to check separations of
 *         comments being done correctly by functionize function
 *
 *  It defines a class of source code and runs functionize function only to match it with the expected output later on.
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */
TEST (functionize,separation_of_comments){
std::string input_src;
	if (FILE *fp = fopen("functionize/f1.py","r"))
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
	source_code input_code(input_src);
	input_code.functionize();
	std::vector<line_pair>::iterator itr=input_code.lines.begin();
	EXPECT_STREQ("a=2",itr->first.c_str());
	itr++;
	EXPECT_STREQ("b=3",itr->first.c_str());
	itr++;
	ASSERT_STREQ("print a+b",itr->first.c_str());
}

/** @brief This is a Test function to check correctness by testing 
 *         for some random function.
 *  It defines a class of source code and runs functionize function only to match it with the expected output later on.
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */
TEST (functionize,random_function){
	std::string input_src;
	if (FILE *fp = fopen("functionize/f2.py","r"))
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
	source_code input_code(input_src);
	input_code.functionize();
	std::vector<line_pair>::iterator itr=input_code.lines.begin();
	ASSERT_STREQ("def fib(n):",itr->first.c_str());
	ASSERT_EQ(0,itr->second);
	itr++;
	ASSERT_STREQ("if n==1:",itr->first.c_str());
	ASSERT_EQ(4,itr->second);
	itr++;
	ASSERT_STREQ("return 1",itr->first.c_str());
	ASSERT_EQ(7,itr->second);
	itr++;
	ASSERT_STREQ("if n==0:",itr->first.c_str());
	ASSERT_EQ(4,itr->second);
	itr++;
	ASSERT_STREQ("return fib(n-1)+fib(n-2)",itr->first.c_str());
	ASSERT_EQ(8,itr->second);
	itr++;
	ASSERT_STREQ("print fib(10)",itr->first.c_str());
	ASSERT_EQ(0,itr->second);
}

