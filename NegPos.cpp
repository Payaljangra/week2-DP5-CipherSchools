#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[];
        for(int i=0; i<n;i++)
        {
            cin>>arr[i];
        }
        int sum=0;
        for(int i=0; i<n; i+2)
        {
            arr[i] = arr[i] * (-1);
            arr[i+1] = arr[i+1] * (-1);
        }

    }
}