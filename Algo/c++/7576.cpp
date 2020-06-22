#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

int dx[4] = { 0, 0, -1 ,1};
int dy[4] = {-1, 1, 0, 0 };
int n,m, ans = 0;
int Map[MAX][MAX];
int Dis[MAX][MAX];
bool ok = true;
queue<pair<int, int> > q;
int Max( int A, int B) { if( A > B) return A; return B; }
void Input()
{
	cin>>n>>m;
	memset(Dis,-1,sizeof(Dis));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin>>Map[i][j];
			if(Map[i][j] == 1) {
				q.push(make_pair(i,j));
				Dis[i][j] = 0;
			}
		}
	}
}

void Find() 
{
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(Map[i][j] == 0) {
				ok =false; ans = -1;
				return;
			}
			else ans = Max(ans,Dis[i][j]);
		}
	}
}

void Solution()
{
	while( !q.empty() )
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if( Map[nx][ny] == 0 ) {
					Map[nx][ny] = 1;
					Dis[nx][ny] = Dis[x][y] + 1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}

void Solve()
{
	Input();
	Solution();
	Find();
	cout<<ans<<endl;
}
int main(void)
{
	Solve();
	return 0;
}
