// // the task is to find the second largest and the second smallest number in an array
// #include <stdio.h>

// int main(){
    
//     int n;
//     printf("Enter the number of elements in the array: ");
//     scanf("%d", &n);
//     int arr[n];
    
//     printf("Enter the elements of the array: ");
//     for(int i = 0; i < n; i++){
//         scanf("%d", &arr[i]);
//     }

//     //now for sorting the array
//     for(int i = 0; i < n-1; i++){
//         for(int j = 0; j < n-i-1; j++){
//             if(arr[j] > arr[j+1]){
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }

//     printf("The second smallest numebr is: %d\n", arr[1]);

// }

//--------------------------------------------------

//we have to do it without sorting the array and also we have to find the second largest number and the second smallest number in the array
// #include <stdio.h>

// int main(){
//     int n;
//     printf("Enter the number of elements in the array: ");
//     scanf("%d", &n);
//     int arr[n];
    
//     printf("Enter the elements of the array: ");
//     for(int i = 0; i < n; i++){
//         scanf("%d", &arr[i]);
//     }

//     int largest = arr[0];
//     int smallest = arr[0];

//     for(int i = 0; i < n; i++){
//         if(arr[i] > largest){
//             largest = arr[i];
//         }
//         if(arr[i] < smallest){
//             smallest = arr[i];
//         }
//     }

//     for(int i = 0; i < n; i++){
//         if(arr[i] == largest){
//             arr[i] = 0;
//             break;
//         }
//     }

//     int second_largest = arr[0];
//     for(int i = 0; i < n; i++){
//         if(arr[i] > second_largest){
//             second_largest = arr[i];
//         }
//     }
//     printf("The second largest number is: %d\n", second_largest);
// }

//--------------------------------------------------

// #include <stdio.h>

// int main(){
//     int n;
//     printf("Enter the number of elements in the array: ");
//     scanf("%d", &n);
//     int arr[n];
    
//     printf("Enter the elements of the array: ");
//     for(int i = 0; i < n; i++){
//         arr[i] = rand() % 100;
//     }

//     int a, b;
//     for (int i = 0; i < (n-1); i++){
//         a = arr[i];
//         b = arr[i+1];
//         if(b > a){
//             b = b;
//         }
//         else{
//             b = a;
//         }
//     }
//     if (b > arr[n]){
//         printf("The second largest number is: %d\n", b);
//     }

// }

//Final code for finding the second largest and second smallest number in an array without sorting the array

#include <stdio.h>

int main(){
    
    int n, l;
    int a[100];
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    int smallest = a[0];
    int second_smallest = a[0];
    int largest = a[0];
    int second_largest = a[0];

    for(int i = 0; i < n; i++){
        if(a[i] < smallest){
            second_smallest = smallest;
            smallest = a[i];
        }
        else if(a[i] < second_smallest || second_smallest == smallest){
            second_smallest = a[i];
        }

        if(a[i] > largest){
            second_largest = largest;
            largest = a[i];
        }
        else if(a[i] > second_largest || second_largest == largest){
            second_largest = a[i];
        }
    }

    printf("Second smallest = %d\n", second_smallest);
    printf("Second largest = %d\n", second_largest);

    return 0;
}
