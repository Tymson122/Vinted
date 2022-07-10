#include <iostream>
#include <fstream>
#include <string>
#include "Przedmiot.h"
using namespace std;

void Przedmiot::menu()
{
	fstream file_menu;
	string line;
	file_menu.open("menu.txt", ios::in);
	if (file_menu.good() == false)
	{
		cout << "Nie mozma odnalesc pliku z menu!";
		exit(0);
	}
	while (getline(file_menu, line))
	{
		cout << line << endl;
	}
	file_menu.close();
	wybor_programu();
}

void Przedmiot::wybor_programu()
{
	cout << "Twoj wybor to: "; cin >> liczba_programu;
	system("cls");
	if (liczba_programu == -1) exit(0);
	else if (liczba_programu == 1)
	{
		cout << "Jezeli chcesz wrocic do menu to wpisz -1" << endl;
		while (true)
		{
			wczytaj();
		}		
	}
	else if (liczba_programu == 2)
	{
		cout << "Jezeli chcesz wrocic do menu to wpisz -1" << endl;
		while (true)
		{
			szukaj();
		}
	}
	else if (liczba_programu == 3)
	{
		pokaz_przychod();
	}
	else if (liczba_programu == 4)
	{
		cout << "Jezeli chcesz wrocic do menu to wpisz -1" << endl <<endl;
		while (true)
		{
			usun();
		}
	}
	else cout << "cos zle wpisales";
}
void Przedmiot::wczytaj()
{	
	cout << "Podaj numer przedmiotu: "; cin >> nr_przedmiotu;
	if (nr_przedmiotu == -1){
		system("cls"); menu();

	}
	cout << "Podaj ile kosztowal ten przedmiot: "; cin >> cena_zakupu;
	cout << "Podaj za ile ten przedmiot chcesz wystawic:  "; cin >> cena_sprzedazy;
	cout << "Podaj przedmiot (bez spacji np: czarna_czapka):  "; cin >> rzecz;
	cout << endl;
	nazwa_pliku = to_string(nr_przedmiotu); //konwersja int na string

	sciezka = "produkty/" + nazwa_pliku + ".txt"; // tworzenie pliku w folderze
	fstream plik;
	plik.open(sciezka, ios::out);

	plik << nr_przedmiotu << endl; // zapis pliku
	plik << cena_zakupu << endl;
	plik << cena_sprzedazy << endl;
	plik << rzecz << endl;

}
void Przedmiot::szukaj()
{
	fstream szukany_plik;
	string linia;
	int nr_linii = 1;

	cout << endl << "Wpisz numer ubrania: "; cin >> nr_ubrania;
	if (nr_ubrania == "-1") {
		system("cls"); menu();
	}
	sz_sciezka = "produkty/" + nr_ubrania + ".txt";
	szukany_plik.open(sz_sciezka, ios::in);
	if (szukany_plik.good() == false)
	{
		cout << "Podany numer ubrania nie istnieje!" << endl;
		szukaj();
	}
	while (getline(szukany_plik, linia))
	{
		switch (nr_linii)
		{
		case 1: sz_nr_przedmiotu = linia; 	 break;
		case 2: sz_cena_zakupu = linia;      break;
		case 3: sz_cena_sprzedazy = linia;  break;
		case 4: sz_rzecz = linia;			 break;
		}
		nr_linii++;
	}
	cout << sz_nr_przedmiotu << endl;
	cout << sz_cena_zakupu << endl;
	cout << sz_cena_sprzedazy << endl;
	cout << sz_rzecz << endl;
}
void Przedmiot::pokaz_przychod()
{
	fstream pobierz_przychod;
	pobierz_przychod.open("przychod.txt", ios::in);
	getline(pobierz_przychod, pobrany_przychod);
	cout << "zarobiles juz: " << pobrany_przychod << "zl"<<endl;
	cout << "Nacisnij -1 aby wyjsc: "; cin >> wyjdz;
	if (wyjdz == -1) {
		system("cls"); menu();
	}
}
void Przedmiot::usun()
{
	cout << "Podaj przyczyne usuwania pliku (wpisz numer)" << endl;
	cout << "1. plik dodany przez pomylke" << endl;
	cout << "2. Produkt zostal sprzedany" << endl;
	cout << "twoj wybor: "; cin >> przyczyna;

	if (przyczyna == -1) {
		system("cls"); menu();
	}
	else if (przyczyna == 1)
	{
		if (remove(us_sciezka.c_str()) == 0) cout << "Plik zostal usuniety" << endl << endl;
		else cout << "Nie udalo sie usunac pliku lub plik nie istnieje" << endl << endl;
	}
	else if (przyczyna == 2)
	{

		fstream odczytany_produkt, odczytany_przychod, zapis_przychodu;
		cout << "Twoj przedmiot jest uzywany czy kupiony pod handel" << endl;
		cout << "1. uzywany" << endl;
		cout << "2. kupiony pod handel" << endl;
		cout << "Twoj wybor to: "; cin >> rodz_przedmiotu;

		cout << "Podaj numer przedmiotu do usuniecia: "; cin >> usuwany_plik;
		us_sciezka = "produkty/" + usuwany_plik + ".txt";
		if (rodz_przedmiotu == 1)
		{
			//otwarcie pliku z produktem i zapisanie zarobku do zmiennej zarobek
			odczytany_produkt.open(us_sciezka, ios::in);
			while (getline(odczytany_produkt, linia))
			{
				switch (nr_linii)
				{
				case 1: null = linia; break;
				case 2: null = linia; break;
				case 3: zarobek = linia; break;
				case 4: null = linia; break;
				}
				nr_linii++;
			}
			odczytany_produkt.close();
			// odczytanie przychodu
			odczytany_przychod.open("przychod.txt", ios::in);
			getline(odczytany_przychod, stary_przychod);
			odczytany_przychod.close();
			// zapis nowego przychodu
			sp = atoi(stary_przychod.c_str());
			z = atoi(zarobek.c_str());
			przychod = sp + z;
			zapis_przychodu.open("przychod.txt", ios::out);
			zapis_przychodu << przychod;
			if (remove(us_sciezka.c_str()) == 0) cout << "Plik zostal usuniety" << endl << endl;
			else cout << "Nie udalo sie usunac pliku lub plik nie istnieje" << endl << endl;
		}
		else if (rodz_przedmiotu == 2)
		{
			//otwarcie pliku z produktem i zapisanie zarobku do zmiennej zarobek
			odczytany_produkt.open(us_sciezka, ios::in);
			while (getline(odczytany_produkt, linia))
			{
				switch (nr_linii)
				{
				case 1: null = linia; break;
				case 2: wydane = linia; break;
				case 3: zarobek = linia; break;
				case 4: null = linia; break;
				}
				nr_linii++;
			}
			odczytany_produkt.close();
			// odczytanie przychodu
			odczytany_przychod.open("przychod.txt", ios::in);
			getline(odczytany_przychod, stary_przychod);
			odczytany_przychod.close();
			// zapis nowego przychodu
			sp = atoi(stary_przychod.c_str());
			z = atoi(zarobek.c_str());
			w = atoi(wydane.c_str());
			przychod = z - w + sp;
			zapis_przychodu.open("przychod.txt", ios::out);
			zapis_przychodu << przychod;
			if (remove(us_sciezka.c_str()) == 0) cout << "Plik zostal usuniety" << endl << endl;
			else cout << "Nie udalo sie usunac pliku lub plik nie istnieje" << endl << endl;
		}
		
	}

}
	