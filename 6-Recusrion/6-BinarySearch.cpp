#include<iostream>
#include<vector>
using namespace std;
int BinarySearch(vector<int>arr,int target,int start,int end){
   if(start<=end){

    int mid=start+(end-start)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(target>=arr[mid]){
       return BinarySearch(arr,target,mid+1,end);
    }
    else{
        return BinarySearch(arr,target,start,mid-1);
    }
   }
   return -1;
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 9;

    int result = BinarySearch(arr, target,0, arr.size() - 1);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}


// __________________TIME COMPLEXITY_______________________
// TC=log2n * o(1)
// TC=o(logn)

// ________________SPACE COMPLEXITY________________________
// SC=o(logn)



















// void reverseString(string str,int indx){                        //string=Hassan     nassah
        
//    if(indx<0){
//     return;
//    }
//    cout<<str[indx];
//    reverseString(str,indx-1);
// }

// int main(){
//     string input="Hassan";
//       reverseString(input,input.length()-1);
//     return 0;
// }