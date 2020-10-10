//Program8−−−some heap practice
//compile:gcc −o program8 program8.c
//usage:./program8
//Name:
//
//Date submitted:
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 20
//GlobalVariables
int heapstate=0;//0=heap,1=maxheap,2=minheap
enum heapguide {
    NO_HEAP,
    MAX_HEAP,
    MIN_HEAP
};
void print(int A[],int heapsize){
    for(int i=1;i<=heapsize;i++)
    printf("%d−",A[i]);
}

void max_sift_up(int A[], int i, int heapsize) {
    int parent = i/2;
    int temp;
    if(parent > 0 && parent < heapsize) {
        if(A[i] > A[parent]) {
            temp = A[i];
            A[i] = A[parent];
            A[parent] = temp;
            max_sift_up(A, parent, heapsize);
        }
    }
}
void min_sift_up(int A[], int i, int heapsize) {
    int parent = i/2;
    int temp;
    if(parent > 0 && parent < heapsize) {
        if(A[i] < A[parent]) {
            temp = A[i];
            A[i] = A[parent];
            A[parent] = temp;
            min_sift_up(A, parent, heapsize);
        }
    }
}
void add(int  A[],int *heapsize,int  val){
    if(*heapsize < N) {
        A[*heapsize+1] = val;
        (*heapsize)++;
        switch(heapstate) {
            case NO_HEAP:
                break;
            case MIN_HEAP:
                min_sift_up(A, *heapsize, *heapsize);
                break;
            case MAX_HEAP:
                max_sift_up(A, *heapsize, *heapsize);
                break;
            default:
                printf("error");
        }
        printf("Added %d \n",val);
    } else {
        printf("Heap full delete some items \n");
    }
}
int extract(int A[], int heapsize){
    int a = 10;
    return a;
}
void min_heapify(int A[], int i, int heapsize) {
    int temp, smallest, left, right;
    smallest = i;
    left = (2*i);
    right = (2*i+1);
  
    if (left <= heapsize && A[left] < A[smallest]) 
        smallest = left; 
  
    if (right <= heapsize && A[right] < A[smallest]) 
        smallest = right; 
  
    if (smallest != i) { 
        temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
        min_heapify(A, smallest, heapsize); 
    } 
}
void max_heapify(int A[], int i, int heapsize) {
    int temp, largest, left, right;
    largest = i;
    left = (2*i);
    right = ((2*i)+1);
    if (left <= (heapsize) && A[left] > A[largest]) 
        largest = left;

    if (right <= (heapsize) && A[right] > A[largest])  
        largest = right;

    if (largest != i) {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        max_heapify(A, largest, heapsize);
    }
}
void make_max_heap(int A[],int heapsize){
    printf("Making a max heap\n");
    for (int j = heapsize/2; j >= 1; j--) {
        max_heapify(A, j, heapsize);
    }
}
void make_min_heap(int A[],int heapsize){
    for (int j = heapsize/2; j >= 1; j--) {
        min_heapify(A, j, heapsize);
    }
    printf("Making a min heap");
}

void heapsort(int A[],int heapsize){
    int temp;
    if(heapstate==0)return;
    if(heapstate == MAX_HEAP) {
        for(int i=heapsize; i>1; i--) { 
            temp = A[1];
            A[1] = A[i];
            A[i] = temp;
            max_heapify(A, 1, i-1); 
        } 
    } else {
        for(int i=heapsize; i>1; i--) { 
            temp = A[1];
            A[1] = A[i];
            A[i] = temp;
            min_heapify(A, 1, i-1); 
        }
    }
}

int  main(){
    int  A[N+1];
    int  heapsize=0;
    char *command = malloc(10);
    int  val=0;

    //Initialize
    //Remember that our arrays start with index 1.
    for(int i=1;i<=N;i++)
    A[i]=0;
    do{
        scanf("%s",command);
        if(!strcmp(command, "add")){
            //Add a value to the end of the heap.
            //Should maintain the heap property according to heap state.
            scanf("%d",&val);
            add(A, &heapsize, val);
        }
        if(command=="extract"){
            //Should extract A[1] and maintain heap property,
            //according to heapstate
            printf("Extracted %d",extract(A,heapsize));
        }
        if(!strcmp(command,"neither")){
            heapstate=0;
        }
        if(!strcmp(command,"max")){
            heapstate=1;
            make_max_heap(A,heapsize);
        }
        if(!strcmp(command,"min")){
            heapstate=2;
            make_min_heap(A,heapsize);
        }
        if(!strcmp(command,"sort")){
            //Sort into increasing order if heap state=1,
            //and into decreasing order if heap state=2.
            heapsort(A,heapsize);
        }
        print(A,heapsize);
    } while(strcmp(command, "end"));
    return 0;
}