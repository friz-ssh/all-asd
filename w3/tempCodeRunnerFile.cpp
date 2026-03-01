#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// fungsi bantuan untuk bikin list awalnya
void buatList(int val) {
    Node* nodeBaru = new Node();
    nodeBaru->data = val;
    nodeBaru->next = nullptr;
    if (head == nullptr) { head = nodeBaru; return; }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = nodeBaru;
}

void insertTengah(int target, int valBaru) {
    Node* temp = head;
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }
    // cek apakah angka target ditemukan
    if (temp == nullptr) {
        std::cout << "Angka tidak ditemukan!\n";
        return;
    }
    Node* nodeBaru = new Node();
    nodeBaru->data = valBaru; // isi data baru ke node baru
    nodeBaru->next = temp->next; // hubungkan node baru ke node setelahnya
    temp->next = nodeBaru; // hubungkan node sebelumnya ke node baru
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
    // bikin list awal dulu: 10 -> 30
    buatList(67);
    buatList(78);
    std::cout << "List Awal:\n"; display();
    
    // Sisipkan 70 setelah angka 67
    insertTengah(67, 70);
    std::cout << "Setelah insert tengah:\n"; display(); 
    return 0;
}