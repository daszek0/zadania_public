// Jakub Daszkiewicz
// zadanie Drukarka

#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct Trie_node
{
	bool e = false;	  // koniec słowa
	map<char, int> n; // sąsiedzi
};

vector<Trie_node> g;
vector<char> a; // odpowiedź

int wtl(int n) // znalezienie trasy do najdłuższego
{
	int r = 0;
	for (auto i : n->n)
	{
		r = max(r, wtl(i.second));
	}
	return r + 1;
}

void ga(int n) // znalezienie odpowiedzi
{
	for (auto i : n->n)
	{
		a.push_back(i.first);
		ga(i.second);
		a.push_back('-');
	}
	if (n->e)
		a.push_back('P');
}

int main()
{
	int n; // liczba słów
	scanf("%d\n", &n);
	char c;		 // znak do wczytywania
	Trie_node e; // pusty wierzchołek
	int cn;		 // numer bieżącego wierzchołka
	for (int i = 0; i < n; i++)
	{
		c = getchar_unlocked();
		cn = 0;
		while (c >= 'a' && c <= 'z')
		{
			if (!(g[cn].n.count(c)))
			{
				g[cn].n[c] = g.size();
				g.push_back(e);
			}
			cn = g[cn].n[c];
			c = getchar_unlocked();
		}
		g[cn].e = true;
	}
	
	return 0;
}