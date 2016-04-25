#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#define chunk 1024	
#include <limits.h>
#include<string>


TEST (newtest, forloop){	
	system("../translator  alltests/for.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/for.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	

	std::string input_src2;
	if (FILE *fp = fopen("alltests/forexpect.cpp","r"))
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

//==============================================================================================================================

TEST (newtest, constructor){	
	system("../translator  alltests/constructor.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/constructor.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	

	std::string input_src2;
	if (FILE *fp = fopen("alltests/constructorexpect.cpp","r"))
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

//=======================================================================================================================================

TEST (newtest, string){	
	system("../translator  alltests/string.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/string.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	

	std::string input_src2;
	if (FILE *fp = fopen("alltests/stringexpect.cpp","r"))
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

//========================================================================================================================

TEST (newtest,alu){	
	system("../translator  alltests/alu.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/alu.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	

	std::string input_src2;
	if (FILE *fp = fopen("alltests/aluexpect.cpp","r"))
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

//==================================================================================================================

TEST (newtest, function){	
	system("../translator  alltests/function.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/function.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	

	std::string input_src2;
	if (FILE *fp = fopen("alltests/functionexpect.cpp","r"))
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

//========================================================================================================================================

TEST (newtest, inheritance){	
	system("../translator  alltests/inheritance.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/inheritance.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	

	std::string input_src2;
	if (FILE *fp = fopen("alltests/inheritanceexpect.cpp","r"))
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

//===============================================================================================================================================

TEST (newtest, square){	
	system("../translator  alltests/square.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/square.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	
	std::string input_src2;
	if (FILE *fp = fopen("alltests/squareexpect.cpp","r"))
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

//======================================================================================================================

TEST (newtest, basictype){	
	system("../translator  alltests/basictype.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/basictype.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	
	std::string input_src2;
	if (FILE *fp = fopen("alltests/basictypeexpect.cpp","r"))
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

//========================================================================================================================

TEST (newtest, nestedfunction){	
	system("../translator  alltests/nestedfunction.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/nestedfunction.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	
	std::string input_src2;
	if (FILE *fp = fopen("alltests/nestedfunctionexpect.cpp","r"))
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

//============================================================================================================================

TEST (newtest, randomfunction){	
	system("../translator  alltests/randomfunction.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/randomfunction.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	
	std::string input_src2;
	if (FILE *fp = fopen("alltests/randomfunctionexpect.cpp","r"))
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

//==================================================================================================================================

TEST (newtest, ifinwhileinfor){	
	system("../translator  alltests/ifinwhileinfor.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/ifinwhileinfor.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	
	std::string input_src2;
	if (FILE *fp = fopen("alltests/ifinwhileinforexpect.cpp","r"))
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

//==============================================================================================================================

TEST (newtest, functioninclass){	
	system("../translator  alltests/functioninclass.py");   

	

	std::string input_src1;
	if (FILE *fp = fopen("alltests/functioninclass.cpp","r"))
	{
		char buf[chunk];
		while (size_t len = fread(buf, 1, sizeof(buf), fp))
			input_src1.insert(input_src1.end(), buf, buf + len);
		fclose(fp);

		
	}
	else {
		std::cout<<"Unable to open source file (newtest.cpp)\n";
	exit(0);
	}
	
	std::string input_src2;
	if (FILE *fp = fopen("alltests/functioninclassexpect.cpp","r"))
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