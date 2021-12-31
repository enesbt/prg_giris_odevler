
#include <iostream>   //input output fonksiyonlari
#include<time.h>      //random kutuphane
#include<Windows.h>   //renk kutuphanesi

using namespace std;
#define max 50  //dizi eleman sayisi (sabit)

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //renk komutu

//kutulari olusturmak icin hazir kodlar
char	DUZCIZGI = 205;
char	SOLUSTKOSE = 201;
char	SAGUSTKOSE = 187;
char	DIKEYCIZGI = 186;
char	ASAGIAYRAC = 203;
char	SOLALTKOSE = 200;
char	SAGALTKOSE = 188;
char	YUKARIAYRAC = 202;

class Karakter {
public:
    Karakter(); //karakter sinifinin kurucu fonksiyonu
    char harf;
    int renk;


};
class Katar {
public:
    Katar(); //katar sinifinin kurucu fonksiyonu
    //fonksiyonlarin prototip tanimlamasi
    void karakter_ekle();
    void karakter_cikar();
    void yazdir();
    int getKaraktersayisi();
private:
    int karakter_sayisi;
    Karakter karakterler[max];

};
Karakter:: Karakter() {   //karakter sinifinin yapici fonksiyonu ilk deger atamasi icin
    harf = NULL;
    renk = 0;
}
int Katar::getKaraktersayisi() {   //main fonksiyonda private olan karakter sayisina ulasmak icin
    return karakter_sayisi;
}

Katar::Katar() {         //Katar sinifinin yapici fonksiyonu
    karakter_sayisi = 0;
}
void Katar::karakter_ekle(){  //karakterler dizisinin karakter sinifindan aldigi elemanlarin degerleri 
               
    if (karakter_sayisi >= max)                  //karakter sayisi sabit max degerinden fazlaysa ekleme yapmamasi icin      
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Ekleme Yapilamaz \n";
        SetConsoleTextAttribute(hConsole, 15);
    }
    else
    {
        karakterler[karakter_sayisi].renk = (rand() % 6 + 9);    //9-14 arasi rastgele renk secimi icin
        karakterler[karakter_sayisi].harf = (char)(rand() % 26) + 65; //rastgele harf secimi
        karakter_sayisi++;    //her cagrildiginda karakter sayisi 1 artsin

    }
   
  
}
void Katar::karakter_cikar() {
    if (karakter_sayisi<=0)                 
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Cikarma Yapilamaz \n";
        SetConsoleTextAttribute(hConsole, 15);
    }
    
    else
    {
        
        karakter_sayisi--;
    }
 
    
}
void Katar::yazdir() {
   
        //1.satir olusmasi icin
        cout << SOLUSTKOSE;                             
        for (int i = 0; i < karakter_sayisi-1; i++) 
        {
            cout << DUZCIZGI << ASAGIAYRAC;
        }
        cout << DUZCIZGI;

        cout << SAGUSTKOSE;
        cout << endl; //1.satir bitti
       

       //2.satir
        for (int i = 0; i < karakter_sayisi; i++)
        {
            cout << DIKEYCIZGI;
            SetConsoleTextAttribute(hConsole, karakterler[i].renk); //random renk konsola geldi
            cout << karakterler[i].harf; //harf renkli cikti verir
            SetConsoleTextAttribute(hConsole, 15); //konsolu eski haline ceviriyoruz

        }
        
        cout << DIKEYCIZGI;
        cout << endl;

        //3.satir
        cout << SOLALTKOSE;
        for (int i = 0; i < karakter_sayisi-1; i++)
        {
            cout << DUZCIZGI << YUKARIAYRAC;
        }
        cout << DUZCIZGI;

        cout << SAGALTKOSE;
        cout << endl;
}


int main()
{
    srand(time(0)); 
    int secim;
    Katar katar; //Katar sinifindan katar adli nesne olusturduk
    
    while (true) //surekli ekleme cikarma yapmamiz icin dongu
    {
        do        //menu
        {
            cout << "Islem Seciniz \n";
            cout << "1-Karakter Ekle \n";
            cout << "2-Karakter Cikar \n";
            cout << "3-Cikis \n";
            cin >> secim;

        } while (secim != 1 && secim != 2 && secim != 3); //3secim harici secim geldiginde tekrar menuyu goster
        if (secim==1)
        {
            
            cout << "Onceki Durum - Eleman Sayisi =" << katar.getKaraktersayisi() << endl;//get fonksiyonu ile karakter sayisini cagirdik
            katar.yazdir(); //ekleme yapmadan onceki durumu gostermek icin 
            katar.karakter_ekle(); 
            cout << "Sonraki Durum -Eleman Sayisi =" << katar.getKaraktersayisi() << endl;
            katar.yazdir();
            cout << endl;
        }
        if (secim==2)
        {
   
            cout << "Onceki Durum - Eleman Sayisi =" << katar.getKaraktersayisi() << endl;
            katar.yazdir();
            katar.karakter_cikar();
            cout << "Sonraki Durum -Eleman Sayisi =" << katar.getKaraktersayisi() << endl;
            katar.yazdir();
            cout << endl;
         
        }
        if (secim==3)
        {
            exit(0); //cikis fonksiyonu
        }
    }
   
    
}


