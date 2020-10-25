#include <iostream>
#include <algorithm>
#include <queue>

using namespace std; 

#include "Node.h"

struct resultado{
  long ip;
  int cantAcceso;
};

class BST{
  public:
    BST();
    ~BST();
    void add(int cantAcceso, long ip);
    void printCinco();
  private:
    Node *root;
    void destruye(Node *r);
    void inordenC(Node *r,queue<resultado> &q);
};

BST::BST(){
  root = nullptr;
}

BST::~BST(){
  destruye(root);
}

//Complejidad: O(n)
void BST::destruye(Node *r){
  if (r != nullptr){
    destruye(r->getLeft());
    destruye(r->getRight());
    delete r;
  }
}


//Complejidad: O(altura del arbol)
void BST::add(int cantAcceso, long ip){
  Node *curr = root;
  Node *father = nullptr;
  while(curr !=nullptr){
    //curr = (curr->getAcceso() > cantAcceso) ? curr->getLeft() : curr->getRight();
    father = curr;
    if (curr->getAcces() > cantAcceso){
      curr = curr->getLeft();
    }
    else if(curr->getAcces() < cantAcceso){
      curr =  curr->getRight();
    }
    else{
      curr = (curr->getIp() > ip) ? curr->getRight() : curr->getLeft();
    }
  }
  if(father == nullptr){
    root = new Node(cantAcceso, ip);
  }
  else{
    if(father->getAcces() > cantAcceso){
      father->setLeft(new Node(cantAcceso,ip));
    }
    else if(father->getAcces() < cantAcceso){
      father->setRight(new Node(cantAcceso,ip));
    }
    else{
      if(father->getIp() > ip){
        father->setRight(new Node(cantAcceso,ip));
      }
      else{
        father->setLeft(new Node(cantAcceso,ip));
      }
    }
  }
}



void BST::inordenC(Node *r, queue<resultado> &q){
  if(r !=nullptr){
    inordenC(r->getRight(),q);
    resultado salida;
    salida.cantAcceso = r->getAcces();
    salida.ip = r->getIp();
    q.push(salida);
    inordenC(r->getLeft(), q);
  }
}

string conversion(long ip){
  string conv = "";
  for(int i = 0; i < 3; i++){
    conv = "." + to_string(ip%1000) + conv;
    ip = ip/1000;
  }
  return to_string(ip%1000) + conv;
}

void BST::printCinco(){
  queue<resultado> que;
  inordenC(root, que);
  for(int cont = 1; cont < 6; cont++){
    cout << cont << " " <<conversion(que.front().ip) << " " << que.front().cantAcceso << endl;
    que.pop(); 
  }
}



