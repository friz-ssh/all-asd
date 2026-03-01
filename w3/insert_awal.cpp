#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAwal(int val) {
    Node* nodeBaru = new Node();
    nodeBaru->data = val; // isi data baru ke node baru
    nodeBaru->next = head; // menghubungkan node baru ke node yg udah ada (kalo ada)
    head = nodeBaru; // set node baru buat jadi head
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
    // panggil berkali-kali buat insert data di awal
    insertAwal(76);
    insertAwal(65);
    insertAwal(54);
    std::cout << "Hasil insert awal:\n"; // outputnya 54, 65, 76, NULL
    display();
    return 0;
}