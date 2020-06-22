#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001

using namespace std;
int n,k;
pair<int, int> Map[MAX];
queue <int>q;

void Input()
{
	cin>>n>>k;
	memset(Map,-1,sizeof(Map));
	q.push(n);
	Map[n] = make_pair(0,-1);
}
void go (int k)
{
	if( k == -1) 	return;
	go(Map[k].second);
	cout<<k<<' ';
}

void Solution()
{
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		if( x*2 < MAX && Map[x*2].first == -1) {
			q.push(x*2);
			Map[x*2].first = Map[x].first + 1;
			Map[x*2].second = x;
		}
		 if( x-1 >= 0  && Map[x-1].first == -1) {
			q.push(x-1);
			Map[x-1].first = Map[x].first + 1;
			Map[x-1].second = x;
		}
		if( x+1 < MAX && Map[x+1].first == -1) {
			q.push(x+1);
			Map[x+1].first = Map[x].first + 1;
			Map[x+1].second = x;
		}
		if( Map[k].first != -1) break;
	}
}

int main(void)
{
	Input();
	Solution();
	cout<<Map[k].first<<endl;
	go(k);
	cout<<endl;
	return 0;
}
