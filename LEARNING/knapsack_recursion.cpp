#include <iostream>
#include <cstdlib>
using namespace std;

int knapsack(int values[], int weights[], int n, int weight)
{
    if (n == 0 || weight == 0)
    {
        return 0;
    }
    if (weights[n - 1] > weight)
    {
        return knapsack(values, weights, n - 1, weight);
    }
    else
    {
        return max(
            values[n - 1] + knapsack(values, weights, n - 1, weight - weights[n - 1]),
            knapsack(values, weights, n - 1, weight)
        );
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout << "How many items do you have: " << endl;
    int size;
    cin >> size;
    int values[size], weights[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value and corresponding weight for item " << i + 1 << ": ";
        cin >> values[i] >> weights[i];
    }
    int weight;
    cout << "Enter the maximum weight that the knapsack can hold: " << endl;
    cin >> weight;
    cout << "Maximum value that the knapsack can contain is " << knapsack(values, weights, size, weight) << endl;
    return EXIT_SUCCESS;
}
