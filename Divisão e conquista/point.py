import math
import random
import time
import pandas as pd
import matplotlib.pyplot as plt

def dist(p1,p2):
    return math.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)


def merge(V,i,m,f):
	U = []
	i_ = i
	j = m+1
	for t in V:
		if (V[i]<=V[j] and i<=m) or j>=f:
			U.append(V[i])
			i+=1
		else:
			U.append(V[j])
			j+=1
	return U


def parProximoDireto(V,i,f):  # O(n^2)
    d=dist(V[i],V[i+1])
    par=(V[i],V[i+1])
    for j in range(i,f-1):
        for k in range(j+1,f):
            if dist(V[j],V[k])<d:
                d= dist(V[j],V[k])
                par=(V[j],V[k])
    return (d,par)


def parProximoDC(V,i,f):
    if f-i<100:
        return parProximoDireto(V,i,f)
    m = int((f+i)/2)
    r1 = parProximoDC(V,i,m)
    r2 = parProximoDC(V,m+1,f)
    delta = r1[0]
    par = r1[1]
    if r2[0]<r1[0]:
        delta = r2[0]
        par = r2[1]
    faixa = []
    for k in range(i,f):
        if V[k][0]>V[m][0]-delta and V[k][0]<V[m][0]+delta:
            faixa.append(V[k])
    faixa = sorted(faixa, key= lambda x:x[1])
    for k in range(len(faixa)-1):
        for l in range(1,8):
            if k+l < len(faixa):
                if dist(faixa[k],faixa[k+l])<delta:
                    delta = dist(faixa[k],faixa[k+l])
                    par = (faixa[k],faixa[k+l])
    return (delta,par)


def parProximoPB(V,i,f):
    if f-i<100:
        return parProximoDireto(V,i,f)
    m = int((f+i)/2)
    r1 = parProximoDC(V,i,m)
    r2 = parProximoDC(V,m+1,f)
    delta = r1[0]
    par = r1[1]
    if r2[0]<r1[0]:
        delta = r2[0]
        par = r2[1]
    '''faixa = []
    for k in range(i,f):
        if V[k][0]>V[m][0]-delta and V[k][0]<V[m][0]+delta:
            faixa.append(V[k])'''
    faixa = merge(V,i,m,f)  # sorted(faixa, key= lambda x:x[1])
    for k in range(len(faixa)-1):
        for l in range(1,8):
            if k+l < len(faixa):
                if dist(faixa[k],faixa[k+l])<delta:
                    delta = dist(faixa[k],faixa[k+l])
                    par = (faixa[k],faixa[k+l])
    return (delta,par)

def randP(n):
	prob = []
	x=-1
	for i in range(n):
	   x += random.randint(1,3)
	   y = random.randint(0,100000)
	   prob.append([x,y])
	return prob


df = pd.DataFrame()

l1=[]
l2=[]
l3=[]

for i in range(100,101,10):
	prob = randP(i)
	l = [0,0,0]
	
	t0 = time.time()
	print(parProximoDireto(prob,0,len(prob)))
	t1 =time.time()
	l1.append(t1-t0)
	
	t0 = time.time()
	print(parProximoDC(prob,0,len(prob)))
	t1 =time.time()
	l2.append(t1-t0)
	
	t0 = time.time()
	print(parProximoPB(prob,0,len(prob)))
	t1 =time.time()
	l3.append(t1-t0)
	
df["quadratico"] = l1
df["divisão"] = l2
df["pig back"] = l3
	
#print(df)
df.plot()
plt.show()
