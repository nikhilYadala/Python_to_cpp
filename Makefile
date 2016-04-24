TARGET = translator
SOURCE_DIR = Source/src/
all:
	g++ --std=gnu++11 $(SOURCE_DIR)convert_to_cpp.cpp  $(SOURCE_DIR)functionize.cpp  $(SOURCE_DIR)generate_cpp_code.cpp  $(SOURCE_DIR)main.cpp  $(SOURCE_DIR)render_code.cpp $(SOURCE_DIR)convert_to_cpp_classes.cpp $(SOURCE_DIR)generated_cpp_classes.cpp $(SOURCE_DIR)make_classes.cpp -o $(TARGET)
	
clean:
	rm -f Target/*
	echo "Target directory cleaned.[SUCCESSFULL]"

