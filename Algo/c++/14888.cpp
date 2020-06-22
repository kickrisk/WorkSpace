#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) 
{
    int n;
    long long int max = -9876543210, min = 9876543210;
    cin>>n;
    vector<int> a(n);
    int b[4] = {0};
    
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<4;i++) {
        cin>>b[i];
    }
    vector<int> c;
    for(int i=0;i<4;i++) {
        for(int j=0;j<b[i];j++) {
            c.push_back(i+1);
        }
    }
    do {
        vector<int> d(c);
	long long int temp;
	temp = a[0];
        for(int i=0;i<n-1;i++) {
            if( d.back() == 4) { temp = temp / a[i+1];  d.pop_back(); }
            else if( d.back() == 3) { temp = temp * a[i+1]; d.pop_back(); }
            else if( d.back() == 2) { temp = temp - a[i+1]; d.pop_back(); }
            else if( d.back() == 1) { temp = temp + a[i+1]; d.pop_back(); }   
        }
        if(max < temp) max = temp;
        if( min > temp) min = temp;
    }
    while(next_permutation(c.begin(),c.end()));
    cout<<max<<'\n'<<min<<'\n';
    return 0;
}
