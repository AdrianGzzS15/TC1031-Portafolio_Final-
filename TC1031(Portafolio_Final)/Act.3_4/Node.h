using namespace std;

class Node{
private:
  Node *left; 
  Node *right;
  long ip;
  int cantAcceso;
public: 
  Node(int cantAcceso, long ip, Node *left, Node *right);
  Node(int cantAcceso, long ip);

  //Sets
  void setIp(long ip);
  void setAcces(int cantAcceso);
  void setLeft(Node *left);
  void setRight(Node *right);

  //Gets
  int getAcces();
  long getIp();
  Node* getLeft();
  Node* getRight();

};

//Descripcion : Constructor de Nodo sin parámetros
//Complejidad : O(1)
Node::Node(int cantAcceso, long ip){
  this->cantAcceso = cantAcceso;
  this->ip = ip;
  this->left = nullptr;
  this->right = nullptr;
}

//Descripcion : Constructor de nodo con left y right
//Complejidad : O(1)
Node::Node(int cantAcceso, long ip, Node* left, Node* right){
  this->cantAcceso = cantAcceso;
  this->ip = ip;
  this->left = left;
  this->right = right;
}

//Descripcion : Regresa el atributo data de un nodo
//Complejidad : O(1)
int Node::getAcces(){
  return cantAcceso;
}

//Descripcion : Cambia el atributo data de un nodo por el valor asignado
//Complejidad : O(1)
void Node::setAcces(int cantAcceso){
  this->cantAcceso = cantAcceso;
}

//Descripcion : Regresa el atributo ip de un nodo
//Complejidad : O(1)
long Node::getIp(){
  return ip;
}

//Descripcion : Cambia el atributo ip de un nodo por el valor asignado
//Complejidad : O(1)
void Node::setIp(long ip){
  this->ip = ip;
}

//Descripcion : Regresa el hijo izquierdo de un nodo
//Complejidad : O(1)
Node* Node::getLeft(){
  return left;
}

//Descripcion : Cambia el hijo izquierdo de un nodo por el asignado
//Complejidad : O(1)
void Node::setLeft(Node *left){
  this->left=left;
}

//Descripcion : Regresa el hijo derecho de un nodo
//Complejidad : O(1)
Node* Node::getRight(){
  return right;
}

//Descripcion : Cambia el hijo derecho de un nodo por el asignado
//Complejidad : O(1)
void Node::setRight(Node *right){
  this->right=right;
}