#include <iostream>
#include <queue>
#include <cstring>
#include <deque>
#define MAX 50

using namespace std;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int r, c;
char Map[MAX][MAX];
int Cnt[MAX][MAX];
queue<pair<int, int> > S, Sn, W, Wn;
bool ok = false;
pair<int, int> d;
void printing()
{	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cout<<Map[i][j]<<' ';
		}
		cout<<endl;
	}
}
void Printing()
{	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			printf("%2d",Cnt[i][j]);
		}
		cout<<endl;
	}
}
void Input() 
{
	scanf("%d %d", &r, &c);
	memset(Cnt,-1,sizeof(Cnt));
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin>>Map[i][j];
			if( Map[i][j] == 'D') {
				d = make_pair(i,j);
			}
			else if( Map[i][j] == 'S') {
				Sn.push(make_pair(i,j)); 
				Cnt[i][j] = 0;
			}
			else if( Map[i][j] == '*') {
				Wn.push(make_pair(i,j));
				Cnt[i][j] = 0;
			}
		}
	}
}
void Bfs_W()
{
	W = Wn;
	Wn = queue<pair<int, int> > ();
	while( !W.empty()) {
		int x = W.front().first;
		int y = W.front().second;
		W.pop();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if( Map[nx][ny] == 'D' || Map[nx][ny] == 'X') {
					continue;
				}
				else {
					Wn.push(make_pair(nx,ny));
					Map[nx][ny] = '*';
				}
			}
		}
	}
}
void Bfs_S()
{
	if(Sn.empty()) {
		ok = true; return;
	}
	S = Sn;
	Sn = queue<pair<int, int> > ();
	while( !S.empty()) {
		int x = S.front().first;
		int y = S.front().second;
		S.pop();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if( Map[nx][ny] == '*' || Map[nx][ny] == 'X') {
					continue;
				}
				else {
					if( Map[nx][ny] == 'D') {
						Cnt[nx][ny] = Cnt[x][y] + 1;
						ok = true; return;
					}
					else {
						Sn.push(make_pair(nx,ny));
						Cnt[nx][ny] = Cnt[x][y] + 1;
					}
				}
			}
		}
	}
}
void Solution()
{
	while(!ok) {
		Bfs_W();
		Bfs_S();
//		printing();
//		Printing();
	}
}
void Solve()
{
	Input();
	Solution();
	int ans = Cnt[d.first][d.second];
	if( ans != -1) cout<<ans<<endl;
	else cout<<"KAKTUS"<<endl;
}
int main(void)
{
	Solve();
	return 0;
}
