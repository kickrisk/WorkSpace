#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = {-1, 1,  0, 0 };
int d[100][100];
int th[100];
int r, c, n;
char m[100][100];

int a = 0;
void Input()
{
	cin>>r>>c;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin>>m[i][j];
		}
	}
	cin>>n;
	for(int i=0; i<n; i++) {
		int temp;
		cin>>temp;
		th[i] = --temp;
	}
	memset(d,-1,sizeof(d));
	memset(w,-1,sizeof(w));
}
pair<int, int > dfs(int x, int y,int dir)
{
	pair<int, int> temp;
	bool ok = false
	while(1) {
		if(ok == true) break;
		if( m[x][y] == 'x' ) ok =true;
		x = x + dx[dir], y = y + dy[dir];
		dfs(x,y,dir);
	}
	temp = make_pair(x,y);
	return temp;
}
bool Checking( int x, int y, int dong)
{
	queue<pair<int, int> > q1;
	bool ok = false;
	q1.push(make_pair(x,y));
	while( !q.empty() ) {
		if(ok == true) break;
		x = q1.front().first, y= q1.front().second;
		q1.pop();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];, dy = y + dy[k];
			if( nx >= 0 && nx < r && ny >=0 && ny < c ) {
				if(m[nx][ny] == 'x' && d[nx][ny] == dong) {
					if(nx == 0 ) {
						ok = true; break;
					}
					q.push(make_pair(nx,ny));
				} 
			}
	}
	return ok;
}
void bfs(int i, int j)
{
	queue<pair<int, int> > q;
	q.push(make_piar(i,j));
	while( !q.empty() )
	{
		int x= q.front().first, y = q.front().second;
		d[x][y] = a;
		q.pop();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];, dy = y + dy[k];
			if( nx >= 0 && nx < r && ny >=0 && ny < c ) {
				if(m[nx][ny] == 'x' && d[nx][ny] == -1) {
					q.push(make_pair(nx,ny));
				} 
			}
		}	
	}
}
void Solution()
{
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(m[i][j] == 'x' && d[i][j] == -1) {
				bfs(i,j);
				a++;
			}
		}
	}
	for(int i=0; i<n; i++) {
		while(1) {
			int start = 0; bool ok = false;
			if( i % 2 != 0 ) start = c-1;
			pair<int, int > point = dfs(th[i],start, i%2 + 1);
			m[point.first][point.second] = '.';
			
	}
}
