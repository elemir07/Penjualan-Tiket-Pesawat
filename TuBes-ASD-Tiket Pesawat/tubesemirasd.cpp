/*Nama   : El Emir Di Haryanto
  NPM    : 4521210031
  Materi : Penjualan Tiket Pesawat Pakai Inputan
  Soal   : No.30
  Tugas Besar Praktek Algortima dan Struktur Data B
*/

#include <iostream>
#include <conio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <list>
#define HASHSIZE 100
#define NOHP 30
#define NAMA 13
#define MAX 1000 //MAKSIMAL NOMOR ANTRIAN
#define	_CONIO_H_
using namespace std;

struct tiket{ //struct untuk single linked list 
char nama[80];
string maskapai, rute, tgl;
int harga, kode, jumlah, total;
struct tiket *next; 
};
typedef tiket pesawat;
pesawat *baru, *awal=NULL, *akhir=NULL, *hapus, *bantu; 

struct HashData{  //struct untuk hash
	char emir [NOHP];
	char nama [NAMA];
};

template <typename T>
class Graph  //class untuk graph bfs
{
    map<T, list <pair <T, int>>> l;
public:
    void add_edge(T node, T neighbour, int distance = 1, bool is_directed = false)
    {
        l[node].push_back(make_pair(neighbour, distance));
 
        if(!is_directed)
            l[neighbour].push_back(make_pair(node, distance));
    }
	void print_graph()
    {
        for(auto p : l)
        {
            T node = p.first;
            list <pair <T, int>> neighbour = p.second;
 
            cout << "Neighbours of: " << node << " are:\n";
 
            for(auto nbr : neighbour)
            {
                T dest = nbr.first;
                int distance = nbr.second;
 
                cout << "Neighbour: " << dest << " " << " Distance: "<< distance << endl;
            }
            cout << endl;
        }
    }
 
    void bfs(T src)
    {
        map <T, bool> visited;
 
        queue <T> q;
 
        q.push(src);
        visited[src] = true;
 
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << endl;
 
            for(pair <T, int> nbr : l[node])
            {

                if(!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                }
            }
        }
 
        return;
    }
};

typedef struct //struct untuk queue
{
	int nomer[MAX];
int head=-1, tail=-1;
}data;

data antri; 

bool IsEmpty(){ 
   if(antri.tail == -1){
       return true;
   }else{
       return false;
   }
}

bool IsFull(){ 
   if(antri.tail == MAX-1){
       return true;
   }else{
       return false;
   }
}

void AntrianMasuk(int no){ //function untuk menampung data antrian
    if (IsEmpty()){
        antri.head=antri.tail=0;
    }else {
        antri.tail++;
    }
    antri.nomer[antri.tail]=no;
}

void AntrianKeluar(){ //function untuk pemanggilan antrian
    if(IsEmpty()){ 
        cout<<"Antrian sudah kosong ! ";
        getch();
    } else {
        for(int a=antri.head;a<antri.tail;a++){
            antri.nomer[a]=antri.nomer[a+1];
        }
        antri.tail--;
        if(antri.tail == -1){
            antri.head = -1;
        }
    }
}

void Clear(){ //function untuk menghapus data antrian
     antri.head=antri.tail=-1;
}

void View(){ //function untuk menampilkan data antrian 
     if(IsEmpty()){
         cout<<"Antrian kosong ! ";

     }else {
         for(int a=antri.head;a<=antri.tail;a++){
              cout << "==============================="
                   << "\n >> No. Antri : [" << antri.nomer[a] << "]"
                   << "\n==============================="<< endl;
         }
     }
};

//function pembuatan hash
static HashData *hashTable[HASHSIZE];
int searchingProcess(HashData *, int);
void deleting(HashData *);
int hashFunction(HashData *);
bool isIndexEmpty(int);
int characterAmount(char []);
void DisplayTable();

