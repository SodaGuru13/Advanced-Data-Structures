#include "buus_assign2.h"

/*
**  Author: Clayton Buus
**  Function Purpose:
**      Sets the root to null and the amount of nodes in the tree to 0.
**  Function Output: Nothing
**  Side Effects: top pointer is set to null and nodeAmount is set to 0.
*/
DSW::DSW(void){
    this->top = NULL;
    this->nodeAmount = 0;
}

/*
**  Author: Clayton Buus
**  Function Purpose:
**      Calls deleteTree to remove all the nodes recursively from the tree.
**  Function Output: Nothing
**  Side Effects: Nothing
*/
DSW::~DSW(void){
    this->deleteTree(this->top);
}

/*
**  Author: Clayton Buus
**  Function Purpose:
**      Assigns the value to a node as well as makes the pointer on the node point to null and returns it.
**  Function Output: Nothing
**  Side Effects: The pointers of the node are set to null and the value stored on the node is set.
*/
NODE* DSW::createNode(int value){
    NODE *temp = new NODE;

    temp->value = value;
    temp->lchild = NULL;
    temp->rchild = NULL;
    temp->parentNode = NULL;

    return temp;
}

/*
**  Author: Clayton Buus
**  Function Purpose:
**      The purpose is to add a node onto the tree and update the amount of nodes indicated by the counter.
**  Function Output: Nothing
**  Side Effects: A node is added to the tree and nodeAmount gets incremented.
*/
void DSW::insertValue(int value){

    NODE *node = this->createNode(value);
    if( NULL == this->top ) {
        this->top = node;
    } else {
        this->p_insertValue(this->top, node);
    }

    this->nodeAmount++;

    return;

}

/*
**  Author: Clayton Buus
**  Function Purpose:
**      The function moves down the tree and finds the node that has the same value as the amount passed in.
**  Function Output: Nothing
**  Side Effects: Nothing
*/
NODE* DSW::findNode(int amount, NODE *node){
    if( node == NULL )
        return NULL;
    if( amount > node->value && node->rchild != NULL )
        return findNode(amount, node->rchild);
    else if( amount < node->value && node->lchild != NULL )
        return findNode(amount, node->lchild);
    else if( amount == node->value )
        return node;
    else
        return NULL;
}

/*
**  Author: Clayton Buus
**  Function Purpose:
**      The function calls the formatted print or throws an exception.
**  Function Output: Nothing
**  Side Effects: Nothing
*/
void DSW::printTree(){
    if( NULL != this->top ){
        this->p_formattedPrint(this->top, 0);
    } else {
        throw MyException("You forgot to insert values into the tree.");
    }
}

/*
**  Author: Clayton Buus
**  Function Purpose:
**      The function calls createVine and createTree or throws an exception if the top points to null.
**  Function Output: Nothing
**  Side Effects: Nothing
*/
void DSW::sortTree(){
    if( NULL != this->top ){
        p_createVine(this->top);
        p_createTree(this->top);
    } else {
        throw MyException("You forgot to insert values into the tree.");
    }
}

/*
**  Author: Clayton Buus
**  Function Purpose:
**      Throw an exception if the tree is empty or it calls the private version of getHeight.
**  Function Output: Nothing
**  Side Effects: Nothing
*/
int DSW::getHeight(void){
    if( NULL == this->top){
        throw MyException("You forgot to insert values into the tree.");
    } else {
        return this->p_getHeight(this->top);
    }
}

void DSW::deleteTree(NODE *node){
    if( NULL == node ){
        return;
    } else {
        this->deleteTree(node->lchild);
        this->deleteTree(node->rchild);
        delete node;
    }
}

NODE* DSW::p_insertValue(NODE* parent, NODE* nodeToInsert){
    if( NULL == parent){
        return nodeToInsert;
    } else {
        if( nodeToInsert->value < parent->value ){
            parent->lchild = this->p_insertValue(parent->lchild, nodeToInsert);
            parent->lchild->parentNode = parent;
        } else {
            parent->rchild = this->p_insertValue(parent->rchild, nodeToInsert);
            parent->rchild->parentNode = parent;
        }
    }
    return parent;
}

