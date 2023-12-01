#include <iostream>	// std::cin/cout
#include <string>	// std::string
#include <ctype.h>	// isdigit()
#include <vector>	// std::vector
#include <map>

int main() {
	std::string line{};
	int answer{};
	std::map<std::string,std::string> numbers{
		{"one","1"},
		{"two","2"},
		{"three","3"},
		{"four","4"},
		{"five","5"},
		{"six","6"},
		{"seven","7"},
		{"eight","8"},
		{"nine","9"},
	};
	while(std::cin>>line) {
		for(std::size_t i = 0;i < line.length();++i) {
			for(const auto& [word, number] : numbers) {
				if((line.length()-i)<word.length())
					continue;
				if(line.substr(i,word.length()).compare(word) == 0)
					line.replace(i,word.length(),number);
			}
		}
		std::vector<int> digits{};
		for(char c : line) {
			if(isdigit(c))					// https://stackoverflow.com/questions/2340688/how-to-find-out-if-a-character-in-a-string-is-an-integer
				digits.push_back(c-'0');		// https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
		}
		answer += (digits.front()*10)+digits.back();
	}
	std::cout<<"Answer: "<<answer<<"\n";
}
