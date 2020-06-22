#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 51
using namespace std;
int n, m;
int ans = -1;
int Map[MAX][MAX];
int d[MAX][MAX];
int dx[] = { 0, 0, -1, 1};
int dy[] = { -1, 1, 0, 0};
void printing(int a[MAX][MAX])
{
	cout<<"+++++++++++++++++++++++++"<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<"+++++++++++++++++++++++++"<<endl;
}
int bfs(queue<pair<int, int> > q, int C[MAX][MAX])
{
	int temp = 0;
	while( !q.empty() ) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k = 0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if( d[nx][ny] == -1 ) {
					if( C[nx][ny] == 1) {
						d[nx][ny] = d[x][y] + 1;
						q.push(make_pair(nx,ny));
					}
					else {
						q.push(make_pair(nx,ny));
						d[nx][ny] = d[x][y] + 1;
					}
				}
			}
		}
	}
	//printing(d);
//	printing(C);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(C[i][j] == 1) {
				temp += d[i][j];
			}
		}
	}
	return temp;
}
int main()
{
	cin>>n>>m;
	vector<pair<int ,int> > c;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>Map[i][j];
			if(Map[i][j] == 2) {
				c.push_back(make_pair(i,j));
			}
		}
	}
	int size = c.size();
	vector<int> v;
	for(int i=0; i<m; i++) { v.push_back(1); }
	for(int i=0; i<size-m; i++) { v.push_back(0);}
	sort(v.begin(),v.end());
	do {
		int C[MAX][MAX];
		queue<pair<int, int> > q;
		memcpy(C,Map,sizeof(C));
		memset(d,-1,sizeof(d));
		for(int i=0; i<size; i++) {
			int x = c[i].first, y = c[i].second;		
			if(v[i] == 1) {	
				d[x][y] = 0;
				q.push(make_pair(x,y));
			}
		}
		int temp = bfs(q,C);
		if(ans == -1 || ans > temp) {
			ans = temp;
		}
	} while(next_permutation(v.begin(),v.end()));
	cout<<ans<<endl;
}
