#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int dim;
    cout<<"enter the dimension of square matrix : "<<endl;
    cin>>dim;
    int arr[dim][dim];
    for (int i =0;i<dim;i++)
    {
        for (int j=0;j<dim;j++)
        {
            cout<<"arr["<<i<<"]"<<"["<<j<<"]"<<endl;
            cin>>arr[i][j];
        }
    }
    for (int i =0;i<dim;i++)
    {
        for (int j=i;j<dim;j++)
        {
                    int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
        for (int i =0;i<dim;i++)
    {
        for (int j=0;j<dim;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return EXIT_SUCCESS;
}