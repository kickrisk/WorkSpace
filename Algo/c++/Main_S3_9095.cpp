#include <iostream>
using namespace std;
int ans=0;
void cal(int a)
{
    if (a < 0) return;
    else if(a == 1) ans+=1;
    else if (a == 2) ans+=2;
    else if (a == 3) ans+=4;
    else {
        cal(a-1); cal(a-2); cal(a-3);
    }
}
int main(void)
{
    int t;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++) {
        cin>>a[i];
    }
    for(int i=0; i<t;i++) {
        ans = 0;
        cal(a[i]);
        cout<<ans<<'\n';
    }
    return 0;
}
