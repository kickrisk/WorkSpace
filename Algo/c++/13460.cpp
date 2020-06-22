#include <iostream>
#include <cmath>
#pragma warning (disable : 4018)
#pragma warning (disable : 4996)
#define endl "\n"
using namespace std;

char map[10][10];
int dx[4] = { 0, 0, 1 , -1}; 
int dy[4] = { 1, -1, 0, 0 };
int ans = 987654321;
int N,M;
pair<int, int> Red, Blue;

int Min(int a, int b) { if(a>b) return b; return a;}
void Input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>map[i][j];
            if(map[i][j] == 'R') {
            	Red.first = i;
            	Red.second = j;
            	map[i][j] = '.';
            }
            else if(map[i][j] == 'B') {
            	Blue.first = i;
            	Blue.second = j;
            	map[i][j] = '.';
            }
        }
    }
}
int Compare_Move(int x, int y, int xx, int yy) 
{
    return abs(x-xx) + abs(y-yy);
}
int Reverse_Direction(int cur)
{
    if(cur == 0) return 1;
    else if(cur == 1) return 0;
    else if(cur == 2) return 3;
    else if(cur == 3)  return 2;
}
void Move_Bead(int Rx, int Ry, int Bx, int By, int cnt, int dir)
{
    if(cnt >= ans)  return;
    if(cnt > 10)    return;
    
    bool Red_Flag = false;
    bool Blue_Flag = false;
    
    int nRx = Rx + dx[dir];
    int nRy = Ry + dy[dir];
    
    while(1) {
        if(map[nRx][nRy] == '#') break;
        if(map[nRx][nRy] == 'O') {
            Red_Flag = true;
            break;
        }
        nRx = Rx + dx[dir];
        nRy = Ry + dy[dir];
    }
    nRx = nRx - dx[dir];
    nRy = nRy - dy[dir];        // Red bead is moving
    
    int nBx = Bx + dx[dir];
    int nBy = By + dy[dir];
    
    while(1) {
        if(map[nBx][nBy] == '#') break;
        if(map[nBx][nBy] == 'O') {
            Blue_Flag = true;
            break;
        }
        nBx = Bx + dx[dir];
        nBy = By + dy[dir];
    }
    nBx = Bx - dx[dir];
    nBy = By - dy[dir];            //Blue bead is moving
    
    if(Blue_Flag == true) return;
    else {
        if(Red_Flag == true) {
            ans = Min(ans,cnt);
            return;
        }
    }                                // Checking if the beads fell into the hole!
    
    if(nRx == nBx && nRy == nBy) {
        int mR = Compare_Move(Rx,Ry,nRx,nRy);
        int mB = Compare_Move(Bx,By,nBx,nBy);
        if(mR > mB) {
            nRx = nRx - dx[dir];
            nRy = nRy - dy[dir];
        }
        else {
            nBx = nBx - dx[dir];
            nBy = nBy - dy[dir];
        }
    }                                    // Make sure the beads are in the same position!
    
    for(int i=0; i<4; i++) {
        if(i == dir) continue;
        if(i == Reverse_Direction(dir)) continue;
        Move_Bead(nRx,nRy,nBx,nBy,cnt+1,i);
    }                                    // if bead can't go current direct, then change it's direction
}
void Solution(void)
{    
    for(int i=0; i<4; i++) {
        int x = Red.first; int y = Red.second;
        int xx = Blue.first; int yy = Blue.second;
        Move_Bead(x,y,xx,yy,1,i);
    }
    if(ans > 10) cout<<-1<<endl;
    else cout<<ans<<endl;
}

void Solve(void)
{
    Input();
    Solution();   
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Solve();
    
    return 0;
}
