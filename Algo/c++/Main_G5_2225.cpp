#include <iostream>
#define MAX 201
using namespace std;
long long MOD = 1000000000;
long long d[MAX][MAX];
int main(void)
{
    int n,k;
    cin>>n>>k;
    d[0][0] = 1LL;
    for(int i=1; i<=k; i++) {
        for(int j=0; j<=n; j++) {
            for(int l=0; l<=j; l++) {
                d[i][j] += d[i-1][j-l];
                d[i][j] %= MOD;
            }
        }
    }
    cout<<d[k][n]<<endl;
    return 0;
}
