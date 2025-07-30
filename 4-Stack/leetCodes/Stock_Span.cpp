// ________________________Appproch by using Vector_____________________
// #include <iostream>
// #include <vector>
// using namespace std;

// class Stock_Spaner
// {
// private:
//     vector<int> arr;

//     public:
//     Stock_Spaner()
//     {
//         arr = {};
//     }

//     int next(int val)
//     {
//         arr.push_back(val);
//         int count = 1;

//         for(int i=arr.size()-2;i>=0;i--){
//             if(arr[i]<=val){
//                 count++;
//             }
//             else{
//                 break;
//             }
//         }
//         return count;
//     }
// };

// int main(){
//     Stock_Spaner s;
//    cout<< s.next(2)<<endl;
//    cout<< s.next(2)<<endl;
//    cout<< s.next(2)<<endl;
//    cout<< s.next(2)<<endl;
//    cout<< s.next(2)<<endl;

// }
// ----Conclusion----Using vector/array is not great approch as it will loop throug entire vector each time doing referse transversal(int i=arr.size()-2;i>=0;i--) andlooking for IF condition

// ________________________________BY USING STACK_________________________________________
#include <iostream>
#include <stack>
using namespace std;

class StockSpanner {
private:
    int index;  
    stack<pair<int, int>> st; // Stack to store {price, index}

public:
    StockSpanner() {
        index = -1; // Start index from -1
        while (!st.empty()) st.pop(); // Clear stack
    }

    int next(int val) {
        index++; // Increase index (representing the next stock day)

        // Remove all elements from the stack that have a price <= current price
        while (!st.empty() && st.top().first <= val) {
            st.pop();
        }

        // Compute stock span
        int ans = index - (st.empty() ? -1 : st.top().second);

        // Push current price and index to the stack
        st.push({val, index});

        return ans; // Return the span for this price
    }
};

int main() {
    StockSpanner s;
    cout << s.next(100) << endl; // 1
    cout << s.next(80) << endl;  // 1
    cout << s.next(60) << endl;  // 1
    cout << s.next(70) << endl;  // 2
    cout << s.next(60) << endl;  // 1
    cout << s.next(75) << endl;  // 4
    cout << s.next(85) << endl;  // 6
    return 0;
}
