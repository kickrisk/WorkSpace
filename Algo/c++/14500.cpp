#include <iostream>
using namespace std;

int block[19][3][2] = {
    {{0,1},{0,2},{0,3}},//
    {{1,0},{2,0},{3,0}},//
    
    {{0,1,},{1,0},{1,1}},//
    
    {{1,0},{2,0},{2,1}},//
    {{1,0},{2,0},{2,-1}},//
    {{0,1},{0,2},{1,0}},//
    {{1,0},{1,1},{1,2}},//
    {{0,1},{0,2},{1,2}},//
    {{0,1},{0,2},{-1,2}},//
    {{0,1},{1,1},{2,1}},//
    {{0,1},{2,0},{1,0}},//
    
    {{1,0},{1,1},{2,1}},//
    //{{1,0},{0,1},{-1,1}},// diff
   {{1,0},{1,-1},{2,-1}}, 
   {{0,1},{-1,1},{-1,2}},//
    {{0,1},{1,1},{1,2}},//
    
    {{0,1},{-1,1},{0,2}},//
    {{0,1},{1,1},{0,2}},//
    {{1,0},{2,0},{1,1}},//
//    {{0,1},{1,-1},{1,1}}
    {{1,0},{2,0},{1,-1}},
};

int main(void) 
{
    int n,m;
    int ans=0;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
		for(int k=0;k<19;k++) {
            		int sum = a[i][j];
            		bool ok = true;
                	for(int l=0;l<3;l++) {
                    		int y = i + block[k][l][0];
                    		int x = j + block[k][l][1];
                    		if(0<=x && x<m && 0<= y && y<n) {
                        		sum += a[y][x];
                	    	}
                    		else {
					ok = false;
                        		break;
                    		}
                	}
                	if(ok && ans<sum) {
                    		ans = sum;
                	}
            	}
        }
    }
    cout<<ans<<'\n';
    return 0;
}
