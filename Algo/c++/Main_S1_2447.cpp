#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char m[6561][6561];
void printing(int n, int x, int y) 
{
	if( n == 1) {
		m[x][y] = '*'; return;
	}
	int div = n/3;
	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			if( i == 1 && j == 1) continue;
			printing(div, x + div*i, y + div*j );
		}
	}
}
int main()
{
	int n;
	cin>>n;
	memset(m,' ',sizeof(m));
	printing(n,0,0);
	for(int i =0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<m[i][j];
		}
        cout<<endl;
	}
}
