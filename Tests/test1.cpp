/* This file tests the functions present in supporting_libs.h
*/
#include <limits.h>
#include "../Source/Header/supporting_libs/supporting_libs.h"
#include "gtest/gtest.h"
#include<string>

TEST (capitialize, trivialnull) {
//EXPECT_STREQ(false,"NULL".capitialize());                                   
EXPECT_STREQ("@8.41#$","@8.41#$".capitialize());                    
}

TEST (capitialize, various_strings) {
ASSERT_STREQ("Abhishek","abhishek".capitialize());                      //To Test the function capitalize
ASSERT_STREQ("India_is_my_country","india_is_my_country".capitialize());
ASSERT_STREQ("We like CS242","We like CS242".capitialize());
}
//==================================================================================================

TEST (len, trivialnull){
	EXPECT_EQ(0,len(NULL));
}

TEST (len, otherlengths){                                              //To Test the function len
	ASSERT_EQ(9,len("123456789"));
	ASSERT_EQ(32,len("This is Python to C++ translator"));
	ASSERT_EQ(7,len("!@#$^&("));
}
//===================================================================================================

TEST (upper, trivialnull){
	EXPECT_STREQ(false,NULL.upper());
EXPECT_STREQ("@8.41#$","@8.41#$".upper());                    
}

TEST (upper, various_strings) {
std::string std_output="india_is_my_country";
ASSERT_STREQ("ABHISHEK","abhishek".upper());                      //To Test the function upper
ASSERT_STREQ("INDIA_IS_MY_COUNTRY",std_output.upper());
ASSERT_STREQ("WE LIKE CS242","We like CS242".upper());
}
//===================================================================================================

TEST (max, trivialnull){
//	EXPECT_STREQ(NULL,max("@!@#443243646"));
	EXPECT_STREQ(NULL,max(NULL));
}
                                                                        
Test (max, diffstrings){                                       //To Test the max function
ASSERT_STREQ("a",max("a2312300AZ"));
ASSERT_STREQ("z",max("zZaA@!"));
ASSERT_STREQ("s",max("iamms"));
//ASSERT_STREQ(NULL,max("2837!&25JGU"));
ASSERT_STREQ("T",max("AGILEMETHOD"));
}
//====================================================================================================

TEST (upper, trivialnull){
	EXPECT_STREQ(false,NULL.capitialize());
EXPECT_STREQ("@8.41#$","@8.41#$".capitialize());                    
}

TEST (upper, various_strings) {
ASSERT_STREQ("abhishek","abhishek".capitialize());                      //To Test the function lower
ASSERT_STREQ("india_is_my_country","INDIA_IS_MY_COUNTRY".capitialize());
ASSERT_STREQ("we like cs242","We Like CS242".capitialize());
}

//====================================================================================================

TEST (min, trivialnull){
//	EXPECT_STREQ(NULL,max("@!@#443243646"));
	EXPECT_STREQ(NULL,max(NULL));
}
                                                                        
Test (min, diffstrings){                                       //To Test the min function
ASSERT_STREQ(0,max("a2312300AZ"));
ASSERT_STREQ("!",max("zZaA@!"));
ASSERT_STREQ("a",max("iamms"));
//ASSERT_STREQ(NULL,max("2837!&25JGU"));
ASSERT_STREQ("A",max("AGILEMETHOD"));
}
//====================================================================================================

TEST (swapcase, trivialnull){
	EXPECT_STREQ(NULL,""swapcase());
}

TEST (swapcase, diffstrings){
	ASSERT_STREQ("This Is Great",swapcase("tHIS iS gREAT"));       //To test the swapcase function
	ASSERT_STREQ("abcdefghiJKLMN",swapcase("ABCDEFGHIjklmn"));
	ASSERT_STREQ("!@# 456 asd QWE",swapcase("!@# 456 ASD qwe"));
}
//===================================================================================================

TEST (islower, trivialcases){
	EXPECT_FALSE("".islower());
}

TEST(islower, diffcases){
	ASSERT_TRUE("cppiscool".islower());                      //To test the islower function
	ASSERT_FALSE("cpp_is_cool".islower());
	ASSERT_FALSE("123&*".islower());
	ASSERT_FALSE("CPPISCOOL".islower());
}
//==============================================================================================================

TEST (isupper, trivialcases){
	EXPECT_FALSE("".isupper());
}

TEST(isupper, diffcases){
	ASSERT_FALSE("cppiscool".isupper());                      //To test the isupper function
	ASSERT_FALSE("123&*".isupper());
	ASSERT_TRUE("CPPISCOOL".isupper());
	ASSERT_FALSE("CPP_IS_COOL".isupper());
}
//=============================================================================================================

TEST (isalpha, trivialcases){
	EXPECT_FALSE("".isalpha());
}

TEST(isalpha, diffcases){
	ASSERT_TRUE("cppiscool".isalpha());                      //To test the isalpha function
	ASSERT_FALSE("123&*".isalpha());
	ASSERT_TRUE("CPPISCOOL".isalpha());
	ASSERT_TRUE("CPP_IS_COOL".isalpha());
}
//======================================================================================================================

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}

