#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    while(true) {
        int k;
        cin>>k;
   	    if(k == 0) break;
   	    vector<int> s(k);
    		for(int i=0;i<k;i++) {
        		cin>>s[i];
   	 	}    
    		int a[k];
    		for(int i=0;i<6;i++) {
        		a[i] = 1;
    		}
    		for(int i=6;i<k;i++) {
        		a[i] = 0;
    		}
    		sort(a,a+k,greater<int>());
    		do {
       	 	for(int i=0;i<k;i++) {
	    			if(a[i] == 1) cout<<s[i]<<' ';
			}
			cout<<'\n';
    		} while(prev_permutation(a,a+k)); 
    		cout<<'\n';
    }
    return 0;
}
