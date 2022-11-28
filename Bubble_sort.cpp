#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    bool swaped;

    for(int i = 0; i < n-1; i++)
    {
        swaped = false;
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swaped = true;
            }
        }
        if(!swaped)
        break;
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main()
{
    int n;
    cout<<"Input the size of the array: "<<endl;
    cin>>n;
    cout<<"Input the array: "<<endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    bubbleSort(arr, n);
    print(arr,n);
    
    return 0;
}