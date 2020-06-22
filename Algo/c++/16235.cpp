#include <stdio.h>
#include <queue>
#include <deque>
using namespace std;

int n, m, k, ret;
int map[11][11];
int feed[11][11];
const int dx[] = { 1,1,1,0,-1,-1,-1,0 };
const int dy[] = { -1,0,1,1,1,0,-1,-1 };
deque<int> alive[11][11];
queue<int> dead[11][11];

int main(void)
{
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = 5;
			scanf("%d", &feed[i][j]);
		}
	for (int i = 0; i < m; i++)
	{
		int y, x, years;
		scanf("%d %d %d", &y, &x, &years);
		alive[y][x].push_back(years);
	}
	while (k--)
	{
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int len = alive[i][j].size();
				for (int k = 0; k < len; k++) {
					int cur = alive[i][j].front(); alive[i][j].pop_front();
					if (map[i][j] >= cur) {
						alive[i][j].push_back(cur + 1);
						map[i][j] -= cur;
					} 
					else {
						dead[i][j].push(cur);
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				while (!dead[i][j].empty()) {
					int cur = dead[i][j].front(); dead[i][j].pop();
					map[i][j] += cur / 2;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int len = alive[i][j].size();
				for (int k = 0; k < len; k++)
				{
					if (alive[i][j][k] % 5 == 0) {
						for (int dir = 0; dir < 8; dir++)
						{
							int nx = j + dx[dir];
							int ny = i + dy[dir];
							if (nx <1 || ny <1 || nx >n || ny >n)
								continue;
							alive[ny][nx].push_front(1);
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				map[i][j] += feed[i][j];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ret += alive[i][j].size();
	printf("%d\n", ret);
	return 0;
}
