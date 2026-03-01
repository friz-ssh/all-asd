#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertEmpty(int val) {
    // cek apakah list tidak kosong
    if (head != nullptr) {
        std::cout << "List tidak kosong!\n";
        return;
    }
    Node* nodeBaru = new Node();
    nodeBaru->data = val; // isi data baru ke node baru
    nodeBaru->next = nullptr; // node baru bakal jadi node terakhir juga, jadi next-nya null
    head = nodeBaru;
    std::cout << "Berhasil insert ke empty list: " << val << "\n";
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
    insertEmpty(67);
    display(); // outputnya 67, NULL
    return 0;
}