//function untuk linked list
int pil;
void pilih();
void buat_baru();
void tambah_akhir_tiket();
void tampil();
void arah();
void bayar();
void antrian_queue();
void riset();
void header();
void bayar();
void member();
void tugas_besar();

void header()
{
  cout<<"=============================================="<<endl;
  cout<<"                SITUS TIKET ONLINE            "<<endl;
  cout<<"=============================================="<<endl;
  cout<<"                 Selamat Datang               "<<endl;
  cout<<"=============================================="<<endl;
  cout<<"              Menjual Tiket Pesawat           "<<endl;
  cout<<"              Bandara Soekarno-Hatta          "<<endl;
  cout<<"=============================================="<<endl;
  cout<<"        BY : EL EMIR DI HARYANTO (4521210031) "<<endl;
  cout<<"Mahasiswa Universitas Pancasila S2 Informatika"<<endl;
  cout<<"=============================================="<<endl;
  cout<<"               Selamat Mencoba ^_^            "<<endl;
}

void antrian_queue()
{
int choose, p=1, urut; //Materi queue
		  do{
		cout << "\n\n===== Silahkan Antri Dulu ========"
             << "\n===================================="
             << "\n|1. Ambil Antrian Tiket            |"
             << "\n|2. Panggil Antrian                |"
             << "\n|3. Lihat Daftar Antrian Tiket     |"
             << "\n|4. Hapus Antrian                  |"
             << "\n|5. Exit Dan Kembali Ke Menu Utama |"
             << "\n====================================";
        cout << "\nChoose ! "; cin >> choose;
        cout << "\n\n";
        if(choose == 1){
            if(IsFull()) {
                cout<<"Antrian sudah penuh, mohon tunggu beberapa saat lagi ";
            }
            else{
                urut=p;
                AntrianMasuk(urut);
                cout << "---------------------------------" << endl;
                cout << "|          NO. ANTRIAN          |" << endl;
                cout << "|               " << p << "              ||" << endl;
                cout << "---------------------------------" << endl;
                cout << "|       Silahkan Mengantri      |" << endl;
                cout << "|     Mohon Tunggu " << antri.tail << " Antrian   ||" << endl;
                cout << "---------------------------------" << endl;
                p++;
            }
        }
        else if(choose == 2){
            cout << "=================================" << endl;
            cout << "No. Antri : [" << antri.nomer[antri.head] << "]";
            cout << "\n=================================" << endl;
            AntrianKeluar();
            cout << "Anda Dipanggil Silahkan Pilih Menu 5 !" << endl;
        }
        else if(choose == 3){
            View();
        }
        else if(choose == 4){
            Clear();
            cout<<"Antrian dikosongkan ! ";
        }
        else if(choose == 5){
        }
        else {
            cout << "Masukan anda salah ! \n"<< endl;
        }
        getch();
        }while(choose!=5);
}

void arah()
{
   cout<<"=============================================="<<endl;
   cout<<"             List Data Penerbangan            "<<endl;
   cout<<"=============================================="<<endl;
   cout<<"             Bandara Soekarno-Hatta           "<<endl;
   cout<<"=============================================="<<endl;
   cout<<endl;
   Graph <string> g; //Materi Graph dan BFS
    
    g.add_edge("Berangkat", "Jakarta");       
    g.bfs("Berangkat"); 
    cout<<endl;
    
    g.add_edge("Tujuan", "Pontianak");
    g.add_edge("Tujuan", "Palembang");
    g.add_edge("Tujuan", "Padang");
    g.add_edge("Tujuan", "Singapura");
    g.add_edge("Tujuan", "Balikpapan");
    g.bfs("Tujuan");  
    cout<<endl;
}

