#include <iostream>
#define MAX 20
using namespace std;

char Map[MAX][MAX];
int r,c;
bool Check[26];
int dx[4] = { 0, 0, 1 , -1};
int dy[4] = { 1, -1,  0, 0};

int  go( int a, int b)
{
	int ans =0;
	int x = a, y = b;
	for(int k=0; k<4; k++) {
		int nx = a + dx[k], ny = b + dy[k];
		if( nx >=0 && nx < r && ny >= 0 && ny < c) {
			if( !Check[ Map[nx][ny] - 'A'] ) {
				Check[Map[nx][ny] -'A']= true;
				int next = go(nx,ny); 
				if( ans < next) {
					ans = next;
				}
				Check[Map[nx][ny] -'A']= false;
			}
		}
	}
	return ans + 1;
}

int main()
{
	cin>>r>>c;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin>>Map[i][j];
		}
	}
	Check[Map[0][0] - 'A'] = true;
	cout<<go(0,0)<<endl;
	return 0;
}
