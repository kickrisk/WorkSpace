#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int a[101][101];
int check[101];    // 1- 10 is stair size, 11 => already set slope
int cnt = 0;

bool set_slope_x(int t, int l, int n, int start, int end)
{
	int num =0;
	if(start < 0 || end > n) return false;
	for(int i=start; i <= end; i++) {
		if(check[i])  return false;
		if (a[t][start] == a[t][i])
			num++;
	}
	if(num == l) {
		for(int i=start;i<=end;i++) 
			check[i] = true;
		return true;
	}
	else {
		return false;
	}
}

bool set_slope_y(int t, int l, int n, int start, int end)
{
	int num=0;
	if(start < 0 || end > n) {
		return false;
	}
	for(int i=start; i <= end; i++) {
		if(check[i])  return false;
		if(a[start][t] == a[i][t])
			num++;
	}
	if(num == l) {
		for(int i=start;i<=end;i++) 
			check[i] = true;
		return true;
	}
	else {
		return false;
	}
}

void path_find_x(int n, int l)
{
	bool ok = true;

	for(int i=0;i<n;i++) {
		ok = true;
		memset(check,false,sizeof(check));
		for(int j=0;j<n-1;j++) {
			if(ok == false) break;
			
			if(a[i][j] == a[i][j+1]) { 
				continue;
			}
			else if(a[i][j] - a[i][j+1] == -1) {
						ok = set_slope_x(i,l, n, j-l+1, j);
			}
			else if(a[i][j]-a[i][j+1] == 1) {
					ok = set_slope_x(i,l,n, j+1, j+l);
			}
			else {
				ok = false;
			}
		}
		if(ok) {
	 		cnt++;
	 		cout<<i+1<<"row is possible"<<'\n'; 
		}
	}
}

void path_find_y(int n, int l)
{
	bool ok = true;

	for(int i=0;i<n;i++) {
		ok = true;
		memset(check,false,sizeof(check));
		for(int j=0;j<n-1;j++) {
			if(ok == false) break;
			
			if(a[j][i] == a[j+1][i]) { 
				continue;
			}
			else if(a[j][i] - a[j+1][i] == -1) {
						ok = set_slope_y(i,l, n, j-l+1, j);
			}
			else if(a[j][i]-a[j+1][i] == 1) {
					ok = set_slope_y(i,l,n, j+1, j+l);
			}
			else ok = false;
		}
		if(ok) {
			cnt++;
			cout<<i+1<<"column is possible"<<'\n'; 
		}
	}
}

int main(void)
{
	int n,l;
	cin>>n>>l;
	for(int i=0; i<n;i++) {
		for(int j=0;j<n;j++) {
		cin>>a[i][j];
		}
	}
	path_find_x(n, l);
	path_find_y(n, l);
	cout<<cnt<<'\n';
	return 0;
}
