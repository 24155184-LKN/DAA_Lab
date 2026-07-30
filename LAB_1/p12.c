#include <stdio.h>
    int main(){
        
        printf("Enter the number of elements you want in the array: ");
        int n;
        scanf("%d", &n);
        int ip_arr[n];

        printf("Enter the elements of the array: ");
        for(int i = 0; i < n; i++){
            scanf("%d", &ip_arr[i]);
        }
        
        int sum = 0;
        int op_arr[n];
        for (int i = 0; i < n; i++){
            op_arr[i] = ip_arr[i] + sum;
            sum = op_arr[i];
        }

        printf("The output array is: ");
        for (int i = 0; i < n; i++){
            printf("%d ", op_arr[i]);
        }
        printf("\n");
        return 0;
    }