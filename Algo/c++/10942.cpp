#include <iostream>
#include <vector>
#include <cstring>
#define MAX 2000
using namespace std;
int d[MAX][MAX];
int a[MAX];
int go( int s, int e) 
{
    if( s == e ) {
    	return 1;
    }	else if ( e-s == 1) {
    		if(a[s] == a[e] ) return 1;
    		else return 0;
    }
    if(d[s][e] != -1) {
    	return d[s][e];
    }
    if(a[s] != a[e])  {
    	return d[s][e] = 0;
    }	else {
    	return d[s][e] = go(s+1,e-1);
    }
}
int main()
{
    int n,m;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[n];
    }
    cin>>m;
    while(m--) {
        int s, e;
        cin>>s>>e;
        memset(d,-1,sizeof(d));
        int ok = go(s - 1 , e -1);
        cout<<ok<<endl;
    }
}
