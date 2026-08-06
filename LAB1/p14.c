#include <stdio.h>

void exchange(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void rotate_right(int a[], int n){
    int i;
    for(i = n - 1; i > 0; i--){
        exchange(&a[i], &(a[i - 1]));
    }
}

int main(){
    int a[100], N, p2, i;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    printf("Enter the elements:\n");
    for(i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter number of elements to rotate: ");
    scanf("%d",&p2);

    printf("\nBefore Rotate: ");
    for(i = 0; i < N; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    rotate_right(a, p2);

    printf("After rotate: ");
    for(i = 0; i < N; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}