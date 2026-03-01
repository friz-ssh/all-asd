#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAkhir(int val) {
    Node* nodeBaru = new Node();
    nodeBaru->data = val; // isi data baru ke node baru
    nodeBaru->next = nullptr; // node baru bakal jadi node terakhir, jadi next-nya null
    // cek apakah list kosong
    if (head == nullptr) {
        head = nodeBaru;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nodeBaru; // hubungkan node terakhir yang lama ke node baru
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << ", ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

int main() {
    // panggil berkali-kali buat insert data di akhir
    insertAkhir(76);
    insertAkhir(65);
    insertAkhir(54);
    std::cout << "Hasil insert akhir:\n"; // outputnya 76, 65, 54, NULL
    display();
    return 0;
}