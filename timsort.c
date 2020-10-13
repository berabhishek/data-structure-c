#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

const int RUN = 32; 
int min(int x, int y) {
    if(x<y) {
        return x;
    }
    return y;
}

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

void insertionSort(int arr[], int left, int right) { 
    for (int i = left + 1; i <= right; i++) 
    { 
        int temp = arr[i]; 
        int j = i - 1; 
        while (j >= left && arr[j] > temp) 
        { 
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = temp; 
    } 
} 

void merge(int arr[], int l, int m, int r) { 
    int len1 = m - l + 1, len2 = r - m; 
    int left[len1], right[len2]; 
    for (int i = 0; i < len1; i++) 
        left[i] = arr[l + i]; 
    for (int i = 0; i < len2; i++) 
        right[i] = arr[m + 1 + i]; 
  
    int i = 0; 
    int j = 0; 
    int k = l; 
  
    while (i < len1 && j < len2) { 
        if (left[i] <= right[j]) { 
            arr[k] = left[i]; 
            i++; 
        } 
        else { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < len1) { 
        arr[k] = left[i]; 
        k++; 
        i++; 
    } 
  
    while (j < len2) { 
        arr[k] = right[j]; 
        k++; 
        j++; 
    } 
} 

//the main algo here
void timSort(int arr[], int n) { 
    for (int i = 0; i < n; i+=RUN) 
        insertionSort(arr, i, min((i+31),(n-1))); 
    for (int size = RUN; size < n; size = 2*size) { 
        for (int left = 0; left < n; left += 2*size) { 
            int mid = left + size - 1; 
            int right = min((left + 2*size - 1),(n-1)); 
            merge(arr, left, mid, right); 
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
    timSort(arr, len);
    print_sorted(arr, len);    
    return 0;
}
