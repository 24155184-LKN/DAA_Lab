// //Find the factorial of any number without recursion and count the number of steps
// #include <stdio.h>
// int main(){
 
//     int n;
//     printf("Enter the number to find the factorial: ");
//     scanf("%d", &n);
 
//     int fact = 1;
//     int count = 0;
 
//     for(int i = 1; i <= n; i++){
//         fact *= i;
//         count++;
//     }
 
//     printf("The factorial of %d is: %d\n", n, fact);
//     printf("Number of steps taken: %d\n", count);

//     return 0;
// }

#include <stdio.h>
int main(){

    int data;
    printf("Enter the number of data you want to take: ");
    scanf("%d", &data);

    for(int i = 0; i < data; i++){

        int n;
        printf("Enter the number to find the factorial: ");
        scanf("%d", &n);
    
        int fact = 1;
        int count = 0;
    
        for(int i = 1; i <= n; i++){
            fact *= i;
            count++;
        }
    
        printf("The factorial of %d is: %d\n", n, fact);
        printf("Number of steps taken: %d\n", count);

        printf("Steps visualization: ");
        for(int j = 0; j < count; j++){
            printf("*");
        }
        printf("\n\n");
    }



    return 0;
}
