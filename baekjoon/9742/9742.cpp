#include<iostream>
#include<string.h>
using namespace std;

int perm(int n);

int main()
{
	char z[11], result[11];
	int i, j, order;
	while(cin >> z >> order)
	{
		cout << z << " " << order << " = ";
	int iter = strlen(z);
	if(perm(strlen(z))<order)
	{
		cout << "No permutation" << endl;
		continue;
	}
	for(i=1; i<=iter; i++)
	{
		int omit = (order-1)/perm(iter-i);
		result[i-1] = z[omit];
		order %= perm(iter-i);
		if(order == 0)
			order = perm(iter-i);
		for(j=omit;j<strlen(z)-1;j++)
			z[j] = z[j+1];
		z[j]=0;
	}
	result[i-1]=0;
	cout << result << endl;
	}
	return 0;
}

int perm(int n)
{
	if(n==1||n==0)
		return 1;
	else
		return n*perm(n-1);
}
