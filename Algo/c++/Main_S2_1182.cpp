#include <iostream>
#include <vector>

using namespace std;
int ans =0;
void check(vector<int> a, int index, int s,int sum)
{

    if(index==a.size()) {
	if(sum == s) {
	    ans+=1;
	}
	return;
    }
    check(a,index+1,s,sum+a[index]);
    check(a,index+1,s,sum);
} 
int main(void)
{
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    check(a,0,s,0);
    if(s==0) ans-=1;
    cout<<ans<<'\n';
    return 0;
}
