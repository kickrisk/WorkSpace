#include <cstdio>
#include <cstring>
int a[501];
int d[501][501];
int c[501][501];
int go(int i, int j) {
    if (i == j) {
        return 0;
    }
    if (d[i][j] != -1) {
        return d[i][j];
    }
   c[i][j] = d[i][j];
    int sum = 0;
    for (int k=i; k<=j; k++) {
        sum += a[k];
    }
    for (int k=i; k<=j-1; k++) {
        int temp = go(i, k) + go(k+1, j) + sum;
        if (c[i][j] == -1 || c[i][j] > temp) {
            c[i][j] = temp;
        }
    }
    return c[i][j];
}
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        memset(d,-1,sizeof(d));
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n; i++) {
            scanf("%d",&a[i]);
        }
        printf("%d\n",go(1, n));
    }
    return 0;
}

