#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1000001

using namespace std;

int Map[MAX];
bool Check[MAX];
queue<int> q;
int n;
int Min(int a, int b) { if( a<=b) return a; return b; }
void printing()
{
	cout<<"[";
	for(int i=1; i<=n; i++) {
		cout<<Map[i]<<' '; 
	}
	cout<<"]"<<endl;
}
void Input()
{
	cin>>n;
	memset(Check,false,sizeof(Check));
	Map[1] = 0;
	Map[2] = 1;
	Map[3] = 1;
}


void Solution()
{
	q.push(n);
	Check[n] = true;
	while( !q.empty()) {
		int x = q.front();
		int xx = q.front();
//		cout<<'('<<x<<','<<Map[x]<<')'<<endl;
//		printing();
		q.pop();
		if( x < 1 ) break;
		if( Check[x-1] == false) {
			q.push(x-1);
			Map[x-1] = Map[x] + 1;
			Check[x-1] = true;
		}
		if( x%3 == 0 && x/3 > 1 ) {
			if( Check[x/3] == false) {
				q.push(x/3);
				Map[x/3] = Map[x] + 1;
				Check[x/3] = true;
			}
			else{
				if( Map[x] +1 < Map[x/3]) {
					Map[x/3] = Map[x] +1;
					q.push(x/3);
				}
			}
		}
		if( xx%2 == 0 && xx/2 > 1) {
			if (Check[xx/2] == false) {
				q.push(xx/2);
				Map[xx/2] = Map[x] + 1;
				Check[xx/2] = true;
			}
			else {
				if( Map[xx] +1 < Map[xx/2]) {
					Map[xx/2] = Map[xx] +1;
					q.push(xx/2);
				}
			}
		}	
	}
}
void Solve()
{
	Input();
	Solution();
	//printing();
	if(n <4) {
		cout<<Map[n]<<endl;
		return;
	}
	if( Map[2] != 1 && Map[3] != 1) {
		int ans = Min(Map[2], Map[3]);
		cout<<ans+1<<endl;
		return;
	}
	else if (Map[2] == 1 && Map[3] == 1) {
		cout<<Map[2] + 1<<endl;
	}
	else if ( Map[2] != 1 || Map[3] != 1 ) {
		int ans;
		if(Map[2] == 1)  ans = Map[3] + 1;
		else ans = Map[2] + 1;
		cout<<ans<<endl;
	}
}
int main(void)
{
	Solve();
	return 0;
}
