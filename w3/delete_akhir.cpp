#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;
// fungsi insert buat bikin list awalnya (pake logika insert akhir)
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

void deleteAkhir() {
    if (head == nullptr) return; // cek apakah list kosong
    // cek apakah hanya ada satu node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next; // hapus node terakhir
    temp->next = nullptr; // set node kedua terakhir jadi node terakhir
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
    buatList(76); buatList(65); buatList(54);
    std::cout << "Sebelum delete akhir:\n"; display();
    
    deleteAkhir();
    std::cout << "Setelah delete akhir:\n"; display(); // bakal ngehapus angka 54
    return 0;
}