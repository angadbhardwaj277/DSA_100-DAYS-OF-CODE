#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    
    long long l = 0, r = n, ans = 0;
    
    while(l <= r) {
        long long m = (l + r) / 2;
        
        if(m * m <= n) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    
    printf("%lld", ans);
    return 0;
}
