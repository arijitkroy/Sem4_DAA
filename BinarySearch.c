#include <stdio.h>
#define MAX 20

int binarySearch(int arr[], int l, int h, int k) {
    int m = (l + h) / 2;
    if (l > h) return -1;
    if (arr[m] == k) return m;
    if (arr[m] < k) binarySearch(arr, m + 1, h, k);
    else binarySearch(arr, l, m - 1, k);
}

void main() {
    int n, arr[MAX], i, key;
    printf("Number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Element to search: ");
    scanf("%d", &key);
    i = binarySearch(arr, 0, n - 1, key);
    if (i == -1) printf("Element not found");
    else printf("Element found at position %d", i+1);
}