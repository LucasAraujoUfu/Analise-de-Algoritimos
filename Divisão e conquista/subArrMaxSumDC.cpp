#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

pair<int,int> maxSum(int *v,int in, int fm){
    if(in==fm)return {in,fm};
    int m = (fm+in)/2;
    pair<int,int> rp = maxSum(v,in,m);
    pair<int,int> lp = maxSum(v,m+1,fm);
    int d=0,e=0,tot=0;
    for(int i=rp.F;i<=rp.S;i++){
        d+=v[i];
    }
    for(int i=lp.F;i<=lp.S;i++){
        e+=v[i];
    }
    for(int i=rp.F;i<=lp.S;i++){
        tot+=v[i];
    }
    if(tot>max(e,d)){
        return {rp.F,lp.S};
    }
    else if(e>d){
        return {lp.F,lp.S};
    }
    else{
        return {rp.F,rp.S};
    }
}


int main(){
    int v[8] = {1,-2,3,4,4,3,-2,1};
    pair<int,int> res = maxSum(v,0,7);
    printf("%d, %d\n",res.F,res.S);
    return 0;
}
