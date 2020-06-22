#include <iostream>

using namespace std;

// 3 <= N <= 100 , 10<= M <= 300,000

int N, M;

void blackjack(int N, int M);

int main()
{
	cin>>N;
	cin>>M<<endl;
	
	char *arr = new char[N];

	blackjack(arr,N,M);

}

void blackjack(char arr[],int N, int M)
{
	int a=0, b=1, c=2;
	int key = arr[a]+arr[b]+arr[c] - M;
	int flag = 0;	
	for(a=0; a<N;a++) {
		if(a == b) a = b+1;
		else if (a == c) a = c+1;
		for(`
}
