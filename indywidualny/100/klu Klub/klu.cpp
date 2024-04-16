// Jakub Daszkiewicz
// zadanie Klub

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s; // sekcja
	cin >> s;
	long long p; // liczebność sekcji
	long long a = 0; // odpowiedź
	while (cin.eof() == false) // czytanie do końca pliku
	{
		cin >> p;
		if (s.length() % 2) // jeżeli liczba składników sekcji nieparzysta
			a += p;
		else // jeżeli parzysta
			a -= p;
		cin >> s;
	}
	cout << a << "\n";
	return 0;
}