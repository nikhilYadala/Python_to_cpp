/** @file test1.cpp
 *  @brief Test the artificial string library function 
 *   We are testing the artificial string functions on some trivial and corner cases strings and comparing it with expected output
 *  @bug No known bugs.
 */
#include <limits.h>
#include "../Source/Header/supporting_libs/supporting_libs.h"
#include "gtest/gtest.h"
#include<string>

 /** @brief This is a Test function to check 
 *         if capitalize function works.
 *
 *  It defines a class of source code and runs the capitalize string function
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */

TEST (capitialize, trivialnull) {
	artificial_string abc= artificial_string("@8.41#$");
	abc.capitalize();
    EXPECT_STREQ("@8.41#$",abc.str.c_str()); 
    abc.str="";
    EXPECT_STREQ("",abc.str.c_str());                   
}

TEST (capitialize, various_strings) {
artificial_string abc= artificial_string("abhishek");
abc.capitalize();
ASSERT_STREQ("Abhishek",abc.str.c_str());                      //To Test the function capitalize
abc.str="We like CS242";
ASSERT_STREQ("We like CS242",abc.str.c_str());
}
//==================================================================================================
 /** @brief This is a Test function to check 
 *         if len function works.
 *
 *  It defines a class of source code and runs the len string function
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */


TEST (len, trivialnull){
	artificial_string abc= artificial_string("");
	EXPECT_EQ(0,abc.len());
}

TEST (len, otherlengths){                                              //To Test the function len
	artificial_string abc= artificial_string("123456789");
	ASSERT_EQ(9,abc.len());
	abc.str="This is Python to C++ translator";
	ASSERT_EQ(32,abc.len());
	abc.str="!@#$^&(";
	ASSERT_EQ(7,abc.len());
}
//===================================================================================================
 /** @brief This is a Test function to check 
 *         if upper function works.
 *
 *  It defines a class of source code and runs the upper string function
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */
TEST (upper, trivialnull){
	artificial_string abc= artificial_string("");
	abc.upper();
	EXPECT_STREQ("",abc.str.c_str());
	abc.str="@8.41#$";
	abc.upper();
EXPECT_STREQ("@8.41#$",abc.str.c_str());                    
}

TEST (upper, various_strings) {
artificial_string abc= artificial_string("abhishek");
abc.upper();
ASSERT_STREQ("ABHISHEK",abc.str.c_str());                      //To Test the function upper
abc.str="We like CS242";
abc.upper();
ASSERT_STREQ("WE LIKE CS242",abc.str.c_str());
}
//===================================================================================================
 /** @brief This is a Test function to check 
 *         if max function works.
 *
 *  It defines a class of source code and runs the max string function
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */
TEST (max, trivialnull){
	artificial_string abc= artificial_string("@!@#443243646");
	EXPECT_EQ(' ',abc.max());
	abc.str="";
	EXPECT_EQ(' ',abc.max());
}
                                                                        

TEST (max, diffstrings) {                                       //To Test the max function
	artificial_string abc= artificial_string("a2312300AZ");
	EXPECT_EQ('a',abc.max());
	abc.str="zZaA@!";
	ASSERT_EQ('z',abc.max());
	abc.str="iamms";
	ASSERT_EQ('s',abc.max());
	abc.str="2837!&25JGU";
	ASSERT_EQ(' ',abc.max());
	abc.str="AGILEMETHOD";
	ASSERT_EQ(' ',abc.max());
}
//====================================================================================================
 /** @brief This is a Test function to check 
 *         if lower function works.
 *
 *  It defines a class of source code and runs the lower string function
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */
TEST (lower, trivialnull){
	artificial_string abc= artificial_string("");
	abc.lower();
	EXPECT_STREQ("",abc.str.c_str());
	abc.str="@8.41#$";
	abc.lower();
EXPECT_STREQ("@8.41#$",abc.str.c_str());                    
}

TEST (lower, various_strings) {
	artificial_string abc= artificial_string("abhishek");
	abc.lower();
ASSERT_STREQ("abhishek",abc.str.c_str());                      //To Test the function lower
	abc.str="INDIA_IS_MY_COUNTRY";
	abc.lower();
ASSERT_STREQ("india_is_my_country",abc.str.c_str());
	abc.str="We Like CS242";
	abc.lower();
ASSERT_STREQ("we like cs242",abc.str.c_str());
}

//====================================================================================================
 /** @brief This is a Test function to check 
 *         if min function works.
 *
 *  It defines a class of source code and runs the min string function
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */
TEST (min, trivialnull){
artificial_string abc= artificial_string("@!@#443243646");
	EXPECT_EQ(' ',abc.min());
	abc.str="";
	EXPECT_EQ(' ',abc.min());
}
                                                                        
TEST (min, diffstrings){                                       //To Test the min function
artificial_string abc= artificial_string("a2312300AZ");
ASSERT_EQ('a',abc.min());
abc.str="zZaA@!";
	ASSERT_EQ('a',abc.min());
	abc.str="iamms";
	ASSERT_EQ('a',abc.min());
	abc.str="2837!&25JGU";
	ASSERT_EQ(' ',abc.min());
	abc.str="AGILEMETHOD";
	ASSERT_EQ(' ',abc.min());
}	
//====================================================================================================
 /** @brief This is a Test function to check 
 *         if swapcase function works.
 *
 *  It defines a class of source code and runs the swapcase string function
 *  @param Nil.
 *  @return If the testcase is passed or not.
 */
TEST (swapcase, trivialnull){
artificial_string abc= artificial_string("");
	abc.swapcase();
	EXPECT_STREQ("",abc.str.c_str());
}

TEST (swapcase, diffstrings){
	artificial_string abc = artificial_string("tHIS iS gREAT");
	abc.swapcase();
	EXPECT_STREQ("This Is Great",abc.str.c_str());       //To test the swapcase function
	//artificial_string abc = artificial_string("ABCDEFGHIjklmn");
	abc.str="ABCDEFGHIjklm";
	abc.swapcase();
	ASSERT_STREQ("abcdefghiJKLM",abc.str.c_str());
    abc.str="!@# 456 ASD qwe";
    //artificial_string abc = artificial_string("!@# 456 ASD qwe");
	abc.swapcase();
	ASSERT_STREQ("!@# 456 asd QWE",abc.str.c_str());
}
//===================================================================================================


