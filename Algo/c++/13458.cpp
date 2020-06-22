#include <iostream>
using namespace std;

long long a[1000001];
long long n, b, c;

int main() {
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	cin>>b>>c;
	long long Ans = 0;
	for(int i=0; i<n; i++) {
		long long cnt = 1;
		long long temp = a[i]-b;
		if( temp > 0 ) {
			 int k= temp / c;
			if(  k > 0 ) {
				cnt += k;
				if( temp % c != 0) cnt += 1;
			}
			else {
				if( temp % c != 0) cnt += 1;
			}
		}
		Ans += cnt;
	}
	cout<<Ans<<endl;
}
