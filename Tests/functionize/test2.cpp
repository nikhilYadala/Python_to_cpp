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

/* FOR RFEERNCE
for(std::vector<line_pair>::iterator itr=input_code.lines.begin();itr!=input_code.lines.end();++itr)
		std::cout<<"?????????     "<<itr->first<<"      ??????????????????\n";
		*/

TEST (functionize,boundaryconditions){
		std::string input_src;
	FILE *fp = fopen("f.py","r");
	char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src.insert(input_src.end(), buf, buf + len);
		fclose(fp);
	source_code input_code(input_src);
	input_code.functionize();
	std::vector<line_pair>::iterator itr=input_code.lines.begin();
EXPECT_STREQ("s1=012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890",itr->first.c_str());
itr++;
EXPECT_STREQ("s2=0678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890",itr->first.c_str());
}

TEST (functionize,separation_of_comments){
std::string input_src;
	FILE *fp = fopen("f1.py","r");
	char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src.insert(input_src.end(), buf, buf + len);
		fclose(fp);
	source_code input_code(input_src);
	input_code.functionize();
	std::vector<line_pair>::iterator itr=input_code.lines.begin();
	EXPECT_STREQ("a=2",itr->first.c_str());
	itr++;
	EXPECT_STREQ("b=3",itr->first.c_str());
	itr++;
	ASSERT_STREQ("print a+b",itr->first.c_str());
}

TEST (functionize,random_function){
	std::string input_src;
	FILE *fp = fopen("f2.py","r");
	char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src.insert(input_src.end(), buf, buf + len);
		fclose(fp);
	source_code input_code(input_src);
	input_code.functionize();
	std::vector<line_pair>::iterator itr=input_code.lines.begin();
	ASSERT_STREQ("def fib(n):",itr->first.c_str());
	itr++;
	ASSERT_STREQ("if n==1:",itr->first.c_str());
	itr++;
	ASSERT_STREQ("return 1",itr->first.c_str());
	itr++;
	ASSERT_STREQ("if n==0:",itr->first.c_str());
	itr++;
	ASSERT_STREQ("return fib(n-1)+fib(n-2)",itr->first.c_str());
	itr++;
	ASSERT_STREQ("print fib(10)",itr->first.c_str());
}


int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}