#include<iostream>
#include<regex>

int main() {
	std::string s = "<div class=a id=b>abc </div>";
	std::smatch m;
	std::regex r("class[ ]*=[ ]*[A-Za-z]");
	
	std::regex_search(s, m, r);

	for (auto x : m) {
		std::cout << x << std::endl;
	}

	return 0;
}