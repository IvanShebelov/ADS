#ifndef TLIST_H
#define TLIST_H

template <typename T>
class TList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    TList() : head(nullptr), tail(nullptr), size(0) {}
    ~TList();

    void push_back(const T& data);
    void remove(const T& data);
    bool contains(const T& data) const;
    size_t getSize() const;
    T* find(const T& data);
};

template <typename T>
TList<T>::~TList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void TList<T>::push_back(const T& data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
void TList<T>::remove(const T& data) {
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->data == data) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                head = current->next;
            }
            if (current == tail) {
                tail = prev;
            }
            delete current;
            size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

template <typename T>
bool TList<T>::contains(const T& data) const {
    Node* current = head;
    while (current) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
size_t TList<T>::getSize() const {
    return size;
}

template <typename T>
T* TList<T>::find(const T& data) {
    Node* current = head;
    while (current) {
        if (current->data == data) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

#endif // TLIST_H