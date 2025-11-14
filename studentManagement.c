#include <stdio.h>

struct student {
    int roll;
    char name[50];
    char program[50];
    char course[50];
    int marks[5];
    int total  ;
    float average;
};

int main() {
    struct student s[100]; 
    int n = 0;              
    int choice, i, j;
    int k =1;

    do{
        printf("=== student management system ===\n");
        printf(" 1.create\n 2.display\n 3.exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
            printf("enter the number of student to be enter : ");
            scanf("%d",&n);
            for(int i =0 ;i<n;i++){
                printf("%d . student details \n", i+1);

                printf("ROLL NO. :");
                scanf("%d" ,&s[i].roll);

                printf("NAME :");
                scanf("%s" ,s[i].name);

                printf("PROGRAM NAME :");
                scanf("%s" ,s[i].program);

                printf("COURSE NAME :");
                scanf("%s" ,s[i].course);
                s[i].total = 0;
                printf("enter the marks of 5 subject : \n");
                for(int j =0 ;j<5;j++)
                {
                    printf("%d subject :", j+1);
                    scanf("%d" ,&s[i].marks[j]);
                    s[i].total += s[i].marks[j];
                }

                printf("total marks obtained : %d \n",s[i].total );

                s[i].average = s[i].total / 5.00 ;

                printf("%f\n" , s[i].average);


            }
            break;
            
            case 2:
            if( n ==0 ){
                printf("database is empty:\n");
                
            }
            else{for(int i =0 ;i<n;i++){
                printf("%d . student details \n", i+1);

                printf("ROLL NO. :");
                printf("%d \n" ,s[i].roll);

                printf("NAME :");
                printf("%s \n" ,s[i].name);

                printf("PROGRAM NAME :");
                printf("%s \n" ,s[i].program);

                printf("COURSE NAME :");
                printf("%s \n" ,s[i].course);

                s[i].total = 0;
                printf("entered  marks of 5 subject : \n");
                for(int j =0 ;j<5;j++)
                {
                    printf("%d subject marks : %d \n" ,j+1,s[i].marks[j]);
                }

                printf("total marks obtained : %d \n",s[i].total );

                s[i].average = s[i].total / 5.00 ;

                printf("average marks :%f \n" , s[i].average);
                
        }
        

    }break;
    case 3: printf("exit \n");
    break;
        
    default:
    printf("Invalid choice\n");
}
    }while (choice!=3);

    

    return 0;
}
