#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int a[8][8];
int main()
{
	int n,m;
	cin>>n>>m;
	queue<pair<int, pair<int, int> > > q;
	int p = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m;j++) {
			cin>>a[i][j];
			if(a[i][j] != 6 && a[i][j] != 0) {
				q.push(make_pair(a[i][j],make_pair(p++,make_pair(i,j))));
			}
		}
	}
	int ans = -1;
	queue<pair<int, pair<int, int> > > q1(q);
	while( !q.empty() ) {
		int num = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
	}
}
