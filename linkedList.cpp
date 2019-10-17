#include "linkedList.h"

//Constructor
list::list() {

    head = nullptr;
    size = 0;
}

//Destructor
list::~list() {

    deleteList( head );
}

/* Insert ( public )
*  Param: val to be inserted
*/

void list::insert( int val ) {

    insert( val, head );
    return;
}

/* Insert ( private )
*  Param: val to be inserted, a node
*/

void list::insert( int val, node *& head ) {

    if ( head ) {

        insert( val, head->next );
    } else {

        node * aNode = new node( val );
        head = aNode;
        size++;
    }
    return;
}

/* getValAt ( public )
*   -Param:  which node val to be returned
*   -Return: node val
*/

int list::getValAt( int place ) {

    int returnVal = getValAt( place, head );
    return returnVal;
}

/* getValAt ( private )
*   -Param:  which node val to be returned, a node
*   -Return: node val
*/
int list::getValAt( int place, node * head ) {

    int returnVal = 0;

    //Found the node and node exists
    if ( ( place == 1 ) && head ) {

        returnVal = head->val;
    } else {

        returnVal = getValAt( place - 1, head->next );
    }

    return returnVal;
}

/* deleteList ( private )
*   -Param: a node
*/

void list::deleteList( node *& head ) {

    if ( head ) {

        node * temp = head->next;
        delete head;
        head = nullptr;
        deleteList( temp );
    }

    return;
}
