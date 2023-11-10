#include<iostream>
#include<unordered_map>

char firstNonRepeatingChar(const std::string& input_string);

int main()
{
    std::string myStr{"truetalent"};
    std::cout << "First non repeating char: " << firstNonRepeatingChar(myStr);
    std::cout << std::endl;
}

char firstNonRepeatingChar(const std::string& input_string) {
	std::unordered_map<char, int> myMap;
	for(const auto &c: input_string)
	    ++myMap[c];
	
	for(const auto &c: input_string)
	    if(myMap[c] == 1)
	        return c;
	
	return '\0';
}














