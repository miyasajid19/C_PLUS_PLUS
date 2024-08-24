// Given an array of n integers and a target value x.
// Print whether x exists in the array or not.
// Constraints:
// 0 <= n <=le6 , -1e8 <=x<=le8, - l * e * 8 <= a[i] <=le8
// Inputl: n = 8 , x = 14 , ay = [4, 12, 54, 14, 3, 8, 6, 1]
// Outputl: Yes
// Input2: n = 1 , x = 9 , array = [2]
// Output2: No
#include <iostream>
#include <cstdlib>
#include<vector>
using namespace std;
bool findX(vector<int>arr, int value)
{
    
    if(arr.size()==0)
    {
       return false; 
    }
    if(arr.back()==value)
    {
        return true;
    }
    arr.pop_back();
    return findX(arr,value);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
vector<int> arr;
int size,num;
cout<<"how many data do you have?"<<endl;
cin>>size;
for(int i =0;i<size;i++)
{
    cout<<"data "<<i+1<<":::"<<endl;
    cin>>num;
    arr.push_back(num);
}
cout<<"Enter the data you want ot search??"<<endl;
cin>>num;
findX(arr,num)?cout<<"element is present in the chuunk of data"<<endl:cout<<"element is not present in the chunk of data"<<endl;
    return EXIT_SUCCESS;
}