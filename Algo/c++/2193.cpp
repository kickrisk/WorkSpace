#include <iostream>
#define MAX 91
using namespace std;

int d[MAX][2];
int n;
int main(void)
{
    cin>>n;
    d[1][0] = 0; d[1][1] = 1;
    for(int i = 2; i<=n; i++) {
        for(int j=0; j<2; j++) {
            if( j == 1) {
                d[i][j] = d[i-1][0];
            }
            else {
                d[i][j] = d[i-1][0] + d[i-1][1];
            }
        }
    }
    int ans = d[n][0] + d[n][1];
    cout<<ans<<endl;
}
