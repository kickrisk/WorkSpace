#include <iostream>
#include <cmath>
using namespace std;
int ans, n, m, len, c;
bool broken[10];
int possible(int c)
{
    if( c == 0 ) {
        return broken[c] ? 0 : 1;
    }
    len = 0;
    while(c > 0) {
        if( broken[c % 10] == true) return 0;
        len += 1;
        c /= 10;
    }
    return len;
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++) {
        int k;
        cin>>k;
        broken[k] = true;
    }
    ans = abs(n-100);
    for(int i=0; i<= 1000000; i++) {
        int c = i;
        if(possible(c)) {
            int press = abs(n-c);
             if( ans > press + len) {
                 ans = press + len;
             }
        }
    }
    cout<<ans<<endl;
    return 0;
}   
