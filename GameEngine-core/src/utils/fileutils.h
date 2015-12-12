#pragma once
#include <string>
#include <fstream>
namespace GameEngine {
	class utils{
	public:
		static std::string read_file(const char* filepath){
			FILE* file = fopen(filepath, "rt");
			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);//for binary its no of bytes; maybe not for text lun of char = 1 byte
			char *data = new char[length + 1];
			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);
			delete[] data;
			return result;
		}

	};
	
}

/*
Usage example
std::string f = read_file("main.cpp");
std::cout << f << std::endl;
system("PAUSE");
return 0;

*/