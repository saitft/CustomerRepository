/*
 Ahmet Sait Tanrıöver
 2212729008
 Bilgisayar Mühendisliği 1. Sınıf
 Tüpçü Müşteri Takip Otomasyonu
 */

#include <iomanip>
#include <cstring>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
struct Musteri{
    char ad[75];
    char soyad[75];
    char tel_no[11];
    char e_posta[75];
    char mahalle[75];
    char daireno[10];
    char tup_tipi[15];
    char odeme_tipi[75];
};
void MusteriEkle();
void MusteriListeleme();
void MusteriArama();
void MusteriSil();
void MusteriDuzenle();
int main(){
    char anamenu;
    do{
        system("cls");
        cout << endl << endl  << endl << endl << endl << endl;
        cout << "                                 |||-----------------------------------------------|||                    " << endl;
        cout << "                                 ||| -------------Hosgeldiniz--------------------- |||                    " << endl;
        cout << "                                 |||  ------------Secim Yapiniz------------------  |||                    " << endl;
        cout << "                                 |||   ---------1 - Musteri Ekleme-------------    |||                    " << endl;
        cout << "                                 |||    --------2 - Musteri Listeleme---------     |||                    " << endl;
        cout << "                                 |||   ---------3 - Musteri Arama--------------    |||                    " << endl;
        cout << "                                 |||  ----------4 - Musteri Silme----------------  |||                    " << endl;
        cout << "                                 ||| -----------5 - Musteri Duzenleme------------- |||                    " << endl;
        cout << "                                 |||-----------------------------------------------|||                    " << endl;
        char secim;
        cin>> secim;
        switch(secim)
        {
            case '1' :
            {
                MusteriEkle();
                break;
            }
            case '2' :
            {
                MusteriListeleme();
                break;
            }
            case '3' :
            {
                MusteriArama()	;
                break;
            }
            case '4' :
            {
                MusteriSil();
                break;
            }
            case '5' :
            {
                MusteriDuzenle();
                break;
            }
        }
        cout << "Ana menu icin '0' tusuna basin cikmak, icin 'herhangi bir' tusuna basin" << endl;
        anamenu=getche();
    }while(anamenu=='0');
    return 0;
}
Musteri m;
void MusteriEkle()
{
    ofstream yaz("Musteri.dat",ios::binary |ios::app);
    char secim;
    int adet=0;
    do{
        cout <<"-------------------------------------------------------"<<endl;
        cout << "Musteri Ad Giriniz                           :" << endl;
        cin>>m.ad;
        cout <<"------------------------------------------------"<<endl;
        cout << "Musteri Soyad Giriniz                        :" << endl;
        cin>>m.soyad;
        cout <<"------------------------------------------------"<<endl;
        cout << "Musteri e-posta Giriniz                      :" << endl;
        cin>> m.e_posta;
        cout <<"------------------------------------------------"<<endl;
        cout << "Musteri Telefon numarasi Giriniz             :" << endl;
        cin>> m.tel_no;
        cout <<"------------------------------------------------"<<endl;
        cout << "Musteri Mahalle Giriniz                      :" << endl;
        cin>>m.mahalle;
        cout <<"------------------------------------------------"<<endl;
        cout << "Musteri Daire no Giriniz                      :" << endl;
        cin>>m.daireno;
        cout <<"------------------------------------------------"<<endl;
        cout << "Musteri Odeme tipi Giriniz                   :" << endl;
        cin>> m.odeme_tipi;
        cout <<"------------------------------------------------"<<endl;
        cout << "Musteri Tup tipi Giriniz(Sanayi/Piknik/Ev)   :" << endl;
        cin>> m.tup_tipi;
        cout <<"------------------------------------------------"<<endl;
        cout << endl;
        yaz.write((char*)&m, sizeof(m));
        adet++;
        cout << "Musteri eklemek ister misiniz?(E/H): " << endl;
        secim=getche();
        cout << endl;
    }while(secim=='e' || secim=='E');
    cout << adet << " adet musteri basariyla eklendi." << endl;
    yaz.close();
}
void MusteriListeleme()
{
    ifstream oku("Musteri.dat",ios::binary |ios::app);
    oku.seekg(0,ios::end);
    int kayitsayisi=oku.tellg()/sizeof(m);
    cout << "Sistemde kayitli musteri sayisi: "<< kayitsayisi << endl;
    if(kayitsayisi>0)
    {
        for(int i=0; i<kayitsayisi;i++)
        {
            oku.seekg(i*sizeof(m));
            oku.read((char*)&m, sizeof(m));
            cout <<"------------------------------------------------"<<endl;
            cout <<"------------------------------------------------"<<endl;
            cout << i+1 << ". Musterinin Bilgileri"<< endl;
            cout << "Musteri Adi        : "<< m.ad <<endl ;
            cout << "Musteri Soyadi     : "<< m.soyad <<endl ;
            cout << "Musteri E-posta    : "<< m.e_posta<<endl ;
            cout << "Musteri Telefon No : "<< m.tel_no <<endl ;
            cout << "Musteri mahalle    : "<< m.mahalle <<endl ;
            cout << "Musteri daire no   : "<< m.daireno <<endl ;
            cout << "Odeme Tipi         : "<< m.odeme_tipi<<endl ;
            cout << "Tup Tipi           : "<< m.tup_tipi <<endl ;
        }
    }
    else
        cout << "Henuz hicbir kayit eklemediniz :(" << endl;
    oku.close();
}
void MusteriArama()
{
    ifstream oku("Musteri.dat",ios::binary |ios::app);
    oku.seekg(0,ios::end);
    int kayits=oku.tellg()/sizeof(m);
    cout <<"Aramak istediginiz musterinin Ad-Soyad bilgisi giriniz: "<< endl;
    char findname[80];
    cin>> findname;
    if(kayits>0)
    {
        for(int i=0; i<kayits;i++)
        {
            oku.seekg(i*sizeof(m));
            oku.read((char*)&m, sizeof(m));
            if(strcmp(m.ad,findname)==0)
            {
                cout << "Aradiginiz musteri bilgileri asagidadir." << endl;
                cout <<"------------------------------------------------"<<endl;
                cout << "Musteri Adi        : "<< m.ad <<endl ;
                cout << "Musteri Soyadi     : "<< m.soyad <<endl ;
                cout << "Musteri E-posta    : "<< m.e_posta<<endl ;
                cout << "Musteri Telefon No : "<<m.tel_no <<endl ;
                cout << "Musteri mahalle    : "<<m.mahalle <<endl ;
                cout << "Musteri daire no   : "<< m.daireno <<endl ;
                cout << "Odeme Tipi         : "<<m.odeme_tipi<<endl ;
                cout << "Tup Tipi           : "<<m.tup_tipi <<endl ;
                cout <<"------------------------------------------------"<<endl;
            }
        }
    }
    else
        cout << "Aradiginiz kisi listede kayitli degil :(" << endl;
    oku.close();
}
void MusteriSil()
{
    char findname[80];
    char secim= ' ';
    bool var=false;
    ifstream oku("Musteri.dat",ios::binary |ios::app);
    oku.seekg(0,ios::end);
    int kayitsayisi=oku.tellg()/sizeof(m);
    cout<<"Silmek istediginiz musteri ismini giriniz : ";
    cin>>findname;
    for(int i=0;i<kayitsayisi;i++)
    {
        oku.seekg(i*sizeof(m));
        oku.read((char*)&m, sizeof(m));

        if(strcmp(m.ad,findname)==0)
        {
            cout<<endl;
            cout<<"Silmek istediginiz musterinin bilgileri: " << endl;
            cout <<"------------------------------------------------"<<endl;
            cout <<"------------------------------------------------"<<endl;
            cout<<"\nMusteri adi : "<<m.ad;
            cout<<"\nMusteri soyad : "<<m.soyad;
            cout<<"\nE-posta adresi : "<<m.e_posta;
            cout<<"\nTelefon numarasi : "<<m.tel_no;
            cout<<"\nMahalle : "<<m.mahalle;
            cout<<"\nDaire no : "<<m.daireno;
            cout<<"\nOdeme tipi : "<<m.odeme_tipi;
            cout<<"\nTup tipi : "<<m.tup_tipi;
            cout <<"\n------------------------------------------------"<<endl;
            cout <<"------------------------------------------------"<<endl;
            cout<<"\n\nSilmek istediginiz musteri dogru mu)(e/h): ";
            secim=getche();
            if(secim == 'H' || secim == 'h')
            {
                Musteri y_m;
                ofstream y_dosya("Yedekmusteri.dat",ios::app|ios::binary);
                strcpy(y_m.ad,  m.ad);
                strcpy(y_m.soyad,  m.soyad);
                strcpy(y_m.e_posta,   m.e_posta);
                strcpy(y_m.tel_no,    m.tel_no);
                strcpy(y_m.mahalle,     m.mahalle);
                strcpy(y_m.daireno,  m.daireno);
                strcpy(y_m.odeme_tipi,m.odeme_tipi);
                strcpy(y_m.tup_tipi,  m.tup_tipi);
                y_dosya.write((char*)&m, sizeof(m));
                y_dosya.close();
            }
            if(secim=='e'||secim=='E')
            {
                var=true;
            }
        }
        else
        {
            Musteri y_m;
            ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
            strcpy(y_m.ad,  m.ad);
            strcpy(y_m.soyad,  m.soyad);
            strcpy(y_m.e_posta,   m.e_posta);
            strcpy(y_m.tel_no,    m.tel_no);
            strcpy(y_m.mahalle,     m.mahalle);
            strcpy(y_m.daireno,  m.daireno);
            strcpy(y_m.odeme_tipi,m.odeme_tipi);
            strcpy(y_m.tup_tipi,  m.tup_tipi);
            y_dosya.write((char*)&m, sizeof(m));
            y_dosya.close();
        }
    }
    oku.close();
    if(var){
        remove("Musteri.dat");
        rename("Yedek.dat","Musteri.dat");
        cout<<"\nMusteri basariyla silindi :("<<endl;
    }
    else{
        remove("Yedek.dat");
        cout<<"\n Girdiginiz musteri kayitlarimizda bulunumadi."<<endl;
    }
}
void MusteriDuzenle()
{
    char findname[80];
    char secim= ' ';
    bool var=false;
    ifstream oku("Musteri.dat",ios::binary |ios::app);
    oku.seekg(0,ios::end);
    int kayitsayisi=oku.tellg()/sizeof(m);
    cout<<"Duzenleme yapmak istediginiz musteri ad-soyad giriniz: ";
    cin>>findname;
    for(int i=0;i<kayitsayisi;i++){
        oku.seekg(i*sizeof(m));
        oku.read((char*)&m, sizeof(m));
        if(strcmp(m.ad,findname)==0)
        {
            cout<<endl;
            cout<<"Duzenlemek istediginiz musterinin bilgileri: ";
            cout <<"------------------------------------------------"<<endl;
            cout <<"------------------------------------------------"<<endl;
            cout<<"\nMusteri adi : "<<m.ad;
            cout<<"\nMusteri soyad : "<<m.soyad;
            cout<<"\nE-posta adresi : "<<m.e_posta;
            cout<<"\nTelefon numarasi : "<<m.tel_no;
            cout<<"\nMahalle : "<<m.mahalle;
            cout<<"\nDaire no : "<<m.daireno;
            cout<<"\nOdeme tipi : "<<m.odeme_tipi;
            cout<<"\nTup tipi : "<<m.tup_tipi<<endl;
            cout <<"------------------------------------------------"<<endl;
            cout <<"------------------------------------------------"<<endl;
            cout<<"\n\nDuzenlemek istediginiz musteri dogru mu)(e/h): "<< endl;
            secim=getche();
            if(secim == 'E' || secim == 'e'){
                var=true;
                ofstream dosya("Yedek.dat",ios::app|ios::binary);
                cout <<"------------------------------------------------"<<endl;
                cout << "Musteri Ad Giriniz" << endl;
                cin>>m.ad;
                cout <<"------------------------------------------------"<<endl;
                cout << "Musteri Soyad Giriniz" << endl;
                cin>>m.soyad;
                cout <<"------------------------------------------------"<<endl;
                cout << "Musteri e-posta Giriniz" << endl;
                cin>> m.e_posta;
                cout <<"------------------------------------------------"<<endl;
                cout << "Musteri Telefon numarasi Giriniz" << endl;
                cin>> m.tel_no;
                cout <<"------------------------------------------------"<<endl;
                cout << "Musteri Mahalle Giriniz" << endl;
                cin>>m.mahalle;
                cout <<"------------------------------------------------"<<endl;
                cout << "Musteri daire no Giriniz" << endl;
                cin>>m.daireno;
                cout <<"------------------------------------------------"<<endl;
                cout << "Musteri Odeme tipi Giriniz" << endl;
                cin>> m.odeme_tipi;
                cout <<"------------------------------------------------"<<endl;
                cout << "Musteri Tup tipi Giriniz(Sanayi/Piknik/Ev)" << endl;
                cin>> m.tup_tipi;
                cout <<"------------------------------------------------"<<endl;
                cout << endl;
                dosya.write((char*)&m, sizeof(m));
                dosya.close();
            }
            else{
                Musteri y_m;
                ofstream y_dosya;
                y_dosya.open("Yedek.dat",ios::app|ios::binary);
                strcpy(y_m.ad,  m.ad);
                strcpy(y_m.soyad,  m.soyad);
                strcpy(y_m.e_posta,   m.e_posta);
                strcpy(y_m.tel_no,    m.tel_no);
                strcpy(y_m.mahalle,     m.mahalle);
                strcpy(y_m.daireno,  m.daireno);
                strcpy(y_m.odeme_tipi,m.odeme_tipi);
                strcpy(y_m.tup_tipi,  m.tup_tipi);
                y_dosya.write((char*)&y_m, sizeof(y_m));
                y_dosya.close();
            }
        }
    }
    oku.close();
    if(var){
        remove("Musteri.dat");
        rename("Yedek.dat","Musteri.dat");
        cout<<"\nMusteri kaydi basariyla duzenlendi."<<endl;
    }
    else{
        remove("Yedek.dat");
        cout<<"\nAradiginiz kayit bulunamadi"<<endl;
    }
}
