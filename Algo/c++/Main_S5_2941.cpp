#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int cnt = 0;
	for(int i=0; i<s.size(); i++) {
		if(s[i] == 'd') {
			if(s[i+1] == 'z' && s[i+2] =='=') i += 2;
			else if(s[i+1] == '-') i += 1;
		}
		else if(s[i] == 'c') {
			if(s[i+1] == '=' || s[i+1] == '-') i += 1;
		}
		else if(s[i] == 'l' && s[i+1] == 'j') i += 1;
		else if(s[i] == 'n' && s[i+1] == 'j') i += 1;
		else if(s[i] == 's' && s[i+1] == '=') i += 1;
		else if(s[i] == 'z' && s[i+1] == '=') i += 1;
		cnt++;
	}
	cout<<cnt<<endl;
}
