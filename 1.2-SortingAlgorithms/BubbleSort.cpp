#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n)
{
for (int i=0;i<n-1;i++)
{
    bool swaped=false;
    for(int j=0;j<n-i-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
            bool swaped=true;
        }
    }
    if(!swaped){
      return;
    }
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
    BubbleSort(arr,n);
    cout<<"After applying Bubble Sort :"<<endl;
    Print(arr,n);
}

// Time Complexity:o(n*2)
// Not a good time complexity 
// Effecient Sorting algorithm workin nlogn TIME COMPLEXITY