/* Main.cpp
  A simple program that takes a file name as input containing a collection of numbers then sorts them based on five different algorithms
  @author Sebastian Brumm
  @author brumm@chapman.edu
  @author Id:2319132
*/
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//Bubble sort, sorts an array on doubles
void bubbleSort(double arr[], int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(arr[i] < arr[j]){
        double temp;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

//Selection sort, sorts an array of doubles
void selectionSort(double arr[], int n){
  for(int i = 0; i < n; i++){
    int idx = i;
    for(int j = i + 1; j < n; j++){
      if(arr[j] < arr[idx]){
        idx = j;
      }
    }
    double temp;
    temp = arr[idx];
    arr[idx] = arr[i];
    arr[i] = temp;
  }
}

//Insertion sort, sorts an array of doubles
void insertionSort(double arr[], int n){
  for(int i = 0; i < n; i++){
    double temp = arr[i];
    int k = i;
    while(k > 0 && arr[k-1] >= temp){
      arr[k] = arr[k-1];
      --k;
    }
    arr[k] = temp;
  }
}

//Helper function for merge sort that separates the array into two subarrys then sorts them
void merge(double arr[], int l, int m, int r){
  int leftSize = m - l + 1;
  int rightSize = r - m;

  double left[leftSize];
  double right[rightSize];

  for(int i = 0; i < leftSize; i++){
    left[i] = arr[l + i];
  }
  for(int j = 0; j < rightSize; j++){
    right[j] = arr[m + 1 + j];
  }

  int a = 0;
  int b = 0;
  int c = l;
  while(a < leftSize && b < rightSize){
    if(left[a] <= right[b]){
      arr[c] = left[a];
      a++;
    }else{
      arr[c] = right[b];
      b++;
    }
    c++;
  }

  while(a < leftSize){
    arr[c] = left[a];
    a++;
    c++;
  }
  while(b < rightSize){
    arr[c] = right[b];
    b++;
    c++;
  }
}

//The recursive function of merge sort
void mergeSort(double arr[], int left, int right){
  if(left < right){
    int temp = (left+right)/2;

    mergeSort(arr, left, temp);
    mergeSort(arr, temp+1, right);

    merge(arr, left, temp, right);
  }
}

//A helper function for quick sort that splits the array
int split(double arr[], int l, int r){
  double a = arr[r];
  int b = l - 1;

  for(int i = l; i <= r-1; i++){
    if(arr[i] <= a){
      b++;
      double temp;
      temp = arr[b];
      arr[b] = arr[i];
      arr[i] = temp;
    }
  }
  int temp;
  temp = arr[b+1];
  arr[b+1] = arr[r];
  arr[r] = temp;
  return (b+1);
}

//Quick sort, sorts an array of doubles, is a recursive function
void quickSort(double arr[], int left, int right){
  if(left < right){
    int temp = split(arr, left, right);

    quickSort(arr, left, temp-1);
    quickSort(arr, temp+1, right);
  }
}

//Main function that implements all five of the sorting algorithms
int main(int argc, char *argv[]) {
  time_t timer;
  ifstream input(argv[1]);
  int size;
  string line;

  getline(input,line);
  size = stoi(line);
  double array1[size];
  double array2[size];
  double array3[size];
  double array4[size];
  double array5[size];
  int i = 0;

  while(getline(input,line)){
    array1[i] = stod(line);
    i++;
  }

  for(int i = 0; i < size; i++){
    array2[i] = array1[i];
    array3[i] = array1[i];
    array4[i] = array1[i];
    array5[i] = array1[i];
  }

  timer = time(NULL);
  cout << "Bubble Sort: \n";
  cout << "Start: " << timer << endl;
  bubbleSort(array1,size);
  timer = time(NULL);
  cout << "End: " << timer << endl;
  cout << endl;
  cout << "Selection Sort: \n";
  cout << "Start: " << timer << endl;
  selectionSort(array2,size);
  timer = time(NULL);
  cout << "End: " << timer << endl;
  cout << endl;
  cout << "Insertion Sort: \n";
  cout << "Start: " << timer << endl;
  insertionSort(array3,size);
  timer = time(NULL);
  cout << "End: " << timer << endl;
  cout << endl;
  cout << "Merge Sort: \n";
  cout << "Start: " << timer << endl;
  mergeSort(array4,0,size-1);
  timer = time(NULL);
  cout << "End: " << timer << endl;
  cout << endl;
  cout << "Quick Sort: \n";
  cout << "Start: " << timer << endl;
  quickSort(array5,0,size-1);
  timer = time(NULL);
  cout << "End: " << timer << endl;
  cout << endl;
  return 0;
}
