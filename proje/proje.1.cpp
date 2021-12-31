
#include<iostream> 
#include<locale.h> //turkce harf kullanimi icin kutuphane
#include<Windows.h>//konsolu renklendirmek icin kutuphane
#include<fstream> //dosyalama islemleri icin
#include<string> //string ifadeleri kullanmak icin kutuphane
using namespace std;
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //renkli yazi icin

int kontrol = 0; 
int kontrol2 =0 ;
//MUSTERI SINIFI
class Musteriler { 
private:
	string firmaNo;
	string firmaAdi;
	string firmaTelefon;
	string firmaSorumlusu;
	char kategori;
	string firmaAdres;
	string kontrolfirmano;
	string kategorioku;
	string kontrolfirmano2;
	//fonksiyonların prototip tanimlamasi
public:
	void musteriEkle();
	void musteriAra();
	void musteriDuzelt();
	void musteriSil();

};

//URUN SINIFI
class Urunler {
private:
	string urunKodu;
	string urunAdi;
	string teminSuresi;
	string uretici;
	string uretimTarihi;
	string kontrolurunkod;
	string kontrolurunkod2;
	double genelFiyat;
	double ozelFiyat;
	int kdv;
	int stokAdedi;
	//fonksiyonlarin prototip tanimlamasi
public:
	void urunEkle();
	void urunAra();
	void urunListele();
	void urunDuzelt();
	void urunSil();

};

//SIPARIS SINIFI
class Siparis {
private:
	string siparisKodu;
	string siparisTarihi;
	string siparisListesi;
	string siparisAlan;
	string urunKodu;
	string kontrolsipariskod;
	int adet1;
	string urunkodu1;
	string sipariskodu1;
	string siparisdosyasi;
	//firma iliskisi
	string firmaNo;
	string firmaAdi;
	string firmaTelefon;
	string firmaSorumlusu;
	char kategori;
	string firmaAdres;
	string kontrolfirmano;

	//urun iliskisi
	string urunAdi;
	string teminSuresi;
	string uretici;
	string uretimTarihi;
	string kontrolurunkod;
	double genelFiyat;
	double ozelFiyat;
	string kdv;
	int stokAdedi;

	double siparisTutar;
	int adet;
	char siparis;
public:
	void siparisOlustur();
	void siparisAra();
	void siparisSil();
	void siparisDuzelt();
	void siparisRapor();
};

