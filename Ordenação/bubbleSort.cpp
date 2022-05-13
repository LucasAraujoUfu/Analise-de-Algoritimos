#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

void bubble(vector<int> &v){
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v[i]>v[j]){
				swap(v[i],v[j]);
			}
		}
	}
}


int main(void){
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	bubble(v);
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}printf("\n");
	return 0;
}
