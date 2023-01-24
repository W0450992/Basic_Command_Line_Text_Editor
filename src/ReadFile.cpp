//
// Created by mark- on 2023-01-22.
//
#include <iostream>

#include <string>

#include <fstream>
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include "ReadFile.h"
#include "LinkedList.h"

using namespace std;

LinkedList ReadFile::readfile(std::string argument, LinkedList linkedList) {
    try {
        string line; // declaring string
        fstream myFileIn; // file in stream reading and writing
        ofstream myFileOut; //  file out stream writing only
        myFileIn.open(argument, ios::in | ios::out); // original txt file
        // open for writing
        if (myFileIn.is_open()) {
            cout << "File Open" << endl; // confirmation of successful file open
            while (!myFileIn.eof()) { // continue until end of file
                getline(myFileIn, line);
                linkedList.add(line);
            }

            myFileIn.close(); // closing file in stream

            cout << "File closed" << endl;
            return linkedList;
        } else {
            cout << "Input file failed to open. Making new file." << endl;
            cout << linkedList << endl;
            return linkedList;
        }
//
    }
//        catch (MyException& e) {
//            cout << e.error() << endl;
//        }
    catch (exception &e) {
        cout << "Generic error" << endl;
    }
    catch (...) {
        cout << "General error" << endl;
    }
}
