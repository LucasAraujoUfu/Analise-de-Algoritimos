#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;

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
	//int n;
	//scanf("%d",&n);
	srand(time(NULL));	
	map<int,int> M;
	for(int n=5;n<=100000;n+=5){
		vi v(n);
		for(int i=0;i<n;i++){
			//scanf("%d",&v[i]);
			v[i] = rand();
		}
		time_t in = clock();
		quickSort(v,0,n-1);
		time_t fm = clock();
		M[n] = fm-in;
		printf(".");
	}
	FILE *f = fopen("Resp.txt","w");
	for(auto i : M){
		fprintf(f,"%d: %d\n",i.first,i.second);
	}
	fclose(f);
	/*for(int i=0;i<n;i++){
		printf("%d ",v[i]);
	}printf("\n");*/
	return 0;
}
