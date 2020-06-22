#include <iostream>
#define MAX 100001
using namespace std;
int main()
{
    int n;
    cin>>n;
    int d[MAX];
    for(int i=1; i<=n;i++) {
        d[i] = i;
        for(int j=1; j*j <= i; j++) {
            if(d[i] > d[i-j*j] +1) {
                d[i] = d[i-j*j] + 1;
            }
        }
    }
    cout<<d[n]<<endl;
}
