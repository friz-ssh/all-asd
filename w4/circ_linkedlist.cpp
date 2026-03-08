#include <iostream>
using namespace std;

// implementasi basic operations pada circular single linked list
struct Node{
    int data;
    Node* next;
};

// 1. INSERT TO EMPTY LIST
// bikin pointer tail untuk nandain data terakhir dari list
Node* insKosong(Node* tail, int isi) {
    Node* nodeBaru = new Node();            // a) bikin nodeBaru & memory allocation
    if (tail != nullptr) {                  // b) cek apakah listnya tidak kosong
        cout << "List tidak kosong!\n";
        return tail;
    } 
    nodeBaru->data = isi;                   // c) mengisi data di nodeBaru 
    tail = nodeBaru;                        // d) set data dari nodeBaru sebagai tail
    tail->next = tail;                      // e) karena isi list cuma ada 1 data, berarti data selanjutnya nunjuk diri sendiri
    return tail;
}

// 2. INSERT TO HEAD OF A LINKED LIST
Node* insHead(Node* tail, int isi) {
    Node* nodeBaru = new Node();            // a) bikin nodeBaru & memory allocation         
    if(tail == nullptr)                     // b) cek apakah list kosong, jika iya bakal dialihkan ke insKosong
        return insKosong(tail, isi);
    nodeBaru->data = isi;                   // c) mengisi data di nodeBaru
    nodeBaru->next = tail->next;            // d) hubungkan nodeBaru ke head yg lama agar urut, sekarang nodeBaru berada di sebelum data head lama
    tail->next = nodeBaru;                  // e) pindahin sambungan tail ke nodeBaru
    return tail;                            // f) tail bakal tetep jadi data terakhir di list
}

// 3. INSERT TO MIDDLE OF A LINKED LIST
Node* insTengah(Node* tail, int isi, int target) {
    if (tail == nullptr)                    // a) cek apakah list kosong
        return nullptr;
    Node* skrg = tail->next;                // b) bikin temporary pointer 'skrg' untuk traverse list dari head
    do {                                    // c) iterasi do while untuk traverse
        if(skrg->data == target) {          // jika data target ditemukan
            Node* nodeBaru = new Node();    // - bikin nodeBaru & memory allocation
            nodeBaru->data = isi;           // - isi nodeBaru dengan data
            nodeBaru->next = skrg->next;    // - sambungkan nodeBaru ke data setelah 'skrg'
            skrg->next = nodeBaru;          // - sambungkan 'skrg' ke nodeBaru
            if (skrg == tail)               // - jika data target ternyata tail dari list, update pointer tail
                tail = nodeBaru;
            return tail;
        }
        skrg = skrg->next;                  // geser 'skrg' ke data setelahnya
    } while (skrg != tail->next);           // d) bakal traverse selama 'skrg' bukan head
    cout << "Target tidak ditemukan\n";     // e) jika target tidak ditemukan, display text
    return tail;
}

// 4. INSERT TO END OF A LINKED LIST
Node* insAkhir(Node* tail, int isi) {
    if (tail == nullptr)                    // a) cek apakah list kosong, jika iya bakal dialihkan ke insKosong
        return insKosong(tail, isi);
    Node* nodeBaru = new Node();            // b) bikin node baru & memory allocation
    nodeBaru->data = isi;                   // c) mengisi nodeBaru dengan data
    nodeBaru->next = tail->next;            // d) sambungkan data next dari nodeBaru ke head (tail->next)
    tail->next = nodeBaru;                  // e) sambungkan tail lama ke nodeBaru
    tail = nodeBaru;                        // f) pindah tail ke nodeBaru (data terakhir)
    return tail;
}

// 5. DELETE THE HEAD NODE
Node* delHead(Node* tail) {
    if (tail == nullptr) return nullptr;    // a) cek apakah list kosong
    Node* headLama = tail->next;            // b) tandai data head lama yang mau dihapus
    if (headLama == tail) {                 // jika list cuma ada 1 data
        delete headLama;                    // - hapus datanya
        return nullptr;                     // - list jadi kosong (null)
    }
    tail->next = headLama->next;            // c) tail nunjuk ke data setelah headLama supaya jadi head baru & urutan baru (kalo nunjuk ke headLama berarti gajadi ngehapus :D)
    delete headLama;                        // d) data headLama dihapus dari memory
    return tail;
}

