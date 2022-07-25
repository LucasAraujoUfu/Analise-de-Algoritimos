#include <iostream>

using namespace std;

int fun(int *v, int n, int i){
	if(i>=n)return 0;
	return v[i] + max(fun(v,n,i+2),fun(v,n,i+3));
}

int main(){
	int n;
	cin>>n;
	int v[n];
	for(int i=0;i<n;i++)cin>>v[i];
	int mx = max(fun(v,n,0),fun(v,n,1));
	cout<<mx<<endl;
	return 0;
}
