#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;

pair<int, int> sum;
int N,P;
int land=0;

int Map[10][10];
int d[10][10];
int l[10][10];

int dx[4] = { 0 , 0 ,-1 , 1};
int dy[4] = {-1 , 1, 0, 0};

int bridge[6][6];
bool c[6];

deque<pair<int,int> >dq;
queue<pair<int,int> > q;
vector<int > v[7];
vector<int> t;
void printing( int a[10][10])
{
	for(int i=0; i<N; i++) {
		for(int j=0; j<P; j++) {
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}
void bfs() 
{
	while( !q.empty() ) {
		int x = q.front().first;
		int y = q.front().second;
		Map[x][y] = land+2;
		cout<<'('<<x<<','<<y<<')'<<Map[x][y]<<endl;
		q.pop();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx >= 0 && nx < N && ny >= 0 && ny < P) {
				if( Map[nx][ny] == 1) {
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
}
void check(int start, int cnt, vector<int > v[])
{
	c[start] = true;
	sum.first += bridge[sum.second][start];
	for(int i=0; i<v[start].size(); i++) {
		if( c[i] == false ) {
			sum.second = start;
			check(i,cnt+1,v);	
		}
	}
	if( cnt == land ) {	
		t.push_back(sum.first);
	}
}
void bfs2(deque<pair<int,int> >dq, int start)
{
	while( !dq.empty() ){
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();
		for(int k=0; k<4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx >= 0&& nx < N && ny >= 0 && ny < P) {
				if(l[nx][ny] == 1) 	{
					if(Map[nx][ny] != 0) {
						if(bridge[start][Map[nx][ny]] != 0 ) continue;
						bridge[start][Map[nx][ny]] = d[x][y] + 1;
						v[start].push_back(Map[nx][ny]);
					}
					dq.push_front(make_pair(nx,ny));
					d[nx][ny] = d[x][y];
				}	else {
					dq.push_back(make_pair(nx,ny));
					d[nx][ny] = d[x][y] + 1;
				}
			}
		}
	}
}
int main(void)
{
	cin>>N>>P;
	for(int i=0; i<N; i++) {
		for(int j=0; j<P; j++) {
			cin>>Map[i][j];
			if(Map[i][j] != 0) 
				l[i][j] = 1; 
		}	
	}
	printing(l);
	cout<<1111111111111<<endl;
	for(int i=0; i<N; i++) {
		for(int j=0; j<P; j++) {
			if(l[i][j] == 1) {
				q.push(make_pair(i,j));
				bfs();
				land++;
			}
		}	
	}
	cout<<222222222222222<<endl;
	land -=1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<P; j++) {
			if(l[i][j] != 0) {
				dq.push_front(make_pair(i,j));
				bfs2(dq,Map[i][j]);
				memset(d,0,sizeof(d));
			}
		}	
	}
	cout<<33333333333333<<endl;
	for(int i=0; i<land; i++) {
		sum = make_pair(0,i);
		memset(c,false,sizeof(c));
		check(i,1,v);
	}
	cout<<44444444444444<<endl;
	sort(t.begin(),t.end());
	cout<<t.front()<<endl;

	return 0;
}
