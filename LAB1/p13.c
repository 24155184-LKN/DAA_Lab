#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, count, max_count = 0, most_repeating = -1, duplicate_count = 0;
    int arr[1000];
    int freq[1000];
    
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);
    
    FILE *fp = fopen("number_file.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    
    printf("The content of the array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++) {
        freq[i] = 0;
    }
    
    for (i = 0; i < n; i++) {
        count = 0;
        for (j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        freq[i] = count;
        
        if (count > max_count) {
            max_count = count;
            most_repeating = arr[i];
        }
    }
    
    for (i = 0; i < n; i++) {
        if (freq[i] > 1) {
            int is_duplicate_counted = 0;
            for (j = 0; j < i; j++) {
                if (arr[i] == arr[j]) {
                    is_duplicate_counted = 1;
                    break;
                }
            }
            if (!is_duplicate_counted) {
                duplicate_count++;
            }
        }
    }
    
    printf("Total number of duplicate values = %d\n", duplicate_count);
    printf("The most repeating element in the array = %d\n", most_repeating);
    
    return 0;
}
