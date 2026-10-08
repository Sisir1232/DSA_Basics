#include<iostream>
using namespace std;
int linearSearch(int arr[],int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){                     // searching key one by one in array 
            return i;                        // time complexity of O(n)
        }                                    // space complexity of O(1)
    }
    return -1;
}
int binarySearchRecursive(int arr[],int low,int high, int key){
    if(low>high){
        return -1;                            //condition when key is not found 
    }
    int mid=(low+high)/2;
    if(key==arr[mid]){
        return mid;                             //mid index is the point of sub-division
    }
    else if (key< mid){
        return binarySearchRecursive(arr, low, mid-1,  key);
    }                                                       // partition the array into two sub array 
    else{
        return binarySearchRecursive(arr, mid+1, high,  key);           // time complexity:O(log2(n))
    }                                                          // space complexity:O(log2(n)) for stack frame 
}
int binarySearchIterative(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)                // condition when key is not found in entire array 
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }                               // instead calling the functions by changing the parameters to subdivide 
        else                            // change the low and high variables accordingly inside the function
        {
            low = mid + 1;
        }
    }

    return -1;
}
int main(){
    int arr[]={10,20,30,40,50};
    int key=4,size=sizeof(arr)/sizeof(arr[0]);
    int indexL=linearSearch(arr, size, key);
    if(indexL!=-1){
        cout<<" After Linear search ,the index of the key was found to be in :"<<indexL<<endl;
    }
    else{
        cout<<"key was not found in the given array "<<endl;
    }

    int low=0,high=4;
    int indexB=binarySearchRecursive(arr,low,high, key);
    if(indexB!=-1){
        cout<<" After Binary search ,the index of the key was found to be in :"<<indexB<<endl;
    }
    else{
        cout<<"key was not found in the given array "<<endl;
    }
    return 0;
}