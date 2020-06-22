#include <iostream>
#include <cstring>

using namespace std;
int m[4];
int a[4];
void move()
{
	for(int i=0; i<4; i++) {
		if(m[i] != 0) {
			if(m[i] == 1) {
				int temp = a[i] & 1<<0;
				a[i]>>1;
				a[i] | temp<<7;
			}
			else {
				int temp = a[i] & 1<<7;
				a[i] & 0<<7; a[i]<<1;
				a[i] | temp<<0;
			}
		}
	}
}
void go(int n, int c)
{
	m[n] = c;
	if( n == 1) {
		if( (a[n] & 1<<2) != ( a[n-1] & 1<<6) ) {
			m[n-1] = -c;
		}
		if( (a[n] & 1<<6) != ( a[n+1] & 1<<2) ) {
			m[n+1] = -c;
		}
		if( (a[n+2] & 1<<2) !=  (a[n+1] & 1<<6) ) {
			m[n+2] = c;
		}
	}
	if( n == 2) {
		if( (a[n] & 1<<2) != ( a[n-1] & 1<<6) ) {
			m[n-1] = -c;
		}
		if( (a[n] & 1<<6) != ( a[n+1] & 1<<2) ) {
			m[n+1] = -c;
		}
		if( (a[n-2] & 1<<6) != (a[n-1] & 1<<2)) {
			m[n-2] = c;
		}
	}
	if( n == 3) {
		if( (a[n] & 1<<2) != ( a[n-1] & 1<<6) ) {
			m[n-1] = -c;
		}
		if( (a[n-1] & 1<<2) != ( a[n-2] & 1<<6) ) {
			m[n-2] = c;
		}
		if( (a[n-2] & 1<<2) != (a[n-3] & 1<<6)) {
			m[n-3] = -c;
		}
	}
	if( n == 0) {
		if( (a[n] & 1<<6) != ( a[n+1] & 1<<2) ) {
			m[n+1] = -c;
		}
		if( (a[n+1] & 1<<6) != ( a[n+2] & 1<<2) ) {
			m[n+2] = c;
		}
		if( (a[n+2] & 1<<6) != ( a[n+3] & 1<<2)) {
			m[n+3] = -c;
		}
		move();
	}	
}
int main()
{
	for(int i=0; i<4; i++) {
		int temp;
		for(int j=0; j<8; j++) {
			scanf("%1d",&temp);
			a[i] = 2 * a[i] + temp;
		}
	}
	int t;
	cin>>t;
	int ans = 0;
	while(t--) {
		int n,c;
		memset(m,0,sizeof(m));
		cin>>n>>c;
		go(n-1,c);
	}
	for(int i=0; i<4; i++) {
		for(int j=0; j<8; j++) {
			if(a[i] & 1<<j) 
				cout<<1;
			else
				cout<<0;
		}
		cout<<endl;
	}
	if(a[0] & 1<<7) { ans += 1; cout<<1<<endl; }
	if(a[1] & 1<<7) {ans += 2;	cout<<2<<endl;	}
	if(a[2] & 1<<7) {ans += 4;	cout<<3<<endl;	}
	if(a[3] & 1<<7) {ans += 8;	cout<<4<<endl;	}
	cout<<ans<<endl;	
}
