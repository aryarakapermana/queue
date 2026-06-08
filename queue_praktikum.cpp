#include<iostream>
using namespace std;

//inisiasi variable yang di gunakan
#define MAX 5
int queue_arr[MAX];
int front = -1;
int rear = -1;

//fungsi cek kosong
bool isEmpty(){
	return front == -1||front>rear;
}

//fungsi cek penuh
bool isFull(){
	return rear == MAX-1;
}

//fungsi tambah queue
void enqueue(int data){
	if( isFull()){
		cout<<"Queue penuh!!.\n";
	}
	else {
		if (isEmpty()) front = 0;
		rear++;
		queue_arr[rear] = data;
		cout<<data<<" Berhasil ditambahkan.\n";
	}
}

//fungsi kurang queue
void dequeue(){
	if (isEmpty()){
		cout<<"Queue kosong!!.\n";
	}
	else {
		cout<<queue_arr[front]<<" berhasil di dequeue\n";
		front++;
	}
}

//fungsi tampilkan queue
void display(){
		if (isEmpty()){
		cout<<"Queue kosong!!.\n";
	} else {
		cout<<"Isi QUEUE (front ke rear)\n";
		for (int i = front; i <= rear; i++){
			cout<<"# "<<queue_arr[i]<<endl;
		}
		cout<<"----------------------------\n";
	}
}

//fungsi utama
int main(){
	enqueue(12);
	enqueue(10);
	enqueue(1);
	dequeue();
	display();
}
