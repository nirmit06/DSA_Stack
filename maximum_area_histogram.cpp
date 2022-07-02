#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector <int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    //Modified code for NSL
    vector <int> left;
    stack <pair<int,int>> s;
    int pseudo=-1;
    for(int i=0;i<n;i++){
        if(s.size()==0){
            left.push_back(pseudo);
        }
        else if(s.size()>0 && s.top().first<v[i]){
            left.push_back(s.top().second);
        }
        else if(s.size()>0 && s.top().first>=v[i]){
            while(s.size()>0 && s.top().first>=v[i]){
                s.pop();
            }
            if(s.size()==0){
                left.push_back(pseudo);
            }
            else{
                left.push_back(s.top().second);
            }
        }
        s.push({v[i],i});
    }

    //Modified code for NSR
    vector <int> right;
    stack <pair<int,int>> s1;
    pseudo=n;
    for(int i=n-1;i>=0;i--){
        if(s1.size()==0){
            right.push_back(pseudo);
        }
        else if(s1.size()>0 && s1.top().first<v[i]){
            right.push_back(s1.top().second);
        }
        else if(s1.size()>0 && s1.top().first>=v[i]){
            while(s1.size()>0 && s1.top().first>=v[i]){
                s1.pop();
            }
            if(s1.size()==0){
                right.push_back(pseudo);
            }
            else{
                right.push_back(s1.top().second);
            }
        }
        s1.push({v[i],i});
    }
    reverse(right.begin(),right.end());

    vector <int> width(n);

    for(int i=0;i<n;i++){
        width[i]=right[i]-left[i]-1;
    }

    vector<int> area(n);
    int mx=INT_MIN;
    
    for(int i=0;i<n;i++){
        // cout<<width[i]<<" "<<v[i]<<"-\n";
        area[i]=width[i]*v[i];
        mx=max(mx,area[i]);
    }

    cout<<mx<<"\n";

    return 0;
}