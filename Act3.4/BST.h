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

//Crea un nodo vacío como raíz
//Complejidad: (1)
BST::BST(){
  root = nullptr;
}

//Destruye el árbol
//Complejidad: O(n)
BST::~BST(){
  destruye(root);
}

//Destruye el árbol
//Complejidad: O(n)
void BST::destruye(Node *r){
  if (r != nullptr){
    destruye(r->getLeft());
    destruye(r->getRight());
    delete r;
  }
}

//Ingresa un nuevo nodo con el número de accesos y la ip pasados como parametros
//Complejidad: O(n)
void BST::add(int cantAcceso, long ip){
  Node *curr = root;
  Node *father = nullptr;
  while(curr !=nullptr){
    father = curr;
    if (curr->getAcces() > cantAcceso){
      curr = curr->getLeft();
    }
    else if(curr->getAcces() < cantAcceso){
      curr =  curr->getRight();
    }
    else{
      curr = (curr->getIp() < ip) ? curr->getRight() : curr->getLeft();
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
      if(father->getIp() < ip){
        father->setRight(new Node(cantAcceso,ip));
      }
      else{
        father->setLeft(new Node(cantAcceso,ip));
      }
    }
  }
}

//Acomoda los nodos del árbol (sus ip y sus accesos) en inOrder en un queue
//Complejidad: O(n) 
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

//Convierte los ip de string de vuelta a su forma original con "." en medio
//Complejidad: O(1)
string conversion(long ip){
  string conv = "";
  for(int i = 0; i < 3; i++){
    conv = "." + to_string(ip%1000) + conv;
    ip = ip/1000;
  }
  return to_string(ip%1000) + conv;
}

//Imprime los primeros 5 nodos con más accesos
//Complejidad: O(n)
void BST::printCinco(){
  queue<resultado> que;
  inordenC(root, que);
  for(int cont = 1; cont < 6; cont++){
    cout << cont << " " <<conversion(que.front().ip) << " " << que.front().cantAcceso << endl;
    que.pop(); 
  }
}