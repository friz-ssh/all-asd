#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node*head = NULL; // Pointer ke node pertama (head)
void insertAwal(int value);
void insertTengah(Node *current, int value);
void insertAkhir(int value);
void insertKosong();
void deleteAwal();
void deleteAkhir();
void display();
bool search(int value);

int main() {
    insertAwal(8);
    insertAkhir(20);
    insertTengah(head, 13);
    display();

    std::cout << "Apakah terdapat 12? ";
    if (search(12)) 
        std::cout << "Ja.\n";
    else 
        std::cout << "Nein.\n";
        
    deleteAwal();
    deleteAkhir();
    display();
}

// 1a. Memasukkan data di awal
void insertAwal(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;

};
// 1b. Memasukkan data di tengah
void insertTengah(Node *current, int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != current->data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        std::cout << "Node dengan nilai " << current->data << " tidak ditemukan.\n";
        return;
    }
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}
// 1c. Memasukkan data di akhir
void insertAkhir(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
};
// 1d. Memasukkan data pada linked list kosong
void insertKosong() {
    if (head != NULL) {
        std::cout << "List tidak kosong.\n";
        return;
    }
    int value;
    std::cout << "Masukkan nilai untuk node pertama: ";
    std::cin >> value;
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    head = newNode;
};
// 2a. Menghapus data di awal
void deleteAwal() {
    if (head == NULL) {
        std::cout << "List kosong.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
};
void deleteAkhir() {
    if (head == NULL) {
        std::cout << "List kosong.\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
};
// Menampilkan data dalam linked list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}
// Mencari data dalam linked list
bool search(int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
