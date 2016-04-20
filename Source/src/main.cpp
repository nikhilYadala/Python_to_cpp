#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#define chunk 1024		//Chunk of bytes to be read at a time from file(source code)

#include "../Header/supporting_libs/supporting_libs.h"
#include "../Header/include/function_struct.h"
#include "../Header/include/source_code.h"

void render_code(source_code &src);


int main(int argc, char *argv[])
{

	char *f=argv[1];
	std::string input_src;
	if (FILE *fp = fopen(f,"r"))
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

	
	for(int i=0;;++i)
		if(f[i]=='.')
		{
			f[i]='\0';
			break;
		}
		

	source_code input_code(input_src);
	input_code.file_name=f;
	input_code.functionize();
	// input_code.make_classes();
	std::cout<<f<<"done with make classes\n";
	
	input_code.generate_cpp_code();


	input_code.generate_cpp_classes();
	 std::cout<<f<<"done with generate_cpp_classes\n";
	
	input_code.render_code();
		 std::cout<<f<<"done with rendering of code\n";





	// for(std::string::iterator itr=input_src.begin();itr!=input_src.end();++itr)
		// std::cout<<*itr;

	return 0;

}

