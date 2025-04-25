#include <stdio.h>
#define SIZE 20

void MaxMin(int arr[], int i, int j, int* max, int* min) {
    int mid, l_max, l_min;
    if (i == j) *max = *min = arr[i];
    else if (i == j - 1) {
        if (arr[i] < arr[j]) *max = arr[j], *min = arr[i];
        else *max = arr[i], *min = arr[j];
    }
    else {  
        mid = (i + j) / 2;
        MaxMin(arr, i, mid, max, min);  
        l_max = *max; l_min = *min;
        MaxMin(arr, mid+1, j, max, min);
        if (l_max > *max) *max = l_max;
        if (l_min < *min) *min = l_min;
    }
}

void main() {
    int arr[SIZE], i, n, max, min;
    printf("Total elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    MaxMin(arr, 0, n-1, &max, &min);
    printf("Maximum: %d\nMinimum: %d", max, min);
}