//Musteri Ekle Fonksiyonu
void Musteriler::musteriEkle() {
	kontrol = 0;
	ofstream dosyaYaz; 
	dosyaYaz.open("cari.txt", ios::app); //yazilmak icin dosya acildi
	ifstream dosyaOku;
	dosyaOku.open("cari.txt"); //okunmak icin dosya acildi
	cout << "Firma Numarasi: "; cin >> kontrolfirmano; //tekilligi saglamak icin kontrol istendi
	
	//cari.txt dosyasini satir satir oku
	while (dosyaOku >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> firmaAdres >> kategori)
	{
		if (kontrolfirmano == firmaNo) 
		{
			kontrol = 1;
		
		}	
	}
	if (kontrol==1)  //kontrol numarasi firma numarasina esitse mevcut
	{
		SetConsoleTextAttribute(hConsole,12);
		cout << "Müsteri Zaten Mevcut \n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	if (dosyaOku.tellg()==0) //dosya boş mu kontrol etmek icin
	{
		firmaNo = kontrolfirmano;
		cout << "Fİrma Adi: \n"; cin >> firmaAdi;
		cout << "Firma Telefon: \n"; cin >> firmaTelefon;
		cout << "Firma Sorumlusu: \n"; cin >> firmaSorumlusu;
		cout << "Firma Adres: \n"; cin >> firmaAdres;
		//Musteri kategorisini 0 ve 1 girmesini saglamak icin do dongusu
		do             
		{
			cout << "Firma Kategori (1=ÖZEL 0=GENEL)\n"; cin >> kategori;
		} while (!(kategori == '1' || kategori == '0'));

		//alinan bilgilerin dosyaya yazilmasi
		dosyaYaz << firmaNo << " " << firmaAdi << " " << firmaTelefon << " "
			<< firmaSorumlusu << " " << firmaAdres << " " << kategori << endl;
		SetConsoleTextAttribute(hConsole, 12); 
		cout << "Kayıt Başarılı \n";
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	if (dosyaOku.tellg()!=0) //dosya bos degilse 
	{
		if (kontrol == 0)
		{
			firmaNo = kontrolfirmano;
			cout << "Firma Adi: "; cin >> firmaAdi;
			cout << "Firma Telefon: "; cin >> firmaTelefon;
			cout << "Firma Sorumlusu: "; cin >> firmaSorumlusu;
			cout << "Firma Adres: "; cin >> firmaAdres;
			do
			{
				cout << "Firma Kategori (1=ÖZEL 0=GENEL): "; cin >> kategori;
			} while (!(kategori == '1' || kategori == '0'));

			dosyaYaz << firmaNo << " " << firmaAdi << " " << firmaTelefon << " "
				<< firmaSorumlusu << " " << firmaAdres << " " << kategori << endl;
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Kayıt Başarılı \n";
			SetConsoleTextAttribute(hConsole, 15);
			
		}

	}
	 //dosyalar kapatildi
	dosyaOku.close();
	dosyaYaz.close();
};
//Musteri Ara Fonksiyonu 
void Musteriler::musteriAra() {
	kontrol = 0;
	ifstream dosyaoku;
	dosyaoku.open("cari.txt");
	cout << "Arama Yapmak İstediğiniz Firma Numarasını Giriniz \n"; cin >> kontrolfirmano;
	while (dosyaoku >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> firmaAdres >> kategori) //satir satir cari.txt dosyasini okuyacak
	{
		if (kategori=='1')
		{
			kategorioku = "özel";
		}
		else
		{
			kategorioku = "genel";
		}
		if (kontrolfirmano == firmaNo) //esitse yazdir
		{
			kontrol = 1;
			cout << "Firma Numarası: " << firmaNo << endl << "Firma Adı: " << firmaAdi << endl
				<< "Firma Telefon: " << firmaTelefon << endl << "Firma Sorumlusu: " << firmaSorumlusu
				<< endl << "Firma Adres: " << firmaAdres << endl << "Kategori: " << kategorioku << endl;
			break;
		}
	}
	if (kontrol == 0) { //esit degilse 
		SetConsoleTextAttribute(hConsole, 12); 
		cout << "Müşteri Bulunamadı\n";
		SetConsoleTextAttribute(hConsole, 15);
		
		
	}
	dosyaoku.close();
}

//Musteri Duzelt Fonksiyonu
void Musteriler::musteriDuzelt(){
	kontrol = 0;
	ifstream okumusteri;
	okumusteri.open("cari.txt");
	ofstream duzeltmusteri;
	duzeltmusteri.open("gecici.txt", ios::app);//gecici bir dosya olusturduk bu dosyaya musterileri ekliyoruz
	cout << "Düzeltmek İstediğiniz Firma Numarasını Giriniz \n"; cin >> kontrolfirmano;
	while (okumusteri >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> firmaAdres >> kategori)
	{
		int kontrol2 = 0;
		if (kontrolfirmano == firmaNo)
		{
			kontrol = 1;
			cout << "Güncelleyiniz \n";
			cout << "Firma Numarası: "; cin >> kontrolfirmano2; //tekrar dosyada musteri mevcut mu kontrol etmek icin
			ifstream okumusteri1;
			okumusteri1.open("cari.txt");
			while (okumusteri1 >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> firmaAdres >> kategori)
			{

				if (kontrolfirmano2 == firmaNo)
				{
					kontrol2 = 1;
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Bu Müşteri Zaten Mevcut Olduğu İçin Bu Numarayı Kullanmazsınız\n";
					SetConsoleTextAttribute(hConsole, 15);
				}

			}
			okumusteri1.close();
			if (kontrol2 == 0) //2.kontrolden sonra musteri yoksa eklenebilir
			{
				firmaNo = kontrolfirmano2;
				cout << "Fİrma Adi: "; cin >> firmaAdi;
				cout << "Firma Telefon: "; cin >> firmaTelefon;
				cout << "Firma Sorumlusu: "; cin >> firmaSorumlusu;
				cout << "Firma Adres: "; cin >> firmaAdres;
				do
				{
					cout << "Firma Kategori (1=ÖZEL 0=GENEL): \n"; cin >> kategori;
				} while (!(kategori == '1' || kategori == '0'));
				duzeltmusteri << firmaNo << " " << firmaAdi << " " << firmaTelefon << " " << firmaSorumlusu << " "
					<< firmaAdres << " " << kategori << "\n";

			}
			else //eger musteri mevcutsa degistirmek istedigimiz musteri silinmemesi icin 
			{
				firmaNo = kontrolfirmano;
				duzeltmusteri << firmaNo << " " << firmaAdi << " " << firmaTelefon << " " << firmaSorumlusu << " "
					<< firmaAdres << " " << kategori << "\n";
			}
		}

		else   //düzeltmek istemedigimiz müsterileri direk gecici dosyaya yazıyoruz
		{

			duzeltmusteri << firmaNo << " " << firmaAdi << " " << firmaTelefon << " " << firmaSorumlusu << " "
				<< firmaAdres << " " << kategori << "\n";
		}

	}
	if (kontrol == 0)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Müşteri Bulunamadı\n";
		SetConsoleTextAttribute(hConsole, 15);

	}
	okumusteri.close();
	duzeltmusteri.close();
	remove("cari.txt");				//geciciye geçirdiğimiz müşterileri cari.txt den siliyoruz						
	rename("gecici.txt", "cari.txt");  //gecici.txt dosyasının adını cari.txt yapıyoruz

}
//Musteri Sil Fonksiyonu
void Musteriler::musteriSil() {
	kontrol = 0;
	ifstream okumusteri;
	okumusteri.open("cari.txt");
	ofstream silmusteri;
	silmusteri.open("gecici.txt", ios::app);//gecici bir dosya oluşturduk bu dosyaya müşterileri ekliyoruz
	cout << "Silmek İstediğiniz Firma Numarasını Giriniz \n"; cin >> kontrolfirmano;
	while (okumusteri >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> firmaAdres >> kategori)
	{
		if (kontrolfirmano == firmaNo)   //silmek istenilen firmayi goruntuleyip dosyaya yazmiyoruz
		{
			kontrol = 1;
			cout << "Silinen Musteri Bilgileri \n";
			cout << "Firma numarası: " << firmaNo << endl << "Firma adı: " << firmaAdi << endl
				<< "Firma telefon: " << firmaTelefon << endl << "Firma sorumlusu: " << firmaSorumlusu
				<< endl << "Firma adres: " << firmaAdres << endl << "Kategori: " << kategori << endl;
			SetConsoleTextAttribute(hConsole, 12);
			cout << "SİLİNDİ \n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		else   //silmek istemedigimiz musterileri gecici dosyaya yaziyoruz
		{
			silmusteri << firmaNo << " " << firmaAdi << " " << firmaTelefon << " " << firmaSorumlusu << " "
				<< firmaAdres << " " << kategori << "\n";
		}

	}
	if (kontrol == 0)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Müşteri Bulunamadı\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	okumusteri.close();
	silmusteri.close();
	remove("cari.txt");				//geciciye geçirdiğimiz müşterileri cari.txt den siliyoruz						
	rename("gecici.txt", "cari.txt");  //gecici.txt dosyasının adını cari.txt yapıyoruz
}


//URUNLER 

//Urun Ekle Fonksiyonu
void Urunler::urunEkle() {
	ofstream urunekle;
	urunekle.open("urun.txt", ios::app);
	ifstream urunoku;
	urunoku.open("urun.txt");
	kontrol = 0;
	cout << "Urun Kodu: \n"; cin >> kontrolurunkod;
	while (urunoku>>urunKodu>>urunAdi>>teminSuresi>>uretici>>uretimTarihi>>genelFiyat>>ozelFiyat>>kdv>>stokAdedi)//urun.txt dosyasini satir satir okumak icin
	{
		if (kontrolurunkod==urunKodu)
		{
			kontrol = 1;
		}
	}
	if (kontrol==1)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Ürün Mevcut \n";
		SetConsoleTextAttribute(hConsole, 15);
		cout << "Ürün Kodu: " << urunKodu << endl << "Ürün Adı: " << urunAdi << endl
		<< "Temin Süresi: " << teminSuresi << endl << "Üretim Tarihi: " << uretimTarihi
		<< endl << "Genel Fiyat: " << genelFiyat << endl << "Özelfiyat: " << ozelFiyat << endl
		<< "KDV Oranı: " << kdv << endl << "Stok Adedi: " << stokAdedi << endl;
	}
	if (urunoku.tellg()==0)//dosya bos mu kontrol etmek icin
	{
		urunKodu = kontrolurunkod;
		cout << "Ürün Adı: "; cin >> urunAdi;
		cout << "Ürün Temin Süresi: "; cin >> teminSuresi;
		cout << "Ürün Üretici: "; cin >> uretici;
		cout << "Ürün Üretim Tarihi: "; cin >> uretimTarihi;
		cout << "Ürün Genel Fiyat: "; cin >> genelFiyat;
		cout << "Ürün Özel Fiyat: "; cin >> ozelFiyat;
		cout << "Ürün KDV: "; cin >> kdv;
		cout << "Ürün Stok Adedi: "; cin >> stokAdedi;
		urunekle << urunKodu << " " << urunAdi << " " << teminSuresi << " " << uretici << " " << uretimTarihi << " " <<
			genelFiyat << " " << ozelFiyat << " " << kdv << " " << stokAdedi << "\n";
		cout << "Kayıt Başarılı \n";
	}
	if (urunoku.tellg()!=0) //dosyabos degil ve dosyada bu urun mevcut degilse
	{
		if (kontrol==0)
		{
			urunKodu = kontrolurunkod;
			cout << "Ürün Adı: "; cin >> urunAdi;
			cout << "Ürün Temin Süresi: "; cin >> teminSuresi;
			cout << "Ürün Üretici: "; cin >> uretici;
			cout << "Ürün Üretim Tarihi: "; cin >> uretimTarihi;
			cout << "Ürün Genel Fiyat: "; cin >> genelFiyat;
			cout << "Ürün Özel Fiyat: "; cin >> ozelFiyat;
			cout << "Ürün KDV: "; cin >> kdv;
			cout << "Ürün Stok Adedi: "; cin >> stokAdedi;
			urunekle << urunKodu << " " << urunAdi << " " << teminSuresi << " " << uretici << " " << uretimTarihi << " " <<
				genelFiyat << " " << ozelFiyat << " " << kdv << " " << stokAdedi << "\n";
			cout << "Kayıt Başarılı \n";
		}
	}	
	urunoku.close();
	urunekle.close();
}
//Urun Ara Fonksiyonu
void Urunler::urunAra() {
	kontrol = 0;
	ifstream urunoku;
	urunoku.open("urun.txt");
	cout << "Arama Yapmak İstediğiniz Ürün Kodunu Giriniz \n"; cin >> kontrolurunkod;
	//urun dosyasini satir satir okuyarak urunleri yazdirmak icin
	while (urunoku >> urunKodu >> urunAdi >> teminSuresi >>uretici >>uretimTarihi >> genelFiyat >> ozelFiyat
		>> kdv >> stokAdedi)
	{

		if (kontrolurunkod == urunKodu)
		{
			kontrol = 1;
			cout << "Ürün Kodu: " << urunKodu << endl << "Ürün Adı: " << urunAdi << endl
				<< "Temin Süresi: " << teminSuresi << endl << "Üretim Tarihi: " << uretimTarihi
				<< endl << "Genel Fiyat: " << genelFiyat << endl << "Özelfiyat: " << ozelFiyat << endl
				<< "KDV Oranı: " << kdv << endl << "Stok Adedi: " << stokAdedi << endl;
			break;
		}
	}

	if (kontrol == 0) {
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Ürün bulunamadı\n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	urunoku.close();
}
//Urun Listele Fonksiyonu
void Urunler::urunListele() {
	ifstream urunoku;
	urunoku.open("urun.txt");
	SetConsoleTextAttribute(hConsole, 12);
	cout <<"ÜRÜN LİSTESİ \n";
	SetConsoleTextAttribute(hConsole, 15);
	//urun.txt dosyasindaki satirlari okuyup yazdir
	while (urunoku >> urunKodu >> urunAdi >> teminSuresi >> uretici >> uretimTarihi >> genelFiyat >> ozelFiyat
		>> kdv >> stokAdedi)
	{
		cout << "Ürün Kodu: " << urunKodu << endl << "Ürün Adı: " << urunAdi << endl
			<< "Temin Süresi: " << teminSuresi << endl << "Ürün üretici: " << uretici << endl
			<< "Üretim Tarihi: " << uretimTarihi
			<< endl << "Genel Fiyat: " << genelFiyat << endl << "Özel Fiyat: " << ozelFiyat << endl
			<< "KDV Oranı: " << kdv << endl << "Stok Adedi: " << stokAdedi << endl;
		SetConsoleTextAttribute(hConsole, 12);
		cout << "******************************"<<endl;
		SetConsoleTextAttribute(hConsole, 15);		
	}
	urunoku.close();
}
//Urun Duzelt Fonksiyonu
void Urunler::urunDuzelt() {
	kontrol = 0;
	ifstream okuurun;
	okuurun.open("urun.txt");
	ofstream duzelturun;
	duzelturun.open("gecici.txt", ios::app);
	cout << "Düzeltmek İstediğiniz Ürün Kodunu Giriniz: \n"; cin >> kontrolurunkod;
	while (okuurun >> urunKodu >> urunAdi >> teminSuresi >>uretici >>uretimTarihi >> genelFiyat >> ozelFiyat
		>> kdv >> stokAdedi)
	{
		int kontrol3 = 0;
		if (kontrolurunkod == urunKodu)
		{
			kontrol = 1;
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Güncelleyiniz \n";
			SetConsoleTextAttribute(hConsole, 15);
			cout << "Ürün Kodu: \n"; cin >> kontrolurunkod2;//duzeltilmek istenen urun kodu dosyada var mi tekrar kontrol icin
			ifstream urunoku2;
			urunoku2.open("urun.txt");
			while (urunoku2 >> urunKodu >> urunAdi >> teminSuresi >> uretici >> uretimTarihi >> genelFiyat >> ozelFiyat
				>> kdv >> stokAdedi)
			{

				if (kontrolurunkod2 == urunKodu)
				{
					kontrol3 = 1;
					SetConsoleTextAttribute(hConsole, 12);
					cout << "Bu Ürün Zaten Mevcut Olduğu İçin Bu Numarayı Kullanmazsınız\n";
					SetConsoleTextAttribute(hConsole, 15);
				}
			}
			urunoku2.close();
			
			if (kontrol3==0) //duzeltilmek istenen urun yoksa bilgileri al
			{
				urunKodu = kontrolurunkod2;
				cout << "Ürün Adı: \n"; cin >> urunAdi;
				cout << "Ürün Temin Süresi: \n"; cin >> teminSuresi;
				cout << "Ürün Üretici: \n"; cin >> uretici;
				cout << "Ürün Üretim Tarihi: \n"; cin >> uretimTarihi;
				cout << "Ürün Genel Fiyat: \n"; cin >> genelFiyat;
				cout << "Ürün Özel Fiyat: \n"; cin >> ozelFiyat;
				cout << "Ürün KDV: \n"; cin >> kdv;
				cout << "Ürün Stok Adedi: \n"; cin >> stokAdedi;

				duzelturun << urunKodu << " " << urunAdi << " " << teminSuresi << " " << uretici << " "
					<< uretimTarihi << " " << genelFiyat << " " << ozelFiyat << " " << kdv << " " << stokAdedi << "\n";
			}
			else//duzeltilmek istenen numara dosyada var ise girdigimiz urunun silinmemesi icin
			{
				urunKodu =kontrolurunkod;
				duzelturun << urunKodu << " " << urunAdi << " " << teminSuresi << " " << uretici << " "
					<< uretimTarihi << " " << genelFiyat << " " << ozelFiyat << " " << kdv << " " << stokAdedi << "\n";
			}


		}
		else //duzeltilmek istenmeyen diger urunlerin yazilmasi
		{
			duzelturun << urunKodu << " " << urunAdi << " " << teminSuresi << " " << uretici << " "
				<< uretimTarihi << " " <<genelFiyat << " " << ozelFiyat << " " << kdv << " " << stokAdedi << "\n";
		}

	}
	if (kontrol == 0)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "ÜRÜN BULUNAMADI \n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	okuurun.close();
	duzelturun.close();
	remove("urun.txt");
	rename("gecici.txt", "urun.txt");
}
//Urun Sil Fonksiyonu
void Urunler::urunSil() {
	kontrol = 0;
	ifstream okuurun;
	okuurun.open("urun.txt");
	ofstream silurun;
	silurun.open("gecici.txt", ios::app);
	cout << "Silmek İstediğiniz Ürün Kodunu Giriniz: \n"; cin >> kontrolurunkod;
	while (okuurun >> urunKodu >> urunAdi >> teminSuresi>>uretici >> uretimTarihi >> genelFiyat >> ozelFiyat
		>> kdv >> stokAdedi)
	{
		if (kontrolurunkod == urunKodu)//silinmek istenen urunu gecici dosyaya yazdirmiyoruz
		{
			kontrol = 1;
			cout << "Ürün Kodu: " << urunKodu << endl << "Ürün Adı: " << urunAdi << endl
				<< "Temin Süresi: " << teminSuresi << endl <<"Ürün Üretici: "<<uretici<<endl << "Üretim Tarihi: " << uretimTarihi
				<< endl << "Genel Fiyat: " << genelFiyat << endl << "Özelfiyat: " << ozelFiyat << endl
				<< "KDV Oranı: " << kdv << endl << "Stok Adedi: " << stokAdedi << endl <<
				"******************************" << endl;

			SetConsoleTextAttribute(hConsole, 12);
			cout << "SİLİNDİ \n";
			SetConsoleTextAttribute(hConsole, 15);

		}
		else//diger urunleri geciciye yaz
		{
			silurun << urunKodu << " " << urunAdi << " " << teminSuresi<<" "<<uretici << " " << uretimTarihi << " " <<
				genelFiyat << " " << ozelFiyat << " " << kdv << " " << stokAdedi << "\n";
		}

	}
	if (kontrol == 0)
	{
		
		SetConsoleTextAttribute(hConsole, 12);
		cout << "ÜRÜN BULUNAMADI \n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	okuurun.close();
	silurun.close();
	remove("urun.txt");
	rename("gecici.txt", "urun.txt");

}


//SİPARİS SINIFI

//Siparis Olustur Fonksiyonu
void Siparis::siparisOlustur() {
	kontrol = 0;
	kontrol2 = 0;
	ifstream musterioku;
	musterioku.open("cari.txt");
	cout << "Sipariş İçin Firma Numarası Giriniz: \n"; cin >>kontrolfirmano;
	while (musterioku >> firmaNo >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> firmaAdres >> kategori)
	{
		if (kontrolfirmano == firmaNo)   //musterinin kayitli olup olmadigi kontrol edilir
		{
			kontrol = 1;
			if (kategori == '1')  // musteri genel/ozel mi bakilir(ozel musteri)
			{
				ifstream urunoku;
				urunoku.open("urun.txt");
				//urun.txt dosyasini okuyup listeler fiyat musteri durumuna gore listelenir
				while (urunoku >> urunKodu >> urunAdi >> teminSuresi >>uretici>> uretimTarihi >> genelFiyat >> ozelFiyat>> kdv >> stokAdedi)
				{
					cout << "Ürün Kodu: " << urunKodu << endl << "Ürün Adı: " << urunAdi << endl
						<< "Temin Süresi: " << teminSuresi << endl << "Ürün Üretici: " << uretici << endl << "Üretim Tarihi: " << uretimTarihi
						<< endl << "Fiyat: " << ozelFiyat << endl
						<< "KDV Oranı: " << kdv << endl << "Stok Adedi: " << stokAdedi << endl;
					SetConsoleTextAttribute(hConsole, 12);
					cout << "******************************" << endl;
					SetConsoleTextAttribute(hConsole, 15);
				}

				cout << "Sipariş Vermek İçin e/E Tuşlayın \n"; cin >> siparis;
				if (siparis == 'e' || siparis == 'E')
				{
					ofstream siparissekle;
					siparissekle.open("siparis.txt", ios::app);
					ofstream siparisurun;
					siparisurun.open("siparisurun.txt", ios::app);
					ifstream urunoku;
					urunoku.open("urun.txt");
					cout << "Sipariş Vermek İstediğiniz Ürünün Ürün Kodunu Giriniz \n"; cin >> kontrolurunkod; //kullanici urun secer
					
					//listelenen urunler icinde secilen urunun stogu kontrol edilip diger bilgiler alindiktan sonra dosyaya yazilir				
					while (urunoku >> urunKodu >> urunAdi >> teminSuresi >> uretici >> uretimTarihi >> genelFiyat >> ozelFiyat>> kdv >> stokAdedi)
					{
						if (kontrolurunkod == urunKodu)
						{

							kontrol2 = 1;
							cout << "Kaç Adet İstiyorsunuz: "; cin >> adet;
							if (adet>stokAdedi)
							{
								SetConsoleTextAttribute(hConsole, 12);
								cout << "Stok Mevcut Değil \n";
								SetConsoleTextAttribute(hConsole, 15);
								
							}
							else
							{
								cout << "Sipariş Kodu: "; cin >> siparisKodu;
								firmaNo = kontrolfirmano;
								cout << "Siparis Tarihi: "; cin >> siparisTarihi;
								cout << "Sipariş Alan: "; cin >> siparisAlan;
								cout << "Sipariş Tutarı: " << adet * ozelFiyat << endl;
								siparisTutar = adet * ozelFiyat;
								siparisdosyasi = "siparisurun.txt";
								//2dosyayada siparis kodu eklendi
								siparissekle << siparisKodu << " " << firmaNo << " " << siparisTarihi << " " << siparisTutar << " " << siparisAlan<<" " << siparisdosyasi << "\n";
								siparisurun << siparisKodu << " " << urunKodu << " " << adet << "\n";
								SetConsoleTextAttribute(hConsole, 12);
								cout << "Sipariş Oluşturuldu \n";
								SetConsoleTextAttribute(hConsole, 15);
							}
							
						}
					
					}
					if (kontrol2==0)
					{
						SetConsoleTextAttribute(hConsole, 12);
						cout << "Yanlış Ürün Kodu \n";
						SetConsoleTextAttribute(hConsole, 15);
					}			
					siparissekle.close();
					siparisurun.close();
				}

				urunoku.close();

			}
			
			if (kategori == '0')  // müşteri genel/özel mi bakılır (genel musteri)
			{

				ifstream urunoku;
				urunoku.open("urun.txt");
				while (urunoku >> urunKodu >> urunAdi >> teminSuresi >> uretici >> uretimTarihi >> genelFiyat >> ozelFiyat >> kdv >> stokAdedi)
				{
					cout << "Ürün Kodu: " << urunKodu << endl << "Ürün Adı: " << urunAdi << endl
						<< "Temin Süresi: " << teminSuresi << endl << "Ürün Üretici: " << uretici << endl << "Üretim Tarihi: " << uretimTarihi
						<< endl << "Fiyat: " << genelFiyat << endl
						<< "KDV Oranı: " << kdv << endl << "Stok Adedi: " << stokAdedi << endl;
					SetConsoleTextAttribute(hConsole, 12);
					cout << "******************************" << endl;
					SetConsoleTextAttribute(hConsole, 15);

				}

				cout << "Sipariş Vermek İçin e/E tuslayın \n"; cin >> siparis;
				if (siparis == 'e' || siparis == 'E')
				{
					ofstream siparissekle;
					siparissekle.open("siparis.txt", ios::app);
					ofstream siparisurun;
					siparisurun.open("siparisurun.txt", ios::app);
					ifstream urunoku;
					urunoku.open("urun.txt");
					cout << "Sipariş Vermek İstediğiniz Ürünün Ürün Kodunu Giriniz \n"; cin >> kontrolurunkod;//kullanıcı ürün seçer
	
					while (urunoku >> urunKodu >> urunAdi >> teminSuresi >> uretici >> uretimTarihi >> genelFiyat >> ozelFiyat >> kdv >> stokAdedi)
					{
						if (kontrolurunkod == urunKodu)
						{
							kontrol2 = 1;
							cout << "Kaç Adet İstiyorsunuz: "; cin >> adet;
							if (adet > stokAdedi)
							{
								SetConsoleTextAttribute(hConsole, 12);
								cout << "Stok Mevcut Değil \n";
								SetConsoleTextAttribute(hConsole, 15);

							}
							else
							{
								firmaNo = kontrolfirmano;
								cout << "Sipariş Kodu: "; cin >> siparisKodu;
								cout << "Siparis Tarihi: "; cin >> siparisTarihi;
								cout << "Sipariş Alan: "; cin >> siparisAlan;
								cout << "Sipariş Tutarı: " << adet * genelFiyat << endl;
								siparisTutar = adet * genelFiyat;
								siparisdosyasi = "siparisurun.txt";
								siparissekle << siparisKodu << " " << firmaNo << " " << siparisTarihi << " " << siparisTutar << " " << siparisAlan<<" "<< siparisdosyasi << "\n";
								siparisurun << siparisKodu << " " << urunKodu << " " << adet << "\n";
								SetConsoleTextAttribute(hConsole, 12);
								cout << "Sipariş Oluşturuldu \n";
								SetConsoleTextAttribute(hConsole, 15);
							}
							
						}
					}
					if (kontrol2 == 0)
					{
						SetConsoleTextAttribute(hConsole, 12);
						cout << "Yanlış Ürün Kodu \n";
						SetConsoleTextAttribute(hConsole, 15);
					}

					siparissekle.close();
					siparisurun.close();
				}

				urunoku.close();
			}
		}		
	}
	if (kontrol==0)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "Müşteri Bulunamadı \n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	musterioku.close();
}

//Siparis Ara Fonksiyonu
void Siparis::siparisAra() {
	kontrol = 0;
	ifstream siparisoku;
	siparisoku.open("siparis.txt");
	cout << "Arama Yapmak İstediğiniz Sipariş Kodu Giriniz \n"; cin >>kontrolsipariskod;

	while (siparisoku >>siparisKodu >>firmaNo >> siparisTarihi >> siparisTutar >> siparisAlan>> siparisdosyasi)
	{

		if (kontrolsipariskod == siparisKodu)
		{
			kontrol = 1;
			cout <<"Sipariş Kodu: "<<siparisKodu << endl << "Firma No: " << firmaNo << endl << "Sipariş Tarihi: " << siparisTarihi << endl
				<< "Siparis Tutarı: " << siparisTutar << endl << "Siparis Alan: " << siparisAlan << endl
				<<"Sipariş Dosyası: "<<siparisdosyasi<<endl;
			
		}
	}
	if (kontrol==0)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "SİPARİŞ BULUNAMADI \n";
		SetConsoleTextAttribute(hConsole, 15);
	}

	siparisoku.close();
}

//Siparis Sil Fonksiyonu
void Siparis::siparisSil() {
	ifstream siparisoku;
	siparisoku.open("siparis.txt");
	ifstream urunsiparisoku;
	urunsiparisoku.open("siparisurun.txt");
	ofstream duzeltsiparis;
	duzeltsiparis.open("gecici.txt", ios::app);
	ofstream duzeltsiprs;
	duzeltsiprs.open("gecici2.txt",ios::app);
	cout << "Silmek İstediğiniz Sipariş Kodu Giriniz: \n"; cin >> kontrolsipariskod;
	//siparis.txt silinmek istenen siparis koduna esitse gecici dosyaya yazilmaz digerleri gecici dosyaya eklenir
	while (siparisoku >> siparisKodu >> firmaNo >> siparisTarihi >> siparisTutar >> siparisAlan>> siparisdosyasi)
	{
		if (kontrolsipariskod == siparisKodu)
		{
			kontrol = 1;
			cout << "Siparis Kod: " << siparisKodu << endl << "Firma No: " << firmaNo << endl << "Sipariş Tarihi: " << siparisTarihi << endl
				<< "Siparis Tutarı: " << siparisTutar << endl << "Siparis Alan: " << siparisAlan << endl << "Siparis Dosyası: " <<
				siparisdosyasi << endl<< "********************" << endl;

			SetConsoleTextAttribute(hConsole, 12);
			cout << "SİLİNDİ \n";
			SetConsoleTextAttribute(hConsole, 15);	
		}
		else
		{
			duzeltsiparis << siparisKodu <<" " << firmaNo << " " << siparisTarihi << " " << siparisTutar << " " << siparisAlan <<" "<<siparisdosyasi << "\n";
			
		}

	}
	//urunsiparis dosyasina ayni islem yapilir
	while (urunsiparisoku>>siparisKodu>>urunKodu>>adet)
	{
		if (kontrolsipariskod == siparisKodu)
		{

			
		}
		else
		{
			duzeltsiprs << siparisKodu << " " << urunKodu << " " << adet << "\n";

		}
		
	}
	
	if (kontrol == 0)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "SİPARİŞ BULUNAMADI \n";
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	siparisoku.close();
	duzeltsiparis.close();
	duzeltsiprs.close();
	urunsiparisoku.close();
	duzeltsiprs.close();
	remove("siparisurun.txt");
	rename("gecici2.txt", "siparisurun.txt");
	remove("siparis.txt");
	rename("gecici.txt", "siparis.txt");
}

//Siparis Duzelt
void Siparis::siparisDuzelt() {
	kontrol = 0;
	kontrol2 = 0;
	ifstream siparisoku;
	siparisoku.open("siparis.txt");
	ifstream urunsiparisoku;
	urunsiparisoku.open("siparisurun.txt");
	ofstream duzeltsiparis;
	duzeltsiparis.open("gecici.txt", ios::app);
	ofstream duzeltsiprs;
	duzeltsiprs.open("gecici2.txt", ios::app);
	cout << "Düzenlemek İstediğiniz Sipariş Kodu Giriniz \n"; cin >> kontrolsipariskod;
	while (siparisoku >> siparisKodu >> firmaNo >> siparisTarihi >> siparisTutar >> siparisAlan>> siparisdosyasi)
	{
		if (kontrolsipariskod == siparisKodu)
		{
			kontrol = 1;
			ifstream musterioku;
			musterioku.open("cari.txt");
			while (musterioku >> kontrolfirmano >> firmaAdi >> firmaTelefon >> firmaSorumlusu >> firmaAdres >> kategori)
			{
				if (firmaNo==kontrolfirmano)
				{
					if (kategori == '1')
					{
						ifstream urunoku;
						urunoku.open("urun.txt");

						while (urunoku >> urunKodu >> urunAdi >> teminSuresi >> uretici >> uretimTarihi >> genelFiyat >> ozelFiyat >> kdv >> stokAdedi)
						{
							cout << "Ürün Kodu: " << urunKodu << endl << "Ürün Adı: " << urunAdi << endl
								<< "Temin Süresi: " << teminSuresi << endl << "Ürün Üretici: " << uretici << endl << "Üretim Tarihi: " << uretimTarihi
								<< endl << "Fiyat: " << ozelFiyat << endl
								<< "KDV Oranı: " << kdv << endl << "Stok Adedi: " << stokAdedi << endl;
							SetConsoleTextAttribute(hConsole, 12);
							cout << "******************************" << endl;
							SetConsoleTextAttribute(hConsole, 15);
						}

						cout << "Sipariş Vermek İçin e/E Tuşlayın \n"; cin >> siparis;
						if (siparis == 'e' || siparis == 'E')
						{
						
							ifstream urunoku;
							urunoku.open("urun.txt");
							cout << "Sipariş Vermek İstediğiniz Ürünün Ürün Kodunu Giriniz \n"; cin >> urunkodu1; 						
							while (urunoku >> urunKodu >> urunAdi >> teminSuresi >> uretici >> uretimTarihi >> genelFiyat >> ozelFiyat >> kdv >> stokAdedi)
							{
								if (urunkodu1 == urunKodu)
								{

									kontrol2 = 1;
									cout << "Kaç Adet İstiyorsunuz: "; cin >> adet1;
									if (adet1 > stokAdedi)
									{
										SetConsoleTextAttribute(hConsole, 12);
										cout << "Stok Mevcut Değil \n";
										SetConsoleTextAttribute(hConsole, 15);

									}
									else
									{
										cout << "Sipariş Kodu: "; cin >> sipariskodu1;
										firmaNo = kontrolfirmano;
										cout << "Siparis Tarihi: "; cin >> siparisTarihi;
										cout << "Sipariş Alan: "; cin >> siparisAlan;
										cout << "Sipariş Tutarı: " << adet1 * ozelFiyat << endl;
										siparisTutar = adet1 * ozelFiyat;
										siparisdosyasi = "siparisurun.txt";
										//siparis gecici dosyaya eklenir

										duzeltsiparis << sipariskodu1 << " " << firmaNo << " " << siparisTarihi << " " << siparisTutar << " " << siparisAlan<<" " << siparisdosyasi << "\n";

										SetConsoleTextAttribute(hConsole, 12);
										cout << "Sipariş Oluşturuldu \n";
										SetConsoleTextAttribute(hConsole, 15);
										
									}

								}

							}
							if (kontrol2 == 0)
							{
								SetConsoleTextAttribute(hConsole, 12);
								cout << "Yanlış Ürün Kodu \n";
								SetConsoleTextAttribute(hConsole, 15);
							}

						}

						urunoku.close();

					}

					if (kategori == '0')  // müşteri genel/özel mi bakılır (genel musteri)
					{

						ifstream urunoku;
						urunoku.open("urun.txt");
						while (urunoku >> urunKodu >> urunAdi >> teminSuresi >> uretici >> uretimTarihi >> genelFiyat >> ozelFiyat >> kdv >> stokAdedi)
						{
							cout << "Ürün Kodu: " << urunKodu << endl << "Ürün Adı: " << urunAdi << endl
								<< "Temin Süresi: " << teminSuresi << endl << "Ürün Üretici: " << uretici << endl << "Üretim Tarihi: " << uretimTarihi
								<< endl << "Fiyat: " << genelFiyat << endl
								<< "KDV Oranı: " << kdv << endl << "Stok Adedi: " << stokAdedi << endl;
							SetConsoleTextAttribute(hConsole, 12);
							cout << "******************************" << endl;
							SetConsoleTextAttribute(hConsole, 15);

						}

						cout << "Sipariş Vermek İçin e/E tuslayın \n"; cin >> siparis;
						if (siparis == 'e' || siparis == 'E')
						{
							ifstream urunoku;
							urunoku.open("urun.txt");
							cout << "Sipariş Vermek İstediğiniz Ürünün Ürün Kodunu Giriniz \n"; cin >> urunkodu1;//kullanıcı ürün seçer

							while (urunoku >> urunKodu >> urunAdi >> teminSuresi >> uretici >> uretimTarihi >> genelFiyat >> ozelFiyat >> kdv >> stokAdedi)
							{
								if (urunkodu1 == urunKodu)
								{
									kontrol2 = 1;
									cout << "Kaç Adet İstiyorsunuz: "; cin >> adet1;
									if (adet1 > stokAdedi)
									{
										SetConsoleTextAttribute(hConsole, 12);
										cout << "Stok Mevcut Değil \n";
										SetConsoleTextAttribute(hConsole, 15);

									}
									else
									{
										firmaNo = kontrolfirmano;
										cout << "Sipariş Kodu: "; cin >> sipariskodu1;
										cout << "Siparis Tarihi: "; cin >> siparisTarihi;
										cout << "Sipariş Alan: "; cin >> siparisAlan;
										cout << "Sipariş Tutarı: " << adet1 * genelFiyat << endl;
										siparisTutar = adet1 * genelFiyat;
										siparisdosyasi = "siparisurun.txt";
										duzeltsiparis << sipariskodu1 << " " << firmaNo << " " << siparisTarihi << " " << siparisTutar << " " << siparisAlan <<" "<< siparisdosyasi << "\n";

										SetConsoleTextAttribute(hConsole, 12);
										cout << "Sipariş Oluşturuldu \n";
										SetConsoleTextAttribute(hConsole, 15);
									
									}

								}
							}
							if (kontrol2 == 0)
							{
								SetConsoleTextAttribute(hConsole, 12);
								cout << "Yanlış Ürün Kodu \n";
								SetConsoleTextAttribute(hConsole, 15);
							}


						}

						urunoku.close();
					}
				}
				if (kontrol == 0)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cout << "SİPARİŞ BULUNAMADI \n";
					SetConsoleTextAttribute(hConsole, 15);

				}
			}

			musterioku.close();
		}
		else //degisilmek istenmeyen siparisler direk gecici dosyaya eklenir
		{

			duzeltsiparis << siparisKodu << " " << firmaNo << " " << siparisTarihi << " " << siparisTutar << " " << siparisAlan<<" "<< siparisdosyasi << "\n";

		}

	}
	while (urunsiparisoku >> siparisKodu >> urunKodu >> adet)//urunsiparis dosyasi icin ayni islemler 
	{
		if (kontrolsipariskod == siparisKodu)
		{
			adet = adet1; //bu degiskenler degisecegi icin sipariste aldigimiza esitledik
			urunKodu = urunkodu1;
			siparisKodu = sipariskodu1;
			duzeltsiprs << siparisKodu << " " << urunKodu << " " << adet << "\n";
		}
		else
		{
			duzeltsiprs << siparisKodu << " " << urunKodu << " " << adet << "\n";

		}

	}

	if (kontrol == 0)
	{
		SetConsoleTextAttribute(hConsole, 12);
		cout << "SİPARİŞ BULUNAMADI \n";
		SetConsoleTextAttribute(hConsole, 15);
	}
	siparisoku.close();
	duzeltsiparis.close();
	duzeltsiprs.close();
	urunsiparisoku.close();
	duzeltsiprs.close();
	remove("siparisurun.txt");
	rename("gecici2.txt", "siparisurun.txt");
	remove("siparis.txt");
	rename("gecici.txt", "siparis.txt");

	
	
}

//Siparis Rapor
void Siparis::siparisRapor() {
	ifstream siparisoku;
	siparisoku.open("siparis.txt");
	ifstream urunsiparis;
	urunsiparis.open("siparisurun.txt");
	SetConsoleTextAttribute(hConsole, 12);
	cout << "Sipariş Bilgileri\n";
	cout << "*****************************************\n";
	SetConsoleTextAttribute(hConsole, 15);
	//2dosyada satir satir  okunup icindekileri yazdir 
	while (siparisoku >>siparisKodu >>firmaNo >> siparisTarihi >> siparisTutar >> siparisAlan>> siparisdosyasi)
	{

		cout << "Siparis Kodu: " << siparisKodu << endl << "Firma No: " << firmaNo << endl << "Sipariş Tarihi: " << siparisTarihi << endl << "Sipariş Tutar: " << siparisTutar <<
			endl << "Sipariş Alan: " << siparisAlan << endl<<"Sipariş Dosyasi: "<<siparisdosyasi<<endl;
		SetConsoleTextAttribute(hConsole, 12);
		cout << "*****************************************\n";
		SetConsoleTextAttribute(hConsole, 15);
	
	}
	SetConsoleTextAttribute(hConsole, 12);
	cout << "Sipariş Ürün Bilgileri\n";
	cout << "*****************************************\n";
	SetConsoleTextAttribute(hConsole, 15);
	while (urunsiparis >>siparisKodu >>urunKodu >> adet)
	{
		cout << "Siparis Kodu: " << siparisKodu << endl << "Ürün Kodu: " << urunKodu << endl
			<< "Ürün Adet: " << adet << endl;
		SetConsoleTextAttribute(hConsole, 12);
		cout << "*****************************************\n";
		SetConsoleTextAttribute(hConsole, 15);
		
	}
	siparisoku.close();
	urunsiparis.close();
}



int main()
{
	setlocale(LC_ALL, "Turkish");
	int secim;
	int secim2;
	char devam;
	char cevap;
	Musteriler musteri;
	Urunler urun;
	Siparis siparis;
	do
	{
		do
		{
			SetConsoleTextAttribute(hConsole, 12);
			cout << "***************HOŞGELDİNİZ****************\n";
			SetConsoleTextAttribute(hConsole, 15);
			SetConsoleTextAttribute(hConsole, 11);
			cout << "İŞLEM SEÇİNİZ\n";
			SetConsoleTextAttribute(hConsole, 15);
			cout << "1-Müşteri İşlemleri \n";
			cout << "2-Ürün İşlemleri \n";
			cout << "3-Sipariş İşlemleri \n";
			cout << "4-Exit \n";
			cin >> secim;
		} while (secim != 1 && secim != 2 && secim != 3 && secim != 4);//bu secenekler haricinde girilirse tekrar getir
		system("cls");

		//Müsteri işlemleri
		if (secim == 1)
		{
			do
			{
				cout << "1-Müşteri Ekle \n";
				cout << "2-Müşteri Arama \n";
				cout << "3-Müşteri Düzeltme \n";
				cout << "4-Müşteri Silme \n";
				cin >> secim2;
			} while (secim2 != 1 && secim2 != 2 && secim2 != 3 && secim2 != 4);
			system("cls");
		
			if (secim2 == 1)
			{
				do
				{
					musteri.musteriEkle();
					cout << "Başka Kayıt Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}
			if (secim2==2)
			{
				do
				{
					musteri.musteriAra();
					cout << "Başka Arama Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
			    } while (!(cevap == 'h'));
				
			}
			if (secim2==3)
			{
				do
				{
					musteri.musteriDuzelt();
					cout << "Başka Düzeltme Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}
			if (secim2==4)
			{
				do
				{
					musteri.musteriSil();
					cout << "Başka Silme Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
				
			}

		}
		//ÜRÜN İŞLEMLERİ
		if (secim == 2)
		{

			do
			{
				cout << "1-Ürün Ekle \n";
				cout << "2-Ürün Arama \n";
				cout << "3-Ürün Listele \n";
				cout << "4-Ürün Düzelt \n";
				cout << "5-Ürün Sil \n";
				cin >> secim2;

			} while (secim2 != 1 && secim2 != 2 && secim2 != 3 && secim2 != 4 && secim2 != 5);
			system("cls");
			if (secim2==1)
			{
				do
				{
					urun.urunEkle();
					cout << "Başka Kayıt Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}
			if (secim2 == 2)
			{
				do
				{
					urun.urunAra();
					cout << "Başka Arama Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}
			if (secim2 == 3)
			{
				do
				{
					urun.urunListele();
					cout << "Tekrar Listelemek İstermisiniz e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}
			if (secim2 == 4)
			{
				do
				{
					urun.urunDuzelt();
					cout << "Başka Düzeltme Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}
			if (secim2 == 5)
			{
				do
				{
					urun.urunSil();
					cout << "Başka Silme Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}

		}
		//SİPARİŞ İŞLEMLERİ
		if (secim==3)
		{
			do
			{
				cout << "1-Sipariş Oluştur \n";
				cout << "2-Sipariş Arama \n";
				cout << "3-Sipariş Silme \n";
				cout << "4-Sipariş Düzeltme \n";
				cout << "5-Sipariş Raporlama \n";
				cin >> secim2;

			} while (secim2 != 1 && secim2 != 2 && secim2 != 3 && secim2 != 4 && secim2 != 5);
			system("cls");
			if (secim2==1)
			{
				do
				{
					siparis.siparisOlustur();
					cout << "Başka Sipariş Verecekmisiniz e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}
			if (secim2== 2)
			{
				do
				{
					siparis.siparisAra();
					cout << "Başka Arama Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}
			if (secim2 == 3)
			{
				do
				{
					siparis.siparisSil();
					cout << "Başka Silme Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}
			if (secim2 == 4)
			{
				do
				{
					siparis.siparisDuzelt();
					cout << "Başka Düzeltme Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}
			if (secim2== 5)
			{
				do
				{
					siparis.siparisRapor();
					cout << "Tekrar Raporlama Yapacakmısınız e/h \n"; cin >> cevap;
					system("cls");
				} while (!(cevap == 'h'));
			}
		}
		//ÇIKIŞ
		if (secim==4)
		{
			exit(0);
		}



		
		cout << "Menüye Dönmek İçin E/e Çıkıs İçin h/H tuşlayın \n";
		cin >> devam;
		system("cls");
	} while (devam=='e'||devam=='E');

	//system("cls") ile ekrani temizlemek icin kullandik
	return 0;
}


