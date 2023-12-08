/*Nama   : El Emir Di Haryanto
  NPM    : 4521210031
  Materi : TUGAS BESAR
  Soal   : No.48
*/


#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;

void garis(){
	cout<<"\t====================================\n";
}
void header()
{
	cout<<endl<<endl;
	cout<<"\n\t\t             ========================================================";
    cout<<"\n\t\t           ==============================================================";
    cout<<"\n\t\t        ====================================================================";
    cout<<"\n\t\t      =========================================================================";
    cout<<"\n\t\t   ==============================================================================";
    cout<<"\n\t\t                       SELAMAT DATANG DI VEGAS HOTEL             ";
    cout<<"\n\n\t\t                  JL. HARYANTO , No 48 Telp 4521210031             ";
    cout<<"\n\t\t                        PANCASILA, JAKARTA SELATAN        ";
    cout<<"\n\t\t=================================================================================";
    cout<<"\n\t\t=================================================================================";
	cout<<"\n\t\t=================================================================================";
    cout<<"\n\t\t=================================================================================";
}
int main ()
{
                char emir[30], diharyanto[30], haryanto[50];
                int unpas, emir_it, el_emir,tubes;
                int total, lama, rime, kurang;
                float diskon;
                string jwb, emir_parker, raden_emir, yanto, algo, prak_algo, emir_haryanto, fixkam;
                awal:
               input:
	           getchar();
			   header();
               
                cout<<"\n\n\n\n\t\tSilahkan Isi Form Berikut ini";
cout<<"\n\t\t=================================================================================";cout<<endl;
                cout<<"\t\tNama Resepsionis Yang Melayani : "; gets(emir);
                cout<<"\t\tID Resepsionis                 : "; cin>>raden_emir;
                cout<<"\t\tNama Pemesan                   : "; cin>>diharyanto;
                cout<<"\t\tID Pemesan                     : "; cin>>emir_parker;
                cout<<"\t\tJenis Kelamin [L/P]            : "; cin>>yanto;
                cout<<"\t\tNomor Telepon/HP               : "; cin>>algo;
                cout<<"\t\tAlamat                         : "; cin>>haryanto;
      cout<<"\t\t=================================================================================";
	        
   			 
                cout<<"\n\n\t\tSilahkan Pilih Tipe Kamar Yang Anda Inginkan";
  cout<<"\n\t\t=================================================================================";
                cout<<"\n\t\t1. Standart";
                cout<<"\n\t\t2. Premium";
                cout<<"\n\t\t3. Deluxe";
                cout<<"\n\t\t4. Suite";
                cout<<"\n\t\t5. Presidential";
  cout<<"\n\t\t=================================================================================";
                cout<<"\n\t\tMasukan Pilihan : ";cin>>unpas;
               

                cout<<"\n\n\t\tSilahkan Pilih Tipe Bed Yang Anda Inginkan";
  cout<<"\n\t\t=================================================================================";
                cout<<"\n\t\t1. Single";
                cout<<"\n\t\t2. Double";
  cout<<"\n\t\t=================================================================================";
                cout<<"\n\t\tMasukan Pilihan : ";cin>>tubes;cout<<endl;
               
                if(unpas==1 && tubes==1)
                {
                                cout<<"\n\t\tAnda Memilih Kamar Tipe Standart Dengan Ranjang Single";
                               fixkam="Standart Dengan Single Bed";
                                el_emir=200000;
                }
                else if(unpas==1 && tubes==2)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Tipe Standart Dengan Ranjang Double";
                    fixkam="Standart Dengan Double Bed";
                                el_emir=250000;                  
                }
                else if(unpas==2 && tubes==1)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Tipe Premium Dengan Ranjang single";
                    fixkam="Premium Dengan Single Bed";
                                el_emir=400000;                  
                }
                else if(unpas==2 && tubes==2)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Tipe Premium Dengan Ranjang Double";
                   fixkam="Premium Dengan Double Bed";
                                el_emir=450000;                  
                }
                                else if(unpas==3 && tubes==1)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Tipe Deluxe Dengan Ranjang single";
                    fixkam="Deluxe Dengan Single Bed";
                               el_emir=800000;                  
                }
                else if(unpas==3 && tubes==2)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Tipe Deluxe Dengan Ranjang Double";
                    fixkam="Deluxe Dengan Double Bed";
                                el_emir=900000;                  
                }
                                else if(unpas==4 && tubes==1)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Tipe Suite Dengan Ranjang single";
                    fixkam="Suite Dengan Single Bed";
                                el_emir=1500000;                
                }
                else if(unpas==4 && tubes==2)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Tipe Suite Dengan Ranjang Double";
                    fixkam="Suite Dengan Double Bed";
                                el_emir=1800000;                
                }
                else if(unpas==5 && tubes==1)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Tipe Presidential Dengan Ranjang single";
                    fixkam="Presidential Dengan Single Bed";
                                el_emir=2500000;                
                }
                else if(unpas==5 && tubes==2)
                {
                    cout<<"\n\t\tAnda Memilih Kamar Tipe Presidential Dengan Ranjang Double";
                    fixkam="Presidential Dengan Double Bed";
                                el_emir=4000000;                
                }
                else
                {
                                cout<<"\n\t\tMaaf Pilihan Anda Tidak Tersedia";
                                cout<<"\n\t\tUntuk Keamanan Silahkan Isi Data Dari Awal";
                                cout<<"\n\t\tApakah Anda Ingin Memulai Lagi ? [Y/N]";cin>>jwb;
                                if(jwb=="Y" || "y")
                                {
                                                goto awal;
                                }
                                else
                                {
                                                cout<<"\n\n\t\tTerima Kasih";
                                }
                }
			  
                cout<<"\n\n\n\t\tSilahkan Mengisi Form Berikut";
  cout<<"\n\t\t=================================================================================";
                cout<<"\n\t\tPilih No. Kamar [1-100]     : "; cin>>emir_it;
                cout<<"\n\t\tMenginap Lebih Dari 5 Hari diskon 2% perhari";
                cout<<"\n\t\tLama Menginap               : "; cin>>lama;
               
                if(lama>=5)
                {
                                diskon=0.2;
                }
                else
                {
                                diskon=0;
                }
                cout<<"\n\t\tTanggal Check In [DDMMYY]   : ";cin>>prak_algo;
                cout<<"\n\t\tTanggal Check Out [DDMMYY]  : ";cin>>emir_haryanto;
      cout<<"\t\t=================================================================================";
               
                cout<<"\n\n\n\n\t\tData Pemesanan Kamar"<<endl;
      cout<<"\t\t=================================================================================";
                cout<<"\n\t\tNama Resepsionis : "<<emir;
                cout<<"\n\t\tID Resepsionis   : "<<raden_emir;
                cout<<"\n\t\tNama Pemesan     : "<<diharyanto;
                cout<<"\n\t\tID Pemesan       : "<<emir_parker;
                cout<<"\n\t\tAlamat           : "<<haryanto;
                cout<<"\n\t\tNo Telp/HP       : "<<algo;
                cout<<"\n\t\tTipe Kamar       : "<<fixkam;
                cout<<"\n\t\tNo. Kamar        : ";
                if(emir_it >= 1 && emir_it <= 100)
                {
                                cout<<emir_it;
                }
                else
                {
                                cout<<"\n\t\tMaaf Nomer Kamar Belum Tersedia";
                                cout<<"\n\t\tSilahkan Hubungi Resepsionis Untuk Pergantian Nomer";
                }
                cout<<"\n\t\tLama Menginap    : "<<lama<<" Hari";
                cout<<"\n\t\tTanggal Check in : "<<prak_algo;
                cout<<"\n\t\tTanggal Check out: "<<emir_haryanto;
                cout<<"\n\t\tHarga Perhari    : Rp. "<<el_emir;
                cout<<"\n\t\tHarga Kamar Total: Rp. "<<lama*el_emir;
                cout<<"\n\t\tDiskon           : Rp. "<<diskon*el_emir<<endl;
                total=el_emir*lama-(diskon*el_emir);
      cout<<"\t\t=================================================================================";
                cout<<"\n\n\t\tBiaya Total      : Rp. "<<total;
                cout<<"\n\t\tUang Muka        : Rp. ";cin>>rime;
                kurang=total-rime;
                if(total>=rime)
                {
                                cout<<"\n\t\tKekurangan       : Rp. "<<kurang;
                }
                else
                {
                                cout<<"\n\t\tKembali          : Rp. "<<kurang*(-1);
                }
  cout<<"\n\t\t=================================================================================";
               
                cout<<"\n\n\t\tTerima Kasih Telah Memilih Hotel VEGAS";
                cout<<"\n\t\tSebagai Tempat Peristirahatan Anda";
                cout<<endl;
                cout<<"\n\n\t\tApakah Anda Ingin Memesan Kamar Lagi ? [Y/N]";cin>>jwb;
                if(jwb=="Y" || jwb=="y")
                {
                                goto awal;
                }
                else
                {
                                cout<<"\n\n\t\tTerima Kasih Atas Kunjungannya";
                }
                getch();
}