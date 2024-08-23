// There are N stones, numbered 1,2,..,N. For each i (1≤i≤N),
// the height of Stone i is hi. There is a frog who is initially
// on Stone 1. He will repeat the following action some number of
// times to reach Stone N: If the frog is currently on Stone i, jump
// to Stone i+1 or Stone i+2. Here, a cost of hi- hj is incurred,
// where j is the stone to land on. Find the minimum possible total
// cost incurred before the frog reaches Stone N.
// Input n= 4
// arr[]=10 30 40 20
// Output= 30
#include <iostream>
#include <cstdlib>
using namespace std;
int Incurred(int *heights, int currentposition, int size)
{
    if (currentposition == size - 1)
        return 0;
    if (currentposition == size - 2)
        return Incurred(heights, currentposition + 1, size) + abs(heights[currentposition] - heights[currentposition + 1]);
    return min(Incurred(heights, currentposition + 1, size) + abs(heights[currentposition] - heights[currentposition + 1]), Incurred(heights, currentposition + 2, size) + abs(heights[currentposition] - heights[currentposition + 2]));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int *heights = nullptr;
    int size;
    cout << "enter total no. of steps " << endl;
    cin >> size;
    heights = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "height of block " << i + 1 << endl;
        cin >> heights[i];
    }
    cout << Incurred(heights, 0, size);
    delete[] heights;
    return EXIT_SUCCESS;
}
