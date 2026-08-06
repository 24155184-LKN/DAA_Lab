#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long long insertionSort(int arr[], int n) {
    long long steps = 0;

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
        printf("Unable to open %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }

    fclose(fp);
}

void readArrayFromFile(const char *filename, int arr[], int n) {
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Unable to open %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);
}

int main() {

    int n = 0;
    int *arr = NULL;
    int *bestArr = NULL;
    int choice;
    int x;
    long long averageSteps, bestSteps;
    char input[20];

    srand((unsigned int)time(NULL));

    while (1) {

        printf("\n========== MENU ==========\n");
        printf("1. Generate New Input File\n");
        printf("2. Count Steps (Average Case and Best Case)\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {

        case 1:

            printf("Enter n (1000 - 100000): ");
            scanf("%d", &n);

            if (n < 1000 || n > 100000) {
                printf("Invalid input!\n");
                break;
            }

            arr = (int *)malloc(n * sizeof(int));

            if (arr == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }

            for (int i = 0; i < n; i++)
                arr[i] = rand() % 100000;

            writeArrayToFile("inputNumbers.txt", arr, n);

            insertionSort(arr, n);

            writeArrayToFile("outputNumbers.txt", arr, n);

            free(arr);

            /* Create/clear graph data file */
            FILE *graphFile = fopen("average_steps.txt", "w");
            if (graphFile == NULL) {
                printf("Unable to create average_steps.txt\n");
                return 1;
            }
            fclose(graphFile);

            printf("\nFiles created successfully.\n");
            printf("inputNumbers.txt   -> Random Numbers\n");
            printf("outputNumbers.txt  -> Sorted Numbers\n");
            printf("average_steps.txt  -> Graph Data\n");

            break;

        case 2:

            if (n == 0) {
                printf("Generate the files first.\n");
                break;
            }

            arr = (int *)malloc(n * sizeof(int));
            bestArr = (int *)malloc(n * sizeof(int));

            if (arr == NULL || bestArr == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }

            while (1) {

                printf("\nEnter number of elements (1000-%d) or type exit: ", n);

                scanf("%19s", input);

                if (strcmp(input, "exit") == 0)
                    break;

                x = atoi(input);

                if (x < 1000 || x > n) {
                    printf("Invalid input.\n");
                    continue;
                }

                // Average Case
                readArrayFromFile("inputNumbers.txt", arr, x);
                averageSteps = insertionSort(arr, x);

                // Best Case
                readArrayFromFile("outputNumbers.txt", bestArr, x);
                bestSteps = insertionSort(bestArr, x);

                printf("\nAverage Case Steps = %lld\n", averageSteps);
                printf("Best Case Steps    = %lld\n", bestSteps);

                /* Save average case data for graph */
                FILE *graphFile = fopen("average_steps.txt", "a");

                if (graphFile == NULL) {
                    printf("Unable to open average_steps.txt\n");
                } else {
                    fprintf(graphFile, "%d %lld\n", x, averageSteps);
                    fclose(graphFile);
                }
            }

            free(arr);
            free(bestArr);

            break;

        case 3:

            printf("Program terminated.\n");
            return 0;

        default:

            printf("Invalid choice.\n");
        }
    }

    return 0;
}
