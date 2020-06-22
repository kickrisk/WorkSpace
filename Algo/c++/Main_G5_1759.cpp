#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool check(string password)
{
    int ja =0, mo =0;
    for(char x : password) {
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
            mo +=1;
        else {
            ja +=1;
        }
    }
    return mo>=1 && ja>=2 ;
}

void go(int L, vector<char> &alpha, string password, int i)
{
    if(password.length() == L) {
        if(check(password)) {
            cout<<password<<'\n';
	}
	return;
    }
    if(i < alpha.size()) {
        go(L,alpha,password+alpha[i],i+1);
        go(L,alpha,password,i+1);
    }
}

int main(void)
{
    int L,C;
    cin>>L>>C;
    vector<char> alpha(C);
    for(int i=0;i<C;i++) {
        cin>>alpha[i];
    }
    sort(alpha.begin(),alpha.end());
    string password;
    int i=0;
    go(L,alpha,password,i);
    return 0;
}
