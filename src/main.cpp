#include <iostream>

#include <string>

#include <fstream>
#include <string>
#include <iostream>
#include <exception>
#include <regex>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc > 1) {
        cout << "EDIT " << argv[1] << endl;
        try {
            string line; // declaring string
            fstream myFileIn; // file in stream reading and writing
            ofstream myFileOut; //  file out stream
            myFileIn.open(argv[1], ios::in | ios::out); // original txt file
            // open for writing
            if (myFileIn.is_open()) {
                cout << "File Open" << endl; // confirmation of successful file open
                while (!myFileIn.eof()) { // continue until end of file
                    getline(myFileIn, line);

                    cout << line << endl;


                }

                myFileIn.close(); // closing file in stream

                cout << "File closed" << endl;
            } else {
                cout << "Input file failed to open, making new file" << endl;
                myFileOut.open(argv[1], ios::out);


                myFileOut.close(); // closing file out stream

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


    return 0;
}