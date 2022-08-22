#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>

#include "graph.h"

using namespace std;

set<int> func(int pos, int *v, graph *g){
	if(pos>sizeGraph(g)){
		*v = 0;
		return set<int>();
	}
	int r1 = value(g,pos+2),r2 = value(g,pos+3);
	set<int> _1 = func(pos+2,&r1,g);
	set<int> _2 = func(pos+3,&r2,g);
	*v += max(r1,r2);
	if(r1>=r2){
		_1.insert(pos);
		return _1;
	}
	else{
		_2.insert(pos);
		return _2;
	}
}

int main(){
	int n; //número de nós
	scanf("%d",&n);
	graph *g = createGraph();
	if(g!=NULL){
		for(int i=0;i<n;i++){
			int l;
			scanf("%d",&l);
			int t = addNodeGraph(g,l);
			if(t)return 1;
		}
		int r1 = value(g,1),r2 = value(g,2);
		set<int> _1 = func(1,&r1,g);
		set<int> _2 = func(2,&r2,g);
		set<int> res;
		if(r1>=r2){
			res = _1;
		}
		else{
			res = _2;
		}
		printf("Max: %d\nNodes:",max(r1,r2));
		for(auto i : res){
			printf(" %d",i);
		}printf("\n");
	}
	return 0;
}