void bayar()
{
    cout<<endl;
	cout<<"\t Data Harga Tiket Bandara Soekarno-Hatta Yang Tersedia : \t\t"<<endl;
	cout<<"--------------------------------------------------------------------------"<<endl<<endl;
	cout<<"__________________________________________________________________________________________"<<endl;
	cout<<"|\t Kode Penerbangan\t | \t Rute \t\t |   Pesawat \t |    Harga \t |"<<endl;
	cout<<"|________________________________________________________________________________________|"<<endl;
	cout<<"|\t 1. JKT-PNK \t\t |  Jakarta-Pontianak\t | Citilink\t | Rp. 920000 \t |"<<endl;
	cout<<"|\t 2. JKT-PLM \t\t |  Jakarta-Palembang\t | Garuda\t | Rp. 890000 \t |"<<endl;
	cout<<"|\t 3. JKT-PDG \t\t |  Jakarta-Padang\t | Air Asia\t | Rp. 940000 \t |"<<endl;
	cout<<"|\t 4. JKT-SIN \t\t |  Jakarta-Singapura\t | Batik Air\t | Rp. 1800000 \t |"<<endl;
	cout<<"|\t 5. JKT-BPN \t\t |  Jakarta-Balikpapan\t | Lion Air\t | Rp. 930000 \t |"<<endl;
	cout<<"|________________________________________________________________________________________|"<<endl;
	cout<<endl;
}

void buat_baru(){
baru = new pesawat; //Materi Linked List
cout<<"================================="<<endl;
cout<<"           ISI FORMULIR          "<<endl;
cout<<"================================="<<endl;
cout<<"Nama Pemesan               : ";cin>>baru->nama; 
cout<<"Kode Tiket                 : ";cin>>baru->kode;
cout<<"Jumlah Tiket               : ";cin>>baru->jumlah;
cout<<"Tanggal Pesan [DD/MM/YYYY] : ";cin>>baru->tgl;
baru->next=NULL;
}

void tambah_akhir_tiket()
{
	buat_baru();
	if(awal==NULL)
	{
		awal = baru;
		akhir = baru;
		baru->next = NULL;
	}
	else
	{
		akhir->next = baru;
		akhir = baru;
		baru->next = NULL;
	}
	cout<<endl;
}

void tampil(){
if(awal==NULL)
  {
cout<<"Kosong";
cout<<endl;
  }
 else{
 bantu=awal;
 while(bantu!=NULL)
 {
 cout<<"============================================"<<endl;
 cout<<" Tiket Pesawat Bandara Soekarno-Hatta "<<endl;
 cout<<"============================================"<<endl;
 cout<<"Nama Pemesan \t\t : "<<bantu->nama<<endl;
 cout<<"Kode Tiket \t\t : "<<bantu->kode<<endl;
 if(baru->kode==1)
 {
   bantu->harga=920000;
 }
 else if(baru->kode==2)
 {
  bantu->harga=890000;
 }
 else if(baru->kode==3)
 {
  bantu->harga=940000;
 }
 else if(baru->kode==4)
 {
  bantu->harga=1800000;
 }
 else if(baru->kode==5)
 {
  bantu->harga=930000;
 }
 cout<<"Harga Tiket \t\t : "<<bantu->harga<<endl;
 cout<<"Jumlah Tiket \t\t : "<<bantu->jumlah<<endl;
 cout<<"Tanggal Pesan \t\t : "<<bantu->tgl<<endl;
 if(baru->kode==1)
 {
   cout<<"Maskapai \t\t : Citilink"<<endl;
   cout<<"Rute Penerbangan \t : Jakarta-Pontianak"<<endl;
 }
 else if(baru->kode==2)
 {
   cout<<"Maskapai \t\t : Garuda Indonesia"<<endl;
   cout<<"Rute Penerbangan \t : Jakarta-Palembang"<<endl;
 }
 else if(baru->kode==3)
 {
   cout<<"Maskapai \t\t : Air Asia"<<endl;
   cout<<"Rute Penerbangan \t : Jakarta-Padang"<<endl;
 }
 else if(baru->kode==4)
 {
   cout<<"Maskapai \t\t : Batik Air "<<endl;
   cout<<"Rute Penerbangan \t : Jakarta-Singapura"<<endl;
 }
 else if(baru->kode==5)
 {
   cout<<"Maskapai \t\t : Lion Air "<<endl;
   cout<<"Rute Penerbangan \t : Jakarta-Balikpapan"<<endl;
 }
 bantu->total=bantu->harga*bantu->jumlah;
 cout<<"TOTAL PEMBAYARAN \t : "<<bantu->total<<endl;
 cout<<"SILAHKAN CETAK TIKET DAN LAKUKAN PEMBAYARAN"<<endl;
 cout<<"\t\t Terima Kasih \t"<<endl;
 bantu=bantu->next;
 cout<<"============================================"<<endl;
 }
 }
}

