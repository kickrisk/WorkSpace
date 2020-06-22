#include <iostream>
#include <deque>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;
int N,K;
deque<int> dq;
int Map[MAX];
void Input()
{
	scanf("%d %d", &N, &K);
	memset(Map,-1,sizeof(Map));
	dq.push_back(N);
	Map[N] = 0;
}
void Solution()
{
	while( !dq.empty() ) {
		int x = dq.front();
		dq.pop_front();
		if( x*2 < MAX && Map[x*2] ==-1 ) {
			dq.push_front(x*2);
			Map[x*2] = Map[x];
		}
		if( x-1 >= 0 && Map[x-1] == -1) {
			dq.push_back(x-1);
			Map[x-1] = Map[x] + 1;
		}
		if( x+1 < MAX && Map[x+1] == -1) {
			dq.push_back(x+1);
			Map[x+1] = Map[x] + 1;
		}	
		if(Map[K] != -1) break;
	}
}

int main(void)
{
	Input();
	Solution();
	pritnf("%d\n",Map[K]);
	return 0;
}
