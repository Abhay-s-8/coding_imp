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
        for(int j = 1;j <= n - i ;j++){
            printf(" ");
        }
        for(int j = n -i;j > 0 ;j--){
        printf("%d" ,i);
        }
    }
}
