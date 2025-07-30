#include<iostream>
using namespace std;

void SelectionSort(int arr[],int n)
{
    
  for(int i=0;i<n-1;i++)
  {
    int smallestidx=i;
    for(int j=i+1;j<n;j++)
    {
      if(arr[j]<arr[smallestidx])
      {
        smallestidx=j;
      }                                                                                                 
    }
    swap(arr[i],arr[smallestidx]);
  }

  
}

void Print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

 int main()
{
    int arr[]={1,2,4,3,5,645,423,5,6};
    int n=9;
    Print(arr,n);
    SelectionSort(arr,n);
    cout<<"After applying Selection Sort :"<<endl;
    Print(arr,n);
}