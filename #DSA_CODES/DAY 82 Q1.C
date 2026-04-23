#include <stdio.h>

int lowerBound(int a[], int n, int x) {
    int l = 0, r = n;
    while(l < r) {
        int m = (l + r) / 2;
        if(a[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}

int upperBound(int a[], int n, int x) {
    int l = 0, r = n;
    while(l < r) {
        int m = (l + r) / 2;
        if(a[m] <= x) l = m + 1;
        else r = m;
    }
    return l;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int a[1000];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int x;
    scanf("%d", &x);
    
    int lb = lowerBound(a, n, x);
    int ub = upperBound(a, n, x);
    
    printf("%d %d", lb, ub);
    
    return 0;
}
