#include<iostream>
using namespace std;
void traverse(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";    // one by one from consecutive memory locations 
    }
    cout<<endl;
}
int  findMin(int arr[],int size){
    int min=arr[0];                  // lets assume first element is minimum 
    for(int i=1;i<size;i++){    // go through all the array members one by one 
        if(min>arr[i]){          // if the array member is smaller than previously calculated minimum 
            min=arr[i];           // update the min to the array member
        }
    }
    return min;
}
int  findMax(int arr[],int size){
    int max=arr[0];                // lets assume first element is maximum 
    for(int i=1;i<size;i++){    // go through all the array members one by one 
        if(max<arr[i]){          // if the array member is smaller than previously calculated minimum 
            max=arr[i];           // update the min to the array member
        }
    }
    return max;
}
void deleteAtEnd(int arr[], int &size){ // size as reference variable to increment the size from local scope
    size--;
}
void deleteAtFront(int arr[], int &size){
    for(int i=0;i<size;i++){
        arr[i]=arr[i+1];           // shift the element by left and at last decrement the size
    }
    size--;
}
void deleteAtPos(int arr[], int &size,  int pos){ 
    for(int i=pos;i<size;i++){      
        arr[i]=arr[i+1];           // shift the element by left and at last decrement the size
    }
    size--;
}
void insertAtEnd(int arr[], int &size, int value){ // size as reference variable to increment the size from local scope
    arr[size++]=value;
}
void insertAtFront(int arr[], int &size, int value){
    for(int i=size;i>0;i--){
        arr[i]=arr[i-1];           // shift the element by right making a vacant space for first one
    }
    arr[0]=value;
    size++;
}
void insertAtPos(int arr[], int &size, int value, int pos){ 
    for(int i=size;i>pos;i--){      // pos range is from 0-size
        arr[i]=arr[i-1];           // shift the element by right from pos making a vacant space for pos index 
    }
    arr[pos]=value;
    size++;
}
void reverse(int* arr,int size){
    int j=size-1;
    for(int i=0;i<size/2;i++){       // one index pointer from 0 to mid 
        int temp=arr[i];
        arr[i]=arr[j];                // swapping 
        arr[j]=temp;
        j--;                         // another from size to mid 
    }
}
void copyArray(int arr[],int size){
    int newArr[100]; // new array with max size 100 
    for(int i=0;i<size;i++){
        newArr[i]=arr[i];          // copy from original to new array 
    }
}
void mergeArrays(int* arr1,int size1, int* arr2,int size2){
    for(int i=0;i<size2;i++){
        arr1[size1+i]=arr2[i];
    }
}
int main(){
    int arr[100]={20,30,10,40,50};  
    int size=5; 
    traverse(arr,size);
    int min=findMin(arr,size);
    int max=findMax(arr,size);
    cout<<"minimum value="<<min<<endl;
    cout<<"maximum value="<<max<<endl;

    insertAtEnd(arr,size,60);
    insertAtFront(arr,size,5);
    insertAtPos(arr,size,25,3);
    traverse(arr,size);

    deleteAtFront(arr,size);
    deleteAtEnd(arr,size);
    deleteAtPos(arr,size,2);
    traverse(arr,size);

    reverse(arr,size);
    traverse(arr,size);

    int arr1[100]={10,20,30},arr2[100]={40,50,60};
    mergeArrays(arr1,3,arr2,3);
    traverse(arr1,6);
    return 0;
}