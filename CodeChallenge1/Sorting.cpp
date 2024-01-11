#include <iostream>
#include <fstream>
#include "customErrorClass.h"

using namespace std;

class C_Numbers{
    public:
        
        C_Numbers();
        ~C_Numbers();
        void readFile(char[100]);
        void printArray();
        void sortArray();

    private:
        int *p_numArray;
        int p_arraySize;

        void p_readFile(char[100]);
        void p_printArray();
        void p_sortArray();
};

/*
**    Author: Clayton Buus
**    Function Purpose: 
**        Sets the array to null and the size of the array to zero.
**    Function Output: Nothing
**    Side Effects: p_numArray varaible is set to null and p_arraysize is set to zero.
*/
C_Numbers::C_Numbers(){
    this->p_numArray = NULL;
    this->p_arraySize = 0;
}

/*
**    Author: Clayton Buus 
**    Function Purpose: 
**        This function deletes the elements in p_numArray.
**    Function Output: Nothing
**    Side Effects: The p_numArray elements are deleted.
*/
C_Numbers::~C_Numbers(){
    delete[] this->p_numArray;
}

/*
**    Author: Clayton Buus 
**    Function Purpose: This function calls the private version of the function.
**        
**    Function Output: Nothing 
**    Side Effects: Nothing
*/
void C_Numbers::printArray(){
    if( this->p_numArray == NULL ){
        throw MyException("You forgot to call the readFile function!");
    }
    this->p_printArray();
}

/*
**    Author: Clayton Buus
**    Function Purpose: This function calls the private version of the function.
**        
**    Function Output: Nothing
**    Side Effects: Nothing
*/
void C_Numbers::readFile(char fileName[100]){
    if( fileName == NULL ){
        throw MyException("You forgot to fill the fileName variable with input.dat");
    }
    this->p_readFile(fileName);
}

/*
**    Author: Clayton Buus
**    Function Purpose: This function calls the private version of the function.
**        
**    Function Output: Nothing
**    Side Effects: Nothing
*/
void C_Numbers::sortArray(){
    if( this->p_numArray == NULL ){
        throw MyException("You forgot to call the readFile function!");
    }
    this->p_sortArray();
}

/*
**    Author: Clayton Buus
**    Function Purpose: This function prints out numArray.
**        
**    Function Output: The p_numArray is printed on screen.
**    Side Effects: Nothing
*/
void C_Numbers::p_printArray(){
    int index;
    for(index = 0; index < this->p_arraySize; ++index) {
        cout<<this->p_numArray[index]<<" ";
    }
}

/*
**    Author: Clayton Buus
**    Function Purpose: 
**          This function reads a file and writes the values to the p_numArray.      
**    Function Output: Nothing 
**    Side Effects: The p_numArray is filled with numbers from the input.dat file.
*/
void C_Numbers::p_readFile(char fileName[100]){
    ifstream inpuFile;
    int index = 0;
    inpuFile.open(fileName);
    if( inpuFile.is_open() ){
        inpuFile>>this->p_arraySize;
        this->p_numArray = new int[this->p_arraySize];
        for(index = 0; index < this->p_arraySize; index++){
            inpuFile>>this->p_numArray[index];
        }
        inpuFile.close();
    } else {
        cout<<"File couldn't be opened. Exiting..."<<endl;
    }
}

/*
**    Author: Clayton Buus
**    Function Purpose: 
**        This function uses a bubble sort to sort the numbers in the array.
**    Function Output: Nothing
**    Side Effects: The p_numArray has its elements sorted from least to greatest.
*/
void C_Numbers::p_sortArray(){
    int index, incrementor, temporary;
    for(index = 0; index < this->p_arraySize - 1; index++){
        for(incrementor = 0; incrementor < this->p_arraySize-index-1; incrementor++){
            if(this->p_numArray[incrementor] > this->p_numArray[incrementor+1]){
                temporary = this->p_numArray[incrementor];
                this->p_numArray[incrementor] = p_numArray[incrementor+1];
                this->p_numArray[incrementor+1] = temporary;
            }
        }
    }
}

/*
**    Author: Clayton Buus
**    Function Purpose: 
**        This function declares myClass, fileName, and calls the rest of the functions.
**    Function Output: Prints out exceptions if there is any.
**    Side Effects: This function changed fileName to "input.dat" which is used in other functions.
*/
int main(int argc, char *argv[]){
    C_Numbers myClass;
    char fileName[100] = "input.dat";
    MyException excp("MyError");
    try{
        myClass.readFile(fileName);
    } catch ( MyException &e ){
        cout<<"myexception"<<endl;
        cerr<<e.what()<<endl;
    }
    try{
        myClass.sortArray();
    }
    catch( MyException &e ){
        cout<<"myexception"<<endl;
        cerr<<e.what()<<endl;
    }
    try{
        myClass.printArray();
    } catch( MyException &e ){
        cout<<"myexception"<<endl;
        cerr<<e.what()<<endl;
    }
    return 0;
}