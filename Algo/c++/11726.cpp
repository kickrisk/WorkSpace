#include <iostream>
#define MAX 1001

using namespace std;

int d[MAX];
int n;

int go (int n)
{
	if( n == 1) return 1;
	else if ( n == 2) return 2;
	else {
		if( d[n] != 0 ) {
			return d[n];
		}
		else {
			d[n] = go(n-1) + go(n-2);
		}
	}
	return d[n];
}

int main(void)
{
	cin>>n;
	int ans = go(n);
	cout<<ans%10007<<endl;
}
