#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    long long prefix = 0, count = 0;
    
    long long *freq = calloc(200001, sizeof(long long));
    int offset = 100000;
    
    freq[offset] = 1;
    
    for(int i = 0; i < n; i++) {
        prefix += arr[i];
        
        if(prefix + offset >= 0 && prefix + offset < 200001) {
            count += freq[prefix + offset];
            freq[prefix + offset]++;
        }
    }
    
    printf("%lld", count);
    
    free(freq);
    return 0;
}
