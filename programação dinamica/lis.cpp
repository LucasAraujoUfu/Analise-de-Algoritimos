#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> lis(vector<int> &v){

	vector<int> pilha;

	for(int i=0;i<v.size();i++){
		
		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(),v[i]);
		if(it==pilha.end())pilha.push_back(v[i]);
		else *it = v[i];

	}

	return pilha;
}

int main(void){
	int n;
	while(cin>>n){
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		vector<int> u = lis(v);
		for(int i : u){
			printf("%d ",i);
		}puts("");
	}
}
