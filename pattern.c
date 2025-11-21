#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;printf("enter the number to print :");

    scanf("%d",&n);

    for(int i =0 ;i<n;i++){
        for(int j = 0 ;j<=i ;j++){
            printf("%d",j+1);
        }
        printf("\n");
    }

    printf("\n");

    for(int i = 1; i<= n;i++){
        for(int j = 0;j < n - i ;j++){
            printf(" ");
        }

        for(int j = n ;j > n - i ;j--){
        printf("%d " ,i);
        }
        printf("\n");
    }

    for(int i = n-1 ;i >=1;i--){
        for(int j = 1 ; j<= n - i ;j++ ){
            printf(" ");
        }
        for(int j = 1;j <= i;j++){
            printf("%d ",i);
        }
                printf("\n");
    }
}
