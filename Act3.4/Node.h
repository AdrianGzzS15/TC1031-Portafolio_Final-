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

long Node::getIp(){
  return ip;
}

void Node::setIp(long ip){
  this->ip = ip;
}

Node* Node::getLeft(){
  return left;
}


void Node::setLeft(Node *left){
  this->left=left;
}


Node* Node::getRight(){
  return right;
}


void Node::setRight(Node *right){
  this->right=right;
}