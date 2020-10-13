#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool check(int arr[], int len) {
    int i;
    for(int i = 0; i < len-1; i++) {
        if(arr[i] > arr[i+1]) {
            return false;
        }
    }
    return true;
}

void print_sorted(int arr[], int len) {
    bool sorted;
    sorted = check(arr, len);
    if(!sorted) {
        printf("Array is not sorted \n");
    } else {
        printf("Array is sorted\n");
    }
} 

//The algo here
void smartbubble(int arr[], int len) {
    int temp = 0;
    int i, j;
    for(i=0; i < len; i++) {
        bool swap = false;
        for(j = 0; j < len - i - 1; j++){
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = true;
            }
        }
        if(!swap) {
            break;
        }
    }
}

int main() {
    int len = 100;
    int arr[len];
    srand(0);
    int i;
    for(i=0; i<len;i++){
        arr[i] = rand();
    }
    print_sorted(arr, len);    
    smartbubble(arr, len);
    print_sorted(arr, len);    
    return 0;
}
