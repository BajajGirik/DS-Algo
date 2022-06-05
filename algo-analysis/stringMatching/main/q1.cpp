#include "../headers/stringMatching.h"
#include "../headers/utils.h"

int main() {
	file_io("IO/q1/input.txt", "IO/q1/output.txt");
	
	std::string str, pattern;
	std::cin >>	str >> pattern;

	bool found = naive_string_matching(str, pattern);
	std::cout << "\"" << pattern << "\"";

	if(found) 
		std::cout << " found in the string ";
	else
		std::cout << " not found in the string ";

	std::cout << "\"" << str << "\"";
	return 0;
}