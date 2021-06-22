#include<iostream>
#include<regex>

using namespace std;

int main() {
	string s = "<div class=a id=b>abc </div>";
	smatch m;
	regex r("class[ ]*=[ ]*[A-Za-z]");
	
	regex_search(s, m, r);

	for (auto x : m) {
		cout << x << endl;
	}

	return 0;
}