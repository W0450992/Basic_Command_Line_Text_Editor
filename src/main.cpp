#include <iostream>

#include <string>

#include <fstream>
#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>
#include "LinkedList.h"
#include "ReadFile.h"
#include "TextEditor.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc == 2) {
        LinkedList linkedList;
        TextEditor textEditor;

        linkedList =  ReadFile::readfile(argv[1],linkedList);
        // function call to text editor goes here
        textEditor.startTextEditor(linkedList);
        cout << linkedList << endl;
    }
    else{
        cout << "Check Command Line Arguments" << endl;
    }


    return 0;
}