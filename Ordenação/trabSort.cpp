#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;

void insertionSort(vector<int> &v, int in, int fm){
    for(int j=1;j<=fm;j++){
        int k = v[j];
        int i = j-1;
        while(i>=in && v[i]>k){
            v[i+1] = v[i];
            i--;
        }
        v[i+1] = k;
    }
}

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

void mergeSort(vi &v, int in, int fm, int lim=0){
	if(in>=fm)return;
	if(fm-in<=lim){
		insertionSort(v,in,fm);
	}
	int m = in+(fm-in)/2;
	mergeSort(v,in,m);
	mergeSort(v,m+1,fm);
	merge(v,in,m,fm);
}

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

void quickSort(vector<int> &v, int i, int f,int lim=0){
    if(i>=f)return;
    if(f-i<=lim){
    	insertionSort(v,i,f);
    }
    int q = partition(v,i,f);
    quickSort(v,i,q-1);
    quickSort(v,q+1,f);
}

void printMap(map<int,int> m){
	for(auto i : m)
		printf("%d - %d\n",i.first,i.second);
	puts("---------------------------------------------------------");
}

void testes(vi v){
	map<int,int> ms;
	map<int,int> qs;

	pair<int,int> qmin;
	pair<int,int> mmin;

	for(int i=0;i<fmin(100,v.size());i++){
		vi w(v);
		clock_t in = clock();
		mergeSort(v,0,v.size()-1,10);
		clock_t fm = clock();
		ms[i] = fm-in;
		if(i==0)mmin={ms[i],i};
		if(ms[i]<mmin.first)mmin={ms[i],i};
	}
	
	for(int i=0;i<fmin(100,v.size());i++){
		vi u(v);
		clock_t in = clock();
		quickSort(u,0,u.size()-1,10);
		clock_t fm = clock();
		qs[i] = fm-in;
		if(i==0)qmin={qs[i],i};
		if(qs[i]<qmin.first)qmin={ms[i],i};
	}

	//printMap(qs);
	//printMap(ms);	
	
	printf("%d - %d\n",mmin.first,mmin.second);
	printf("%d - %d\n",qmin.first,qmin.second);
}

void exec(vi v){
	vi u(v);
	clock_t in = clock();
	mergeSort(u,0,u.size()-1,50);
	clock_t fm = clock();
	printf("Merge Sort: %dms\n",fm-in);
	vi w(v);
	in = clock();
	mergeSort(w,0,w.size()-1,5);
	fm = clock();
	printf("Quick Sort: %dms\n",fm-in);
}

int main(void){
	int n;
	scanf("%d",&n);
	vi v(n);
	srand(time(NULL));
	for(int i=0;i<n;i++){
		//scanf("%d",&v[i]);
		v[i] = rand() % 1000000;
	}
	//testes(v);

	exec(v);

	return 0;
}
