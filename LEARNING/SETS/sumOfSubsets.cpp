#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

void sumOfSubset(int arr[], int size, int i, int sum, vector<int> &result)
{
    if (i == size)
    {
        result.push_back(sum);
        return;
    }
    sumOfSubset(arr, size, i + 1, sum + arr[i], result); // Including arr[i] in the subset
    sumOfSubset(arr, size, i + 1, sum, result);          // Excluding arr[i] from the subset
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    set<int> set1;
    int size, num;
    cout << "Enter how many data you have: " << endl;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Data " << i + 1 << " ::: " << endl;
        cin >> num;
        set1.insert(num); // Insert unique values into the set
    }

    int arr[set1.size()];
    size = 0;
    set<int>::iterator itr;
    for (itr = set1.begin(); itr != set1.end(); itr++)
    {
        arr[size++] = *itr; // Fill the array with set elements
    }

    cout << endl
         << "The possible sums of subsets are ::: " << endl;
    vector<int> result;
    sumOfSubset(arr, size, 0, 0, result);

    for (int value : result)
    {
        cout << value << " ";
    }

    return EXIT_SUCCESS;
}
