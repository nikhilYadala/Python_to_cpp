/* This file tests the functions present in supporting_libs.h
*/
#include <limits.h>
#include "supporting_libs.h"
#include "gtest/gtest.h"


TEST (capitialize, trivialnull) {
//EXPECT_STREQ(false,'NULL'.capitialize());                                   
EXPECT_STREQ(@8.41#$,'@8.41#$'.capitialize());                    
}

TEST (capitialize, various_strings) {
ASSERT_STREQ(Abhishek,'abhishek'.capitialize());                      //To Test the function capitalize
ASSERT_STREQ(India_is_my_country,'india_is_my_country'.capitialize());
ASSERT_STREQ(We like CS242,'We like CS242'.capitialize());
}
//==================================================================================================

TEST (len, trivialnull){
	EXPECT_EQ(0,len(NULL));
}

TEST (len, otherlengths){                                              //To Test the function len
	ASSERT_EQ(9,len('123456789'));
	ASSERT_EQ(32,len('This is Python to C++ translator'));
	ASSERT_EQ(8,len('!@#$%^&('));
}
//===================================================================================================

TEST (upper, trivialnull){
	EXPECT_STREQ(false,NULL.capitialize());
EXPECT_STREQ(@8.41#$,'@8.41#$'.capitialize());                    
}

TEST (upper, various_strings) {
ASSERT_STREQ(ABHISHEK,'abhishek'.capitialize());                      //To Test the function upper
ASSERT_STREQ(INDIA_IS_MY_COUNTRY,'india_is_my_country'.capitialize());
ASSERT_STREQ(WE LIKE CS242,'We like CS242'.capitialize());
}
//===================================================================================================

TEST (max, trivialnull){
//	EXPECT_STREQ(NULL,max('@!@#443243646'));
	EXPECT_STREQ(NULL,max(NULL));
}
                                                                        
Test (max, diffstrings){                                       //To Test the max function
ASSERT_STREQ(a,max('a2312300AZ'));
ASSERT_STREQ(z,max('zZaA@!'));
ASSERT_STREQ(s,max('iamms'));
ASSERT_STREQ(NULL,max('2837!&25JGU'));
ASSERT_STREQ(NULL,max('AGILEMETHOD'));
}
//====================================================================================================

TEST (upper, trivialnull){
	EXPECT_STREQ(false,NULL.capitialize());
EXPECT_STREQ(@8.41#$,'@8.41#$'.capitialize());                    
}

TEST (upper, various_strings) {
ASSERT_STREQ(abhishek,'abhishek'.capitialize());                      //To Test the function lower
ASSERT_STREQ(india_is_my_country,'INDIA_IS_MY_COUNTRY'.capitialize());
ASSERT_STREQ(we like cs242,'We Like CS242'.capitialize());
}

//====================================================================================================
int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}