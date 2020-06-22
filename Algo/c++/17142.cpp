#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#pragma warning (disable : 4018)
#pragma warning (disable : 4996)
#define endl "\n"
#define MAX 987654321
using namespace std;

int Map[50][50];
int Time[50][50];

int N, M, Answer = MAX;
int virus = 0; int Empty_Place = 0;
int dx[4] = { -1,   1,   0,   0}; int dy[4] = { 0,   0,   -1,   1};
pair<int, int> pos[10];


int Min(int a, int b) { if( a<b) return a; return b; }

void Spread_Virus(queue<pair<int, int> > Q)
{
    int Infect_Place = 0;
    int Total_Time = 0;
    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if (Map[nx][ny] != 1 && Time[nx][ny] == -1)
                {
                    Time[nx][ny] = Time[x][y] + 1;
                    if (Map[nx][ny] == 0)
                    {
                        Infect_Place++;
                        Total_Time = Time[nx][ny];
                    }
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
    if (Infect_Place == Empty_Place)
    {
        Answer = Min(Answer, Total_Time);
    }
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	int temp =0;
	for(int i=0; i < N; i++) {
		for(int j=0; j < N; j++) {
			cin>>Map[i][j];
			if( Map[i][j] == 2) {
			 	pos[temp++] = make_pair(i,j); virus++;
			 }
			 else if( Map[i][j] == 0) Empty_Place++;
		}
	}
	vector<int> v;
	for(int i=0; i < virus - M; i++) {
		v.push_back(0);
	}
	for(int i=0; i<M; i++) {
		v.push_back(1);
	}
	int s = 1;
	do {
		queue<pair<int, int > > Q;
		memset(Time, -1, sizeof(Time));
		for(int i=0; i<virus; i++) {
			if(v[i] == 1) {
				Q.push(make_pair(pos[i].first,pos[i].second));
				Time[pos[i].first][pos[i].second] = 0;
			}
		}
		Spread_Virus(Q);
	} while(next_permutation(v.begin(), v.end()));
	
	if(Answer == MAX) cout<<-1<<endl;
	else cout<<Answer<<endl;
	
	return 0;
}
