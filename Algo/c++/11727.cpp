#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std;
int n;
int d[MAX];
int go(int n)
{
	if( n == 1) return 1;
	else if( n == 2) return 3;
	else if ( n== 3) return 3;
	else {
		if( d[n] != 0) {
			return d[n];
		}
		else {
			d[n] = ( go(n-1) + go (n-2) + go(n-3) ) % 10007;
		}
	}
	return d[n];
}

int main(void)
{
	cin>>n;
	memset(d,0,sizeof(d));
	int ans = go(n);
	cout<<ans<<endl;
	return 0;
}
