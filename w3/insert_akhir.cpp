#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAkhir(int val) {
    Node* nodeBaru = new Node();
    nodeBaru->data = val;
    nodeBaru->next = nullptr;

    if (head == nullptr) {
        head = nodeBaru;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nodeBaru;
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
    std::cout << "Hasil insert akhir:\n";
    display();
    return 0;
}