#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#pragma warning (disable : 4018)
#pragma warning (disable : 4996)
#define endl "\n"
#define MAX 20
using namespace std;

int Answer = 0;
int N, ans = 0;

int Map[MAX][MAX];
int Map_Copy[MAX][MAX];

bool Check[MAX][MAX];
int dx[4] = { 0, 0, -1 , 1}; 
int dy[4] = { -1, 1, 0 , 0};
int Sel[5] = { 0 };

vector<pair<int, int> > v, temp, real;
int Max(int a, int b) { if( a >= b) return a; return b;}
int Find_Max()
{
	int Op = 0;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			Op = Max( Map_Copy[i][j], Op);
		}
	}
	return Op;
}
void printing ()
{
	cout<<"=============================================="<<endl;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cout<<Map_Copy[i][j]<<' ';
		}
	cout<<endl;
	}
	cout<<"=============================================="<<endl;
}
bool Cmp3( const pair<int, int> &a, const pair<int, int> &b) 
{
	return a.first < b.first;
}
bool Cmp1( const pair<int, int> &a, const pair<int, int> &b) 
{
	return a.second < b.second;
}
bool Cmp2( const pair<int, int> &a, const pair<int, int> &b) 
{
	return a.first > b.first;
}
bool Cmp0( const pair<int, int> &a, const pair<int, int> &b) 
{
	return a.second > b.second;
}

void Input() 
{
	cin>>N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin>>Map[i][j];
			if(Map[i][j] != 0) v.push_back(make_pair(i,j));
		}
	}
}

void Move (int x, int y, int dir)
{
	int nx = x;
	int ny = y;
	while(1)
	 {
	 	int Prev_nx = nx; 
		int Prev_ny = ny;
	 	nx = nx + dx[dir];		
	 	ny = ny + dy[dir];
	 	
	 	real.push_back(make_pair(Prev_nx,Prev_ny));
	 		 
	 	if( nx < 0 || ny <0 || nx >= N || ny >= N )		return;

	 	if(Map_Copy[nx][ny] == 0) 
	 	{	
	 		real.pop_back();
	 		Map_Copy[nx][ny] = Map_Copy[Prev_nx][Prev_ny];
	 		Map_Copy[Prev_nx][Prev_ny] = 0;	
	 		continue;
	 	}
	 		
	 	if( Map_Copy[Prev_nx][Prev_ny] == Map_Copy[nx][ny]) 
	 	{
	 		if( !Check[nx][ny] ) 
	 		{
	 			Map_Copy[nx][ny] = Map_Copy[Prev_nx][Prev_ny] + Map_Copy[nx][ny];
	 			Map_Copy[Prev_nx][Prev_ny] = 0; 
	 			real.pop_back();
	 			Check[nx][ny] = true; 
	 			return;
		 	} 
		 }
	 }
}
void Combination(vector<pair<int, int> > temp, int j)
{
	while( !temp.empty() )
			{
				int x = temp.back().first;
				int y = temp.back().second;
				temp.pop_back();
				Move(x,y,j);
			}
}

void Left(vector<pair<int, int> > bu, int j)
{
		real.clear();
		temp = bu;
		memset(Check,false,sizeof(Check));
		sort(temp.begin(),temp.end(),Cmp0);
//		cout<<"==================Left========================"<<endl;
		Combination(temp, j);
}
void Right(vector<pair<int, int> > bu, int j)
{
	real.clear();
	temp = bu;
	memset(Check,false,sizeof(Check));
	sort(temp.begin(),temp.end(),Cmp1);
//	cout<<"==================Right========================"<<endl;
	Combination(temp, j);
}	
void Up(vector<pair<int, int> > bu, int j)
{
	real.clear();
	temp = bu;
	memset(Check,false,sizeof(Check));
	sort(temp.begin(),temp.end(),Cmp2);
//	cout<<"==================UP========================"<<endl;
	Combination(temp, j);
}
void Down(vector<pair<int, int> > bu, int j)
{
	real.clear();
	temp = bu;
	memset(Check,false,sizeof(Check));
	sort(temp.begin(),temp.end(),Cmp3);
//	cout<<"==================Down========================"<<endl;
	Combination(temp, j);
}
void Play()
{
	real = v;
	for(int i=0; i<5; i++)
	{
		int dir = Sel[i];
		if(dir == 0) Left(real,0);
		else if(dir == 1) Right(real,1);
		else if(dir == 2) Up(real,2);
		else Down(real,3);
	}
}
void Selction(int Idx, int cnt)
{
	if(cnt == 5) 
	{
		Play();
		return;
	}
	for(int i=0; i<4; i++) 
	{
		Sel[cnt] = i;
		Selction(i,cnt+1);
	}
}
void Solution()
{
	Selction(0,0);
	Answer = Max(Answer, Find_Max());
	cout<<Answer<<endl;
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
