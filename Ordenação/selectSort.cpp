#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void selectionSort(vector<int> &v){
    for(int i=0;i<v.size();i++){
        int me=i;
        for(int j=i;j<v.size();j++){
            if(v[j]<v[me]){
                me = j;
            }
        }
        if(me!=i)
            swap(v[i],v[me]);
    }
}


int main(void){
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	selectionSort(v);
	for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}printf("\n");
	return 0;
}