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
int fac(int n) {
    if(n<=1) return 1;
    return n*fac(n-1);
}
int main(void)
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        a[i] = i+1;
    }
    int num = fac(n)+1;
    while(num--) {
		if(num == fac(n)) {
            for(int i=0;i<n;i++) {
        		    cout<<a[i]<<" ";
    		    }  
			cout<<'\n';   
		}    
		if(check_next(a,n)) {
            for(int i=0;i<n;i++) {
        		    cout<<a[i]<<" ";
    		    } 
            cout<<'\n';
        }
	}
    return 0;
}
