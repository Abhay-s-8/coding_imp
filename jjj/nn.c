#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 5
#define MAX_LEN 200

char *queue[MAX];
int front = 0, rear = -1, count = 0;

void enqueue(char *s) {
    if (count == MAX) return;
    rear = (rear + 1) % MAX;
    queue[rear] = s;
    count++;
}

char* dequeue() {
    if (count == 0) return NULL;
    char *s = queue[front];
    front = (front + 1) % MAX;
    count--;
    return s;
}

char *stack[MAX];
int top = -1;

void push(char *s) {
    if (top < MAX - 1) stack[++top] = s;
}

char* pop() {
    if (top == -1) return NULL;
    return stack[top--];
}


double calcAccuracy(char *target, char *typed) {
    int correct = 0, i;
    for (i = 0; target[i] && typed[i]; i++)
        if (target[i] == typed[i]) correct++;
    return (double)correct / strlen(target) * 100;
}

double calcWPM(char *typed, double sec) {
    double words = strlen(typed) / 5.0;
    return words / (sec / 60.0);
}


int main() {
    char *sentences[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Practice makes a man perfect.",
        "Data Structures improve coding efficiency.",
        "C language is powerful and fast."
    };

    for (int i = 0; i < 4; i++) enqueue(sentences[i]);

    int choice;
    char typed[MAX_LEN];

    while (1) {
        printf("\n===== Typing Tutor =====\n");
        printf("1. Start Practice\n");
        printf("2. Undo Last Practice\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1) {
            if (count == 0) {
                printf("No more sentences left!\n");
                continue;
            }

            char *s = dequeue();
            printf("\nType this sentence:\n%s\n", s);
            printf("\nPress Enter to start...");
            getchar();

time_t start, end;
printf("\nStart typing:\n> ");
time(&start); 
fgets(typed, MAX_LEN, stdin);
typed[strcspn(typed, "\n")] = 0;
time(&end);    
double sec = difftime(end, start); 

            double acc = calcAccuracy(s, typed);
            double wpm = calcWPM(typed, sec);

            printf("\nTime: %.2f sec | WPM: %.2f | Accuracy: %.2f%%\n",
                   sec, wpm, acc);

            push(s); 
            enqueue(s);
        }

        else if (choice == 2) {
            char *last = pop();
            if (last == NULL) printf("Nothing to undo!\n");
            else printf("Last practice undone: %s\n", last);
        }

        else if (choice == 3) {
            printf("Exiting\n");
            break;
        }

        else printf("Invalid choice!\n");
    }

return 0;
}