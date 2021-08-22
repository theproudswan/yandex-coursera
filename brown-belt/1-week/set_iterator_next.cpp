/*
*
* Иногда при запуске падает и выдаёт segmentation fault. 
* ОС: Linux
* З.Ы. Система решение приняла :)
*
*/
#include "test_runner.h"
#include <cassert>
#include <deque>
#include <iostream>

using namespace std;


struct Node {
  Node(int v, Node* p)
    : value(v)
    , parent(p)
  {}

  int value;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent;
};


class NodeBuilder {
public:
  Node* CreateRoot(int value) {
    nodes.emplace_back(value, nullptr);
    return &nodes.back();
  }

  Node* CreateLeftSon(Node* me, int value) {
    assert( me->left == nullptr );
    nodes.emplace_back(value, me);
    me->left = &nodes.back();
    return me->left;
  }

  Node* CreateRightSon(Node* me, int value) {
    assert( me->right == nullptr );
    nodes.emplace_back(value, me);
    me->right = &nodes.back();
    return me->right;
  }

private:
  deque<Node> nodes;
};

// Node* Prev (Node* me){

// }
Node* Next(Node* me) {

    if(me->parent == nullptr && 
       me->left == nullptr &&     // Root only case
       me->right == nullptr) 
        return nullptr;

    if (me->right != nullptr){ // Right son exists case
        //cerr << "#1 case" << endl;
        me = me->right;
        while (me->left != nullptr){
            me = me->left;
        }
        return me;
    } else if (me->right == nullptr && (me == (me->parent)->left)){ // Right son doesn't exist and me is left son of parent node 
        //cerr << "#2 case" << endl;
        return me->parent;
    } else if (me->right == nullptr && (me == (me->parent)->right)){ // Right son doesn't exist and me is right son of parent node 
        //cerr << "#3 case" << endl;
        while ((me->parent)->right == me && me->parent != nullptr){
            me = me->parent;
        }
        return me->parent;
    }
}


void Test1() {
  NodeBuilder nb;

  Node* root = nb.CreateRoot(50);
  ASSERT_EQUAL( root->value, 50 );

  Node* l = nb.CreateLeftSon(root, 2);
  Node* min = nb.CreateLeftSon(l, 1);
  Node* r = nb.CreateRightSon(l, 4);
  ASSERT_EQUAL( min->value, 1);
  ASSERT_EQUAL( r->parent->value, 2 );

  nb.CreateLeftSon(r, 3);
  nb.CreateRightSon(r, 5);

  r = nb.CreateRightSon(root, 100);
  l = nb.CreateLeftSon(r, 90);
  nb.CreateRightSon(r, 101);

  nb.CreateLeftSon(l, 89);
  r = nb.CreateRightSon(l, 91);

  ASSERT_EQUAL( Next(l)->value, 91);
  //cerr << "First assert done" << endl;
  ASSERT_EQUAL( Next(root)->value, 89 );
  //cerr << "Second assert done" << endl;
  ASSERT_EQUAL( Next(min)->value, 2 );
  //cerr << "Third assert done" << endl;
  ASSERT_EQUAL( Next(r)->value, 100);
  //cerr << "Fouth assert done" << endl;
  while (min) {
    cout << min->value << '\n';
    min = Next(min);
  }
}

void TestRootOnly() {
  NodeBuilder nb;
  Node* root = nb.CreateRoot(42);
  ASSERT( Next(root) == nullptr);
};


int main() {
  TestRunner tr;
  RUN_TEST(tr, Test1);
  RUN_TEST(tr, TestRootOnly);
  return 0;
}