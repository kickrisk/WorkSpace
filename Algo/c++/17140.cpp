#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define endl "\n"
#pragma warning (disable : 4018)
#pragma warning (disable : 4996)

using namespace std;

int map[100][100];
int r, c, k;
int cnt = 0;
/*void printing(int a, int b)
{
	cout<<"====================================="<<endl;
	for(int i=0; i<a; i++) {
		for(int j=0; j<b; j++) {
			cout<<map[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<"====================================="<<endl;
}

void printing_2(int *a, int line)
{
	cout<<"====================================="<<endl;
	for(int i=0; i<line; i++) {
		cout<<a[i]<<' ';
	}
	cout<<endl;
	cout<<"====================================="<<endl;
}*/
int Max(int a, int b) { if(a>b) return a; return b; }
int Raw(int raw, int line) 
{
	int size = 1;
	int copy[100];
	queue<int > temp[101];
	for(int i=0;i<line;i++) {
		copy[i] = map[raw][i];
		map[raw][i] = 0;
	}
	sort(copy,copy+line);
	for(int i=0;i<line;i++) {
		if(copy[i] == 0) continue;
		if(copy[i] == copy[i+1]) {
			if(i+1 == line) {
				temp[size].push(copy[i]);
			}
			size++;
		}
		else {
			temp[size].push(copy[i]);
			size = 1;
		}
	}
	size = 0;
	for(int i=0; i<100; i++) {
		if(size == 100) break;
		else {
			while( !temp[i+1].empty()) {
				if(size == 100) break;
				int a = temp[i+1].front();
				temp[i+1].pop();
				copy[size++] = a;
				if(size == 100) break;
				copy[size++] = i+1;
			}
		}	
	}
	for(int i=0;i<size;i++) {
		map[raw][i] = copy[i];
	}
	return size;
}
int Column(int col, int line) 
{
	int size = 1;
	int copy[100];
	queue<int> temp[101];
	for(int i=0;i<line;i++) {
		copy[i] = map[i][col];
		map[i][col] =0;
	}
	sort(copy,copy+line);
	for(int i=0;i<line;i++) {
		if(copy[i] == 0) continue;
		if(copy[i] == copy[i+1]) {
			if(i+1 == line) {
				temp[size].push(copy[i]);
			}
			size++;
		}
		else {
			temp[size].push(copy[i]);
			size = 1;
		}
	}
	size = 0;
	for(int i=0; i<100; i++) {
		if(size == 100) break;
		else {
			while(!temp[i+1].empty()) {
				int a = temp[i+1].front();
				temp[i+1].pop();
				copy[size++] = a;
				if(size == 100) break;
				copy[size++] = i+1;
			}
		}
	}
	for(int i=0;i<size;i++) {
		map[i][col] = copy[i];
	}
	return size;
}

int main(void)
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>r>>c>>k;
    for(int i=0; i<3; i++) {
    	for(int j=0; j<3; j++) {
    		cin>>map[i][j];
    	}	
    }
    bool ok = false;
    int raw = 3; int col = 3;
   while(cnt<=100)
    {
//    	cout<<"====================================="<<endl;
 //   	cout<<cnt<<endl;
//    	printing(raw,col);
		if(map[r-1][c-1] == k) {
    		ok = true; break;
    	}
    	if( raw >= col ) {
    		int line = Max(raw,col);
    		for(int i=0; i<raw; i++) {
    			int tu = Raw(i,line);
    			col = Max(tu, col);
    		}
//    		printing(raw,col);
    	}
    	else {
    		int line = Max(raw,col);
    		for(int i=0; i<col; i++) {
    			int tu = Column(i,Max(raw,col));
    			raw = Max(raw,tu);
    		}
//    		printing(raw,col);
		}
		
    	cnt++;
    }
    if(ok) cout<<cnt<<endl;
    else cout<<-1<<endl;
}
