#include <iostream>
#include <string>
using namespace std;

// Funkcja 'check' sprawdza czy podany tekst jest zapisany z małych liter
bool check(string tekst)
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

// Funkcja 'szyfrCezara' szyfruje podany tekst i zwraca zaszyfrowany tekst
string szyfrCezara(string tekst)
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

// Szyfr przestawieniowy
string szyfrPrzestawieniowy(string tekst)
{
	for (int i = 0; i < tekst.length(); i = i + 2)
		if (i+2 > tekst.length())
			break;
		else
			swap(tekst[i], tekst[i + 1]);
	return tekst;
}

// Zaszyfrowanie tekstu szyfrem cezara oraz szyfrem przestawieniowym
string obaSzyfry(string tekst)
{
	string tmp = szyfrCezara(tekst);
	tmp = szyfrPrzestawieniowy(tmp);
	return tmp;
}

// Odszyfrowanie szyfru cezara
void odszyfrowanieCezara(string tekst)
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

int main()
{
	string tekst;

	// Podanie tekstu do szyfrowania
	cout << "Podaj tekst do szyfrowania (Uzyj jedynie malych liter!)\n";
	while (true)
	{
		getline(cin, tekst);

		if (!check(tekst))
			cout << endl << "Podaj poprawny tekst!" << endl;
		else
			break;
	}

	// Wybór opcji
	cout << "\nWybierz opcje:" << endl;
	cout << "1. Szyfr podstawieniowy (szyfr cezara)" << endl;
	cout << "2. Szyfr przestawieniowy" << endl;
	cout << "3. Szyfr podstawieniowy i przestawieniowy" << endl;
	cout << "4. Odszyfruj tekst" << endl;
	
	while (true)
	{
		int akcja;
		cin >> akcja;

		switch (akcja)
		{
		case 1:
			tekst = szyfrCezara(tekst);
			cout << "Zaszyfrowany tekst: " << tekst << endl;
			break;
		case 2:
			cout << "Zaszyfrowany tekst: " << szyfrPrzestawieniowy(tekst) << endl;
			break;
		case 3:
			cout << obaSzyfry(tekst) << endl;
			break;
		case 4:
			odszyfrowanieCezara(tekst);
			break;
		default:
			cout << endl << "Podales bledna wartosc!" << endl;
			continue;
			break;
		}
	}
}