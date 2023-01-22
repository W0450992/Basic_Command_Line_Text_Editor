//
// Created by mark- on 2023-01-22.
//

#ifndef ASSIGNMENT1_LINKEDLIST_H
#define ASSIGNMENT1_LINKEDLIST_H
#include "LinkedListNode.h"
#include "iostream"


class LinkedList {
private:
    LinkedListNode *m_start{nullptr};
    int m_size{0};
public:
    LinkedList() {

    }
    void add(int num);
    void insert(int data, int index);
    void remove(int index);
    friend std::ostream &operator<<(std::ostream &output, LinkedList &list);
};


#endif //ASSIGNMENT1_LINKEDLIST_H
