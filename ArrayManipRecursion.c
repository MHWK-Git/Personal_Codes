#include <stdio.h>
#include "ArrayManipRecursion.h"
#define size 10

void ShiftRight(int* arr,int i){
if(i > 0){
  arr[i] = arr[i - 1];
  ShiftRight(arr,i - 1);
}}

void ShiftLeft(int* arr,int i){
if(i < size + 1){
  arr[i] = arr[i + 1];
  ShiftLeft(arr,i + 1);
}}

void InsertAtFront(int* arr, int NewEle)
{
  ShiftRight(arr,size);
  arr[0] = NewEle;
}

void RemoveFront(int* arr){ShiftLeft(arr,0);}

void InsertAtBack(int* arr, int x, int len){
  len += 2;
  arr[len - 1] = x;
}

void RemoveBack(int* arr, int len){len--;}

void printArray(int* arr, size_t n){
    if(n > 1){printArray(arr, n-1);}
    printf("%d ", arr[n-1]);
}

void createArray(int* array, int s, int x){
  int i = 0;
  if(s > 0){
    array[i++] = x++;
    createArray(array + 1, s - 1,x);
  }}

int main(){ 
int arr[size + 1] = {};

int num = (sizeof(arr)/sizeof(arr[0])) - 1;
createArray(arr, num, 1);

// print the original array
  printArray(arr,num);
  printf("\n\n");

// insert at the front and back of array
  InsertAtFront(arr,61);
  InsertAtBack(arr,94,num); 

// print the updated array 
  printArray(arr,num + 2);
  printf("\n\n"); 

//remove at the front and back of array
  RemoveFront(arr);
  RemoveBack(arr,num + 2);

  // print the updated array 
  printArray(arr,num);
  printf("\n\n");  
 return 0;
}
