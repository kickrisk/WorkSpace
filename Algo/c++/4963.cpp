#include <iostream>
#include <queue>
#include <cstring>
#define MAX 50

using namespace std;

int Map[MAX][MAX];
int Cnt = 0;
bool Check[MAX][MAX];
queue <pair<int, int> > q;
int dx[8] = { 0,  0,  -1,  1,   1,  1,  -1,  -1};
int dy[8] = { -1,  1,   0, 0, -1,  1,   -1,   1};
int w,h;
		
void Find(int x, int y)
{
	q.push(make_pair(x,y));
	while( !q.empty() ) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int k=0; k<8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if( nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if( Check[nx][ny] == false ) {
					Check[nx][ny] = true;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	Cnt++;
}

int main(void)
{
	while(1) {
		cin>>w>>h;
		if( h ==0 && w== 0) break;
		memset(Check,false,sizeof(Check));
		Cnt = 0;
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				cin>> Map[i][j];
				if(Map[i][j] == 0) {
				 	Check[i][j] = true;
				}
			}
		}
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				if(Check[i][j] == false) {
					Find(i,j);
				}
			}
		}
		cout<<Cnt<<endl;
	}
	return 0;
}
