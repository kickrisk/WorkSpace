#include <iostream>
#include <queue>

using namespace std;

int a[20][20];
int dis[20][20];
bool check[20][20];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int cnt=0;
bool ok =true;

typedef struct shark {
	int x;
	int y;
	int body;
	int time;
}shark;

void printing(int n,shark sh)
{
	cout<<sh.body<<'\n';
	cout<<"============================="<<endl;
	for(int i=0; i<n;i++) {
		for(int j=0; j<n;j++)
			cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	cout<<"============================="<<endl;
}

void bfs(int n,shark *sh) 
{
	queue<pair<int, int> > q;
	q.push(make_pair(sh->x, sh->y));
	dis[sh->x][sh->y] = 0;
	check[sh->x][sh->y] = true;
	int d[3] = { 9999,9999,9999 };  // dis x y
	while( !q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx >= 0 && nx < n && ny >= 0 && ny < n) {	// in water
				if( !check[nx][ny] ) { // pass ok
					if(a[nx][ny] == 0 || a[nx][ny] == sh->body) {
						q.push(make_pair(nx, ny)); 
						dis[nx][ny] = dis[x][y] + 1;
						check[nx][ny] = true;
					}
					else if( a[nx][ny] != 0  && a[nx][ny] < sh->body) { // can eat
						if( d[0] > dis[x][y] + 1)  {
							d[0] = dis[x][y] +1; d[1] = nx; d[2] = ny;
						}
						else if( d[0] == dis[x][y] +1) 	{
							if( d[1] > nx) {
								d[1] = nx; d[2] = ny;
							}
							else if( d[1] == nx ) {
								if(d[2] > ny ) {
									d[2] = ny;
								}
							}
						}
						ok = true;  // maybe more fish
					}
				}
			}
		}
	}
	if( ok == true ) {
		sh->time = sh->time + d[0];	//	time +
		cnt++; 	// cnt + 
		a[sh->x][sh->y] = 0;
		sh->x = d[1]; sh->y = d[2]; //  shark position reset
		a[ d[1] ][ d[2] ] = 9;	// swallowed fish
	}
}

int main(void)
{
	int n;
	cin>>n;
	shark sh;
	for(int i=0; i<n;i++) {
		for(int j=0; j<n; j++) {
			cin>>a[i][j];
			if(a[i][j] == 9) {
				sh.x = i; sh.y = j; sh.body = 2; sh.time = 0;
			}
		}
	}
	cout<<"============================="<<endl;
	while(ok == true) {
		ok = false;
		printing(n,sh);
		memset(dis,0,sizeof(dis));
		memset(check,0,sizeof(check));
		bfs(n,&sh);
		if(cnt == sh.body) {
			sh.body += 1; cnt = 0;
		}
	}
	cout<<sh.time<<'\n';
	return 0;
}