int DSW::p_getHeight(NODE *node){
    if( NULL == node ){
        return 0;
    } else {
        int lHeight = 0;
        int rHeight = 0;
        lHeight = this->p_getHeight(node->lchild);
        rHeight = this->p_getHeight(node->rchild);

        if( lHeight > rHeight ){
            return lHeight+1;
        } else {
            return rHeight+1;
        }
    }
}

void DSW::p_createVine(NODE *node){
    NODE* tmp = node;
    while( tmp != NULL )
    {
        if(tmp->lchild != NULL)
        {
            this->p_rotateRight(tmp->parentNode, tmp, tmp->lchild);
            tmp = tmp->parentNode;
        } else {
            tmp = tmp->rchild;
        }
    }
}

void DSW::p_rotateRight(NODE *gparent, NODE *parent, NODE *child){

    if(gparent != NULL)
    {
        if( gparent->rchild == parent ){
            gparent->rchild = child;
        } else if ( gparent->lchild == parent )
        {
            gparent->lchild = child;
        }
        parent->parentNode = child;
        if( NULL != child->rchild ){
            parent->lchild = child->rchild;
            parent->lchild->parentNode = parent;
        } else {
            parent->lchild = NULL;
        }
        child->parentNode = gparent;
        child->rchild = parent; 
    } else {
        parent->parentNode = child;
        if( NULL != child->rchild ){
            parent->lchild = child->rchild;
            parent->lchild->parentNode = parent;  
        } else {
            parent->lchild = NULL;
        }
        child->parentNode = NULL;
        child->rchild = parent;
        this->top = child;
    }
}

void DSW::p_rotateLeft(NODE *parent, NODE *child, NODE *gchild){
    if(parent != NULL)
    {
        if( parent->rchild == child ){
            parent->rchild = gchild;
        } else if ( parent->lchild == child ) {
            parent->lchild = gchild;
        }
        child->parentNode = gchild;
        if( NULL != gchild->lchild ){
            child->rchild = gchild->lchild;
            child->rchild->parentNode = child;
        } else {
            child->rchild = NULL;
        }
        gchild->parentNode = parent;
        gchild->lchild = child;
    } else {
        child->parentNode = gchild;
        if( NULL != gchild->lchild){
            child->rchild = gchild->lchild;
            child->rchild->parentNode = child;
        } else {
            child->rchild = NULL;
        }
        gchild->parentNode = NULL;
        gchild->lchild = child;
        this->top = gchild;
    }
}

void DSW::p_formattedPrint(NODE *node, int indent){
    if( NULL == node ){
        return;
    } else {
        this->p_formattedPrint(node->lchild, indent+4);
        if( indent ){
            cout<<setw(indent)<<" ";
        }
        cout<<node->value<<endl;
        this->p_formattedPrint(node->rchild, indent+4);
    }
}

void DSW::p_createTree(NODE *node){
    NODE* tmp = node;
    int incrementor;
    int initialRotations = 0;
    int rotations = 0;
    initialRotations = nodeAmount + 1 - pow(2, floor(log2(nodeAmount + 1)));
    for(incrementor = 0; incrementor < initialRotations; ++incrementor){
        this->p_rotateLeft(tmp->parentNode, tmp, tmp->rchild);
        tmp = tmp->parentNode;
        tmp = tmp->rchild;
    }
    rotations = floor((nodeAmount - initialRotations)/2);
    while( rotations >= 1 )
    {
        tmp = this->top;
        for(incrementor = 0; incrementor < rotations; ++incrementor){
            this->p_rotateLeft(tmp->parentNode, tmp, tmp->rchild);
            tmp = tmp->parentNode;
            tmp = tmp->rchild;
        }
        rotations = floor((rotations)/2);
    }
}