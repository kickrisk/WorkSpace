#include <iostream>
#define max(a,b) (((a)>(b))?(a):(b))
#define MAX 100001
using namespace std;
long long a[MAX][2];
long long d[MAX][3];
int main(void)
{    
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        cin>>n;
        for(int i=0; i<2; i++) {
            for(int j=1;j<=n; j++) {
                scanf("%lld",&a[j][i]);
            }
        }
        d[0][0] = d[0][1] = d[0][2] = 0;
        for(int i=1; i<=n; i++) {    
            d[i][0] = max(d[i-1][0],max(d[i-1][1],d[i-1][2]));
            d[i][1] = a[i][0] + max(d[i-1][0],d[i-1][2]);         
            d[i][2] = a[i][1] + max(d[i-1][0],d[i-1][1]); 
        }
        long long ans =  0;
        for (int i=1; i<=n; i++) {
            ans = max(max(ans,d[i][0]),max(d[i][1],d[i][2]));
        }
        cout<<ans<<endl;
    }
    return 0;
}
