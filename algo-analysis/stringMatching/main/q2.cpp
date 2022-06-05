#include "../headers/stringMatching.h"
#include "../headers/utils.h"

int main() {
	file_io("IO/q2/input.txt", "IO/q2/output.txt");
	
	std::string str, pattern;
	std::cin >>	str >> pattern;

	bool found = krunth_morris_prat_string_matching(str, pattern);
	std::cout << "\"" << pattern << "\"";

	if(found) 
		std::cout << " found in the string ";
	else
		std::cout << " not found in the string ";

	std::cout << "\"" << str << "\"";
	return 0;
}