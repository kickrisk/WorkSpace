#include <iostream>
#include <vector>
#include <cstring>

#define MAX 1001
using namespace std;
bool check[MAX];
int cnt = 0;

void dfs(vector<int> *a, int num, int c)
{
	check[num] = true;
	for(int i=0; i< a[num].size(); i++) {
		if( !check[ a[num][i] ] ) {
			dfs(a, a[num][i],c);
		}
	}
	cnt = c+1;
}
int main(void)
{
	int n,m;
	cin>>n>>m;
	vector<int> a[n+1];

	for(int i=0; i<m;i++)
	{
		int from,to;
		cin>>from>>to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	memset(check, false, sizeof(check));
	for(int i=1; i<=n; i++) {
		if( !check[i] ) {
			dfs(a,i,cnt);
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
