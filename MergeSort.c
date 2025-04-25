#include <stdio.h>
#define MAX 20

void merge(int arr[], int l, int m, int h) {
    int i = l, j = m + 1, k = l, aux[MAX];
    while (i <= m && j <= h) {
        if (arr[i] < arr[j]) aux[k++] = arr[i++];
        else aux[k++] = arr[j++];
    }
    while (i <= m) aux[k++] = arr[i++];
    while (j <= h) aux[k++] = arr[j++];
    for (i = l; i <= h; i++) arr[i] = aux[i];
}

void mergeSort(int arr[], int p, int q) {
    int mid;
    if (p < q) {
        mid = (p + q) / 2;
        mergeSort(arr, p, mid);
        mergeSort(arr, mid+1, q);
        merge(arr, p, mid, q); 
    }
}

void main() {
    int n, arr[MAX], i;
    printf("Number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    mergeSort(arr, 0, n-1);
    printf("After sorting: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
}