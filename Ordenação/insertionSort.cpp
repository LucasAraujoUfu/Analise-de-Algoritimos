#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


void insertionSort(vector<int> &v){
    for(int j=1;j<v.size();j++){
        int k = v[j];
        int i = j-1;
        while(i>=0 && v[i]>k){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = k;
    }
}

int main(void){
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	insertionSort(v);
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}printf("\n");
	return 0;
}