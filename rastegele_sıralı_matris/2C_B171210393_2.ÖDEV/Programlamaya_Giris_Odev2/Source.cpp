/****************************************************************************
**								SAKARYA �N�VERS�TES�
**			         B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
**						  B�LG�SAYAR M�HEND�SL��� B�L�M�
**						    PROGRAMLAMAYA G�R��� DERS�
**
**				�DEV NUMARASI......:Odev 2
**				��RENC� ADI........:Arif Seyda �Z�EL�K
**				��RENC� NUMARASI...:b171210393
**				DERS GRUBU.........:2/C
****************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include <ctime>

using namespace std;

int sayac;
char Harf[5][10];
void olustur();  //Matris olu�turma
void matrisYaz(); //matrisi yazd�rma
bool elemanKontrol(char deger); //Her harf sadece bir kere kullan�lacakt�r�n kontrol�
void sirala();   //Matris siralama i�lemleri

int main()
{
	srand(time(NULL));
	olustur();
	matrisYaz();
	sirala();
	matrisYaz();

	system("pause");
	return 0;
}

void olustur()   //Matris olu�turma
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			sayac++;
			char deger = rand() % 57 + 65;
			if (elemanKontrol(deger) && (((int)deger >= 65 && (int)deger <=90) || ((int)deger >= 97 && (int)deger <= 122)))
			{
				if (((int)deger >= 97 && (int)deger <= 122) && j % 2 == 1)
					Harf[i][j] = deger;
				else if (((int)deger >= 65 && (int)deger <= 90) && j % 2 == 0)
					Harf[i][j] = deger;
				else
				{
					j--;
					continue;
				}
			}
			else
			{
				j--;
				continue;
			}

		}
	}
	cout << "Toplam Rastgele Cagrim Adedi = " << sayac << endl << endl;
	cout << "Rastgele Olusan ve Elemanlari Birbirinden Farkli Matris:" << endl << endl;
}

bool elemanKontrol(char karakter)   //Her harf sadece bir kere kullan�lacakt�r�n kontrol�
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Harf[i][j] == karakter)
			{
				return false;
			}
		}
	}
	return true;
}
void sirala()   //Matris siralama i�lemleri
{
	cout << endl << endl;
	cout << "Buyukden Kucuge Siralanmis Matris:" << endl << endl;

	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<10; j++)
		{
			for (int a = 0; a<5; a++)
			{
				for (int b = 0; b<10; b++)
				{
					if (Harf[a][b] > Harf[i][j])
					{
						int temp = Harf[a][b];
						Harf[a][b] = Harf[i][j];
						Harf[i][j] = temp;
					}
				}
			}
		}
	}

}
void matrisYaz()    //matrisi yazd�rma
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << setw(5) << Harf[i][j];

		}
		cout << endl;
	}
	cout << endl;
}
