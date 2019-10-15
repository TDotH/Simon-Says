/*Singly linked list data structure
*   -Holds the list itself
*/

#ifndef LIST_H
#define LIST_H

class list {

  public:

  list();
  ~list();

  void insert( int val );

  int getSize() { return size; };
  int getValAt( int place );

  private:

    struct node;

    //Members
    node * head;
    int size;

    //Functions
    void insert( int val, node *& head );
    void deleteList( node *& head );

    int getValAt( int place, node * head );

};

struct list::node {

  node * next;
  int val;

  node( int x ): val( x ), next( nullptr ) {};

};

#endif
