#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <tuple>
#include <string>
#define MAX 1001

using namespace std;

int n, m;
int Map[MAX][MAX];
pair<int, int> Dis[MAX][MAX];

bool Check[MAX][MAX];
queue<pair<int, pair< int, int > > > Now, Next;
int dx[4] = { 0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0 };
int Cal(int A, int B) 
{
	if( A == -1 ) {
		if( B == -1) return -1;
		else return B+1;
	}
	if (B == -1) {
		if( A != -1) return A+1;
	}
	if( A != -1 && B != -1) {
		if( A>B) return B+1;
		else return A+1;
	}
	return 0;
}
void Input()
{
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%1d",&Map[i][j]);
		}
	}
	memset(Dis,-1,sizeof(Dis));
	Now.push(make_pair(0,make_pair(0,0)));
	Dis[0][0] = make_pair(0, 0);
}

void Solution()
{
	while( !Now.empty() ) {
		int x = Now.front().first;
		int y = Now.front().second.first;
		int w = Now.front().second.second;
		Now.pop();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if ( Map[nx][ny] == 1) {
					if(w < 1 ) {
							Dis[nx][ny].first = Dis[x][y].first + 1;
							Dis[nx][ny].second = Dis[x][y].first + 1;
							Now.push(make_pair(nx,make_pair(ny,w+1)));
					}
				}
				if(Map[nx][ny] == 0) {
					if( w ==1 ) {
						if (Dis[nx][ny].second == -1) {
							Dis[nx][ny].second = Dis[x][y].second + 1;
							Now.push(make_pair(nx,make_pair(ny,w)));
						}
					}
					else {
						if (Dis[nx][ny].first == -1) {
							Dis[nx][ny].first = Dis[x][y].first + 1;
							Now.push(make_pair(nx,make_pair(ny,w)));
						}
					}
				}
			}
		}
	}
}
void Solve()
{
	Input();
	Solution();
	//printing();
	int ans;
	ans = Cal(Dis[n-1][m-1].first , Dis[n-1][m-1].second);
	cout<<ans<<endl;
}
int main(void)
{
	Solve();
	return 0;
}
