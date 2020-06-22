#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int cnt = 2;
	int i = 1666;
	while(1) {
		if(n == 1) { i = 666; break; }
		if( n == cnt) break;
		i += 1;
		string s = to_string(i);
		bool ok = false;
		for(int i = 0; i<s.size(); i++) {
			if(s[i] == '6' && ok == false) {
				if( s[i+1] == '6' && s[i+2] == '6' && s[i+3] != '6') {
					ok = true; cnt += 1;
				}
			}
		}
	}
	cout<<i<<endl;
}
