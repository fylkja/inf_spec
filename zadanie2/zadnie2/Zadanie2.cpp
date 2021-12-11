#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <utility>
using namespace std;


pair <int, int> publiczny;
pair <int, int> prywatny;

bool czy_pierwsza(int n)
{
	if (n < 2)
		return false; //gdy liczba jest mniejsza niż 2 to nie jest pierwszą

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
	return true;
}


{
	return (a == 0) ? b : nwd(b % a, a);
}

bool checkNWD(int a, int b) {
	return (nwd(a, b) == 1);
}

void rsaGen() 
{
	int tab[] = { 2,3,5,7 };
	int p = tab[1];
	int q = tab[2];
	int n = p * q;
	int fEulera = (p - 1) * (q - 1);
	int e;
	int d = 0;
	while (true) 
	{
		srand(time(NULL));
		e = rand() % fEulera;
		if (e > 1)
			if (checkNWD(e,fEulera))
				break;
	}

	while (true)
	{
		if ((d * e) % fEulera == 1)
			if(!(d == e))
				break;
		d++;
	}
	publiczny = make_pair(n, e);
	prywatny = make_pair(n, d);
}


{
	for (int i = 0; i < tekst.length(); i++)
	{
		if ((tekst[i] > 96 && tekst[i] < 123) || tekst[i] == 32)
			continue;
		else
			return false;

		return true;
	}
}

class Szyfrowanie {
	public:
		
		{
			int wartosc;
			cout << "Podaj wartosc przesuniecia (Wieksza od 0 i mniejsza niz 27!)" << endl;
			while (true)
			{
				cin >> wartosc;
				if (!(wartosc > 0 && wartosc < 27))
					cout << endl << "Podaj poprawna wartosc!" << endl;
				else
					break;
			}

			for (int i = 0; i < tekst.length(); i++)
			{
				if (tekst[i] == 32)
					continue;
				else if (tekst[i] + wartosc > 122)
					tekst[i] = 96 + ((tekst[i] + wartosc) - 122);
				else
					tekst[i] = tekst[i] + wartosc;
			}
			return tekst;
		}

		
		{
			for (int i = 0; i < tekst.length(); i = i + 2)
				if (i + 2 > tekst.length())
					break;
				else
					swap(tekst[i], tekst[i + 1]);
			return tekst;
		}

		
		{
			string tmp = szyfrCezara(tekst);
			tmp = szyfrPrzestawieniowy(tmp);
			return tmp;
		}
};

class Odszyfrowanie {
	public:
		
		{
			string tmp;
			for (int j = 1; j < 27; j++)
			{
				tmp = tekst;
				for (int i = 0; i < tekst.length(); i++)
				{
					if (tekst[i] == 32)
						continue;
					else if (tekst[i] - j < 97)
						tmp[i] = 122 - (96 - (tmp[i] - j));
					else
						tmp[i] = tmp[i] - j;
				}
				cout << tmp << endl;
			}
		}
};

int main()
{
	string tekst;
	Szyfrowanie szyfr;
	Odszyfrowanie odszyfr;

	
	cout << "Podaj tekst do szyfrowania (Uzyj jedynie malych liter!)\n";
	while (true)
	{
		getline(cin, tekst);

		if (!check(tekst))
			cout << endl << "Podaj poprawny tekst!" << endl;
		else
			break;
	}

	
	cout << "\nWybierz opcje:" << endl;
	cout << "1. Szyfr podstawieniowy (szyfr cezara)" << endl;
	cout << "2. Szyfr przestawieniowy" << endl;
	cout << "3. Szyfr podstawieniowy i przestawieniowy" << endl;
	cout << "4. Odszyfruj tekst" << endl;
	cout << "5. Wygeneruj klucze RSA" << endl;

	while (true)
	{
		int akcja;
		cin >> akcja;

		switch (akcja)
		{
		case 1:
			tekst = szyfr.szyfrCezara(tekst);
			cout << "Zaszyfrowany tekst: " << tekst << endl;
			break;
		case 2:
			cout << "Zaszyfrowany tekst: " << szyfr.szyfrPrzestawieniowy(tekst) << endl;
			break;
		case 3:
			cout << szyfr.obaSzyfry(tekst) << endl;
			break;
		case 4:
			odszyfr.odszyfrowanieCezara(tekst);
			break;
		case 5:
			rsaGen();
			cout << "Wartosci klicza publicznego: n = " << publiczny.first << ", e = " << publiczny.second << endl;
			cout << "Wartosci klicza prywatnego: n = " << prywatny.first << ", d = " << prywatny.second << endl;
			break;
		default:
			cout << endl << "Podales bledna wartosc!" << endl;
			continue;
			break;
		}
	}

}