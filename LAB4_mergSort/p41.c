#include <stdio.h>
#include <stdlib.h>

long long steps = 0;

/* Merge two sorted halves */
void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    /* Copy left half */
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
        steps++;
    }

    /* Copy right half */
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
        steps++;
    }

    int i = 0;
    int j = 0;
    int k = left;

    /* Merge the two halves */
    while (i < n1 && j < n2)
    {
        steps++;   // comparison

        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }

        steps++;   // assignment
    }

    /* Copy remaining elements of left half */
    while (i < n1)
    {
        arr[k++] = L[i++];
        steps++;
    }

    /* Copy remaining elements of right half */
    while (j < n2)
    {
        arr[k++] = R[j++];
        steps++;
    }

    free(L);
    free(R);
}

/* Recursive Merge Sort */
void mergeSort(int arr[], int left, int right){
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/* Read numbers from file */
void readArrayFromFile(const char *filename, int arr[], int n){
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Cannot open %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);
}

int main(){
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *average = (int *)malloc(n * sizeof(int));
    int *best = (int *)malloc(n * sizeof(int));

    if (average == NULL || best == NULL)
    {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    /* ---------- Average Case ---------- */

    readArrayFromFile("input_numbers.txt", average, n);

    steps = 0;
    mergeSort(average, 0, n - 1);

    long long averageSteps = steps;

    /* ---------- Best Case ---------- */

    readArrayFromFile("sorted_output.txt", best, n);

    steps = 0;
    mergeSort(best, 0, n - 1);

    long long bestSteps = steps;

    /* ---------- Display Results ---------- */

    printf("\nMerge Sort Step Count\n");
    printf("-----------------------------\n");
    printf("Average Case : %lld\n", averageSteps);
    printf("Best Case    : %lld\n", bestSteps);

    free(average);
    free(best);

    return 0;
}