void insert(HashData *array){ //Materi Hash Table
	int rec;
	rec = hashFunction(array);
	hashTable[rec] = array;
	cout << "Input successfully!" << endl;
	cout << "Data disimpan pada record indeks" << rec << endl;
	cin.get();
}

int searchingProcess (HashData *cari, int rec)
{
	int m,n,j = 0;
	bool equal = true;
	if (isIndexEmpty(rec) == false){
		n = characterAmount(cari->emir);
		m = characterAmount(hashTable[rec]->emir);
		if (n == m){
			while ((equal == true) && (cari->emir[j] != '\0')){
				if(tolower(cari->emir[j]) != tolower(hashTable[rec]->emir[j]))
					  equal = false;
				j++;
			}
			if(equal == true)
				   return rec;
			else
				   return -1;
		}
		else
				return -1;
	}
	else
		return -1;
		cin.get();
}

void deleting(HashData *hapus){
	int rec;
	rec = hashFunction(hapus);
	rec = searchingProcess(hapus, rec);
	if(rec >= 0){
		cout << "Data :" << endl;
		cout << "	=> No Hp		: " << hashTable[rec]->emir << endl;
		cout << "	=> Nama Member	: " << hashTable[rec]->nama << endl;
		cout << "terhapus!" << endl;
		hashTable[rec] = NULL;
	}
	else
		cout << "Maaf! Data tidak ditemukan!" << endl;
		cin.get();
}

int hashFunction(HashData *array){
	int value = 0, rec, n;
	n = characterAmount(array -> emir);
	for(int i=0; i<n; i++)
		value += array -> emir[i];
		rec = value % HASHSIZE;
		return rec;
}

bool isIndexEmpty(int rec){
	if(hashTable[rec] == NULL)
		 return true;
	else
		 return false;
}

int characterAmount(char array[]){
	int jumlah=0;
	for(int i=0; array[i]!='\0'; i++)
		 jumlah++;
		 return jumlah;
}

void DisplayTable(){
	cout<<"================================================="<<endl;
	cout<<"| Indeks |    NO.HP       |     Nama Member     |"<<endl;
	cout<<"================================================="<<endl;
	for(int i=0; i<HASHSIZE; i++)
	{
		if(isIndexEmpty(i) == false)
		  cout << setw(6) << i << "   " << hashTable[i]->emir <<"\t   " <<hashTable[i]->nama << endl;
	}
}

