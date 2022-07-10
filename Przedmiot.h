#include <iostream>
using namespace std;
class Przedmiot
{
private:
	//zmienne do wyboru programu
	int liczba_programu;

	// zmienne do dodawania do pliku
	int cena_zakupu, cena_sprzedazy, nr_przedmiotu;
	string nazwa_pliku,folder,sciezka, rzecz, cel;

	//zmienne do szukania pliku
	string nr_ubrania;
	string sz_sciezka;
	string sz_nr_przedmiotu,sz_rzecz,sz_cena_zakupu, sz_cena_sprzedazy;

	
	//zmienne do usuwania pliku
	string stary_przychod;
	int z, sp, w;
	string zarobek, null, linia, wydane;
	string usuwany_plik, us_sciezka;
	int przyczyna, rodz_przedmiotu;
	int wybor_pliku;
	int nr_linii = 1;
	int przychod;
	//zmienne do przychodu
	string pobrany_przychod;
	int wyjdz;
public:
	void menu();
	void wczytaj();
	void szukaj();
	void pokaz_przychod();
	void wybor_programu();
	void usun();
};