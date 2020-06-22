#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 25

using namespace std;

int Map[MAX][MAX];
int Num = 0 , Cnt = 0;
int Town[MAX*MAX];
bool Check[MAX][MAX];
int n;
int dx[4] = { 0, 0, -1, 1}; int dy[4] = { -1, 1, 0, 0};
queue<pair<int, int> > q;
void Input()
{
	cin>>n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%1d",&Map[i][j]);
			if(Map[i][j] == 0) {
				Check[i][j] = true;
			}
		}
	}
}
void Find(int i, int j)
{
	q.push(make_pair(i,j));
	Num = 1;
	while( !q.empty() ) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if(Check[nx][ny] == false) {
					Check[nx][ny] = true;
					q.push(make_pair(nx,ny));
					Num++;
				}
			}
		}

	}
	Town[Cnt++] = Num-1;
}
void Solution()
{	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(Check[i][j] == false) {
				Find(i,j);
			}
		}
	}
	cout<<Cnt<<endl;
}
void Solve()
{
	Input();
	Solution();
	sort(Town, Town+Cnt);
	for(int i =0; i<Cnt; i++) {
		if(Town[i] == 0) Town[i]++;
		cout<<Town[i]<<endl;
	}
}
int main(void)
{
	Solve();
	return 0;
}
