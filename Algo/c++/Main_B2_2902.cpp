#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	string p;
	int key = 0;
	for(int i=0; i<s.size(); i++) {
		if(i == key) p += s[i];
		if(s[i] == '-') key = i + 1;
	}
	cout<<p<<endl;
}
