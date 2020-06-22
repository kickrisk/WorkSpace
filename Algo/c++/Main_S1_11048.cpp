#include <iostream>
#define MAX 1001
using namespace std;

int main()
{
    int d[MAX][MAX];
    int a[MAX][MAX];
    int n,m, Ans = 0;
    cin>>n>>m;
    for(int i=1; i<=n;i++) {
        for(int j=1; j<=m;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m;j++) {
            d[i][j] = max(d[i-1][j],max(d[i][j-1],d[i-1][j-1])) + a[i][j];
        }
    }
    cout<<d[n][m]<<endl;
}
