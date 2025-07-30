#include <iostream>
using namespace std;

class MinHeap
{
    int *arr;
    int size;
    int toatlSize;

public:
    MinHeap(int n)
    {
        arr = new int[n];
        size = 0;
        toatlSize = n;
    }

    void insert(int val)
    {
        if (size == toatlSize)
        {
            cout << "Heap overflow\n";
            return;
        }

        arr[size] = val;
        int index = size;
        size++;

        while (index > 0 && arr[(index - 1) / 2] > arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        cout << arr[index] << " added" << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        { // totalSize:Some of it might be unused!   size:These are the only values you’ve inserted so far.(correct)
            cout << arr[i] << " ";
        }
    }

    void heapify(int index)
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left] < arr[smallest])
        {
            smallest = left;
        }
        if (right < size && arr[right] < arr[smallest])
        {
            smallest = right;
        }

        if (smallest != index)
        {
            swap(arr[index], arr[smallest]);
            heapify(smallest); // Fix the subtree
        }
    }

    void Delete()
    {
        if (size == 0)
        {
            cout << "heap underflow";
            return;
        }

        cout << arr[0] << " removed from heap\n";
        arr[0] = arr[size - 1];
        size--;

        if (size == 0)
        {
            return;
        }

        heapify(0);
    }
};

int main()
{
    MinHeap h1(6);
    h1.insert(4);
    h1.insert(2);
    h1.insert(3);
    h1.insert(12);

    h1.print();
    cout<<endl;

    cout<<"---After Deleting---"<<endl;
    h1.Delete();
    h1.print();

}