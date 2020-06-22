#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int ans = 0;
void check(int k,int cnt) 
{
	string s = to_string(k);
	if( cnt == 3) {
		if( (s[0] - s[1]) == (s[1]-s[2]) ) ans++;
	}
	else {
		if( (s[0] - s[1]) == (s[1]-s[2]) && (s[1] - s[2]) == (s[2]-s[3]) ) ans++;
	}
}
int main()
{
	int n;
	cin>>n;
	int cnt = 1;
	for(int i =1; i<=n; i++) {
		if( i < 100)  {
			if(i == 10) cnt++;
			ans++; continue;
		}
		if(i == 100) cnt++;
		if(i == 1000) cnt++;
		check(i,cnt);
	}
	cout<<ans<<endl;
}
