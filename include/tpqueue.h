// Copyright 2022 NNTU-CS
#ifndef TPQUEUE_H
#define TPQUEUE_H

template <typename T>
class TPQueue {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    TPQueue() : head(nullptr) {}

    ~TPQueue() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(const T& val) {
        Node* newNode = new Node(val);

        if (!head || val.prior > head->data.prior) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && current->next->data.prior >= val.prior) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void pop() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    const T& front() const {
        if (!head) throw std::runtime_error("Queue is empty");
        return head->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

#endif // TPQUEUE_H 
