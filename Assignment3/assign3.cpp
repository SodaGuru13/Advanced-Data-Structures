#include <iostream>
#include <fstream>
#include <functional>
#include <iomanip>

using namespace std;

void swap(int *array, int valueOne, int valueTwo){
    int temp = 0;
    temp = array[valueOne];
    array[valueOne] = array[valueTwo];
    array[valueTwo] = temp;
}

bool lessThan(int val1, int val2){

    bool retValue = false;

    if( val1 < val2 ){
        retValue = true;
    }

    return retValue;
}

bool greaterThan(int val1, int val2){
    bool retValue = false;

    if( val1 > val2 ){
        retValue = true;
    }

    return retValue;
}

int partition(int *array, int leftSide, int rightSide, function<bool(int,int)>myComp){
    int pivot = 0, i = 0, j = 0;

    pivot = array[rightSide];
    i = leftSide - 1;

    for( j = leftSide; j <= rightSide-1; ++j){
        if( myComp(array[j], pivot) ){
            ++i;
            swap(array, i, j);
        }
    }

    swap(array, i+1, rightSide);

    return i+1;

}

void quickSort(int *array, int leftSide, int rightSide, function<bool(int,int)>compFun){
    
    int location = 0;

    if( leftSide < rightSide ){
        location = partition(array, leftSide, rightSide, compFun);
        quickSort(array, leftSide, location-1, compFun);
        quickSort(array, location+1, rightSide, compFun);
    }
}

int main(int argc, char *argv[]){

    int myArray[2000000];
    int i = 0, temp = 0, j = 0;

    fstream inputNormalFile;
    fstream outputBinaryFile;

    inputNormalFile.open("input.dat", ios::in);
    outputBinaryFile.open("outputBinaryFile", ios::out|ios::binary);

    if( inputNormalFile.is_open() ){
        while ( !inputNormalFile.eof() ){
           inputNormalFile>>myArray[i];
           ++i;
        }
    }

    cout<<"Enter 1 for less than and 2 for greater than"<<endl;
    cin>>temp;

    if( 1 == temp ){
        quickSort(myArray, 0, 1999999, (*lessThan));
    } else {
        quickSort(myArray, 0, 1999999, (*greaterThan));
    }

    for(i = 0; i < 2000000; ++i){
        cout<<setw(3)<<myArray[i]<<" ";
        if( j % 15 == 0){
            cout<<endl;
        }
        ++j;
    }
    outputBinaryFile.write((char*)myArray, sizeof(int)*2000000);

    inputNormalFile.close();
    outputBinaryFile.close();

    return 0;
}
