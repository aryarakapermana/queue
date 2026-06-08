# 🚀 Program Queue Sederhana (C++)

Program ini merupakan implementasi **struktur data Queue** menggunakan bahasa C++. Queue bekerja dengan prinsip **FIFO (First In, First Out)**, yaitu data yang pertama masuk akan keluar lebih dulu.

### 1. **Cek Queue Kosong**
```cpp
bool isEmpty(){
    return front == -1 || front > rear;
}
```
👉 Fungsi ini mengembalikan `true` jika **queue kosong**, yaitu ketika:
- `front == -1` (belum ada data masuk), atau
- `front > rear` (semua data sudah di-dequeue).

---

### 2. **Cek Queue Penuh**
```cpp
bool isFull(){
    return rear == MAX - 1;
}
```
👉 Fungsi ini mengembalikan `true` jika **queue penuh**, yaitu ketika posisi `rear` sudah mencapai indeks terakhir array (`MAX-1`).

---

### 3. **Menambahkan Data ke Queue (Enqueue)**
```cpp
void enqueue(int data){
    if(isFull()){
        cout << "Queue penuh!!.\n";
    } else {
        if(isEmpty()) front = 0;
        rear++;
        queue_arr[rear] = data;
        cout << data << " Berhasil ditambahkan.\n";
    }
}
```
👉 Fungsi ini menambahkan data ke **belakang queue**:
- Jika penuh → tampilkan pesan.
- Jika kosong → set `front = 0`.
- Tambahkan data ke posisi `rear`.

---

### 4. **Menghapus Data dari Queue (Dequeue)**
```cpp
void dequeue(){
    if(isEmpty()){
        cout << "Queue kosong!!.\n";
    } else {
        cout << queue_arr[front] << " berhasil di dequeue\n";
        front++;
    }
}
```
👉 Fungsi ini menghapus data dari **depan queue**:
- Jika kosong → tampilkan pesan.
- Jika ada data → tampilkan data yang dihapus, lalu geser `front` ke indeks berikutnya.

---

### 5. **Menampilkan Isi Queue**
```cpp
void display(){
    if(isEmpty()){
        cout << "Queue kosong!!.\n";
    } else {
        cout << "Isi QUEUE (front ke rear)\n";
        for(int i = front; i <= rear; i++){
            cout << "# " << queue_arr[i] << endl;
        }
        cout << "----------------------------\n";
    }
}
```
👉 Fungsi ini menampilkan isi queue dari **front ke rear**:
- Jika kosong → tampilkan pesan.
- Jika ada data → tampilkan semua isi queue.

### 📊 Contoh Output
```
12 Berhasil ditambahkan.
10 Berhasil ditambahkan.
1 Berhasil ditambahkan.
12 berhasil di dequeue
Isi QUEUE (front ke rear)
# 10
# 1
----------------------------
```
