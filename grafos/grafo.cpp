#include <iostream>

using namespace std;

int fun(int *v, int n, int i, int *memo){
	if(i>=n)return 0;
	if(memo[i]!=0)return memo[i];
	return memo[i] = v[i] + max(fun(v,n,i+2),fun(v,n,i+3));
}

int main(){
	int n;
	cin>>n;
	int v[n];
	int memo[n];
	memset(memo,0,sizeof(memo));
	for(int i=0;i<n;i++)cin>>v[i];
	memo[n-1] = v[n-1];
	memo[n-2] = v[n-2];
	int mx = max(fun(v,n,0,memo),fun(v,n,1,memo));
	cout<<mx<<endl;
	return 0;
}
