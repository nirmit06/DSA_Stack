#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int mxL[n];
    int mxR[n];

    mxL[0]=arr[0];

    for(int i=1;i<n;i++){
        mxL[i]=max(mxL[i-1],arr[i]);
    }

    mxR[n-1]=arr[n-1];

    for(int i=n-2;i>=0;i--){
        mxR[i]=max(mxR[i+1],arr[i]);
    }

    int water[n];
    int sum=0;
    for(int i=0;i<n;i++){
        water[i]=min(mxL[i],mxR[i])-arr[i];
        sum+=water[i];
    }

    cout<<sum<<"\n";
    return 0;
}