#include <iostream>
#include <cmath>
#define MAX 10000
using namespace std;
int x, y, xx, yy, r, rr;
int ans = 0;
int main()
{
	int t;
	cin>>t;
	while(t--) {
		ans = 0;
		cin>>x>>y>>r>>xx>>yy>>rr;
		if( x == xx && y == yy ) {
			if(r == rr) ans = -1;
		}
		else {
			if( (x - r == xx - rr) || (x - r == xx + rr) || (x + r == xx + rr) || (x + r == xx - rr) || (y - r == yy - rr) || (y - r == yy + rr) || (y + r == yy - rr) || (y + r == yy + rr) ) ans = 1;
			else if( (x - xx)*(x - xx) + (y - yy)*(y - yy) < (r + rr)*(r + rr)	) {
				if( r > 2 * rr || rr > 2 * r) ans = 0;
				else ans = 2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
