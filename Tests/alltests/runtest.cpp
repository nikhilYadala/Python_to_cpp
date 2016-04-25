#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#define chunk 1024	
#include <limits.h>
#include<string>


TEST (runtest, yu ){
	std::string input_src;
	if (FILE *fp = fopen("alltests/yu.py","r"))
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
	
	system("../translator  alltests/yu.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/yu.cpp","r"))
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
	if (FILE *fp = fopen("alltests/yuexpect.cpp","r"))
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

TEST (runtest, myu ){
	std::string input_src;
	if (FILE *fp = fopen("alltests/myu.py","r"))
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
	
	system("../translator  alltests/myu.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/myu.cpp","r"))
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
	if (FILE *fp = fopen("alltests/myuexpect.cpp","r"))
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

TEST (runtest, type ){
	std::string input_src;
	if (FILE *fp = fopen("alltests/type.py","r"))
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
	
	system("../translator  alltests/type.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/type.cpp","r"))
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
	if (FILE *fp = fopen("alltests/typeexpect.cpp","r"))
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