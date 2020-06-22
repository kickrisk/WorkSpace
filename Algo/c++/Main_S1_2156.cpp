#include <iostream>
#define MAX 100001
using namespace std;

int a[MAX];
int d[MAX];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    d[0] = a[0] = 0;
    d[1] = a[1]; 
    d[2] = a[1] + a[2];
    for(int i=3; i<=n; i++) {
        d[i] = max(d[i-1],max(d[i-2]+a[i],d[i-3]+a[i-1]+a[i]));
    }
    cout<<d[n]<<endl;
    return 0;
}
