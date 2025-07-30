// You’re working on a logistics system for a warehouse. The system keeps track of packages that are ready to be delivered. Each package has a priority level (integer) stored in a vector<int>.
// 🎯 Your tasks:
// Input the priority levels of n packages.
// Remove all packages with priority 0 (these were cancelled).
// Sort the remaining packages by priority in descending order (highest priority first).
// Find and print the second highest priority package.
// Print the updated list of packages.


#include <iostream>
#include <Vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of pakages:" << endl;
    cin >> n;
    vector<int> prioritylvl(n);

    cout << "Enter priority level for each package:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> prioritylvl[i];
    }

    for (int priority : prioritylvl)
    {
        cout << priority;
    }

    vector<int> cleaned;
    for (int i = 0; i < n; i++)
    {
        if (prioritylvl[i] != 0)
        {
            cleaned.push_back(prioritylvl[i]);
        }
    }
    cout << "\nCleaned vector (no 0s): ";
    for (int p : cleaned)
    {
        cout << p << " ";
    }
    cout << endl;

    sort(cleaned.begin(),cleaned.end());
    reverse(cleaned.begin(),cleaned.end());

    for(int p:cleaned){
        cout<<p<<" ";
    }

    if(cleaned.size()<2){
    cout << "Not enough packages to find second highest.\n";}
    else{
        int highest=cleaned[0];     //had arranged in decending (larger to  samller)
        int secondhighest=-1;
        for(int i=0;i<cleaned.size();i++){
                if(cleaned[i]<highest){
                    secondhighest=cleaned[i];
                    break;
                }
        }
        if (secondhighest == -1) {
            cout << "All packages have the same priority.\n";
        } else {
            cout << "Second highest priority: " << secondhighest << endl;
        }
    }

}