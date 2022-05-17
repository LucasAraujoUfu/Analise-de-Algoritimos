#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

void merge(vi &v,int in, int m, int fm){
	vi aux(v);
	int i=in,j=m+1;
	for(int k=in;k<=fm;k++){
		if(i>m)v[k]=aux[j++];
		else if(j>fm)v[k]=aux[i++];
		else if(aux[j]<aux[i])v[k]=aux[j++];
		else v[k]=aux[i++];
	}
}

void mergeSort(vi &v, int in, int fm){
	if(in>=fm)return;
	int m = in+(fm-in)/2;
	mergeSort(v,in,m);
	mergeSort(v,m+1,fm);
	merge(v,in,m,fm);
}

int main(void){
	int n;
	scanf("%d",&n);
	vi v(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	mergeSort(v,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}printf("\n");
	return 0;
}
