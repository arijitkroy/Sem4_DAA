#include <stdio.h>
#define MAX 20

int partition(int arr[], int p, int q) {
    int x = arr[p], i = p, j = q, tmp;
    while (i < j) {
        while (arr[i] <= x) i++;
        while (arr[j] > x) j--;
        if (i < j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    tmp = arr[p];
    arr[p] = arr[j];
    arr[j] = tmp;
    return j;
}

void quickSort(int arr[], int p, int r) {
    int q;
    if (p < r) {
        q = partition(arr, p, r);
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

void main() {
    int n, arr[MAX], i;
    printf("Number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    quickSort(arr, 0, n-1);
    printf("After sorting: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
}