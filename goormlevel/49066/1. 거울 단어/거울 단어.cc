#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<char, char> mirror;
	mirror['b'] = 'd';
	mirror['d'] = 'b';
	
	mirror['i'] = 'i';
	mirror['l'] = 'l';
	mirror['m'] = 'm';
	mirror['n'] = 'n';
	mirror['o'] = 'o';
	
	mirror['p'] = 'q';
	mirror['q'] = 'p';
	mirror['s'] = 'z';
	mirror['z'] = 's';
	
	mirror['u'] = 'u';
	mirror['v'] = 'v';
	mirror['w'] = 'w';
	mirror['x'] = 'x';
	
	int n; cin >> n;
	while (n--) {
		string s; cin >> s;
		size_t i = 0;
		for (; i <= s.length() / 2; i++) {
			if (mirror.find(s[i]) != mirror.end() 
					&& mirror.find(s[s.length() - 1 - i]) != mirror.end()
					&& mirror[s[i]] == s[s.length() - 1 -i]) {
				continue;
			} else {
				cout << "Normal\n";
				break;
			}
		}
		if (i == s.length() / 2 + 1) {
			cout << "Mirror\n";
		}
	}
}