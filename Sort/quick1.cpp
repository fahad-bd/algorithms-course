#include<bits/stdc++.h>
using namespace std;

int partitionOfArr(int arr[], int low, int high){
    int pivot = arr[high];

    int i=low-1;
    int j=low;
    
    while(j<high){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[j]);

    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pivot_position = partitionOfArr(arr,low,high);

        quickSort(arr,low,pivot_position-1);
        quickSort(arr,pivot_position+1,high);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    quickSort(arr,0,n-1);

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    return 0;
}