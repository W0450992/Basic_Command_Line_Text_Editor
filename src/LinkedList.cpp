//
// Created by mark- on 2023-01-22.
//

#include "LinkedList.h"
void LinkedList::add(int num) {
    // create a new node
    auto node = new LinkedListNode();
    node->m_data = num;


    if (m_start == nullptr) {
        // add the first node to the list
        m_start = node;
    } else {
        //add to the end of the list
        LinkedListNode *current = m_start;
        LinkedListNode *previous = nullptr;

        //look for the end of the chain
        while (current != nullptr) {
            previous = current;
            current = current->m_next;
        }

        //attach the new node
        previous->m_next = node;
    }
    m_size++;
}

void LinkedList::insert(int data, int index) {

    if (index >= m_size) {
        return add(data);
    }

    // create a new node
    auto node = new LinkedListNode();
    node->m_data = data;


    //find the index we are inserting before
    auto current = m_start;
    LinkedListNode *previous = nullptr;

    auto count{1};
    while (current != nullptr) {
        if (count++ == index) {
            break;
        }

        previous = current;
        current = current->m_next;

    }

    // am i inserting at the beginning?
    if (previous == nullptr) {
        //insert at the start of the list
        node->m_next = m_start;
        m_start = node;
    } else {
        // inserting in the middle of the list
        node->m_next = previous->m_next;
        previous->m_next = node;
    }
    m_size++;
}

void LinkedList::remove(int index) {

    //find the node to delete
    auto node = m_start;
    LinkedListNode *prev = nullptr;

    auto count{1};
    while (node != nullptr) {
        // look for the desired index
        if (count++ == index) {
            break;
        }
        prev = node;
        node = node->m_next;
    }
    // did we find the node we are looking for?
    if (node != nullptr) {

        // am i deleting the first node?
        if (prev == nullptr) {
            //first node
            m_start = node->m_next;
        } else {
            //other node
            prev->m_next = node->m_next;
        }

        // finally
        delete node;
    }
    m_size--;
}

std::ostream &operator<<(std::ostream &output, LinkedList &list) {
    auto node = list.m_start;
    while (node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
    return output;
}
