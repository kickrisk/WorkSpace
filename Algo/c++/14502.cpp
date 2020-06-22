#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int dx[] = { 0 , 0, -1, 1};
int dy[] = { -1, 1, 0, 0 };
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	vector<pair<int,int> > q;
	queue<pair<int, int> > v1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin>>a[i][j];
			if( a[i][j] == 0 ) {
				q.push_back(make_pair(i,j));
			}
			else if( a[i][j] == 2) {
				v1.push(make_pair(i,j));
			}
		}
	}
	vector<int> t;
	for(int i=0; i < q.size()-3; i++) t.push_back(0);
	for(int i=0; i < 3; i++) t.push_back(1);
	int Ans = -1;
	do {
		int cnt = 0;
		int copy[n][m];
		memcpy(copy,a,sizeof(copy));
		queue<pair<int, int> > v(v1);
		for(int i=0; i< q.size(); i++) {
			if(cnt == 3) break;
			if( t[i] == 1) { copy[q[i].first][q[i].second] = 1; cnt++; }
		}
		while( !v.empty() ) {
			int x = v.front().first, y = v.front().second;
			v.pop();
			for(int k=0; k<4; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
					if( copy[nx][ny] == 0 ){
						copy[nx][ny] = 2;
						v.push(make_pair(nx,ny));
					}
				}
			}
		}
		cnt = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(copy[i][j] == 0) cnt++;
			}
		}
		if( Ans == -1 || Ans < cnt) {
			Ans = cnt;
		}
	} while( next_permutation(t.begin(),t.end()));
	cout<<Ans<<endl;
}
