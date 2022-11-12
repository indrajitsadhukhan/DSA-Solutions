#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int> v = {0,3,2,0,4};
    auto it=v.begin();
    advance(it,2);
    v.insert(it,10);
    // v.unique();
    for(int i: v)
    cout<<i<<' ';
    cout<<endl;
}
