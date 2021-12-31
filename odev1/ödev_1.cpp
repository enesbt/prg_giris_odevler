
#include <iostream> //standart giriş çıkış fonksiyonları için 
#include<string> //string ifadelerin kullanımı için ekledik
#include<cstring> //strlen() fonksiyonu için
#include<locale.h>// diller ve karakter setleri kütüphanesi
#include<time.h>//rastgele değer almak için 
#include<Windows.h>//konsolu renklendirmek için ekledik
using namespace std;
int main()
{
    setlocale(LC_ALL, "Turkish"); //türkçe karakter kullanımı 
    system("color f4");//konsolu renkledirdik
    srand(time(0)); //sürekli rastgele değer almak için 
    char devam; //programı tekrar kullanmak için 
    bool buldum=false;//döngüden çıkıp buluğumuz şehri 1 kere yazdırmak bulmadıysak bulamadık yazdırmak için
    const int max = 81; //dizimizin uzunluğunu belirttik ve bunu değişmez olarak tanımladık
    const int deger = 15; //dizimizin elamanlarının en fazla kaç karakter alabileceğini belirttik ve bunu değişmez olarak tanımladık
    char sehirler[max][deger] = { 
        "adıyaman","afyonkarahisar","ağrı","amasya","ankara","adana","antalya","artvin","aydın","balıkesir","bilecik",
        "bingöl","bitlis","bolu","burdur","bursa","çanakkale","çankırı","çorum","denizli","diyarbakır","edirne","elazığ","erzincan","erzurum",
        "eskişehir","gaziantep","giresun","gümüşhane","hakkari","hatay","ısparta","mersin","istanbul","izmir","kars","kastamonu","kayseri",
        "kırklareli","kırşehir","kocaeli","konya","kütahya","malatya","manisa","kahramanmaraş","mardin","muğla","van","nevşehir","niğde",
        "ordu","rize","sakarya","samsun","siirt","sinop","sivas","tekirdağ","tokat","trabzon","tunceli","şanlıurfa","uşak","muş","yozgat",
        "zonguldak","aksaray","bayburt","karaman","kırıkkale","batman","şırnak","bartın","ardahan","ığdır","yalova","karabük","kilis",
        "osmaniye","düzce" };  //şehirlerin olduğu diziyi tanımladık
    int enkucuk = 999, enbuyuk = 0; //en kucuk ve en buyuk karakterli ili karşılaştrma yaparak bulmak için
    string ekucuk, ebuyuk; //bulduğumuz en küçük ve en büyük ili bu degere aktarmak için
    char ucsehirler[3], dortlusehirler[4], bessehirler[5], altısehirler[6],//şehirlerden aldığımız karakterleri yeni dizlere aktarmak için
            yedisehirler[7], sekizsehirler[8], dokuzsehirler[9], onsehirler[10],
            onbirsehirler[11], onikisehirler[12], onucsehirler[13], ondortsehirler[14];
    string uclu = "", dortlu = "", besli = "", altılı = "", yedili = "", sekizli = "", 
    dokuzlu = "", onlu = "",onbirli ="",onikili ="",onuclu="",ondortlu=""; //yeni diziye aldığımız karakterleri birleştirmek için 
    for (int i = 0; i < max; i++) //sehirler dizisinin elaman sayısı kadar dönecek tüm elemanların uzunluğunu bulup karşılaştıracak
    {
        if (strlen(sehirler[i]) < enkucuk) //sehirlerin elemanlarının uzunluğuna  bakıp en kucukle karşılaştırır
        {
            enkucuk = strlen(sehirler[i]);   //int olan enkucuk karakter sayısını tutar 
            ekucuk = sehirler[i]; // ekucuk ise en az karaktere sahip elemanın ismini tutar
        }

    }
    cout << "KARAKTER UZUNLUGU EN AZ OLAN IL :\n" << ekucuk << endl;

    for (int i = 0; i < max; i++)//sehirler dizisinin eleman sayısı kadar dönecek tüm elemanların uzunluğunu bulup karşılaştıracak
    {
        if (strlen(sehirler[i]) > enbuyuk)//sehirlerin elemanlarının uzunluğuna bakıp en büyükle karşılaştırcak 
        {
            enbuyuk = strlen(sehirler[i]);
            ebuyuk = sehirler[i];
        }
    }
    cout << "KARAKTER UZUNLUGU EN COK OLAN IL :\n" << ebuyuk << endl;

    do{
            for (int i = 0; i < 100000; i++) //100000 kere rastgele 3tane il seçip bu illerin aynı indisleriyle il ismi oluşup oluşmadığını kontrol eder
            {
                    for (int i = 0; i < enkucuk; i++)//en küçük il sayısı kadar rastgele il oluşturacak bu illerin aynı indislerini alıp yeni bir kelime oluşturacak
                    {
                        uclu = "";
                        int random = rand() % 81;
                        char karakter = sehirler[random][i]; //random seçilen şehirin i. indisini karaktere aktaracak
                        ucsehirler[i] = karakter; //aldığımız karakteri yeni diziye aktarır
                        uclu += ucsehirler[0]; //karakterleri birleştirip yeni kelime oluşturur
                        uclu += ucsehirler[1];
                        uclu += ucsehirler[2];
                    }
                    for (int i = 0; i < max; i++) //rastgele seçilen sehirlerden alığımız karakterlerin sehirlerin elemanı olup olmadığına bakmak için
                    {
                        if (uclu == sehirler[i]) {//oluşan kelimenin sehirler dizisinde olup olmadığı kontrol edilir
                            cout << "3HARFLI IL ISMI OLUSANLAR \n";
                            cout << "3HARFLI IL BULUNDU: \n" << uclu << endl;
                            buldum = true;  //sehir bulduysa true dönecek
                            break;
                        }
                                        
                    }
                if (buldum == true)   //sehir bulduysa 100.000 döngüden çıkmak için 
                    break;
            }
                    if (buldum == false) //bulmadıysa false dönecek
                         cout << "3HARFLI IL BULUNAMADI" << endl;
                    else
                    {
                          buldum = false; //diğer döngülerde false ile başlaması için
                    }
   
            //4harfli illerde aynı işlemi yapmaya geçtik
            for (int i = 0; i < 100000; i++) //100000 kere rastgele 4 şehir oluşturup sehirleri dizisinde olup olmadığına bakar  
            {
                for (int i = 0; i < enkucuk + 1; i++)
                {
                    dortlu = "";
                    int random = rand() % 81;
                    char karakter = sehirler[random][i];
                    dortlusehirler[i] = karakter;
                    dortlu += dortlusehirler[0];
                    dortlu += dortlusehirler[1];
                    dortlu += dortlusehirler[2];
                    dortlu += dortlusehirler[3];
                }
                for (int i = 0; i < max; i++)
                {
                    if (dortlu == sehirler[i]) {
                        cout << "4HARFLI IL ISMI OLUSANLAR \n";
                        cout << "4HARFLI IL BULUNDU: \n" << dortlu << endl;
                        buldum = true;  
                        break;
                    }
                }
                if (buldum == true)   
                    break;
            }
            if (buldum == false) 
                cout << "4HARFLI IL BULUNAMADI" << endl;
            else
            {
                buldum = false; 
            }

      //5harfli illere geçtik
            for (int i = 0; i < 100000; i++)
            {
                    for (int i = 0; i < enkucuk + 2; i++)
                    {
                        besli = "";
                        int random = rand() % 81;
                        char karakter = sehirler[random][0];
                        bessehirler[i] = karakter;
                        besli += bessehirler[0];
                        besli += bessehirler[1]; 
                        besli += bessehirler[2];
                        besli += bessehirler[3];
                        besli += bessehirler[4];
                    }
                    for (int i = 0; i < max; i++)
                    {
                        if (besli == sehirler[i]) {
                            cout << "5HARFLI IL ISMI OLUSANLAR \n";
                            cout << "5HARFLI IL BULUNDU:\n" << besli << endl;
                            buldum = true;
                            break;
                        }
                     }
                    if (buldum == true)
                        break;
            }
            if (buldum == false)
                cout << "5HARFLI IL BULUNAMADI" << endl;
            else
            {
                buldum = false;
            }
            //6harfli illere geçtik

            for (int i = 0; i < 100000; i++)
            {
                    for (int i = 0; i < enkucuk + 3; i++)
                    {
                    altılı = "";
                    int random = rand() % 81;
                    char karakter = sehirler[random][i];
                    altısehirler[i] = karakter;
                    altılı += altısehirler[0];
                    altılı += altısehirler[1];
                    altılı += altısehirler[2];
                    altılı += altısehirler[3];
                    altılı += altısehirler[4];
                    altılı += altısehirler[5];
                    }
                    for (int i = 0; i < max; i++)
                    {
                        if (altılı == sehirler[i]) {
                            cout << "6HARFLI IL ISMI OLUSANLAR \n";
                            cout << "6HARFLI IL BULUNDU:\n" << altılı << endl;
                            buldum = true;
                            break;
                        }
                    }
                    if (buldum == true)
                        break;
            }
            if (buldum == false)
                cout << "6HARFLI IL BULUNAMADI" << endl;
            else
            {
                buldum = false;
            }

            //7harfli illere geçtik
            for (int i = 0; i < 100000; i++)
            {
                    for (int i = 0; i < enkucuk + 4; i++)
                    {
                        yedili = "";
                        int random = rand() % 81;
                        char karakter = sehirler[random][i];
                        yedisehirler[i] = karakter;
                        yedili += yedisehirler[0];
                        yedili += yedisehirler[1];
                        yedili += yedisehirler[2];
                        yedili += yedisehirler[3];
                        yedili += yedisehirler[4];
                        yedili += yedisehirler[5];
                        yedili += yedisehirler[6];
                    }
                    for (int i = 0; i < max; i++)
                    {
                        if (yedili == sehirler[i]) {
                            cout << "7HARFLI IL ISMI OLUSANLAR \n";
                            cout << "7HARFLI IL BULUNDU:\n" << yedili << endl;
                            buldum = true;
                            break;
                        }
                    }
                    if (buldum == true)
                        break;
            }
            if (buldum == false)
                cout << "7HARFLI IL BULUNAMADI" << endl;
            else
            {
                buldum = false;
            }

            
           //8harfli illere geçtik
            for (int i = 0; i < 100000; i++)
            {
                    for (int i = 0; i < enkucuk + 5; i++)
                    {
                        sekizli = "";
                        int random = rand() % 81;
                        char karakter = sehirler[random][i];
                        sekizsehirler[i] = karakter;
                        sekizli += sekizsehirler[0];
                        sekizli += sekizsehirler[1];
                        sekizli += sekizsehirler[2];
                        sekizli += sekizsehirler[3];
                        sekizli += sekizsehirler[4];
                        sekizli += sekizsehirler[5];
                        sekizli += sekizsehirler[6];
                        sekizli += sekizsehirler[7];
                    }
                    for (int i = 0; i < max; i++)
                    {
                        if (sekizli == sehirler[i]) {
                            cout << "8HARFLI IL ISMI OLUSANLAR \n";
                            cout << "8HARFLI IL BULUNDU:\n" << sekizli << endl;
                            buldum = true;
                            break;
                        }
                    }
                    if (buldum == true)
                        break;
            }
            if (buldum == false)
                cout << "8HARFLI IL BULUNAMADI" << endl;
            else
            {
                buldum = false;
            }


          //9 harflere geçtik
            for (int i = 0; i < 100000; i++)
            {
                    for (int i = 0; i < enkucuk + 6; i++)
                    {
                        dokuzlu = "";
                        int random = rand() % 81;
                        char karakter = sehirler[random][i];
                        dokuzsehirler[i] = karakter;
                        dokuzlu += dokuzsehirler[0];
                        dokuzlu += dokuzsehirler[1];
                        dokuzlu += dokuzsehirler[2];
                        dokuzlu += dokuzsehirler[3];
                        dokuzlu += dokuzsehirler[4];
                        dokuzlu += dokuzsehirler[5];
                        dokuzlu += dokuzsehirler[6];
                        dokuzlu += dokuzsehirler[7];
                        dokuzlu += dokuzsehirler[8];
                    }
                    for (int i = 0; i < max; i++)
                    {
                        if (dokuzlu == sehirler[i]) {
                            cout << "9HARFLI IL ISMI OLUSANLAR \n";
                            cout << "9HARFLI IL BULUNDU:\n" << dokuzlu << endl;
                            buldum = true;
                            break;
                        }
                    }
                    if (buldum == true)
                        break;
            }
            if (buldum == false)
                cout << "9HARFLI IL BULUNAMADI" << endl;
            else
            {
                buldum = false;
            }

            //10harflere geçtik
            for (int i = 0; i < 100000; i++)
            {
                for (int i = 0; i < enkucuk + 7; i++)
                {
                    onlu = "";
                    int random = rand() % 81;
                    char karakter = sehirler[random][i];
                    onsehirler[i] = karakter;
                    onlu += onsehirler[0];
                    onlu += onsehirler[1];
                    onlu += onsehirler[2];
                    onlu += onsehirler[3];
                    onlu += onsehirler[4];
                    onlu += onsehirler[5];
                    onlu += onsehirler[6];
                    onlu += onsehirler[7];
                    onlu += onsehirler[8];
                    onlu += onsehirler[9];
                }
                for (int i = 0; i < max; i++)
                {
                    if (onlu == sehirler[i]) {
                        cout << "10HARFLI IL ISMI OLUSANLAR \n";
                        cout << "10HARFLI IL BULUNDU:\n" << onlu << endl;
                        buldum = true;
                        break;
                    }
                }
                if (buldum == true)
                    break;
            }
            if (buldum == false)
                cout << "10HARFLI IL BULUNAMADI" << endl;
            else
            {
                buldum = false;
            }

            //11harflere geçtik
            for (int i = 0; i < 100000; i++)
            {
                for (int i = 0; i < enkucuk + 8; i++)
                {
                    onbirli = "";
                    int random = rand() % 81;
                    char karakter = sehirler[random][i];
                    onbirsehirler[i] = karakter;
                    onbirli += onbirsehirler[0];
                    onbirli += onbirsehirler[1];
                    onbirli += onbirsehirler[2];
                    onbirli += onbirsehirler[3];
                    onbirli += onbirsehirler[4];
                    onbirli += onbirsehirler[5];
                    onbirli += onbirsehirler[6];
                    onbirli += onbirsehirler[7];
                    onbirli += onbirsehirler[8];
                    onbirli += onbirsehirler[9];
                    onbirli += onbirsehirler[10];
                }
                for (int i = 0; i < max; i++)
                {
                    if (onbirli == sehirler[i]) {
                        cout << "11HARFLI IL ISMI OLUSANLAR \n";
                        cout << "11HARFLI IL BULUNDU:\n" << onbirli << endl;
                        buldum = true;
                        break;
                    }
                }
                if (buldum == true)
                    break;
            }
            if (buldum == false)
                cout << "11HARFLI IL BULUNAMADI" << endl;
            else
            {
                buldum = false;
            }


            //12 harflere geçtik
            for (int i = 0; i < 100000; i++)
            {
                for (int i = 0; i < enkucuk + 9; i++)
                {
                    onikili = "";
                    int random = rand() % 81;
                    char karakter = sehirler[random][i];
                    onikisehirler[i] = karakter;
                    onikili += onikisehirler[0];
                    onikili += onikisehirler[1];
                    onikili += onikisehirler[2];
                    onikili += onikisehirler[3];
                    onikili += onikisehirler[4];
                    onikili += onikisehirler[5];
                    onikili += onikisehirler[6];
                    onikili += onikisehirler[7];
                    onikili += onikisehirler[8];
                    onikili += onikisehirler[9];
                    onikili += onikisehirler[10];
                    onikili += onikisehirler[11];
                }
                for (int i = 0; i < max; i++)
                {
                    if (onikili == sehirler[i]) {
                        cout << "12HARFLI IL ISMI OLUSANLAR \n";
                        cout << "12HARFLI IL BULUNDU:\n" << onikili << endl;
                        buldum = true;
                        break;
                    }
                }
                if (buldum == true)
                    break;
            }
            if (buldum == false)
                cout << "12HARFLI IL BULUNAMADI" << endl;
            else
            {
                buldum = false;
            }


           //13 harflere geçtik
            for (int i = 0; i < 100000; i++)
            {
                for (int i = 0; i < enkucuk+10; i++)
                {
                    onuclu = "";
                    int random = rand() % 81;
                    char karakter = sehirler[random][i];
                    onucsehirler[i] = karakter;
                    onuclu += onucsehirler[0];
                    onuclu += onucsehirler[1];
                    onuclu += onucsehirler[2];
                    onuclu += onucsehirler[3];
                    onuclu += onucsehirler[4];
                    onuclu += onucsehirler[5];
                    onuclu += onucsehirler[6];
                    onuclu += onucsehirler[7];
                    onuclu += onucsehirler[8];
                    onuclu += onucsehirler[9];
                    onuclu += onucsehirler[10];
                    onuclu += onucsehirler[11];
                    onuclu += onucsehirler[12];
                }
                for (int i = 0; i < max; i++)
                {
                    if (onuclu == sehirler[i]) {
                        cout << "13HARFLI IL ISMI OLUSANLAR\n";
                        cout << "13HARFLI IL BULUNDU:\n" << onuclu << endl;
                        buldum = true;
                        break;
                    }
                }
                if (buldum == true)
                    break;
            }
            if (buldum == false)
                cout << "13HARFLI IL BULUNAMADI" << endl;
            else
            {
                buldum = false;
            }


            //14harflere geçitk
            for (int i = 0; i < 100000; i++)
            {
                for (int i = 0; i < enkucuk + 10; i++)
                {
                    ondortlu = "";
                    int random = rand() % 81;
                    char karakter = sehirler[random][i];
                    ondortsehirler[i] = karakter;
                    ondortlu += ondortsehirler[0];
                    ondortlu += ondortsehirler[1];
                    ondortlu += ondortsehirler[2];
                    ondortlu += ondortsehirler[3];
                    ondortlu += ondortsehirler[4];
                    ondortlu += ondortsehirler[5];
                    ondortlu += ondortsehirler[6];
                    ondortlu += ondortsehirler[7];
                    ondortlu += ondortsehirler[8];
                    ondortlu += ondortsehirler[9];
                    ondortlu += ondortsehirler[10];
                    ondortlu += ondortsehirler[11];
                    ondortlu += ondortsehirler[12];
                    ondortlu += ondortsehirler[13];
                }
                for (int i = 0; i < max; i++)
                {
                    if (onuclu == sehirler[i]) {
                        cout << "14HARFLI IL ISMI OLUSANLAR\n";
                        cout << "14HARFLI IL BULUNDU:\n" << onuclu << endl;
                        buldum = true;
                        break;
                    }
                }
                if (buldum == true)
                    break;
            }
            if (buldum == false)
                cout << "14HARFLI IL BULUNAMADI" << endl;
          


                        do{            
                                    cout << "Programi Tekrar Calistirmak icin 'E' ya da 'e' tuslayin  Cikis icin 'h' veya'H' tuslayin \n" ;
                                    cin >> devam;
                             } while(! (devam=='e' ||devam=='E' || devam=='h' || devam=='H'));

             //Kullanıcının programı tekrar çalıştırması veya programdan çıkması için
     }while (devam=='e' || devam=='E');
   
     return 0;  //program hatasız sonlandırıldı
}










