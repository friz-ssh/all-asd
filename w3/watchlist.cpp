#include <iostream>
#include <string>

struct Film {
    std::string judul;
    int durasi;
};

struct Node {
    Film data;
    Node* next;
};
Node*head = nullptr;

// function prototypes
void insertAwal(std::string jud, int dur);
void insertTengah(std::string newJud, int newDur, std::string prevJud);
void insertAkhir(std::string jud, int dur);
void insertEmpty();
void deleteAwal();
void deleteAkhir();
void display();

int main() {
    insertAwal("Merah Putih: One For All", 70);
    insertAkhir("Clockwork Orange", 136);
    insertTengah("Interstellar", 169, "Merah Putih: One For All");
    display(); // menampilkan daftar film setelah penambahan

    deleteAwal();
    deleteAkhir();
    display(); // menampilkan daftar film setelah data dihapus

    return 0;
};

// 1a. Memasukkan data di awal
void insertAwal(std::string jud, int dur){
    Node* nodeBaru = new Node(); // buat node baru
    nodeBaru->data.judul = jud; // isi judul film ke node baru
    nodeBaru->data.durasi = dur; // isi durasi film ke node baru
    nodeBaru->next = head; // menghubungkan node baru ke node yg udah ada (kalo ada)
    head = nodeBaru; // set node baru buat jadi head
    std::cout << "Film " << jud << " berhasil ditambahkan di awal.\n";
}

// 1b. Memasukkan data di tengah
void insertTengah(std::string newJud, int newDur, std::string prevJud){
    Node* temp = head;
    while (temp != nullptr && temp->data.judul != prevJud) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        std::cout << "Film tidak ditemukan.\n";
        return;
    }
    Node* nodeBaru = new Node(); // buat node baru
    nodeBaru->data.judul = newJud; // isi judul film ke node baru
    nodeBaru->data.durasi = newDur; // isi durasi film ke node baru
    nodeBaru->next = temp->next; // menghubungkan node baru ke node setelahnya
    temp->next = nodeBaru; // menghubungkan node sebelumnya ke node baru
    std::cout << "Film " << newJud << " berhasil ditambahkan setelah " << prevJud << ".\n";
}

// 1c. Memasukkan data di akhir
void insertAkhir(std::string jud, int dur){
    Node* nodeBaru = new Node(); // buat node baru
    nodeBaru->data.judul = jud; // isi judul film ke node baru
    nodeBaru->data.durasi = dur; // isi durasi film ke node baru
    nodeBaru->next = nullptr; // node baru bakal jadi node terakhir, jadi next-nya nullptr
    if (head == nullptr) {
        std::cout << "List kosong, menambahkan film sebagai data pertama.\n";
        head = nodeBaru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
}

// 1d. Menambahkan data pada linked list kosong
void insertEmpty(){
    // cek apakah linked list tidak kosong
    if (head != nullptr) {
        std::cout << "List tidak kosong.\n";
        return;
    }
    
    std::string jud;
    int dur;
    std::cout << "Masukkan judul film: ";
    std::getline(std::cin, jud);
    std::cout << "Masukkan durasi film (dalam menit): ";
    std::cin >> dur;

    Node* nodeBaru = new Node(); // buat node baru
    nodeBaru->data.judul = jud; // isi judul film ke node baru
    nodeBaru->data.durasi = dur; // isi durasi film ke node baru
    nodeBaru->next = nullptr; // node baru bakal jadi node terakhir juga, jadi next-nya nullptr
    head = nodeBaru; // set node baru buat jadi head
    std::cout << "Film berhasil ditambahkan sebagai data pertama.\n";
}

// 2a. Menghapus data di awal
void deleteAwal(){
    // cek apakah linked list kosong
    if (head == nullptr) {
        std::cout << "List kosong.\n";
        return;
    }
    Node* temp = head; // simpan node pertama yang akan dihapus
    head = head->next; // set node berikutnya buat jadi head
    delete temp; // hapus node pertama yang lama
    std::cout << "Film pertama berhasil dihapus.\n";
}

// 2b. Menghapus data di akhir
void deleteAkhir(){
    // cek apakah linked list kosong
    if (head == nullptr) {
        std::cout << "List kosong.\n";
        return;
    }
    // cek apakah hanya ada satu node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        std::cout << "Film terakhir berhasil dihapus.\n";
        return;
    }
    Node* temp = head;
    // cari node kedua terakhir
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next; // hapus node terakhir
    temp->next = nullptr; // set node kedua terakhir jadi node terakhir dengan next nullptr
    std::cout << "Film terakhir berhasil dihapus.\n";
}

// menampilkan isi linked list
void display() {
    if (head == nullptr) {
        std::cout << "List kosong.\n";
        return;
    }
    Node* temp = head;
    std::cout << "Daftar Film:\n";
    while (temp != nullptr) {
        std::cout << "- " << temp->data.judul << " (" << temp->data.durasi << " menit)\n";
        temp = temp->next;
    };
    std::cout << "\n";
}