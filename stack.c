#include <stdio.h>
#include <string.h>

int main(){
    int n ,x;
    int found = 0;
    printf("enter number for members : ");
    scanf("%d",&n);

    char contacts[n][50];

    for(int i =0 ;i<n;i++){
        printf("%d name : " , i+1);
        scanf("%s",contacts[i]);
    }

    char searchName[50];
    printf("enter name to be searched : ");
    scanf("%s",searchName);


    

}