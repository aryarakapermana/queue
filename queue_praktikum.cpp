#include<iostream>
#define MAX 300
using namespace std;

//berikan struct
struct Pasien{
	int nomor;
	string nama;
	
};

//deklarasi variable
struct AntrianPasien{
	Pasien data[MAX];
	int front, rear;
	int autoNomor;
	
	//taro front,rear,nomor antrian
	AntrianPasien(){
		front=0;
		rear=-1;
		autoNomor=0;
	}
	
	//cek penuh
	bool isFull(){
		return rear == MAX-1;
	}
	
	//cek kosong
	bool isEmpty(){
		return front>rear;
	}
	
	//fungsi tambah queue
	void enqueue(string nama){
		if (isFull()){
			cout<<"Antrian Penuh ! Tidak bisa menambah pasien lagi.\n";
			return;
		}
		autoNomor++;
		rear++;
		data[rear].nomor = autoNomor;
		data[rear].nama = nama;
		cout<<"Pasien "<<nama<<" (No. "<<autoNomor<<" ) berhasil ditambahkan ke antrian. \n";
	}
	
	//fungsi kurang
	void dequeue(){
		if(isEmpty()){
			cout<<"Antrian kosong ! Tidak ada pasien yang dilayani.\n";
			return;
		}
		cout<<"Melayani Pasien : "<<data[front].nama << "(No. "<<data[front].nomor<<" )\n";
		front++;
		
	}
	
	//fungsi lihat head/awal
	void peekFront() {
		if (isEmpty()) {
			cout<< " Antrian kosong!\n";
			return;
		}
		cout<<"Pasien selanjutnya : "<<data[front].nama<<"(No. "<<data[front].nomor<<")\n";
	}
	
	//fungsi lihat tail/akhir / cek kosong
	void peekBack() {
		if (isEmpty()) {
			cout<< " Antrian kosong!\n";
			return;
		}
		cout<<"Pasien terakhir : "<<data[rear].nama<<"(No. "<<data[rear].nomor<<")\n";
	}
	
	//tampilan queue
	void display(){
		if(isEmpty()){
			cout<<"Antrian kosong!\n";
			return;
		}
		cout<<"Daftar pasien dalam antrian :\n";
		
		for(int i = front; i<=rear; i++){
			cout<<data[i].nomor<<". "<<data[i].nama<<endl;
		}
	}
	
	//oprasi cek jumlah antrian
	void jumlahAntrian(){
		cout<<"Jumlah pasien dalam antrian : "<<(rear-front+1)<<endl;
	}
};

//codingan utama
int main(){
	AntrianPasien antrian;
	int pilihan;
	string nama;
	
	
	//menu
	do{
		cout<<"\n=== Menu Antrian Pasien ===\n";
		cout<<" 1.Tambah Pasien\n";
		cout<<" 2.Layani Pasien\n";
		cout<<" 3.Lihat Pasien selanjutnya\n";
		cout<<" 4.Lihat Pasien Terakhir\n";
		cout<<" 5.Lihat Semua Pasien\n";
		cout<<" 6.Lihat jumlah \n";
		cout<<" 7.Keluar\n";
		cout<<"Pilihan anda :";
		cin>>pilihan;
		cin.ignore();
		
		
		//pilihan
		switch(pilihan){
			case 1:
			cout<<"Masukan nama pasien : ";
			getline(cin,nama);
			antrian.enqueue(nama);
			break;
			
			case 2:
			antrian.dequeue();
			break;
			
			case 3:
			antrian.peekFront();
			break;
			
			case 4:
			antrian.peekBack();
			break;
			
			case 5:
			antrian.display();
			break;
			
			case 6:
			antrian.jumlahAntrian();
			break;
			
			case 7:
			cout<<"Program selesai.\n";
			break;
			default:
				cout<<"Pilihan tidak valid!\n";
		}
	}
	while ( pilihan !=7);
	return 0;
}
