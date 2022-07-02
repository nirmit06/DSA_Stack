#include <bits/stdc++.h>
using namespace std;
stack <int> s;
stack <int> ss;

void push(int a){
    s.push(a);
    if(ss.size()==0 || a<=ss.top()){
        ss.push(a);
    }
    return;
}

int getMin(){
    if(ss.size()==0){
        return -1;
    }
    return ss.top();
}

int pop(){
    if(s.size()==0)
        return -1;
    int ans=s.top();
    s.pop();
    if(ans==ss.top()){
        ss.pop();
    }
    return ans;
}
int main(){
    push(10);
    push(5);
    push(4);
    cout<<getMin()<<"\n";
    return 0;
}