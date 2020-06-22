#include <iostream>
using namespace std;
int gcd(int a,int b){
	if( b ==0)
		return a;
	return gcd(b, a %b);
}
int main (){
	int t;
	cin >> t;
	while(t--)
	{
		int n; 
        long long sum = 0;
		cin >> n;
		int ary[n];
		for(int i = 0; i < n ; i ++){
			cin >> ary[i];
		}
		for(int i = 0; i < n-1; i ++){
			for(int j = i+1; j < n ; j ++)
			 	sum += gcd(ary[i],ary[j]);
		}
		cout << sum << endl;
	}
}
