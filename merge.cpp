

#include<iostream>
using namespace std;

void merge(int tablica[], int start, int srodek, int koniec)
{
	int *tab_pom = new int[(koniec-start)]; // utworzenie tablicy pomocniczej
	int i = start, j = srodek+1, k = 0; // zmienne pomocnicze

	while (i <= srodek && j <= koniec) 
	{
		if (tablica[j] < tablica[i])
		{
			tab_pom[k] = tablica[j];
			j++;
		}
		else
		{
			tab_pom[k] = tablica[i];
			i++;
		}
		k++;
	}
 
	if (i <= srodek)
	{
		while (i <= srodek)
		{
			tab_pom[k] = tablica[i];
			i++;
			k++;
		}
	}
	else
	{
		 while (j <= koniec)
		 {
			  tab_pom[k] = tablica[j];
			  j++;
			  k++;
		 }
	}
 
	for (i = 0; i <= koniec-start; i++)
		tablica[start+i] = tab_pom[i];  

	cout << endl;
	for (i = start; i <= koniec; i++) // wypisanie posortowanej tablicy
		cout << "tablica[" << i << "] = " << tablica[i] << endl;
}

void merge_sort(int tablica[], int start, int koniec)
{
	int srodek;

	if (start != koniec)
	{
		srodek = (start + koniec)/2;
		merge_sort(tablica, start, srodek);
		merge_sort(tablica, srodek+1, koniec);
		merge(tablica, start, srodek, koniec);
	}
}

int main()
{
	int ilosc_liczb, i;
	cout << "Podaj ilosc licz do posortowania: ";
	cin >> ilosc_liczb;

	int *tablica = new int [ilosc_liczb]; // tablica zawierajaca ciag wejsciowy

	for (i = 0; i < ilosc_liczb; i++) // wczytywanie liczb do tablicy
	{
		cout << "Podaj liczba: ";
		cin >> tablica[i];
	}

	merge_sort(tablica, 0, ilosc_liczb-1);

	cout << endl << "wynik:" << endl;
	for (i = 0; i < ilosc_liczb; i++) // wypisanie posortowanej tablicy
		cout << "tablica[" << i << "] = " << tablica[i] << endl;

	// zwolnienie tablic zaalokowanych dynamicznie
	delete [] tablica; 

    return 0;
}