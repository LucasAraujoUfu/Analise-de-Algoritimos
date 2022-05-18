#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int i, int f){
    int pivo = v[f];
	int q = i-1;
	
	for(int j=i;j<=f;j++){
		if(v[j]<pivo){
			q++;
			swap(v[q],v[j]);
		}
	}
	swap(v[++q],v[f]);
	return q;
}

void quickSort(vector<int> &v, int i, int f){
    if(i>=f)return;
    int q = partition(v,i,f);
    quickSort(v,i,q-1);
    quickSort(v,q+1,f);
}

int main(void){
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	quickSort(v,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}printf("\n");
	return 0;
}
