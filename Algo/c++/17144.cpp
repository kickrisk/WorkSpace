#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

queue<int> map[51][51];
int check[51][51];
pair <int, int> air[2];

int dy[4] = { 1, 0, -1,  0 };
int dx[4] = { 0, 1,  0, -1 };

int direct = 0;
int r, c, t;
int d=0;

void printing() 
{	
	cout<<"=================================="<<endl;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			printf("%5d",map[i][j].front());
		}	
		cout<<endl;
	}
	cout<<"=================================="<<endl;
}
void move_dirt() 
{
	int tm[51][51] = {0, };
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if( map[i][j].front() > 0) {
				for(int k=0; k<4; k++) {
					int x = j + dx[k];
					int y = i + dy[k];
					if( x >= 0 && x < c && y >=0 && y < r && check[y][x] != -1  ) {
							map[y][x].push(map[i][j].front()/5);					
							tm[i][j]++;
					}	
				}
			}
		}
	}
	for(int i=0; i<r; i++ ) {
		for(int j=0; j<c; j++) {
			if( map[i][j].front() >= 0 ) {
				int sum = map[i][j].front() - (tm[i][j] * (map[i][j].front()/5) );
				map[i][j].pop();
				while( !map[i][j].empty() ) {
					sum += map[i][j].front();
					map[i][j].pop();
				}

				map[i][j].push(sum);
				check[i][j] = 1;
			}
		}	
	}
}

void ccw( )
{
	int direct = 1;
	int x = air[0].second+1;
	int y = air[0].first;
	int temp = 0;
	while(1) {
		if( y == air[0].first && x== air[0].second )	{
			map[y][x+1].push(0);	break;
		}
		if( x == c-1 && y == air[0].first)	direct = 2;
		if ( x == 0 && y == 0)		direct = 0;
		if( y == 0 && x == c-1 ) 	direct = 3;
		temp = map[y][x].front();
		map[y][x].pop();
		x += dx[direct];
		y += dy[direct];
		map[y][x].push(temp);
	}
}

void cw()
{
	int direct = 1;
	int x = air[1].second+1;
	int y = air[1].first;
	int temp = 0;
	while(1) {
		if( y == air[1].first && x== air[1].second )	{
			map[y][x+1].push(0);	break;
		}
		if( x== c-1 && y == air[1].first)	direct = 0;
		if ( y == r-1 && x == c-1)	direct = 3;
		if( x == 0 && y == r-1) 	direct = 2;
		temp = map[y][x].front();
		map[y][x].pop();
		x += dx[direct];
		y += dy[direct];
		map[y][x].push(temp);	
	}
}
int main(void)
{
	cin>>r>>c>>t;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			int temp;
			cin>>temp;
			map[i][j].push(temp);
			if(map[i][j].front() == -1) {
				air[d] = make_pair(i,j);
				d++;
				check[i][j] = -1;
			}
			else if(map[i][j].front() != 0) { 
				check[i][j] = 1;
			}
		}	
	}
	int a =1;
	while(t--) {
		cout<<a<<endl;
		printing();
		move_dirt();
		cout<<a<<endl;
		printing();
		ccw();
		cw();
		printing();
		a++;
	}
	int sum = 0;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(check[i][j] == 1) sum += map[i][j].front();
		}
	}
	cout<<sum<<'\n';
	return 0;
}
