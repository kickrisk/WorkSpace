#include <iostream>
#include <cstring>
#define MAX 10001
using namespace std;

int d[MAX];
int a[MAX];
int n;
int Min(int a, int b) { if ( a < b) return a; return b;}
void go()
{
    memset(d,MAX*MAX,sizeof(d));
    d[0] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            d[i] = Min(d[i],d[i-j]+a[j]);
        }
    }
}
int main(void)
{
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    go();
    cout<<d[n]<<endl;
}
