# # the compiler: gcc for C program, define as g++ for C++
# CC = gcc

# # compiler flags:
# #  -g    adds debugging information to the executable file
# #  -Wall turns on most, but not all, compiler warnings
# CFLAGS  = -gcc	-Wall
# # the build target executable:
# TARGET = myprog
# all: $(TARGET)
# $(TARGET): $(TARGET).c
# $(CC)	$(CFLAGS)	-o $(TARGET)	$(TARGET).c

# clean:
# 	$(RM) $(TARGET) 

TARGET = translator
SOURCE_DIR = Source/src/
all:
	g++ $(SOURCE_DIR)convert_to_cpp.cpp  $(SOURCE_DIR)functionize.cpp  $(SOURCE_DIR)generate_cpp_code.cpp  $(SOURCE_DIR)main.cpp  $(SOURCE_DIR)render_code.cpp -o $(TARGET)
	
clean:
	rm -f Target/*
	echo "Target directory cleaned.[SUCCESSFULL]"

