#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
queue<pair<int, int> > q;
void hanoi(int n, int from, int by, int to){
    if (n == 1)
       cout<<from<<' '<<to<<endl;
    else{
        hanoi(n - 1, from, to, by);    
        cout<<from<<' '<<to<<endl;
        hanoi(n - 1, by, from, to);    
    }
}
int main()
{
	int n; 
	cin>>n;
	int a = 1;
	for(int i=1; i<=n; i++) {
		a *= 2;
	}
	cout<<a-1<<endl;
	hanoi(n,1,2,3);
	return 0;
}
