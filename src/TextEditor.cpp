//
// Created by mark- on 2023-01-22.
//

#include "TextEditor.h"
#include <iostream>
#include <sstream>
#include <string>
#include "LinkedList.h"

//int cursorPosition;
LinkedList TextEditor::startTextEditor(LinkedList linkedList) {
    std::string input;
    linkedList.list();
    char command;
    int start, end;
    int cursorPosition;
    int count = 0;
    while (input != "E") {
        start = '\0';

        if (count == 0) {

            cursorPosition = linkedList.printLastNum();
            std::cout << cursorPosition << "> ";
        }
        getline(std::cin, input);

        std::stringstream ss;
        std::stringstream ss2;
        std::stringstream ss3;
        ss << input;
        ss2 << input;
        ss3 << input;

        ss >> command >> start >> end;
        if (!ss) {
            // command with start and end not entered
            ss2 >> command >> start;
            if (!ss2) {
                // command with start not entered
                ss3 >> command;
                if (!ss3) {
                    // no commands entered
                } else {

                    // just command is entered
                    if (command == 'L') {
                        if (count == 0) {
                            cursorPosition = linkedList.printLastNum();
                        }
                        linkedList.list();
                    }
                    if (command == 'I') {
                        if (count == 0) {
                            std::string data;
                            getline(std::cin, data);
                            linkedList.insert(data, linkedList.printLastNum());
                            cursorPosition = linkedList.printLastNum();
                        } else {
                            std::string data;
                            getline(std::cin, data);
                            std::cout << cursorPosition << "> ";
                            linkedList.insert(data, cursorPosition);
                        }
                    }
                    if (command == 'D') {
                        if (count == 0) {
                            linkedList.remove(linkedList.printLastNum());
                            cursorPosition = linkedList.printLastNum();
                        } else {

                            linkedList.remove(cursorPosition);
                        }
                    }
                }
            } else {
                // command and index is entered
                cursorPosition = start;
                if (command == 'L') {

                    linkedList.list(start);
                }
                if (command == 'I') {
                    std::string data;
                    std::cout << cursorPosition << "> ";
                    getline(std::cin, data);
                    linkedList.insert(data, start);
                }
                if (command == 'D') {
                    linkedList.remove(start);
                }
            }
        } else {
            // command with start and end entered
            cursorPosition = start;
            if (command == 'L') {
                cursorPosition = start;
                linkedList.list(start, end);
            }
            if (command == 'D') {
                cursorPosition = start;
                linkedList.remove(start, end);
            }
        }
        count++;
        if (count == 0) {
            cursorPosition = linkedList.printLastNum();
        } else {
            std::cout << "\n" << cursorPosition << "> ";
        }
    } //  end while loop

    return linkedList;
} // end texteditor function

