#include <iostream>
#include <stdio.h>
using namespace std;



void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  


void printArray(int arr[], int n)    //function to print the array
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[n-i] << " ";  
    cout << endl; 
}  
  


int main()  
{   
    
    int n;
    cin>>n;
    int *arr = new int[n+1]; 
       
       
    for(int i = 0;i< n;i++){
        arr[i] = i;
    }
  
    insertionSort(arr, n);  
    // printArray(arr, n);  
  
    return 0;  
}





