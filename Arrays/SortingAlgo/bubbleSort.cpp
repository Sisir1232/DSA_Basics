#include<iostream>
using namespace std;
void bubbleSort(int* arr, int n ){
    int count=0;    // to detect no of swapping
    for(int i=0;i<n-1;i++){ // n-1 because last remaining element is already sorted ,n will also work 
        for(int j=0;j<n-i-1;j++){ // at each pass ( ith itr ) , largest element is in its correct positon: so no need to visit there 
            if(arr[j]>arr[j+1]){    // if early positions have higher value , push it to adjacent next position
                swap(arr[j], arr[j+1]);
                count++;
            }
        }
        if(count==0) return;   // in a pass if there is 0 swapping means array is already sorted
    }
}
void swap(int &a, int &b){   // use of ref variable to update the value of array member from another function
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int arr[]={50,40,30,20,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"before sort"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
    bubbleSort(arr,size);
    cout<<endl<<"after sort"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}

// Algorithm Analysis
// Time Complexity: Bestcase:O(n) Averagecase:O(n2)  worstcase:O(n2)
// space Complexity: O(1) : inplace sorting 

// made adapative using counting variable 
// stable because it retains the original order of equal values 
   // This is because swapping happens in arr[j]>arr[j+1] condition : if it is equal no swapping =order preserved
