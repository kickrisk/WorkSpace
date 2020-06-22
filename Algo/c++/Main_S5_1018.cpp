#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	int r, c;
	cin>>r>>c;
	string m;
	for(int i=0; i<r; i++) {
		string t;
		cin>>t;
		m += t;
	}
	string s1 =  "WBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBW";
	string s2 = "BWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWBBWBWBWBWWBWBWBWB";
	int ans = -1;
	for(int i=0; i<=r-8; i++) {
		for(int j=0; j<=c-8; j++) {
			string p;
			for(int k=0; k<8; k++) {
				p += m.substr( (i+k) *c + j,8);
			}
			int temp1 = 0, temp2 = 0;
			for(int k=0; k<64; k++) {
				if(p[k] != s1[k] ) temp1 += 1;
				if(p[k] != s2[k] ) temp2 += 1;
			}
			int temp = min(temp1, temp2);
			if( ans == -1 || ans > temp) ans = temp;
		}
	}
	cout<<ans<<endl;
}
