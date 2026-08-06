/*
Write a program in C to find the GCD of two numbers using recursion.Read all pair of numebr form a file named inGCD.txt, Store the GCD value in a separate disk file named outGCD.txt.
The input will be like: 8 12 20 45 30 80
The output will be like 
The GCD of 8 and 12 is 4
The GCD of 20 and 45 is 5
The GCD of 30 and 80 is 10
*/

#include <stdio.h>
#include <stdlib.h>

// Function to find GCD using recursion
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    FILE *inputFile, *outputFile;
    int num1, num2;

    // Open the input file for reading
    inputFile = fopen("inGCD.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Open the output file for writing
    outputFile = fopen("outGCD.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Read pairs of numbers from the input file and calculate GCD
    while (fscanf(inputFile, "%d %d", &num1, &num2) == 2) {
        int result = gcd(num1, num2);
        fprintf(outputFile, "The GCD of %d and %d is %d\n", num1, num2, result);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("GCD calculation completed. Check outGCD.txt for results.\n");

    return EXIT_SUCCESS;
}
