/****************************************************************************
**		
**		
**			  AD-Soyad............:Melih Güler
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
	string secim;		//Menü seçimlerinde kullanýlan deðiþken.
	do {
		system("cls");
		cout << "OTEL ÝÞLEMLERÝ\n";
		for (int i = 0; i < 20; i++)
			cout << "-";
		cout << endl;
		cout << "1- ODA ÝSLEMLERÝ\n";
		cout << "2- MÜÞTERÝ ÝÞLEMLERÝ\n";
		cout << "3- ODA KAYIT ÝÞLEMLERÝ\n";
		cout << "99- ÇIKIÞ\n";
		cout << "SEÇÝMÝNÝZ: ";
		cin >> secim;

		//------------------------------------------------------ANA_MENU_1.SECENEK_GIRIS-----------------------------------------------				
		if (secim == "1") {
			string secimILK;		//Menü seçimlerinde kullanýlan deðiþken.
			do {
				system("cls");
				cout << "ODA ÝÞLEMLERÝ\n";
				for (int i = 0; i < 20; i++)
					cout << "-";
				cout << endl;
				cout << "1- ODA EKLE\n";
				cout << "2- ODA SÝL\n";
				cout << "3- ODALARI LÝSTELE\n";
				cout << "99- ÜST MENÜ\n";
				cout << "SEÇÝMÝNÝZ: ";
				cin >> secimILK;
				//------------------------------------1 in icindeki 1 giris-------------
				if (secimILK == "1") {
					string kontrol;			//iþlem sonunda devam edilip edilmeyeceði sorulurken kullanýlan deðiþken.
					do {
						system("cls");
						string tut;
						int kontrolx = 0, kontrol2x = 0;  //oda numaralarý daha önce kullanýlmýþ mý ve nizami mi diye kontrol ederken kullanýlan yardýmcý deðiþken.
						do {
							kontrolx = 0, kontrol2x = 0;
							dosyaOku.open("odaKayit.txt");
							cout << "4 HANELÝ ODA NUMARASI GÝRÝN: ";
							cin >> ODA.odaNo;
							tut = ODA.odaNo;
							while (dosyaOku >> ODA.odaNo >> ODA.ucret) {

								if (tut == ODA.odaNo)
									kontrolx = 1;         //eðer oda numarasý daha öncee kullanýlmýþsa deðiþkene 1 deðeri atanýyor.
							}
							dosyaOku.close();
							for (int i = 0; i < tut.length(); i++) {
								if (!(tut[i] > 47 && tut[i] < 58))
									kontrol2x = 1;       //eðer oda numarasýna rakamdandan baþka birþey yazýldýysa kontrol2x deðiþkenine 1 atanýyor.
							}
							if (kontrolx == 1) {
								system("cls");
								cout << "BU ODA NUMRASI KULLANILMAKTADIR. BAÞKA BÝR NUMARA SEÇÝN...\n";				//kontrolx deðiþkenine 1 atanmýþsa kullanýcýya uyarý yapýlýyor.
								system("pause");
								system("cls");
							}
							else if (kontrol2x == 1) {
								system("cls");
								cout << "ODA NUMARASI RAKAMLARDAN OLUÞMALI...\n";						//kontrol2x deðiþkenine 1 atanmýþsa kullanýcýya uyarý yapýlýyor.
								system("pause");
								system("cls");
							}
							else if (tut.length() != 4) {
								system("cls");
								cout << "ODA NUMARASI 4 HANELÝ OLMALI...\n";			//oda numarasý 4 haneden fazla ise kullanýcýya uyarý yapýlýyor.
								system("pause");
								system("cls");
							}

						} while (kontrolx == 1 || kontrol2x == 1 || tut.length() != 4);		//yukarýdaki uyarýlardan en az biri bile yapýldýysa tekrardan numara girmesi isteniyor.
						kontrolx = 0, kontrol2x = 0;
						int kontrol4x;		//eðer harf harici bir karakter kullanýlmýþsa kullanýcýyý uyarmak için kullanýlacak deðiþken.
						string uctut; //oda ucreti girilirken rakam harici bir karakter kullanýlmýþ mý diye kontrol etmek icin kullanýlan deðiþken.
						do {
							kontrol4x = 0;				//kontrol4x deðiþkenine random olarak 0 atanýr.
							cout << "ODANIN ÜCRETÝNÝ GÝRÝN: ";
							cin >> ODA.ucret;
							uctut = ODA.ucret;
							int nn;
							char li;
							for (int i = 0; i < uctut.length(); i++) {
								li = uctut[i];
								nn = static_cast<int>(li);
								if (!((nn > 47) && (nn < 58)))
									kontrol4x = 1;				//eðer rakam harici bir karakter kullanýlmýþsa kontrol4x deðiþkenine 1 atanýr.
							}
							if (kontrol4x == 1) {
								system("cls");
								cout << "ÜCRET ALANINA RAKAMDAN BAÞKA BÝR ÞEY GÝRÝLEMEZ...\n";			//eðer kontrol4x deðiþkenine 1 atanmýþsa uyarý verir.
								system("pause");
								system("cls");
							}
						} while (kontrol4x == 1);	//kontrol4x deðiþkeni 1 ise uyarýdan sonra yeniden ücret girilmesi istenir.

						dosyaYaz.open("odaKayit.txt", ios::app);
						dosyaYaz << tut << "\t" << ODA.ucret << endl;
						dosyaYaz.close();
						system("cls");
						cout << "ODA KAYDI BAÞARIYLA YAPILMIÞTIR\n";
						do {
							system("cls");
							cout << "KAYIT ÝÞLEMÝNE DEVAM ETMEK ÝSTERMÝSÝNÝZ(e/h): ";
							cin >> kontrol;
							if (kontrol != "e"&&kontrol != "h") {
								cout << "\n-e- VEYA -h- HARFLERÝNDEN BÝRÝNÝ GÝRÝN...\n";
								system("pause");
								system("cls");
							}

						} while (kontrol != "e"&&kontrol != "h");
					} while (kontrol == "e");

				}
				//-----------------------------1 icindeki 2 giris-------------------
				else if (secimILK == "2") {

					string secim1;
					int  nul;		//oda silerken silinecek odanýn olup olmadýðýný söylemek için kullanýlan deðiþken.
					string no;		//girilen oda numarasýnýn olup olmadýðýný kontrol ederken kullanýlan deðiþken.
					do {
						do {
							nul = 0;
							system("cls");
							cout << "SÝLÝNECEK ODANIN NUMARASINI GÝRÝN: ";
							cin >> no;
							dosyaOku.open("odaKayit.txt");
							while (dosyaOku >> ODA.odaNo >> ODA.ucret) {
								if (no == ODA.odaNo)
									nul = 1;							//böyel bir numara varsa nul deðiþkenine 1 atanýr.
							}
							dosyaOku.close();
							if (nul == 0) {
								system("cls");
								cout << "BU NUMARADA BÝR ODA BULUNMAMAKTADIR.\n";    // böyle bir numara yoksa nul deðiþkeni varsayýlan olarak sýfýr olur ve uyarý verir.
								system("pause");
							}
						} while (nul == 0);  //girilen oda numarasý yoksa yeniden numara ister.

											 //---------------------------------------------------------------------------------
						dosyaYaz.open("rezervTut.txt");                                               //eðer silinen odanýn rezervasyonu varsa onu da siler.
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
						cout << "SÝLME ÝÞLEMÝ BAÞARILI\n";

						do {
							system("cls");
							cout << "SÝLME ÝÞLEMÝNE DEVAM ETMEK ÝSTERMÝSÝNÝZ(e/h): ";
							cin >> secim1;
							if (secim1 != "e"&&secim1 != "h") {
								cout << "\n-e- VEYA -h- HARFLERÝNDEN BÝRÝNÝ GÝRÝN...\n";
								system("pause");
								system("cls");
							}

						} while (secim1 != "e"&&secim1 != "h");
					} while (secim1 == "e");
				}
				//-------------------1 icindeki 3 giris--------------------------------
				else if (secimILK == "3") {
					system("cls");
					cout << "Oda Numarasý" << "\t" << "Ücreti\n";
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
					cout << "HATALI SEÇÝM\n";
					system("pause");
				}

			} while (secimILK != "99");

		}
		//------------------------------------------------------------------------ANA_MENU_1.SECENEK_CIKIS--------------------------------------	


		//------------------------------------------------------------------------ANA_MENU_2.SECENEK_GIRIS-------------------------------------

		if (secim == "2") {
			string secimILK;   //menü seçimde kullanýlacak deðiþken.
			do {
				system("cls");
				cout << "MÜÞTERÝ ÝÞLEMLERÝ\n";
				for (int i = 0; i < 20; i++)
					cout << "-";
				cout << endl;
				cout << "1- MÜÞTERÝ EKLE\n";
				cout << "2- MÜÞTERÝ SÝL\n";
				cout << "3- MÜÞTERÝLERÝ LÝSTELE\n";
				cout << "99- ÜST MENÜ\n";
				cout << "SEÇÝMÝNÝZ: ";
				cin >> secimILK;
				//------------------------------------2 nin icindeki 1 giris-------------
				if (secimILK == "1") {
					string kontrol;
					string a;
					int pl; //ad ve soyadda rakam ve kullanýlamayan karakterilerin kontrolü için oluþturulan deðiþken.
					do {

						system("cls");
						do {
							pl = 0;
							cout << "MÜÞTERÝ ADINI GÝRÝN: ";
							cin >> must.ad;
							for (int i = 0; i < ((must.ad).length()); i++) {
								int n = static_cast<int>(must.ad[i]);
								if (!((n > 64 && n < 91) || (n > 96 && n < 123))) {
									pl = 1;

								}
							}
							if (pl == 1) {
								system("cls");
								cout << "ÝSÝM BÖLÜMÜNDE ÝNGÝLÝZCE HARFLERDEN BAÞKA KARAKTER KULLANILAMAZ\n";
								system("pause");
								system("cls");
							}
						} while (pl == 1);

						do {
							pl = 0;
							cout << "MÜÞTERÝ SOYADINI GÝRÝN: ";
							cin >> must.soyad;
							for (int i = 0; i < ((must.soyad).length()); i++) {
								int n = static_cast<int>(must.soyad[i]);
								if (!((n > 64 && n < 91) || (n > 96 && n < 123))) {
									pl = 1;

								}
							}
							if (pl == 1) {
								system("cls");
								cout << "SOYAD BÖLÜMÜNDE ÝNGÝLÝZCE HARFLERDEN BAÞKA KARAKTER KULLANILAMAZ\n";
								system("pause");
								system("cls");
							}
						} while (pl == 1);
						int u = 0, olo = 0;  //tc no ve müþteri no'larý nizamimi ve daha önceden kullanýlmýþ mý diye kontrol ederken kullanýlan deðiþkenler.
						char n;
						string tutTC, tg, yh, th; //dosyada nokuma esnasýnda ad,soyad ve tcnin karýþmamasý için kullanýlan deðiþkenler.
						do {
							dosyaOku.open("musteriKayit.txt");
							u = 0, olo = 0; int p = 0;
							cout << "MÜÞTERÝNÝN 11 HANELÝ TC KÝMLÝK NUMARASINI GÝRÝN: ";
							cin >> must.tckn;
							tutTC = must.tckn;
							while (dosyaOku >> tg >> th >> must.tckn >> yh) {
								if (tutTC == must.tckn)          //eðer tckn sistemde kayýtlýysa olo deðiþkenine 1 atar.
									olo = 1;
							}
							dosyaOku.close();

							for (int i = 0; i < (tutTC.length()); i++) {
								n = tutTC[i];
								p = static_cast<int>(n);
								if (!(p > 47 && p < 58))						//eðer tckn de rakamdan farklý bir karakter kulllanýlmýþsa u deðiþkenine 1 atar.
									u = 1;
							}
							if (u == 1) {
								system("cls");
								cout << "TCKN SADECE RAKAMLARDAN OLUÞMALI...\n";			//u deðiþkenine 1 atanmýþsa uyarý verir.
								system("pause");
								system("cls");
							}
							else if (tutTC.length() != 11) {
								system("cls");
								cout << "TCKN 11 HANELÝ OLMALI...\n";					//tckn 11 haneli deðilse uyarý verir.
								system("pause");
								system("cls");
							}

							else if (olo == 1) {
								system("cls");
								cout << "BU TCKN KAYITLARDA BULUNMAKTA. BAÞKA BÝR TCKN GÝRÝNÝZ...\n";			//olo deðikenine 1 atanmýþsa uyarý verir.
								system("pause");
								system("cls");
							}
						} while (u == 1 || tutTC.length() != 11 || olo == 1); //eðer uyarýlardan biri bile olduysa tckn nin yeniden girilmesini ister.

						int tutucu, tutucu2;   //musteri numarasý daha önceden alýnmýþ mý ve nizami mi diye kontrol edilirken kullanýlan deðiþkenler.
						string mustno;
						do {
							tutucu = 0, tutucu2 = 0;
							cout << "MÜÞTERÝNÝN 5 HANELÝ MÜÞTERÝ NUMARASINI GÝRÝN: ";
							cin >> must.musteriNuumarasi;
							mustno = must.musteriNuumarasi;
							dosyaOku.open("musteriKayit.txt");
							while (dosyaOku >> tg >> th >> must.tckn >> must.musteriNuumarasi) {
								if (mustno == must.musteriNuumarasi)
									tutucu = 1;                              // müþteri numarasý daha önceden kayýtlanmýþsa tutucu deðiþkenine 1 atar.
							}
							char u;
							int y;
							dosyaOku.close();
							for (int i = 0; i < mustno.length(); i++) {
								u = mustno[i];
								y = static_cast<int>(u);
								if (!(y > 47 && 58 > y))					//eðer müþteri numarasýnda rakamdan farklý bir karakter varsa tutucu2 deðiþkenine 1 atar.
									tutucu2 = 1;
							}
							if (tutucu == 1) {
								system("cls");
								cout << "BU MÜÞTERÝ NUMARASI BAÞKA BÝR KÝÞÝ TARAFINDAN KULLANILMAKTADIR...\n";
								system("pause");
								system("cls");
							}
							else if (tutucu2 == 1) {
								system("cls");
								cout << "MÜÞTERÝ NUMARASI SADECE RAKAMLARDAN OLUÞMALI...\n";
								system("pause");
								system("cls");
							}
							else if (mustno.length() != 5) {						//müþeri numarasý 5 haneden farklý ise uyarý verir.
								system("cls");
								cout << "MÜÞTERÝ NUMARASI 5 HANELÝ OLMALI...\n";
								system("pause");
								system("cls");
							}
						} while (tutucu == 1 || tutucu2 == 1 || mustno.length() != 5);  //uyarýlardan biri bile verildiyse yeninen numara girmenizi ister.

						dosyaYaz.open("musteriKayit.txt", ios::app);
						dosyaYaz << must.ad << "\t" << must.soyad << "\t" << tutTC << "\t" << mustno << endl;
						dosyaYaz.close();
						system("cls");
						cout << "MÜÞTERÝ KAYDI YAPILMIÞTIR\n";
						system("pause");
						do {
							system("cls");
							cout << "YENÝ KAYIT(e/h): ";
							cin >> kontrol;
							if (kontrol != "e"&&kontrol != "h") {
								cout << "\n-e- VEYA -h- HARFLERÝNDEN BÝRÝNÝ GÝRÝN...\n";
								system("pause");
								system("cls");
							}

						} while (kontrol != "e"&&kontrol != "h");
					} while (kontrol == "e");

				}
				//-----------------------------2 nin icindeki 2 giris-------------------
				else if (secimILK == "2") {

					string secim1;
					string no;  //müþteri numarasý sistemde varmý diye kontrol eden deðiþken.

					do {
						int g = 0;      //silinmesi için girilen numaranýn var olup olmadýðýný anlamak için kullanýlan deðiþken.
						do {
							g = 0;
							system("cls");
							cout << "SÝLÝNECEK MÜÞTERÝNÝN NUMARASINI GÝRÝN: ";
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
								cout << "BÖYLE BÝR KAYIT BULUNMAMAKTADIR.\n";
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
						cout << "SÝLME ÝÞLEMÝ YAPILMIÞTIR\n";
						system("pause");
						do {
							system("cls");
							cout << "SÝLME ÝÞLEMÝNE DEVAM ETMEK ÝSTERMÝSÝNÝZ(e/h): ";
							cin >> secim1;
							if (secim1 != "e"&&secim1 != "h") {
								cout << "\n-e- VEYA -h- HARFLERÝNDEN BÝRÝNÝ GÝRÝN...\n";
								system("pause");
								system("cls");
							}

						} while (secim1 != "e"&&secim1 != "h");
					} while (secim1 == "e");
				}
				//-------------------2 nin icindeki 3 giris--------------------------------
				else if (secimILK == "3") {
					system("cls");
					cout << "MÜÞTERÝ ADI" << "\t" << "MÜÞTERÝ SOYADI" << "\t" << "MÜÞTERÝ TCKN" << "\t" << "MÜÞTERÝ NUMARASI\n";
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
					cout << "HATALI SEÇÝM\n";
					system("pause");
				}

			} while (secimILK != "99");

		}
		//------------------------------------------------------------------------ANA_MENU_2.SECENEK_CIKIS-------------------------------------

		//------------------------------------------------------------------------ANA_MENU_3.SECENEK_GIRIS-------------------------------------
		if (secim == "3") {
			string secimILK;   //menü seçimlerinde kullanýlan deðiþken.
			do {
				system("cls");
				cout << "ODA KAYIT ÝÞLEMLERÝ\n";
				for (int i = 0; i < 20; i++)
					cout << "-";
				cout << endl;
				cout << "1- ODA REZERVASYONU\n";
				cout << "2- REZERVASYON SÝLME\n";
				cout << "3- REZERVASYONLARI LÝSTELE\n";
				cout << "99- ÜST MENÜ\n";
				cout << "SEÇÝMÝNÝZ: ";
				cin >> secimILK;

				//------------------------3 icindeki 1 giris-----------------------------------------------------------			

				if (secimILK == "1") {
					int  b = 0, d = 0, t = 0, y, o = 0;   //oda daha önce tutulmuþsa veya böyle bir oda yoksa bu bilgileri saklamak için kullanýlan deðiþkenler.
					string q;  //yeni rezeervasyon yapýlýp yapýlmayacaðýný tutan deðiþken.
					string adtut, a, tutt, c;    //odanýn daha öne tutulup tutulmadýðýný ve böyle bir odanýn olup olmadýðýný kontrol ederken kullanýlan deðiken.

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
								cout << "BU ODA DAHA ÖNCEDEN ALINMIÞ...\n";
								system("pause");
								system("cls");
							}

						} while (b == 0 || o == 1);
						do {
							d = 0;        // girilen numaranýn rezervasyonu daha önceden yapýlmýþ mý ve girilen numara sistemde kayýtlý mý diye kontrol eden deðiþkenler.		 
							t = 0;
							cout << "ODAYA YERLEÞECEK MÜÞTERÝNÝN NUMARASI: ";
							cin >> c;
							dosyaOku.open("rezerv.txt");
							while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad)
							{
								if (c == must.musteriNuumarasi)				//numaranýn daha önceden rezervasyonu yapýlmýþsa t deðiþkenine 1 atar.
									t = 1;

							}
							dosyaOku.close();
							dosyaOku.open("musteriKayit.txt");
							while (dosyaOku >> must.ad >> must.soyad >> must.tckn >> must.musteriNuumarasi) {
								if (c == must.musteriNuumarasi) {							//müþteri numarasý sistemde kayýtlýysa d deðiþkenine 1 atar.
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
								cout << "HATALI MÜÞTERÝ NUMARASI...\n";
								system("pause");
								system("cls");
							}
							else if (t == 1)   // t deðiþkenine 1 atanmýþsa uyarý verir.
							{
								system("cls");
								cout << "GÝRDÝÐÝNÝZ NUMARANIN REZERVASYONU YAPILMIÞ...\n";
								system("pause");
								system("cls");
							}

						} while (d == 0 || t == 1);   //t deðiþkenine 1 atanmýþsa veya d deðiþkeni 0 sa yeniden numara girilmesini ister.
						dosyaYaz.open("rezerv.txt", ios::app);
						dosyaYaz << tutt << "\t" << must.musteriNuumarasi << "\t" << must.ad << endl;
						dosyaYaz.close();
						do {
							system("cls");
							cout << "YENÝ REZERVASYON(e/h): ";
							cin >> q;
							if (q != "e" && q != "h") {
								cout << "-e- VEYA -h- HARFLERÝNDEN BÝRÝNÝ GÝRÝN...\n";
								system("pause");
							}

						} while (q != "e"&&q != "h");



					} while (q == "e");//oda kayit devam
				}

				//------------------------3 icindeki 2 giris-------------------------------------------------

				if (secimILK == "2") {
					int lol;		//numara var mý yok mu diye kontrol edilirken kullanýlan deðiþken.
					string secim1;
					string no;  //silinecek nmaranýn rezervasyonu var mý diye kontrol etmek için kullanýlan deðiþken.
					do {
						do {
							lol = 0;
							system("cls");
							cout << "REZERVASYONU SÝLÝNECEK MÜÞTERÝNÝN NUMARASINI GÝRÝN: ";
							cin >> no;
							dosyaOku.open("rezerv.txt");
							while (dosyaOku >> ODA.odaNo >> must.musteriNuumarasi >> must.ad)
							{
								if (no == must.musteriNuumarasi)                        //numaranýn rezervasyonu varsa lol deðiþkenine 1 atanýr.
									lol = 1;
							}
							dosyaOku.close();
							if (lol == 0) {									//eðer lol deðiþkeni sýfýrsa yani bu numaranýn rezervasyonu yoksa uyarý verir.
								system("cls");
								cout << "BU NUMARANIN REZERVASYONU BULUNMAMAKTADIR.\n";
								system("pause");
							}
						} while (lol == 0);  // lol deðiþkeni sýfýrsa yeniden numara ister.

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
						cout << "REZERVASYON SÝLME ÝÞLEMÝ BAÞARILI\n";
						system("pause");
						do {
							system("cls");
							cout << "SÝLME ÝÞLEMÝNE DEVAM ETMEK ÝSTERMÝSÝNÝZ(e/h): ";
							cin >> secim1;
							if (secim1 != "e"&&secim1 != "h") {
								cout << "\n-e- VEYA -h- HARFLERÝNDEN BÝRÝNÝ GÝRÝN...\n";
								system("pause");
								system("cls");
							}

						} while (secim1 != "e"&&secim1 != "h");

					} while (secim1 == "e");

				}

				//------------------------------------3 ic 2 cýkýs-----------------------------------------------

				if (secimILK == "3") {
					system("cls");
					dosyaOku.open("rezerv.txt");
					cout << setw(15) << "                        --------------------------REZERVASYONLAR--------------------------\n";
					cout << "ODA NUMARASI" << "\t" << "MÜÞTERÝ NUMARASI" << "\t" << "MÜSTERÝ ADI" << endl;
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
				//-----------------------------------3 ic 3  cýkýs-----------------------------------------------




				if (secimILK != "1" && secimILK != "2" && secimILK != "3" && secimILK != "99") {
					system("cls");
					cout << "HATALI SEÇÝM.\n";
					system("pause");
				}




			} while (secimILK != "99");

		}
		if ((secim != "1") && (secim != "2") && (secim != "3") && (secim != "99")) {
			system("cls");
			cout << "HATALI SEÇÝM\n";
			system("pause");
		}
	} while (secim != "99");
	system("cls");
	
	system("del musteriKayitTut.txt");
	system("del rezervTut.txt");
	system("del odaKayitTut.txt");
	system("cls");
	cout << "PROGRAMDAN ÇIKILDI.\n";
	system("pause");
	return 0;
}
