#include <iostream>
#include <algorithm>
using namespace std;
bool check_next(int *a,int n) {
    int i=n-1;
    while(i>0 && a[i] <= a[i-1]) i -=1;
    if(i<=0) return false;
    int j=n-1;
    while(a[j]<=a[i-1]) j-=1;
	swap(a[i-1],a[j]); 
    j= n-1;
    while(i<j) {
        swap(a[i],a[j]);
        i +=1; j-=1;
    }
    return true;
}
int main(void)
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    if(check_next(a,n)) {
        for(int i=0;i<n;i++) {
        		cout<<a[i]<<" ";
    		} 
    }
   else { 
		cout<<"-1";
    }
    cout<<'\n';
    return 0;
}