void tugas_besar() { 
	cout<<"\t--------------------------------------------------------------------------------\n";	
	cout<<"\tSITUS TIKET ONLINE\n";
	cout<<"\t---------------------------------------------------------------------------------\n";	
	cout<<"\tSelamat datang di webiste penjualan tiket online ini! "<<endl;
	cout<<"\tMenyediakan penjualan tiket pesawat untuk Bandara Soekarno-Hatta secara Online!"<<endl;
	cout<<"\tPilihan tepat  membeli tiket pesawat online disini, harganya ramah serta prosesnya cepat!"<<endl;
	cout<<"\t--------------------------------------------------------------------------------\n";	
	cout<<"\tTerima Kasih telah berkunjung, semoga anda puas dengan pelayanan dan kinerja website ini!"<<endl;
	cout<<"\tJangan lupa untuk jadi member dan bagian dari kami, karena akan ada banyak diskon dan hadiah menarik lainnya!"<<endl;
	cout<<"\t----------------------------------------------------------------------------------\n";
	cout<<"\tNegara : Indonesia\n";
	cout<<"\tBandara : Soekarno-Hatta\n";
	cout<<"\tKota : Tangerang, Banten\n";
	cout<<"\tKeberangkatan : Jakarta\n";
	cout<<"\tMenyediakan : Tiket online untuk 5 pesawat\n";
	cout<<"\tStatus Website	: Hanya Untuk Memenuhi Tugas Besar\n";
	cout<<"\tDibuat Oleh : El Emir Di Haryanto\n";
	cout<<"\tStatus Pembuat	: Mahasiswa Universitas Pancasila\n";
	cout<<"\tNPM : 4521210031\n";
	cout<<"\tJurusan : Teknik Informatika S2\n";
	cout<<"\tDosen : Bu Candra\n";
	cout<<endl;
}

int main()
{
int  menu;
char pilih1,next1;
header();
cout<<endl;
   do{
       awal :
	   cout<<endl;
	   cout<<"    Menu Utama   "<<endl;
       cout<<"1. Antrian Tiket "<<endl;
	   cout<<"2. Pesan Tiket   "<<endl;
	   cout<<"3. Tampilan Data "<<endl;
	   cout<<"4. Daftar Member "<<endl;
	   cout<<"5. About Website "<<endl;      
	   cout<<"6. Keluar Program"<<endl;
	   cout << "Menu pilihan Anda : "; cin >> menu;
	  switch(menu)
	  {
		  case 1 :
	      antrian_queue();
		  break;
		  
		case 2 :
		 arah();
         bayar();
		 tambah_akhir_tiket();
			break;
			
		  case 3 :
				 tampil(); 
				 break;
				 
		  case 4 :
            ay:
			cout<<endl;
			cout<<"========================================================="<<endl;
			cout<<"                    DAFTAR NEW MEMBER                    "<<endl;
			cout<<"========================================================="<<endl;
			cout<<"Keuntungan mendapatkan diskon 10% setiap pembelian tiket "<<endl;
			cout<<"                     (Rp50000/month)                     "<<endl;
			cout<<"========================================================="<<endl;
			cout<<"Serta berkesempatan mendapat hadiah menarik secara undian"<<endl;
			cout<<"========================================================="<<endl;
			cout<<"A. Daftar"<<endl;
			cout<<"B. Cancel"<<endl;
			cout<<"C. Display"<<endl;
			cout<<"D. Balik menu utama"<<endl;
			cout<<"Pilih [A/B/C/D] : "; cin >> pilih1;
			if(pilih1=='A')
			{
				HashData *array;
			    array = new HashData;
			    cout<<endl;
			    cout<<"No.Handphone : "; cin >> array->emir;
			    cout<<"Nama Member  : "; cin >> array->nama;
			    cout<<endl;
			    insert(array);
				goto ay;
			}
			else if(pilih1=='B')
			{
				HashData *hapus;
			    hapus = new HashData;
			    cout<<"Hapus Nomor HP : "; cin >> hapus->emir;
			    deleting(hapus); 
				goto ay;
			}
			else if(pilih1=='C')
			{
				DisplayTable();
				goto ay;
			}
			else if(pilih1=='D')
			{
				goto awal;
			}
           break;
		   
		  case 5 :
		  tugas_besar();
		  break;
		  
		  case 6 :
		  cout<<"Anda Keluar dari Program Terimakasih"<<endl;
		  return 0;
      }
	  cout<<"Kembali ke menu [Y/N]: "; cin >> next1;
   }
	while(next1=='Y');
	cin.get();
}