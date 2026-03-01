#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;
// fungsi bantuan untuk bikin list awalnya (pake logika insert akhir)
void buatList(int val) {
    Node* nodeBaru = new Node();
    nodeBaru->data = val;
    nodeBaru->next = nullptr;
    if (head == nullptr){
        head = nodeBaru;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = nodeBaru;
}

void deleteAwal() {
    if (head == nullptr) return; // cek apakah list kosong
    Node* temp = head;
    head = head->next; // set node berikutnya buat jadi head
    delete temp; // hapus node pertama yang lama
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
    // bikin list awal dulu
    buatList(12); buatList(23); buatList(34);
    std::cout << "Sebelum delete awal:\n"; display();
    
    deleteAwal();
    std::cout << "Setelah delete awal:\n"; display(); // bakal ngehapus angka 12
    return 0;
}