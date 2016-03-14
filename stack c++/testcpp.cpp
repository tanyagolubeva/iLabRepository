#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "stack1.h"
#include <string>
#include <fstream>
using namespace std;
int main(){
//ifstream in( argv[1] );
/*    ofstream of("stackdata2.txt");
    if (!of){
        cout << "error2" << endl;
        system( "pause" ); 
        exit(1);
        }
    of << "adfsgdg\n";
    of << "bhgfhgf\n";
    of << "chghghjj\n";
    of << "dutrjhhh\n";
    of.flush();
    of.close();*/
    ifstream in( "/sdcard/CppDroid/projects/testcpp/stackdata.txt");
    if (!in){
        cout << "error" << endl;
        system( "pause" ); 
        exit(1);
        }
    Stack textlines;
    //textlines.initialize();
    string line;
    while ( getline( in, line ) )
    textlines.push( new string( line ) );
    string* s;
    while ( (s = (string*)textlines.pop() ) != 0 ){
    cout << *s << endl;
    delete s;
    }
    //textlines.cleanup();
    return 0;
}
