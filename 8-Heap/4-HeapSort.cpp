#include <iostream>
using namespace std;

void Heapify(int arr[], int index, int n)
{
    int largeest=index;
    int left=2*index+1;
    int right=2*index+2;

    if(left<n && arr[left]>arr[largeest]){
        largeest=left;
    }

    
    if(right<n && arr[right]>arr[largeest]){
        largeest=right;
    }

    if(largeest!=index){
        swap(arr[index],arr[largeest]);
        Heapify(arr,largeest,n);
    }

}
void BuildMaxHeap(int arr[], int n)
{
    // step down
    for (int i = n / 2 - 1; i >= 0; i--)                                   //n is the total number of elements in the array.      int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};    int n = 10;
    {
        Heapify(arr, i, n);
    }
    // So the last non-leaf node (i.e., a node that has at least one child) is at:
   // i = n/2 - 1
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
     cout<<endl;
};

void sortArray(int arr[],int n)
{
        for(int i=n-1;i>0;i--){
            swap(arr[i],arr[0]);
            Heapify(arr,0,i);
        } 
}

int main(){
    int arr[]={10,3,8,9,5,13,18,14,17,70};
    cout<<"--Max Heap--"<<endl;
    BuildMaxHeap(arr,10);
    print(arr,10);
    cout<<"---Heap after Heap Sorting---\n";
    sortArray(arr,10);
    print(arr,10);
}