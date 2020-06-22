#include <iostream>
#define MAX 10001
using namespace std;
int a[MAX];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int l = 0, r =0, ans = 0, sum = a[0];
    while(l<=r && r<n) {
        if(sum < m) {
            r += 1;
            sum += a[r];
        }
        else if(sum == m) {
            ans += 1;
            r += 1;
            sum += a[r];
        }
        else if(sum > m) {
            sum -= a[l];
            l += 1;
            if( l > r && l<n) {
                r =l;
                sum = a[l];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
