/****************************************************************************
**		
**		
**			  AD-Soyad............:Melih G�ler
**			  Proje Adi...........:Otel Otomasyon Programi				 
**			
****************************************************************************/
#include <iostream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
using namespace std;
struct musteri {
	string ad, soyad, musteriNuumarasi, tckn;
};
struct oda {
	string odaNo, ucret;
};
int main() {
	system("color 20");
	setlocale(LC_ALL, "turkish");
	ofstream dosyaYaz;
	ifstream dosyaOku;
	musteri must;
	oda ODA;
	string secim;		//Men� se�imlerinde kullan�lan de�i�ken.
	do {
		system("cls");
		cout << "OTEL ��LEMLER�\n";
		for (int i = 0; i < 20; i++)
			cout << "-";
		cout << endl;
		cout << "1- ODA �SLEMLER�\n";
		cout << "2- M��TER� ��LEMLER�\n";
		cout << "3- ODA KAYIT ��LEMLER�\n";
		cout << "99- �IKI�\n";
		cout << "SE��M�N�Z: ";
		cin >> secim;

		//------------------------------------------------------ANA_MENU_1.SECENEK_GIRIS-----------------------------------------------				
		if (secim == "1") {
			string secimILK;		//Men� se�imlerinde kullan�lan de�i�ken.
			do {
				system("cls");
				cout << "ODA ��LEMLER�\n";
				for (int i = 0; i < 20; i++)
					cout << "-";
				cout << endl;
				cout << "1- ODA EKLE\n";
				cout << "2- ODA S�L\n";
				cout << "3- ODALARI L�STELE\n";
				cout << "99- �ST MEN�\n";
				cout << "SE��M�N�Z: ";
				cin >> secimILK;
				//------------------------------------1 in icindeki 1 giris-------------
				if (secimILK == "1") {
					string kontrol;			//i�lem sonunda devam edilip edilmeyece�i sorulurken kullan�lan de�i�ken.
					do {
						system("cls");
						string tut;
						int kontrolx = 0, kontrol2x = 0;  //oda numaralar� daha �nce kullan�lm�� m� ve nizami mi diye kontrol ederken kullan�lan yard�mc� de�i�ken.
						do {
							kontrolx = 0, kontrol2x = 0;
							dosyaOku.open("odaKayit.txt");
							cout << "4 HANEL� ODA NUMARASI G�R�N: ";
							cin >> ODA.odaNo;
							tut = ODA.odaNo;
							while (dosyaOku >> ODA.odaNo >> ODA.ucret) {

								if (tut == ODA.odaNo)
									kontrolx = 1;         //e�er oda numaras� daha �ncee kullan�lm��sa de�i�kene 1 de�eri atan�yor.
							}
							dosyaOku.close();
							for (int i = 0; i < tut.length(); i++) {
								if (!(tut[i] > 47 && tut[i] < 58))
									kontrol2x = 1;       //e�er oda numaras�na rakamdandan ba�ka bir�ey yaz�ld�ysa kontrol2x de�i�kenine 1 atan�yor.
							}
							if (kontrolx == 1) {
								system("cls");
								cout << "BU ODA NUMRASI KULLANILMAKTADIR. BA�KA B�R NUMARA SE��N...\n";				//kontrolx de�i�kenine 1 atanm��sa kullan�c�ya uyar� yap�l�yor.
								system("pause");
								system("cls");
							}
							else if (kontrol2x == 1) {
								system("cls");
								cout << "ODA NUMARASI RAKAMLARDAN OLU�MALI...\n";						//kontrol2x de�i�kenine 1 atanm��sa kullan�c�ya uyar� yap�l�yor.
								system("pause");
								system("cls");
							}
							else if (tut.length() != 4) {
								system("cls");
								cout << "ODA NUMARASI 4 HANEL� OLMALI...\n";			//oda numaras� 4 haneden fazla ise kullan�c�ya uyar� yap�l�yor.
								system("pause");
								system("cls");
							}

						} while (kontrolx == 1 || kontrol2x == 1 || tut.length() != 4);		//yukar�daki uyar�lardan en az biri bile yap�ld�ysa tekrardan numara girmesi isteniyor.
						kontrolx = 0, kontrol2x = 0;
						int kontrol4x;		//e�er harf harici bir karakter kullan�lm��sa kullan�c�y� uyarmak i�in kullan�lacak de�i�ken.
						string uctut; //oda ucreti girilirken rakam harici bir karakter kullan�lm�� m� diye kontrol etmek icin kullan�lan de�i�ken.
						do {
							kontrol4x = 0;				//kontrol4x de�i�kenine random olarak 0 atan�r.
							cout << "ODANIN �CRET�N� G�R�N: ";
							cin >> ODA.ucret;
							uctut = ODA.ucret;
							int nn;
							char li;
							for (int i = 0; i < uctut.length(); i++) {
								li = uctut[i];
								nn = static_cast<int>(li);
								if (!((nn > 47) && (nn < 58)))
									kontrol4x = 1;				//e�er rakam harici bir karakter kullan�lm��sa kontrol4x de�i�kenine 1 atan�r.
							}
							if (kontrol4x == 1) {
								system("cls");
								cout << "�CRET ALANINA RAKAMDAN BA�KA B�R �EY G�R�LEMEZ...\n";			//e�er kontrol4x de�i�kenine 1 atanm��sa uyar� verir.
								system("pause");
								system("cls");
							}
						} while (kontrol4x == 1);	//kontrol4x de�i�keni 1 ise uyar�dan sonra yeniden �cret girilmesi istenir.

						dosyaYaz.open("odaKayit.txt", ios::app);
						dosyaYaz << tut << "\t" << ODA.ucret << endl;
						dosyaYaz.close();
						system("cls");
						cout << "ODA KAYDI BA�ARIYLA YAPILMI�TIR\n";
						do {
							system("cls");
							cout << "KAYIT ��LEM�NE DEVAM ETMEK �STERM�S�N�Z(e/h): ";
							cin >> kontrol;
							if (kontrol != "e"&&kontrol != "h") {
								cout << "\n-e- VEYA -h- HARFLER�NDEN B�R�N� G�R�N...\n";
								system("pause");
								system("cls");
							}

						} while (kontrol != "e"&&kontrol != "h");
					} while (kontrol == "e");

				}
				//-----------------------------1 icindeki 2 giris-------------------
				else if (secimILK == "2") {

					string secim1;
					int  nul;		//oda silerken silinecek odan�n olup olmad���n� s�ylemek i�in kullan�lan de�i�ken.
					string no;		//girilen oda numaras�n�n olup olmad���n� kontrol ederken kullan�lan de�i�ken.
					do {
						do {
							nul = 0;
							system("cls");
							cout << "S�L�NECEK ODANIN NUMARASINI G�R�N: ";
							cin >> no;
							dosyaOku.open("odaKayit.txt");
							while (dosyaOku >> ODA.odaNo >> ODA.ucret) {
								if (no == ODA.odaNo)
									nul = 1;							//b�yel bir numara varsa nul de�i�kenine 1 atan�r.
							}
							dosyaOku.close();
							if (nul == 0) {
								system("cls");
								cout << "BU NUMARADA B�R ODA BULUNMAMAKTADIR.\n";    // b�yle bir numara yoksa nul de�i�keni varsay�lan olarak s�f�r olur ve uyar� verir.
								system("pause");
							}
						} while (nul == 0);  //girilen oda numaras� yoksa yeniden numara ister.

											 //---------------------------------------------------------------------------------
						dosyaYaz.open("rezervTut.txt");                                               //e�er silinen odan�n rezervasyonu varsa onu da siler.
						dosyaOku.open("rezerv.txt");
						while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad) {
							if (ODA.odaNo != no)
								dosyaYaz << ODA.odaNo << "\t" << must.musteriNuumarasi << "\t" << must.ad << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						dosyaYaz.open("rezerv.txt");
						dosyaOku.open("rezervTut.txt");
						while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad) {

							dosyaYaz << ODA.odaNo << "\t" << must.musteriNuumarasi << "\t" << must.ad << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();

						//---------------------------------------------------------------------------------
						dosyaYaz.open("odaKayitTut.txt");
						dosyaOku.open("odaKayit.txt");
						while (dosyaOku >> ODA.odaNo >> ODA.ucret) {
							if (ODA.odaNo != no)
								dosyaYaz << ODA.odaNo << "\t" << ODA.ucret << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						dosyaYaz.open("odaKayit.txt");
						dosyaOku.open("odaKayitTut.txt");
						while (dosyaOku >> ODA.odaNo >> ODA.ucret) {

							dosyaYaz << ODA.odaNo << "\t" << ODA.ucret << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						system("cls");
						cout << "S�LME ��LEM� BA�ARILI\n";

						do {
							system("cls");
							cout << "S�LME ��LEM�NE DEVAM ETMEK �STERM�S�N�Z(e/h): ";
							cin >> secim1;
							if (secim1 != "e"&&secim1 != "h") {
								cout << "\n-e- VEYA -h- HARFLER�NDEN B�R�N� G�R�N...\n";
								system("pause");
								system("cls");
							}

						} while (secim1 != "e"&&secim1 != "h");
					} while (secim1 == "e");
				}
				//-------------------1 icindeki 3 giris--------------------------------
				else if (secimILK == "3") {
					system("cls");
					cout << "Oda Numaras�" << "\t" << "�creti\n";
					for (int i = 0; i < 18; i++) {
						cout << "_";
						if (i == 11)
							cout << "\t";
					}
					cout << endl;
					dosyaOku.open("odaKayit.txt");
					while (dosyaOku >> ODA.odaNo >> ODA.ucret) {
						cout << "    " << left << setw(8) << ODA.odaNo << "\t" << " " << ODA.ucret << " TL" << endl;
					}
					dosyaOku.close();

					system("pause");
					system("cls");
				}
				if ((secimILK != "1") && (secimILK != "2") && (secimILK != "3") && (secimILK != "99")) {
					system("cls");
					cout << "HATALI SE��M\n";
					system("pause");
				}

			} while (secimILK != "99");

		}
		//------------------------------------------------------------------------ANA_MENU_1.SECENEK_CIKIS--------------------------------------	


		//------------------------------------------------------------------------ANA_MENU_2.SECENEK_GIRIS-------------------------------------

		if (secim == "2") {
			string secimILK;   //men� se�imde kullan�lacak de�i�ken.
			do {
				system("cls");
				cout << "M��TER� ��LEMLER�\n";
				for (int i = 0; i < 20; i++)
					cout << "-";
				cout << endl;
				cout << "1- M��TER� EKLE\n";
				cout << "2- M��TER� S�L\n";
				cout << "3- M��TER�LER� L�STELE\n";
				cout << "99- �ST MEN�\n";
				cout << "SE��M�N�Z: ";
				cin >> secimILK;
				//------------------------------------2 nin icindeki 1 giris-------------
				if (secimILK == "1") {
					string kontrol;
					string a;
					int pl; //ad ve soyadda rakam ve kullan�lamayan karakterilerin kontrol� i�in olu�turulan de�i�ken.
					do {

						system("cls");
						do {
							pl = 0;
							cout << "M��TER� ADINI G�R�N: ";
							cin >> must.ad;
							for (int i = 0; i < ((must.ad).length()); i++) {
								int n = static_cast<int>(must.ad[i]);
								if (!((n > 64 && n < 91) || (n > 96 && n < 123))) {
									pl = 1;

								}
							}
							if (pl == 1) {
								system("cls");
								cout << "�S�M B�L�M�NDE �NG�L�ZCE HARFLERDEN BA�KA KARAKTER KULLANILAMAZ\n";
								system("pause");
								system("cls");
							}
						} while (pl == 1);

						do {
							pl = 0;
							cout << "M��TER� SOYADINI G�R�N: ";
							cin >> must.soyad;
							for (int i = 0; i < ((must.soyad).length()); i++) {
								int n = static_cast<int>(must.soyad[i]);
								if (!((n > 64 && n < 91) || (n > 96 && n < 123))) {
									pl = 1;

								}
							}
							if (pl == 1) {
								system("cls");
								cout << "SOYAD B�L�M�NDE �NG�L�ZCE HARFLERDEN BA�KA KARAKTER KULLANILAMAZ\n";
								system("pause");
								system("cls");
							}
						} while (pl == 1);
						int u = 0, olo = 0;  //tc no ve m��teri no'lar� nizamimi ve daha �nceden kullan�lm�� m� diye kontrol ederken kullan�lan de�i�kenler.
						char n;
						string tutTC, tg, yh, th; //dosyada nokuma esnas�nda ad,soyad ve tcnin kar��mamas� i�in kullan�lan de�i�kenler.
						do {
							dosyaOku.open("musteriKayit.txt");
							u = 0, olo = 0; int p = 0;
							cout << "M��TER�N�N 11 HANEL� TC K�ML�K NUMARASINI G�R�N: ";
							cin >> must.tckn;
							tutTC = must.tckn;
							while (dosyaOku >> tg >> th >> must.tckn >> yh) {
								if (tutTC == must.tckn)          //e�er tckn sistemde kay�tl�ysa olo de�i�kenine 1 atar.
									olo = 1;
							}
							dosyaOku.close();

							for (int i = 0; i < (tutTC.length()); i++) {
								n = tutTC[i];
								p = static_cast<int>(n);
								if (!(p > 47 && p < 58))						//e�er tckn de rakamdan farkl� bir karakter kulllan�lm��sa u de�i�kenine 1 atar.
									u = 1;
							}
							if (u == 1) {
								system("cls");
								cout << "TCKN SADECE RAKAMLARDAN OLU�MALI...\n";			//u de�i�kenine 1 atanm��sa uyar� verir.
								system("pause");
								system("cls");
							}
							else if (tutTC.length() != 11) {
								system("cls");
								cout << "TCKN 11 HANEL� OLMALI...\n";					//tckn 11 haneli de�ilse uyar� verir.
								system("pause");
								system("cls");
							}

							else if (olo == 1) {
								system("cls");
								cout << "BU TCKN KAYITLARDA BULUNMAKTA. BA�KA B�R TCKN G�R�N�Z...\n";			//olo de�ikenine 1 atanm��sa uyar� verir.
								system("pause");
								system("cls");
							}
						} while (u == 1 || tutTC.length() != 11 || olo == 1); //e�er uyar�lardan biri bile olduysa tckn nin yeniden girilmesini ister.

						int tutucu, tutucu2;   //musteri numaras� daha �nceden al�nm�� m� ve nizami mi diye kontrol edilirken kullan�lan de�i�kenler.
						string mustno;
						do {
							tutucu = 0, tutucu2 = 0;
							cout << "M��TER�N�N 5 HANEL� M��TER� NUMARASINI G�R�N: ";
							cin >> must.musteriNuumarasi;
							mustno = must.musteriNuumarasi;
							dosyaOku.open("musteriKayit.txt");
							while (dosyaOku >> tg >> th >> must.tckn >> must.musteriNuumarasi) {
								if (mustno == must.musteriNuumarasi)
									tutucu = 1;                              // m��teri numaras� daha �nceden kay�tlanm��sa tutucu de�i�kenine 1 atar.
							}
							char u;
							int y;
							dosyaOku.close();
							for (int i = 0; i < mustno.length(); i++) {
								u = mustno[i];
								y = static_cast<int>(u);
								if (!(y > 47 && 58 > y))					//e�er m��teri numaras�nda rakamdan farkl� bir karakter varsa tutucu2 de�i�kenine 1 atar.
									tutucu2 = 1;
							}
							if (tutucu == 1) {
								system("cls");
								cout << "BU M��TER� NUMARASI BA�KA B�R K��� TARAFINDAN KULLANILMAKTADIR...\n";
								system("pause");
								system("cls");
							}
							else if (tutucu2 == 1) {
								system("cls");
								cout << "M��TER� NUMARASI SADECE RAKAMLARDAN OLU�MALI...\n";
								system("pause");
								system("cls");
							}
							else if (mustno.length() != 5) {						//m��eri numaras� 5 haneden farkl� ise uyar� verir.
								system("cls");
								cout << "M��TER� NUMARASI 5 HANEL� OLMALI...\n";
								system("pause");
								system("cls");
							}
						} while (tutucu == 1 || tutucu2 == 1 || mustno.length() != 5);  //uyar�lardan biri bile verildiyse yeninen numara girmenizi ister.

						dosyaYaz.open("musteriKayit.txt", ios::app);
						dosyaYaz << must.ad << "\t" << must.soyad << "\t" << tutTC << "\t" << mustno << endl;
						dosyaYaz.close();
						system("cls");
						cout << "M��TER� KAYDI YAPILMI�TIR\n";
						system("pause");
						do {
							system("cls");
							cout << "YEN� KAYIT(e/h): ";
							cin >> kontrol;
							if (kontrol != "e"&&kontrol != "h") {
								cout << "\n-e- VEYA -h- HARFLER�NDEN B�R�N� G�R�N...\n";
								system("pause");
								system("cls");
							}

						} while (kontrol != "e"&&kontrol != "h");
					} while (kontrol == "e");

				}
				//-----------------------------2 nin icindeki 2 giris-------------------
				else if (secimILK == "2") {

					string secim1;
					string no;  //m��teri numaras� sistemde varm� diye kontrol eden de�i�ken.

					do {
						int g = 0;      //silinmesi i�in girilen numaran�n var olup olmad���n� anlamak i�in kullan�lan de�i�ken.
						do {
							g = 0;
							system("cls");
							cout << "S�L�NECEK M��TER�N�N NUMARASINI G�R�N: ";
							cin >> no;
							dosyaOku.open("musteriKayit.txt");
							while (dosyaOku >> must.ad >> must.soyad >> must.tckn >> must.musteriNuumarasi)
							{
								if (no == must.musteriNuumarasi)
									g = 1;
							}
							dosyaOku.close();
							if (g == 0) {
								system("cls");
								cout << "B�YLE B�R KAYIT BULUNMAMAKTADIR.\n";
								system("pause");
								system("cls");
							}
						} while (g == 0);
						//-----------------------------------------
						dosyaYaz.open("rezervTut.txt");
						dosyaOku.open("rezerv.txt");
						while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad) {
							if (must.musteriNuumarasi != no)
								dosyaYaz << ODA.odaNo << "\t" << must.musteriNuumarasi << "\t" << must.ad << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						dosyaYaz.open("rezerv.txt");
						dosyaOku.open("rezervTut.txt");
						while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad) {

							dosyaYaz << ODA.odaNo << "\t" << must.musteriNuumarasi << "\t" << must.ad << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();


						//---------------------------------------------
						dosyaYaz.open("musteriKayitTut.txt");
						dosyaOku.open("musteriKayit.txt");
						while (dosyaOku >> must.ad >> must.soyad >> must.tckn >> must.musteriNuumarasi) {
							if (must.musteriNuumarasi != no)
								dosyaYaz << must.ad << "\t" << must.soyad << "\t" << must.tckn << "\t" << must.musteriNuumarasi << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						dosyaYaz.open("musteriKayit.txt");
						dosyaOku.open("musteriKayitTut.txt");
						while (dosyaOku >> must.ad >> must.soyad >> must.tckn >> must.musteriNuumarasi) {

							dosyaYaz << must.ad << "\t" << must.soyad << "\t" << must.tckn << "\t" << must.musteriNuumarasi << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						system("cls");
						cout << "S�LME ��LEM� YAPILMI�TIR\n";
						system("pause");
						do {
							system("cls");
							cout << "S�LME ��LEM�NE DEVAM ETMEK �STERM�S�N�Z(e/h): ";
							cin >> secim1;
							if (secim1 != "e"&&secim1 != "h") {
								cout << "\n-e- VEYA -h- HARFLER�NDEN B�R�N� G�R�N...\n";
								system("pause");
								system("cls");
							}

						} while (secim1 != "e"&&secim1 != "h");
					} while (secim1 == "e");
				}
				//-------------------2 nin icindeki 3 giris--------------------------------
				else if (secimILK == "3") {
					system("cls");
					cout << "M��TER� ADI" << "\t" << "M��TER� SOYADI" << "\t" << "M��TER� TCKN" << "\t" << "M��TER� NUMARASI\n";
					for (int i = 0; i < 53; i++) {
						cout << "_";
						if (i == 10)
							cout << "\t";
						if (i == 24)
							cout << "\t";
						if (i == 36)
							cout << "\t";

					}
					cout << endl;
					dosyaOku.open("musteriKayit.txt");
					while (dosyaOku >> must.ad >> must.soyad >> must.tckn >> must.musteriNuumarasi) {
						string ad = must.ad, soyad = must.soyad;

						cout << left << setw(18 - (ad.length())) << must.ad << "\t" << left << setw(16 - (soyad.length())) << must.soyad << "\t" << must.tckn << "\t" << setw(5) << must.musteriNuumarasi << endl;
					}
					dosyaOku.close();

					system("pause");
					system("cls");
				}
				if ((secimILK != "1") && (secimILK != "2") && (secimILK != "3") && (secimILK != "99")) {
					system("cls");
					cout << "HATALI SE��M\n";
					system("pause");
				}

			} while (secimILK != "99");

		}
		//------------------------------------------------------------------------ANA_MENU_2.SECENEK_CIKIS-------------------------------------

		//------------------------------------------------------------------------ANA_MENU_3.SECENEK_GIRIS-------------------------------------
		if (secim == "3") {
			string secimILK;   //men� se�imlerinde kullan�lan de�i�ken.
			do {
				system("cls");
				cout << "ODA KAYIT ��LEMLER�\n";
				for (int i = 0; i < 20; i++)
					cout << "-";
				cout << endl;
				cout << "1- ODA REZERVASYONU\n";
				cout << "2- REZERVASYON S�LME\n";
				cout << "3- REZERVASYONLARI L�STELE\n";
				cout << "99- �ST MEN�\n";
				cout << "SE��M�N�Z: ";
				cin >> secimILK;

				//------------------------3 icindeki 1 giris-----------------------------------------------------------			

				if (secimILK == "1") {
					int  b = 0, d = 0, t = 0, y, o = 0;   //oda daha �nce tutulmu�sa veya b�yle bir oda yoksa bu bilgileri saklamak i�in kullan�lan de�i�kenler.
					string q;  //yeni rezeervasyon yap�l�p yap�lmayaca��n� tutan de�i�ken.
					string adtut, a, tutt, c;    //odan�n daha �ne tutulup tutulmad���n� ve b�yle bir odan�n olup olmad���n� kontrol ederken kullan�lan de�iken.

					do {
						system("cls");
						do {
							b = 0, t = 0, o = 0;
							cout << "TUTULACAK ODANIN NUMARASI: ";
							cin >> a;
							tutt = a;
							dosyaOku.open("rezerv.txt");
							while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad) {
								if (a == ODA.odaNo)
									o = 1;
							}
							dosyaOku.close();
							dosyaOku.open("odaKayit.txt");
							while (dosyaOku >> ODA.odaNo >> ODA.ucret) {
								if (a == ODA.odaNo)
									b = 1;
							}
							dosyaOku.close();
							if (b == 1) {
								ODA.odaNo = tutt;
							}
							if (b == 0) {
								system("cls");
								cout << "HATALI ODA NUMARASI...\n";
								system("pause");
								system("cls");
							}
							if (o == 1) {
								system("cls");
								cout << "BU ODA DAHA �NCEDEN ALINMI�...\n";
								system("pause");
								system("cls");
							}

						} while (b == 0 || o == 1);
						do {
							d = 0;        // girilen numaran�n rezervasyonu daha �nceden yap�lm�� m� ve girilen numara sistemde kay�tl� m� diye kontrol eden de�i�kenler.		 
							t = 0;
							cout << "ODAYA YERLE�ECEK M��TER�N�N NUMARASI: ";
							cin >> c;
							dosyaOku.open("rezerv.txt");
							while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad)
							{
								if (c == must.musteriNuumarasi)				//numaran�n daha �nceden rezervasyonu yap�lm��sa t de�i�kenine 1 atar.
									t = 1;

							}
							dosyaOku.close();
							dosyaOku.open("musteriKayit.txt");
							while (dosyaOku >> must.ad >> must.soyad >> must.tckn >> must.musteriNuumarasi) {
								if (c == must.musteriNuumarasi) {							//m��teri numaras� sistemde kay�tl�ysa d de�i�kenine 1 atar.
									d = 1;
									adtut = must.ad;
								}


							}
							dosyaOku.close();

							if (d == 1 && t == 0) {
								must.musteriNuumarasi = c;
								must.ad = adtut;
							}
							else if (d == 0) {
								system("cls");
								cout << "HATALI M��TER� NUMARASI...\n";
								system("pause");
								system("cls");
							}
							else if (t == 1)   // t de�i�kenine 1 atanm��sa uyar� verir.
							{
								system("cls");
								cout << "G�RD���N�Z NUMARANIN REZERVASYONU YAPILMI�...\n";
								system("pause");
								system("cls");
							}

						} while (d == 0 || t == 1);   //t de�i�kenine 1 atanm��sa veya d de�i�keni 0 sa yeniden numara girilmesini ister.
						dosyaYaz.open("rezerv.txt", ios::app);
						dosyaYaz << tutt << "\t" << must.musteriNuumarasi << "\t" << must.ad << endl;
						dosyaYaz.close();
						do {
							system("cls");
							cout << "YEN� REZERVASYON(e/h): ";
							cin >> q;
							if (q != "e" && q != "h") {
								cout << "-e- VEYA -h- HARFLER�NDEN B�R�N� G�R�N...\n";
								system("pause");
							}

						} while (q != "e"&&q != "h");



					} while (q == "e");//oda kayit devam
				}

				//------------------------3 icindeki 2 giris-------------------------------------------------

				if (secimILK == "2") {
					int lol;		//numara var m� yok mu diye kontrol edilirken kullan�lan de�i�ken.
					string secim1;
					string no;  //silinecek nmaran�n rezervasyonu var m� diye kontrol etmek i�in kullan�lan de�i�ken.
					do {
						do {
							lol = 0;
							system("cls");
							cout << "REZERVASYONU S�L�NECEK M��TER�N�N NUMARASINI G�R�N: ";
							cin >> no;
							dosyaOku.open("rezerv.txt");
							while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad)
							{
								if (no == must.musteriNuumarasi)                        //numaran�n rezervasyonu varsa lol de�i�kenine 1 atan�r.
									lol = 1;
							}
							dosyaOku.close();
							if (lol == 0) {									//e�er lol de�i�keni s�f�rsa yani bu numaran�n rezervasyonu yoksa uyar� verir.
								system("cls");
								cout << "BU NUMARANIN REZERVASYONU BULUNMAMAKTADIR.\n";
								system("pause");
							}
						} while (lol == 0);  // lol de�i�keni s�f�rsa yeniden numara ister.

						dosyaYaz.open("rezervTut.txt");
						dosyaOku.open("rezerv.txt");
						while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad) {
							if (must.musteriNuumarasi != no)
								dosyaYaz << ODA.odaNo << "\t" << must.musteriNuumarasi << "\t" << must.ad << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						dosyaYaz.open("rezerv.txt");
						dosyaOku.open("rezervTut.txt");
						while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad) {

							dosyaYaz << ODA.odaNo << "\t" << must.musteriNuumarasi << "\t" << must.ad << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						system("cls");
						cout << "REZERVASYON S�LME ��LEM� BA�ARILI\n";
						system("pause");
						do {
							system("cls");
							cout << "S�LME ��LEM�NE DEVAM ETMEK �STERM�S�N�Z(e/h): ";
							cin >> secim1;
							if (secim1 != "e"&&secim1 != "h") {
								cout << "\n-e- VEYA -h- HARFLER�NDEN B�R�N� G�R�N...\n";
								system("pause");
								system("cls");
							}

						} while (secim1 != "e"&&secim1 != "h");

					} while (secim1 == "e");

				}

				//------------------------------------3 ic 2 c�k�s-----------------------------------------------

				if (secimILK == "3") {
					system("cls");
					dosyaOku.open("rezerv.txt");
					cout << setw(15) << "                        --------------------------REZERVASYONLAR--------------------------\n";
					cout << "ODA NUMARASI" << "\t" << "M��TER� NUMARASI" << "\t" << "M�STER� ADI" << endl;
					for (int i = 0; i < 40; i++) {
						cout << "_";
						if (i == 12)
							cout << "\t";
						if (i == 28)
							cout << "\t";

					}
					cout << endl;
					while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad) {



						cout << left << setw(16) << ODA.odaNo << left << setw(24) << must.musteriNuumarasi << must.ad << endl;


					}
					dosyaOku.close();

					system("pause");

				}
				//-----------------------------------3 ic 3  c�k�s-----------------------------------------------




				if (secimILK != "1" && secimILK != "2" && secimILK != "3" && secimILK != "99") {
					system("cls");
					cout << "HATALI SE��M.\n";
					system("pause");
				}




			} while (secimILK != "99");

		}
		if ((secim != "1") && (secim != "2") && (secim != "3") && (secim != "99")) {
			system("cls");
			cout << "HATALI SE��M\n";
			system("pause");
		}
	} while (secim != "99");
	system("cls");
	
	system("del musteriKayitTut.txt");
	system("del rezervTut.txt");
	system("del odaKayitTut.txt");
	system("cls");
	cout << "PROGRAMDAN �IKILDI.\n";
	system("pause");
	return 0;
}
