#ifndef TLIST_H
#define TLIST_H

template <typename T>
class TList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t _size;

public:
    TList() : head(nullptr), tail(nullptr), _size(0) {}
    ~TList();

    void push_back(const T& data);
    void remove(const T& data);
    T* find(const T& data);
    size_t size() const;
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
    _size++;
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
            _size--;
            return;
        }
        prev = current;
        current = current->next;
    }
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

template <typename T>
size_t TList<T>::size() const {
    return _size;
}

#endif // TLIST_H