#include <iostream>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int a[55][55];
int main() {
    int n, m;
    cin >> n >> m;
    int x, y, dir;
    cin >> x >> y >> dir;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    while (true) {
        if (a[x][y] == 0) {
            a[x][y] = 2;
        }
        if (a[x+1][y] != 0 && a[x-1][y] != 0 && a[x][y-1] != 0 && a[x][y+1] != 0) {
            if (a[x-dx[dir]][y-dy[dir]] == 1) {
                break;
            } else {            
                x -= dx[dir];
                y -= dy[dir];
            }
        } else {
            dir = (dir + 3) % 4;
            if (a[x+dx[dir]][y+dy[dir]] == 0) {
                x += dx[dir];
                y += dy[dir];
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 2) {
                cnt += 1;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
