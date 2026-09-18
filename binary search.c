//find the exucution time of binary search algorithm
#include <stdio.h>
#include <time.h>

int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(a[mid] == key)
            return mid;
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int a[1000], n, key, i, result;
    clock_t start, end;
    double time;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &key);

    start = clock();

    result = binarySearch(a, n, key);

    end = clock();

    time = (double)(end - start) / CLOCKS_PER_SEC;

    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    printf("Execution Time = %f seconds", time);

    return 0;
}