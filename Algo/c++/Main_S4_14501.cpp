#include <iostream>

using namespace std;

int t[21];
int p[21];
int n=0;
int ans=0;

void go(int num, int sum)
{
    if(num==n+1) {
        if(ans<sum) ans =sum;
        return;
    }
    if(num>n+1) return;
    go(num+t[num],sum+p[num]);
    go(num+1,sum);
 
}
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>t[i]>>p[i];
    }
    go(1,0);
    cout<<ans<<'\n';
    return 0;
}
