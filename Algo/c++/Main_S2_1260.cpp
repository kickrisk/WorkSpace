#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 1001

using namespace std;

bool check[MAX];

void bfs(vector<int> *a, int num)
{
	queue<int> q; 
	check[num] = true;		q.push(num);
	while(!q.empty()) 
	{
		int x = q.front(); q.pop();
		printf("%d ", x);
		for(int i=0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if(!check[y]) {
				check[y] = true; q.push(y);	
			}
		}
	}
}

void dfs(vector<int> *a, int num)
{
	check[num] = true;
	printf("%d ", num);
	for(int i=0; i < a[num].size(); i++) {
		int y = a[num][i];
		if(!check[y]) {
			dfs(a,y);
		}
	}
}

int main(void) 
{
	int n,m,v;
	cin>>n>>m>>v;
	vector<int> a[n+1];
	
	for(int i=0; i<m;i++) {
		int from, to;
		cin>>from>>to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	
		for(int i=1; i<=n; i++) {
			sort(a[i].begin(),a[i].end());
		}
	
	dfs(a,v);
	cout<<'\n';
	memset(check,false,sizeof(check));
	bfs(a,v);
	cout<<'\n';
}
