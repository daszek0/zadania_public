// Jakub Daszkiewicz
// zadanie Plażowicze

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void read_int(int *n)
{
	int r = 0;
	char c = getchar_unlocked();
	while (c < '0' || c > '9')
		c = getchar_unlocked();
	while (c >= '0' && c <= '9')
	{
		r = (r << 3) + (r << 1) + c - '0';
		c = getchar_unlocked();
	}
	*n = r;
}

void read_ll(long long *n)
{
	long long r = 0;
	char c = getchar_unlocked();
	while (c < '0' || c > '9')
		c = getchar_unlocked();
	while (c >= '0' && c <= '9')
	{
		r = (r << 3) + (r << 1) + c - '0';
		c = getchar_unlocked();
	}
	*n = r;
}

struct fract // ułamek zwykły p/q
{
	long long p, q;
	fract s()
	{
		long long gcd = __gcd(p, q);
		p /= gcd;
		q /= gcd;
		return *this;
	}
	fract operator+(const fract &f)
	{
		fract a;
		a.p = p * f.q + q * f.p;
		a.q = q * f.q;
		return a.s();
	}
	fract operator-(const fract &f)
	{
		fract a;
		a.p = p * f.q - q * f.p;
		a.q = q * f.q;
		return a.s();
	}
	fract div2() // dzielenie przez 2
	{
		fract a = *this;
		if (p % 2)
			a.q <<= 1;
		else
			a.p >>= 1;
		return a;
	}
	bool operator<(const fract &f)
	{
		if (p == f.p)
		{
			return q > f.q;
		}
		if (q == f.q)
		{
			return p < f.p;
		}
		return p * f.q < q * f.p;
	}
	bool operator>(const fract &f)
	{
		if (p == f.p)
		{
			return q < f.q;
		}
		if (q == f.q)
		{
			return p > f.p;
		}
		return p * f.q > q * f.p;
	}
	void write()
	{
		printf("%lld/%lld\n", p, q);
	}
};

int main()
{
	int pn; // plażowicze
	int l;	// długość plaży
	int qn; // liczba zapytań
	read_int(&pn);
	read_int(&l);
	read_int(&qn);
	vector<fract> p; // pozycje plażowiczów
	fract t;		 // wczytywanie
	t.q = 1LL;
	for (int i = 0; i < pn; i++)
	{
		read_ll(&t.p);
		p.push_back(t);
	}
	sort(p.begin(), p.end());
	int q[qn];	// zapytania
	int mq = 0; // największe zapytanie
	for (int i = 0; i < qn; i++)
	{
		read_int(&q[i]);
		mq = max(mq, q[i]);
	}
	fract a[mq];				 // odpowiedzi
	fract md;					 // maksymalna odległość
	vector<fract>::iterator mdi; // iterator po maksymalnej odległości
	for (int i = 0; i < mq; i++)
	{
		md = {0, 1};
		mdi = p.begin();
		for (auto it = next(p.begin()); it != p.end(); it++)
		{
			if (*it - *prev(it) > md)
			{
				md = *it - *prev(it);
				mdi = it;
			}
		}
		a[i] = (*prev(mdi) + *mdi).div2();
		p.insert(mdi, a[i]);
	}
	for (int i = 0; i < qn; i++)
	{
		a[q[i] - 1].write();
	}
	return 0;
}