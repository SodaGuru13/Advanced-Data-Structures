#include "buus_assign2.h"
int main(int argc, char *argv[]){
    DSW myTree;
    ifstream myFile;

    int input;
    int incrementor = 0;
    int height;

    myFile.open("assign.dat");
    
    if( myFile.is_open() ){
        while ( !myFile.eof() ){
            myFile >> input;
            myTree.insertValue(input);
        }
    }
    try{
        myTree.printTree();
    } catch( MyException &e ){
        cerr<<e.what()<<endl;
    }
    try
    {
        height = myTree.getHeight();
    }
    catch( MyException &e )
    {
        cerr<<e.what()<<endl;
    }
    cout<<"Hieght: "<<height<<endl;
    try{
        myTree.sortTree();
    } catch( MyException &e ){
        cerr<<e.what()<<endl;
    }
    try{  
        myTree.printTree();
    } catch( MyException &e ){
        cerr<<e.what()<<endl;
    }
}