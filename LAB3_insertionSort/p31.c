/*
WAP to write the number of steps required to sort the randomly generated list of numbers stored in an array using insertion sort.
    - generate random numbers and store them in a file, the user decides it (range is 1000 < n < 100000)
    - store the output in a file
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insertionSort(int arr[], int n) {
    int steps = 0;

    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
            steps++;
        }

        arr[j + 1] = temp;
        steps++;
    }

    return steps;
}

void writeArrayToFile(const char *filename, int arr[], int n) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Unable to open file: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
}

int main() {
    int n;
    int *arr;
    int steps;

    printf("Enter the number of elements (1000 < n < 100000): ");
    scanf("%d", &n);

    if (n <= 1000 || n >= 10000) {
        printf("Invalid size! Please enter a value in the range 1000 < n < 10000.\n");
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));

    srand((unsigned int)time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    writeArrayToFile("input_numbers.txt", arr, n);

    steps = insertionSort(arr, n);

    writeArrayToFile("sorted_output.txt", arr, n);

    FILE *out = fopen("step_count.txt", "w");
    if (out == NULL) {
        printf("Unable to open output file.\n");
        free(arr);
        return 1;
    }

    fprintf(out, "Number of steps required to sort the array using insertion sort: %d\n", steps);
    fclose(out);

    printf("Random numbers stored in input_numbers.txt\n");
    printf("Sorted numbers stored in sorted_output.txt\n");
    printf("Step count stored in step_count.txt\n");
    printf("Total number of steps: %d\n", steps);

    free(arr);
    return 0;
}

// Breakdown of the code that i wrote...

/*
This is for the sorting and step counting:

Code for insertion sort initially
void insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = temp;
}

Variable for Counting the steps: steps

int insertionSort(int arr[], int n){
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
            steps++;
        }
        
        arr[j + 1] = temp;
        steps++;
    }
    
    return steps;
}
*/
/*
This is for the function to store the randomly generate numbers in a file:

void writeArrayToFile(const char *filename, int arr[], int n){
    FILE *fp = fopen(filename, "w");
    if (fp == NULL){
        printf("Unable to open the file %s\n",filename);
        exit(1);
    }
    
    for (int i = 0; i < n; i++){
        fprint(fp, "%d\n", arr[i]);
    }
    
    fclose(fp);
}
*/
