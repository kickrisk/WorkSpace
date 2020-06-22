#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1000
using namespace std;

int a[MAX];
int d[MAX];
int main(void)
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    for(int i=0; i<n; i++) {
        d[i] = 1;
        for(int j=0; j<i; j++) {
            if(a[j] < a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] +1;    
            }
        }
    }
    sort(d,d+n);
    cout<<d[n-1]<<endl;
    return 0;
}
