#include <bits/stdc++.h>
using namespace std;
stack <int> s;
int minEle;
void push(int x){
    if(s.size()==0){
        minEle=x;
        s.push(x);
    }
    else{
        if(x>=minEle){
            s.push(x);
        }
        else if(x<minEle){
            s.push((2*x)-minEle);
            minEle=x;
        }
    }
}
void pop(){
    if(s.size()==0){
        return ;
    }
    else{
        if(s.top()>=minEle){
            s.pop();
        }
        else if(s.top()<minEle){
            minEle=2*minEle-s.top();
            s.pop();
        }
    }

}
int top(){
    if(s.size()==0){
        return -1;
    }
    else {
        if(s.top()>=minEle){
            return s.top();
        }
        else{
            return minEle;
        }
    }
}
int getMin(){
    if(s.size()==0){
        return -1;
    }
    return minEle;
}
int main(){
    push(10);
    push(5);
    push(4);
    cout<<getMin()<<"\n";
    return 0;
}