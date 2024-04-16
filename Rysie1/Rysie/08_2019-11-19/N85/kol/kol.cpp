#include <bits/stdc++.h>

using namespace std;

const int N=131072;
int tree[262144][2]; // trzymamy aktualna wartosc i ta do przepchniecia
int wynik;

void push(int w)
{
	int a=tree[w][1];
	tree[w*2][0]*=a;
	tree[w*2][1]*=a;
	tree[w*2+1][0]*=a;
	tree[w*2+1][1]*=a;
	tree[w][1]=1;
}

void add (int w, int p, int k, int x, int y, int val)
{
	if (k<x || p>y) return;
	if (p>=x && k<=y)
	{
		tree[w][0]*=val;
		tree[w][1]*val;
		return;
	}
	push(w); //przed schodzeniem nizej uaktualniamy wynik w synach
	add(w*2,p,(p+k)/2,x,y,val);
	add(w*2+1,(p+k)/2+1,k,x,y,val);
	tree[w][0]=tree[w*2][0]+tree[w*2+1][0]; //uaktualniamy informacje w danym wierzcholku
}

void query(int w, int p, int k, int x, int y)
{
	if (k<x || p>y) return;
	if (p>=x && k<=y) 
	{
		wynik+=tree[w][0];
		return;
	} 
	push(w); //przed schodzeniem nizej uaktualniamy wynik w synach
	query(w*2,p,(p+k)/2,x,y);
	query(w*2+1,(p+k)/2+1,k,x,y);
}

int main()
{
	//jakies wywolania naszego drzewka
}
