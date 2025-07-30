#include<iostream>>
using namespace std;

void changearray(int arr[],int size){
cout<<"In function"<<endl;

for(int i=0;i<size;i++){
arr[i]=arr[i]*2;
}
}

int main(){
    int arr[5]={1,2,3,4,5};
    int size=5;


    changearray(arr,3);
    cout<<"In main"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}
// In pass by reference the valueof array in main fun is updated due to changearray fun but if it was pass by value the chagearry() fun will not update the value of main fun.