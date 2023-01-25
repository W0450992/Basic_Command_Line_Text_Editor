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
    LinkedList();
    //virtual ~LinkedList();

    void add(std::string data);
    void insert(std::string data, int index);
    void remove(int index);
    void remove(int start, int end);
    void list();
    void list(int lineNum);
    void list(int start, int end);
    int printLastNum();
    friend std::ostream &operator<<(std::ostream &output, LinkedList &list);
};


#endif //ASSIGNMENT1_LINKEDLIST_H
