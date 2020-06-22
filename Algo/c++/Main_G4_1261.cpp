//2개의 큐 이용
#include <iostream>
#include <queue>
#pragma warning (disable : 4018)
#pragma warning (disable : 4996)
#define MAX 100

using namespace std;

int N,M;
int Dis[MAX][MAX];
int Map[MAX][MAX];
queue<pair<int, int> > Now, Next;
int dx[4] = { 0, 0 , -1 , 1};
int dy[4] = { -1,  1, 0, 0 };
void Input()
{
	scanf("%d %d", &M, &N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			scanf("%1d", &Map[i][j]);
			Dis[i][j] = -1;
		}
	}
}

void Solution()
{
	Now.push(make_pair(0,0));
	Dis[0][0] = 0;
	while (!Now.empty()) {
	    int x = Now.front().first;
		int y = Now.front().second;
		Now.pop();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx >= 0 && nx < N && ny >= 0 && ny <M && Dis[nx][ny] == -1)
			{
				if(Map[nx][ny] == 1)  {
					Dis[nx][ny] = Dis[x][y] + 1;
					Next.push(make_pair(nx,ny));
				}
				else {
					Dis[nx][ny] = Dis[x][y];
					Now.push(make_pair(nx,ny));
				}
			}
		}
		if( Now.empty() )  {
			Now = Next;
		    Next = queue<pair<int, int> > () ;
		}
	}
}

void Solve()
{
	Input();
	Solution();
	printf("%d\n",Dis[N-1][M-1]);
}

int main(void)
{	
	Solve();
	return 0;
}
