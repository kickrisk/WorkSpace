#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#pragma warning (disable : 4996)
#pragma warning (disable : 4251)
#pragma warning (disable : 4018)

using namespace std;

int s[20][20];
int n;	
int ans = 1234567890;
int temp1 = 0; 
int temp2 = 0;

vector<int> a;
vector<int> b;
vector<int> cur;
vector<int> start, link;

int main(void)
{
	cin>>n;
	int p = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>s[i][j];
			cur.push_back(p++);
		}
	}
	
	for(int i=0; i<n/2; i++) {
		a.push_back(0);
		if( i < (n/2 - 2) ) {
			b.push_back(0);
		}
	}
	for(int i=0; i<n/2; i++) {
		a.push_back(1);
		if( i < 2) {
			b.push_back(1);
		}
	}
	do {
		temp1 = 0; temp2 = 0;
		start.clear();	link.clear();
		for(int i=0; i<n; i++) {
			if(a[i] == 1) {
				start.push_back(i);
			}
			else {
				link.push_back(i);
			}
		}
		do {
			int k1 = 0; int k2 =0;
			int arr1[2]; int arr2[2];
			for(int i=0; i<n/2; i++) {
				if(b[i] == 1) {
					arr1[k1++] = start[i];
					arr2[k2++] = link[i];
				}
			}
			temp1 = temp1 +  s[arr1[0]][arr1[1]] + s[arr1[1]][arr1[0]];
			temp2 = temp2 +  s[arr2[0]][arr2[1]] + s[arr2[1]][arr2[0]];
		} while ( next_permutation( b.begin(), b.end() ) );
		if(ans>abs(temp1 - temp2)) {
			ans = abs(temp1 - temp2);
		}
	} while( next_permutation(a.begin(), a.end() ));
	cout<<ans<<'\n';
}
