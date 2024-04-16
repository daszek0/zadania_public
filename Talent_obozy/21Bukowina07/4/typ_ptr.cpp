// Jakub Daszkiewicz
// zadanie Drukarka

#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct Trie_node
{
	bool e = false;			  // koniec słowa
	map<char, Trie_node *> n; // sąsiedzi
	Trie_node *bs;			  // największe poddrzewo
};

vector<char> a; // odpowiedź

int wtl(Trie_node *n) // znalezienie trasy do najdłuższego
{
	int r = 0, d;
	for (auto i : n->n)
	{
		d = wtl(i.second);
		if (d > r)
		{
			r = d;
			n->bs = i.second;
		}
		// r = max(r, wtl(i.second));
	}
	return r + 1;
}

void ga(Trie_node *n) // znalezienie odpowiedzi
{
	char ll = 0;
	if (n->e)
		a.push_back('P');
	for (auto i : n->n)
	{
		if (i.second == n->bs)
		{
			ll = i.first;
			continue;
		}
		a.push_back(i.first);
		ga(i.second);
		a.push_back('-');
	}
	if (ll != 0)
	{
		a.push_back(ll);
		ga(n->bs);
		a.push_back('-');
	}
}

int main()
{
	int n; // liczba słów
	scanf("%d\n", &n);
	char c;					// znak do wczytywania
	Trie_node f;			// pierwszy wierzchołek
	Trie_node *cn;			// bieżący wierzchołek
	vector<Trie_node *> td; // do usunięcia
	for (int i = 0; i < n; i++)
	{
		c = getchar_unlocked();
		cn = &f;
		while (c >= 'a' && c <= 'z')
		{
			if (!(cn->n.count(c)))
			{
				cn->n[c] = new Trie_node;
				td.push_back(cn->n[c]);
			}
			cn = cn->n[c];
			c = getchar_unlocked();
		}
		cn->e = true;
	}
	// char lnc; // znak ostatniego wierzchołka
	// int md = 0, cmd;
	// for (auto i : f.n)
	// {
	// 	cmd = wtl(i.second);
	// 	if (cmd > md)
	// 	{
	// 		md = cmd;
	// 		lnc = i.first;
	// 	}
	// }
	// for (auto i : f.n)
	// {
	// 	if (i.first == lnc)
	// 		continue;
	// 	a.push_back(i.first);
	// 	ga(i.second);
	// 	a.push_back('-');
	// }
	// a.push_back(lnc);
	// ga(f.n[lnc]);
	// a.push_back('-');
	wtl(&f);
	ga(&f);
	for (auto i : td)
	{
		delete i;
	}
	while (a.back() == '-')
		a.pop_back();
	printf("%lu\n", a.size());
	for (auto i : a)
	{
		printf("%c\n", i);
	}
	return 0;
}