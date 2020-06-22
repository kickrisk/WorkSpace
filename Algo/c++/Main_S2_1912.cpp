#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[MAX], d[MAX];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    d[0] = a[0];
    for(int i=1; i<n; i++) {
        d[i] = a[i];
        if(d[i] < d[i-1] + a[i]) {
            d[i] = d[i-1] + a[i];
        }
    }
    sort(d,d+n);
    cout<<d[n-1]<<endl;
    return 0;
}
