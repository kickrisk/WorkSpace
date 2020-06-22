#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;

int main(void)
{
    int a[MAX], d[MAX];
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    for(int i=0; i<n; i++) {
        d[i] = a[i];
        for(int j=0; j<i; j++) {
            if( a[j] < a[i] && d[i] < d[j] + a[i]) {
                d[i] = d[j] + a[i];
            }
        }
    }
    sort(d,d+n);
    cout<<d[n-1]<<endl;
    return 0;
}
