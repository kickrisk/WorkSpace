#include <iostream>
#include <vector>
using namespace std;

int n;
const int Max = 1000000;
bool arr[Max+1];

void eratos() {
	for (int i = 2; i <= Max; i++) 
		arr[i] = true;

	for (int i = 2; i*i <= Max; i++) {
		if(arr[i])
			for (int j = i*i; j <= Max; j += i) { 
				arr[j] = false;
		}
	}
}

int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    eratos();
    vector<int> v;
    int c=1;
    while(c!=0) {
        cin>>c;
        v.push_back(c);
    }
	for(vector<int>::size_type i = 0; i < v.size(); ++i) {
		int o1 = 0, o2 = 0; 
		for (o1 = 3; o1 <= v[i] - 1; o1++) { 
			if (arr[o1]) { 
				o2 = v[i] - o1; 
				if (arr[o2]) { 
					cout << v[i] << " = " << o1 << " + " << o2<<"\n"; 
					break;
				}
			}
		}
        if(o1 == v[i]){
			cout << "Goldbach's conjecture is wrong.";
        }
	}
    return 0;
}
