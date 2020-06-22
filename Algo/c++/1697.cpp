#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001

using namespace std;
int n,k;
int Map[MAX];
queue <int> q;

void Input()
{
	cin>>n>>k;
	memset(Map,-1,sizeof(Map));
	q.push(n);
	Map[n] = 0;
}

void Solution()
{
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		if( x*2 < MAX && Map[x*2] == -1) {
			q.push(x*2);
			Map[x*2] = Map[x] + 1;
		}
		 if( x-1 >= 0  && Map[x-1] == -1) {
			q.push(x-1);
			Map[x-1] = Map[x] + 1;
		}
		if( x+1 < MAX && Map[x+1] == -1) {
			q.push(x+1);
			Map[x+1] = Map[x] + 1;
		}
		if( Map[k] != -1) break;
	}
}

int main(void)
{
	Input();
	Solution();
	cout<<Map[k]<<endl;
	return 0;
}
