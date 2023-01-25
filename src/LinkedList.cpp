//
// Created by mark- on 2023-01-22.
//

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>

LinkedList::LinkedList() {
    LinkedListNode *m_start{nullptr};
    int m_size{0};
}

//LinkedList::~LinkedList() {
//    auto node = m_start;
//    while (node != nullptr) {
//        auto temp = node;
//        node = node->m_next;
//        delete temp;
//    }
//}

void LinkedList::add(std::string data) {
    // create a new node
    auto node = new LinkedListNode();
    node->m_data = data;
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

void LinkedList::insert(std::string data, int index) {

    if (index > m_size) {
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

void LinkedList::remove(int start, int end) {
    for (int i = start; i <= end; i++) {
        remove(start);
    }
}

//void LinkedList::remove(int start, int end) {
//    auto node = m_start;
//    LinkedListNode *prev = nullptr;
//    int fromStart = start;
//    int lineCounter = 1;
//    while (node != nullptr) {
//        if (lineCounter >= fromStart && lineCounter <= end) {
//            fromStart++;
//            if (node != nullptr) {
//
//                // am i deleting the first node?
//                if (prev == nullptr) {
//                    //first node
//                    m_start = node->m_next;
//                } else {
//                    //other node
//                    prev->m_next = node->m_next;
//                }
//                // finally
//                delete node;
//            }
//            m_size--;
//        }
//
//        prev = node;
//        node = node->m_next;
//        if (lineCounter == end + 1) {
//            break;
//        }
//        lineCounter++;
//    }
////    while (node != nullptr) {
////        while (lineCounter >= start && lineCounter <= end) {
////            // look for the desired index
////            if (lineCounter == start) {
////                fromStart++;
////                break;
////            }
////            prev = node;
////            node = node->m_next;
////            lineCounter++;
////        }
////        // did we find the node we are looking for?
////        if (node != nullptr) {
////
////            // am i deleting the first node?
////            if (prev == nullptr) {
////                //first node
////                m_start = node->m_next;
////            } else {
////                //other node
////                prev->m_next = node->m_next;
////            }
////
////            // finally
////            delete node;
////        }
////    }
////    m_size--;
//}

void LinkedList::list() {
    auto node = m_start;
    LinkedListNode *prev = nullptr;
    auto counter = 1;
    while (node != nullptr) {
        std::cout << counter << "> " << node->m_data << " " << "\n";
        node = node->m_next;
        counter++;
        if (node == nullptr) {
            break;
        }
    }
}

void LinkedList::list(int index) {

    auto node = m_start;
    LinkedListNode *prev = nullptr;
    int lineCounter = 1;
    while (node != nullptr) {
        if (lineCounter == index) {
            std::cout << index << "> " << node->m_data << " " << "\n";
        }
        node = node->m_next;
        if (lineCounter == index) {
            break;
        }
        lineCounter++;
    }
}

void LinkedList::list(int start, int end) {


    auto node = m_start;
    int counter2 = start;
    int lineCounter = 1;
    while (node != nullptr) {
        if (lineCounter >= counter2 && lineCounter <= end) {
            std::cout << counter2 << "> " << node->m_data << " " << "\n";
            counter2++;
        }
        node = node->m_next;
        lineCounter++;

        if (lineCounter == end + 1) {
            break;
        }
    }
}


std::ostream &operator<<(std::ostream &output, LinkedList &list) {
    auto node = list.m_start;
    std::ofstream myFileOut;
    myFileOut.open("test.txt", std::ios::out);
    while (node != nullptr) {
        output << node->m_data << " " << "\n";
        myFileOut << node->m_data << " " << "\n";
        node = node->m_next;
    }
    //myFileOut << list;
    myFileOut.close();
    return output;
}


int LinkedList::printLastNum() {
    auto node = m_start;
    LinkedListNode *prev = nullptr;
    auto counter = 1;
    while (node != nullptr) {
        node = node->m_next;
        counter++;
        if (node == nullptr) {
//            std::cout << counter << "> ";
            break;
        }
    }
    return counter;
}





