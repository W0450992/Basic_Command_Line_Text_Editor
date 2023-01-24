//
// Created by mark- on 2023-01-22.
//

#include "TextEditor.h"
#include <iostream>
#include <sstream>
#include <string>
#include "LinkedList.h"

//int cursorPosition;
void TextEditor::startTextEditor(LinkedList linkedList) {
    std::string input;
    linkedList.list();
    char command;
    int start, end;
    int cursorPosition = start;
    while(input != "E") {

        start = '\0';
//        if(start != '\0'){
//            std::cout << start << "> ";
//        }

        getline(std::cin, input);

        std::stringstream ss;
        std::stringstream ss2;
        std::stringstream ss3;
        ss << input;
        ss2 << input;
        ss3 << input;




        ss >> command >> start >> end;
        if(!ss){
            // command with start and end not entered
            ss2 >> command >> start;
            if(!ss2){
                // command with start not entered
                ss3 >> command;
                if(!ss3){
                    // no commands entered
                }
                else{
                    // just command is entered
                    if(command == 'L'){
                        linkedList.list();
                    }
                    if(command == 'I'){
                        if(cursorPosition == start){
                            std::string data;
                            getline(std::cin, data);
                            linkedList.insert(data,linkedList.printLastNum());
                        }
                        else{
                            std::string data;
                            std::cout << cursorPosition << "> ";
                            getline(std::cin, data);
                            linkedList.insert(data, cursorPosition);
                        }
                    if(command == 'D'){
                        if(cursorPosition == start){
                            linkedList.remove(linkedList.printLastNum());
                        }
                        else{
                            std::cout << cursorPosition << "> ";
                            linkedList.remove(cursorPosition);
                        }
                    }
                    }
                }
            }
            else{
                // command and index is entered
                cursorPosition = start;
                if(command == 'L') {

                    linkedList.list(start);
                }
                if(command == 'I'){
                    std::string data;
                    getline(std::cin, data);
                    linkedList.insert(data, start);
                }
                if(command == 'D'){
                    linkedList.remove(start);
                }
            }
        }
        else{
            // command with start and end entered
            cursorPosition = start;
            if(command == 'L') {
                linkedList.list(start, end);
            }
            if(command == 'D'){
                linkedList.remove(start,end);
            }
        }

    } //  end while loop

} // end texteditor function

