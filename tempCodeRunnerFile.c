#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int k) {
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }


    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[5] = {1, 4, 5, 3, 2};
    bubbleSort(arr, 5);

    return 0;
}
