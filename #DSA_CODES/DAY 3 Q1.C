#include <stdio.h>

int main() {
    int n, k, i, c = 0, found = -1;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &k);
    for (i = 0; i < n; i++) {
        c++;
        if (a[i] == k) {
            found = i;
            break;
        }
    }
    if (found != -1)
        printf("Found at index %d\n", found);
    else
        printf("Not Found\n");
    printf("Comparisons = %d", c);
    return 0;
}
