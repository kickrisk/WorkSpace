#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1001

using namespace std;

int d[MAX][MAX];
int S, s, c;
queue<pair<int, int> >q;

void Input()
{
	cin>>S;
	memset(d,-1,sizeof(d));
	d[1][0] = 0;
	q.push(make_pair(1,0));
}

void Solution()
{
	while( !q.empty() ) {
		s = q.front().first;
		c = q.front().second;
		q.pop();
		if(d[s][s] == -1) {
			d[s][s] = d[s][c] +1;
			q.push(make_pair(s,s));
		}
		if( s+c <= S && d[s+c][c] == -1) {
			d[s+c][s] = d[s][c] + 1;
			q.push(make_pair(s+c,s));
		}
		if( s-1 >=0 && d[s-1][c] == -1) {
			d[s-1][c] = d[s][c] + 1;
			q.push(make_pair(s-1,c));
		}
	}
}

void Solve()
{
	int ans = 987654321;
	Input();
	Solution();
	for(int j=0; j<=S; j++) {
		if( d[S][j] != -1) {
			if( ans > d[S][j] ) ans = d[S][j];
		}
	}
	cout<<ans<<endl;
}
int main(void)
{
	Solve();
	return 0;
}
