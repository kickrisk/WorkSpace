#include <iostream>
#include <cstring>
#include<vector>

using namespace std;

int flag = 0;
bool check[2001];
void dfs(vector<int> *a, int start,int n,int m, int cnt) 
{
    check[start] = true;
    if(cnt > m) {
    	return;
    }
    else if(cnt == 4) {
    	flag = 1;
    	return;
    }
    for(int i=0; i< a[start].size(); i++) {
       	if( !check[ a[start][i] ]) {
           	dfs(a,a[start][i],n,m,cnt+1);
       	}
   	}
   	check[start] = false;
}

int main(void)
{
    int n,m;
    cin>>n>>m;
    vector<int> a[n+1];
    
    for(int i=0;i<m;i++) {
        int from, to;
        cin>>from>>to;
    	a[from].push_back(to);
    	a[to].push_back(from);
    }
    for(int i=0; i<n;i++) {
    	if (flag) break;
  // 	memset(check, false, sizeof(check));
    	dfs(a, i, n, m, 0);
    }
    cout<<flag<<'\n';

    return 0;
}
