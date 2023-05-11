#include <stdio.h>

void Min_max(int i, int j, int a[], int *max, int *min) {
    int mid, max_left, min_left, max_right, min_right;
    
    if (i == j) {
        *max = a[i];
        *min = a[j];
    } else if (i == j - 1) {
        if (a[i] < a[j]) {
            *max = a[j];
            *min = a[i];
        } else {
            *max = a[i];
            *min = a[j];
        }
    } else {
        mid = (i + j) / 2;
        Min_max(i, mid, a, &max_left, &min_left);
        Min_max(mid + 1, j, a, &max_right, &min_right);
        
        if (max_left > max_right) {
            *max = max_left;
        } else {
            *max = max_right;
        }
        
        if (min_left < min_right) {
            *min = min_left;
        } else {
            *min = min_right;
        }
    }
}

int main() {
    int n, max, min;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    Min_max(0, n - 1, a, &max, &min);
    
    printf("Max = %d\n", max);
    printf("Min = %d\n", min);
    
    return 0;
}
