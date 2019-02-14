#include<iostream>
using namespace std;

int main()
{
    int n, i;
    long long arr[50];
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    if(arr[1] - arr[0] == arr[2] - arr[1])
        cout << arr[n-1]+arr[1]-arr[0];
    else if(arr[1] / arr[0] == arr[2] / arr[1] )
        cout << arr[n-1]*arr[1]/arr[0];
    return 0;
}
