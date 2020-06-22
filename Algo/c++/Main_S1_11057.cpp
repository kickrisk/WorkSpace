#include <iostream>
#define MAX 1001
#define mod 10007
using namespace std;
int d[MAX][11];
int n;

int main(void)
{
    cin>>n;
    for(int i=0; i<=9; i++) d[1][i] = 1;
    for(int i=2; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            for(int k=0; k<=j; k++) {
                d[i][j] += d[i-1][k];
                d[i][j] %= mod;
            }
        }
    }
    long long ans = 0;
    for ( int i=0; i<=9;i++) ans += d[n][i];
    ans %= mod;
    cout<<ans<<endl;
}
