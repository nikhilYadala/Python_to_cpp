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
#include "../../Source/src/render_code.cpp"
#include "../../Source/src/generate_cpp_code.cpp"
#include "../../Source/src/convert_to_cpp.cpp"
#include "gtest/gtest.h"
#include<string>

TEST (render_code, ifelsecondition ){
	std::string input_src;
	FILE *fp = fopen("p.py","r");
	char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src.insert(input_src.end(), buf, buf + len);
		fclose(fp);
	
	system("../../translator p.py");
	

	std::string input_src1;
	fp = fopen("p.cpp","r");
	//char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);
	

	std::string input_src2;
	fp = fopen("pexpect.cpp","r");
	//char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src2.insert(input_src2.end(), buf, buf + len);
		fclose(fp);
	
	EXPECT_STREQ(input_src2.c_str(),input_src1.c_str());	
}
//============================================================================================================================================================
TEST (render_code, whileloop ){
	std::string input_src;
	FILE *fp = fopen("q.py","r");
	char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src.insert(input_src.end(), buf, buf + len);
		fclose(fp);
	
	
	system("../../translator q.py");
	
	

	std::string input_src1;
	fp = fopen("q.cpp","r");
	//char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);
	

	std::string input_src2;
	fp = fopen("qexpect.cpp","r");
	//char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src2.insert(input_src2.end(), buf, buf + len);
		fclose(fp);
	
	EXPECT_STREQ(input_src2.c_str(),input_src1.c_str());	
}
//============================================================================================================================================================
TEST (render_code, trivialconstant ){
	std::string input_src;
	FILE *fp = fopen("r.py","r");
	char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src.insert(input_src.end(), buf, buf + len);
		fclose(fp);
	
	
	system("../../translator r.py");
	
	

	std::string input_src1;
	fp = fopen("r.cpp","r");
	//char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);
	

	std::string input_src2;
	fp = fopen("rexpect.cpp","r");
	//char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src2.insert(input_src2.end(), buf, buf + len);
		fclose(fp);
	
	EXPECT_STREQ(input_src2.c_str(),input_src1.c_str());	
}
//=============================================================================================================================================================
int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}