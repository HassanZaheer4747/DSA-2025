#include <iostream>
using namespace std;

class MaxHeap
{
    int *arr;            //Using int* arr with new int[n] allows the heap size to be dynamic, i.e., you can create a heap of any size at runtime
    int size;       // toatl elemts in heap  :no of elemts present in heap at the time
    int total_size; // total size of array eg:int his case 6

public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    //    insert into the heap
    void insert(int value)                                     //BY USING ITERATIVE APPROCH
    {
        // if heap size is available or not
        if (size == total_size) // getting out of array(imp check),This condition checks if the heap is full, and prevents adding more than allowed.
        {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = value;             //Put the new value at the end of the heap (arr[size]).
        int index = size;
        size++;                           //Increment size since the heap now has one more element.

        // Compare it with its parents
        while (index > 0 && arr[(index - 1) / 2] < arr[index])     //parent<children  :wrong condition for max head
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << " is inserted into the heap\n";
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void Heapify(int index)
    {
        int largest=index;
        int left    =2*index+1;
        int right    =2*index+2;

         //largest will store the index of the element which is greater between parent, left child and right child

         if(left<size && arr[left]>arr[largest])      //left<size:to check if the index exist
         {
            largest=left;
         }
          if(right<size && arr[right]>arr[largest])
         {
            largest=right;
         }

         if(largest!=index){
            swap(arr[index],arr[largest]);
            Heapify(largest);
         }
    }

    void Delete()
    {
        // when deleting, you're removing elements, not adding.
        // So it's not possible to get an overflow(size == total_size) when deleting — you're not putting anything new in.
        if (size == 0) // if size of heap==0 ;nothing to delete
        {
            cout << "Heap Underflow\n";
            return;
        }

        cout << arr[0] << " deleted from the heap"; // in max heap we delete only first element
        arr[0] = arr[size - 1];    //The value at index 0 is replaced.
        size--;

        if(size==0)
        return;

        Heapify(0);
    }
};

int main()
{
    MaxHeap h1(6);
    h1.insert(4);
    h1.insert(2);
    h1.insert(3);
    h1.insert(12);

    h1.print();
}