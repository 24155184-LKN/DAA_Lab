/*Write a program in C to convert the first n decimal numbers of a dsik file to binary using recursion. Store the binary value in a separate disk file.*/

#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to binary using recursion

void decimalToBinary(int n, FILE *outputFile) {

    if (n > 1) {
        decimalToBinary(n / 2, outputFile);
    }

    fprintf(outputFile, "%d", n % 2);
}

int main() {
 
    FILE *inputFile, *outputFile;
    int n, count = 0, number;
 
    // Open the input file for reading
    inputFile = fopen("inDec.txt", "r");
 
    if (inputFile == NULL) {
        perror("Error opening input file");
 
        return EXIT_FAILURE;
    }
 
    // Open the output file for writing
    outputFile = fopen("outBin.txt", "w");
 
    if (outputFile == NULL) {
 
        perror("Error opening output file");
        fclose(inputFile);
 
        return EXIT_FAILURE;
    }
 
    // Read the first n decimal numbers from the input file
    printf("Enter the number of decimal numbers to convert: ");
    scanf("%d", &n);
 
    while (count < n && fscanf(inputFile, "%d", &number) == 1) {
 
        fprintf(outputFile, "Decimal: %d -> Binary: ", number);
        decimalToBinary(number, outputFile);
        fprintf(outputFile, "\n");
 
        count++;
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion completed. Check outBin.txt for results.\n");

    return EXIT_SUCCESS;
}
