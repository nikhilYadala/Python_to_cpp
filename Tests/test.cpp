#include <limits.h>
#include "../Source/Header/supporting_libs/supporting_libs.h"
#include "gtest/gtest.h"
#include<string>
#include "test1.cpp"
#include "functionize/test2.cpp"
#include "generating_cpp/test3.cpp"
#include "alltests/runtest.cpp"
#include "alltests/newtest.cpp"

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}