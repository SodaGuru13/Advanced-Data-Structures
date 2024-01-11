#include <iostream>
#include <time.h>
#include <math.h>
#include <fstream>
#include <iomanip>
#include "customErrorClass.h"

using namespace std;

struct NODE{
    int value;
    NODE* lchild;
    NODE* rchild;
    NODE* parentNode;
};

class DSW
{
    public:
        DSW();
        ~DSW();
        NODE* createNode(int);
        void insertValue(int);
        NODE* findNode(int, NODE*);
        void printTree();
        void sortTree();
        int getHeight();
        void deleteTree(NODE*);
    private:
        NODE *top;
        int nodeAmount;
        NODE* p_insertValue(NODE*, NODE*);
        int p_getHeight(NODE*);
        void p_createVine(NODE*);
        void p_rotateRight(NODE*, NODE*, NODE*);
        void p_rotateLeft(NODE*, NODE*, NODE*);
        void p_createTree(NODE*);
        void p_formattedPrint(NODE*, int);
};