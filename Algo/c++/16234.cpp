#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 50
using namespace std;
int d[MAX][MAX];
int m[MAX][MAX];
bool c[MAX][MAX];
int dx[] = { 0, 0, -1, 1};
int dy[] = { -1, 1, 0, 0};
int n, l, r, p;
int cnt = 0;
queue<pair<int, int> > q;
int ans = 0;
int a = 1;
void printing(int a[MAX][MAX])
{
	cout<<"++++++++++++++++++++"<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf("%2d ",a[i][j]);
		}
		cout<<endl;
	}
	cout<<"++++++++++++++++++++"<<endl;
}
void bfs()
{
	long long sum = m[q.front().first][q.front().second];
	bool ok = false;
	int cnt = 1;
	while( !q.empty() ) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0; k<4; k++) {
			int nx = x +dx[k], ny = y + dy[k];
			if( nx >=0 && nx < n && ny >=0 && ny < n) {
				if( abs(m[x][y] - m[nx][ny]) <= r && abs(m[x][y] - m[nx][ny]) >= l && d[nx][ny] == -1) {
					q.push(make_pair(nx,ny)); 
					d[nx][ny] = d[x][y] = 1;
					cnt += 1;
					sum += m[nx][ny];
					ok = true;
				}
			}
		}
	}
	if( ok ) {
		printing(d);
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(d[i][j] != -1 && c[i][j] == false) {
					m[i][j] = sum/cnt;
					c[i][j] = true;
				}
			}
		}
		printing(m);
		p += 1;
		cout<<a++<<':'<<cnt<<' '<<sum<<endl;
	}
}
void find()
{
	p = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(d[i][j] == -1) {
				q.push(make_pair(i,j)); 
				bfs();
			}
		}
	}
}
int main()
{
	cin>>n>>l>>r;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>m[i][j];
		}
	}
	while(1) {
		memset(d,-1,sizeof(d));
		memset(c,false,sizeof(c));
		find();
		printing(m);
		printing(d);
		if(p == 0) break;
		else ans += 1;
	}
	cout<<ans<<endl;
}
