import math

def teste(l):
	if len(l)<3:
		return 0
	mn = math.inf
	for i in range(1,len(l)-1):
		mn = min(teste(l[i-1:i]+l[i+1:])+l[i]*l[i-1]*l[i+1],mn)
	return mn


l = [1,2,3,4]
print(teste(l))
