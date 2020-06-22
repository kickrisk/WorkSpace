#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#pragma warning(disable:4996)
#pragma warning(disable:4018)

using namespace std;

typedef struct SHARK {
	bool life = false;
	int x, y;	// column, row
	int s, d, z; //speed, direct, size
	SHARK(int a1, int a2, int a3, int a4, int a5) : x(a1), y(a2), s(a3), d(a4), z(a5) {}
	SHARK() : x(0), y(0), s(0), d(0), z(0) {}
}Shark;

int R, C, M;
int map[100][100] = {0, };
Shark sh[10001];

int dx[4] = { -1 , 1, 0, 0 }, dy[4] = { 0, 0, 1 , -1};
int ans = 0;

void fishing(int start) 
{
	for(int i=0; i<R;i++) {
		if(map[i][start] > 0) {
			ans += sh[map[i][start]].z;
			sh[map[i][start]].life = false;
			map[i][start] = 0;
			break;
		} 
	}
	int tmp[100][100] = {0, };
	
	for(int i = 1; i <= M; i++) {
		if( !sh[i].life) continue;
		int ix = sh[i].x, iy = sh[i].y, s = sh[i].s, idir = sh[i].d;
		int nx, ny;
			while (1) {
					nx = ix + s * dx[idir]; ny = iy + s * dy[idir];
					if (nx < R && nx >= 0 && ny < C&& ny >= 0) break;
					if (idir == 0 && nx < 0) { s -= ix; ix = 0; idir = 1; }
					else if (idir == 1 && nx >= R) { s -= R - 1 - ix; ix = R - 1; idir = 0; }
					else if (idir == 2 && ny >= C) { s -= C - 1 - iy; iy = C - 1; idir = 3; }
					else if (idir == 3 && ny < 0) { s -= iy; iy = 0; idir = 2; }
			}
		if(tmp[nx][ny]) {
			if(sh[tmp[nx][ny]].z < sh[i].z ) {
				sh[tmp[nx][ny]].life = false;
				tmp[nx][ny] = i;
			}
			else sh[i].life = false;
		}
		else tmp[nx][ny] = i;
		sh[i].x = nx; sh[i].y = ny; sh[i].d = idir;
	}
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			map[i][j] = tmp[i][j];
		}
	}
}	

int main(void)
{
	scanf("%d %d %d", &R, &C, &M);
	for(int i = 1; i<=M; i++) {
		int a1, a2, a3, a4, a5;
		scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);
		a1--; a2--; a4--;
		sh[i] = Shark(a1,a2,a3,a4,a5);
		sh[i].life = true;
		map[a1][a2] = i;
	}
	int start = 0;
	while( start < C ) {
		fishing(start);
		start++;
	}
	cout<<ans<<'\n';
}
