#include <iostream>
using namespace std;
long long n;
long long ans;
int Long(long long c) 
{
     int len = 1;
    while(c/10 > 0) {
        len+=1;
        c /= 10;
    }
    return len;
}
int main(void)
{
    cin>>n;
    int len = Long(n);
    long long temp = 1;
    if(len == 1) temp = 0;
    for(int i=1; i<len; i++) {
        temp *= 10;
        if(i == 1) {
            ans += 9; continue;
        }
        ans += 9*(len-1)*10;
    }
    ans += (n-temp+1)*len;
    cout<<ans<<endl;
    return 0;
}