// 6. DELETE A MIDDLE NODE
Node* delTengah(Node* tail, int target) {
    if (tail == nullptr) return nullptr;    // a) cek apakah list kosong
    Node* skrg = tail->next;                // b) bikin temporary pointer 'skrg' untuk traverse
    Node* sebelum = tail;                   // c) bikin pointer 'sebelum' untuk jaga rantai list
    do {
        if (skrg->data == target) {         // d) jika data target ditemukan
            if (skrg == tail->next)         //    - jika target ternyata ada di head, alihkan ke delHead
                return delHead(tail);
            sebelum->next = skrg->next;     // e) sambungkan data 'sebelum' ke data setelah 'skrg'
            if (skrg == tail)               // f) jika target ternyata tail, pindahkan tail ke 'sebelum'
                tail = sebelum;             // (misal ada 3 data, mau hapus data ke 3 yg merupakan tail, berarti tail harus dipindah ke data sebelumnya supaya aman untuk dihapus)
            delete skrg;                    // g) hapus data target dari memory
            return tail;
        }
        sebelum = skrg;                     // h) pindahkan 'sebelum' ke posisi 'skrg'
        skrg = skrg->next;                  // i) geser 'skrg' ke data selanjutnya
    } while (skrg != tail->next);           // j) traverse sampai kembali ke head
    cout << "Data tidak ditemukan\n";
    return tail;
}

// 7. DELETE THE END (TAIL) NODE
Node* delAkhir(Node* tail) {
    if (tail == nullptr || tail->next == tail)  // a) jika list kosong atau cuma ada 1 data
        return delHead(tail);                   // - kalo kosong tetep null, kalo ada 1 data, hapus data tersebut
    Node* skrg = tail->next;                    // b) bikin temporary pointer 'skrg' untuk cari data sebelum tail
    while (skrg->next != tail) {                // c) geser terus sampai nemu data sebelum tail
        skrg = skrg->next;
    }
    skrg->next = tail->next;                    // d) data sebelum tail sekarang menunjuk ke head (supaya data tail aman untuk dihapus)
    delete tail;                                // e) hapus tail lama
    tail = skrg;                                // f) pindahkan pointer tail ke data sebelumnya
    return tail;
}

// Fungsi untuk menampilkan list
void display(Node* tail) {
    if (tail == nullptr) {
        cout << "List Kosong!\n";
        return;
    }
    Node* skrg = tail->next; // bikin temporary pointer 'skrg' untuk traverse
    do {
        cout << skrg->data << " - ";
        skrg = skrg->next;
    } while (skrg != tail->next); // cetak list
    cout << "(kembali ke " << tail->next->data << ")\n"; // untuk nandain kalo ini circular (kembali ke head)
}

int main() { 
    Node* ekor = nullptr;
    cout << "OPERASI INSERTION CIRCULAR SINGLE LINKED LIST\n";
    cout << "------------------------------------------\n";
    ekor = insKosong(ekor, 3); // list: 3 - (kembali ke 3)
    cout << "1) Setelah insert into empty list: ";
    display(ekor);

    ekor = insHead(ekor, 1); // list: 1 - 3 - (kembali ke 1)
    cout << "2) Setelah insert at head: ";
    display(ekor);

    ekor = insTengah(ekor, 2, 1); // list: 1 - 2 - 3 - (kembali ke 1)
    cout << "3) Setelah insert in middle: ";
    display(ekor);

    ekor = insAkhir(ekor, 4); // list: 1 - 2 - 3 - 4 - (kembali ke 1)
    cout << "4) Setelah insert at end (tail): ";
    display(ekor);

    cout << "\nOPERASI DELETION CIRCULAR SINGLE LINKED LIST\n";
    cout << "------------------------------------------\n";

    ekor = delHead(ekor); // hapus angka 1
    cout << "1) Setelah delete head: ";
    display(ekor);

    ekor = delTengah(ekor, 3); // hapus angka 3
    cout << "2) Setelah delete middle: ";
    display(ekor);

    ekor = delAkhir(ekor); // hapus angka 4
    cout << "3) Setelah delete tail: ";
    display(ekor);
    
    return 0;
}