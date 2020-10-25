using namespace std;

struct dato{
  int key;
  string linea;
  string ip;
  string ip2;
  string ip3;
  string ip4;
  string ip5;
  long ipp;
}; 

class Node{
private:
  dato data;
  Node *prev; 
  Node *next;
public: 
  Node(dato data);
  Node(dato data, Node* prev, Node* next);
  dato getData();
  void setData(dato data);
  Node* getPrev();
  void setPrev(Node* data);
  Node* getNext();
  void setNext(Node* data);
  
};

//Descripcion : Constructor de Nodo sin parámetros
//Complejidad : O(1)
Node::Node(dato data){
  this->data = data;
  this->next = nullptr;
  this->prev = nullptr;
}

//Descripcion : Constructor de nodo con next y previo
//Complejidad : O(1)
Node::Node(dato data, Node* prev, Node* next){
  this->data = data;
  this->prev = prev;
  this->next = next;
}

//Descripcion : Regresa el atributo data de un nodo
//Complejidad : O(1)
dato Node::getData(){
  return data;
}

//Descripcion : Regresa el apuntador prev de un nodo 
//Complejidad : O(1)
Node* Node::getPrev(){
  return prev;
}

//Descripcion : Regresa el apuntador prev de un nodo 
//Complejidad : O(1)
Node* Node::getNext(){
  return next;
}

//Descripcion : Cambia el atributo data de un nodo por el valor asignado
//Complejidad : O(1)
void Node::setData(dato data){
  this->data = data;
}

//Descripcion : Cambia el apuntador prev de un nodo por la dirección asignada
//Complejidad : O(1)
void Node::setPrev(Node* prev){
  this->prev = prev;
}

//Descripcion : Cambia el apuntador next de un nodo por la dirección asignada
//Complejidad : O(1)
void Node::setNext(Node* next){
  this->next = next;
}