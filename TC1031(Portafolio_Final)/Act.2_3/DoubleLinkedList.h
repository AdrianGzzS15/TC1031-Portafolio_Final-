#include "Node.h"
#include <iostream>
#include <fstream>

class DoubleLinkedList{
  private:
    Node *head, *tail; 
    int size = 0;
  public:
    DoubleLinkedList();
    ~DoubleLinkedList();
    void addFirst(dato data);
    void print(long, long);
    void burbuja();
};

//Descripcion : Constructor de la lista encadenada, inicializa los valores de una lista vacía
//Complejidad : O(1)
DoubleLinkedList::DoubleLinkedList(){
  size = 0;
  head = nullptr;
  tail = nullptr;
}

//Descripcion : Destructor de la lista encadenada, elimina todos los nodos
//Complejidad : O(1)
DoubleLinkedList::~DoubleLinkedList(){
  Node *curr = head;
  while (head != nullptr){
    head = head->getNext();
    delete curr;
    curr = head;
  }
  size = 0;
}

//Descripcion : Agrega un nuevo nodo al inicio de la lista con la información deseada
//Complejidad : O(1)
void DoubleLinkedList::addFirst(dato data){
  if(size == 0){
      head = new Node(data, nullptr, nullptr); 
      tail = new Node(data, nullptr, nullptr);
  }
  else if(size == 1){
    head = new Node(data, nullptr, head);
    tail -> setPrev(head);
    }
  else{
    Node *curr = new Node(data, nullptr, head);
    head -> setPrev(curr);
    head = curr;
  }
  size++;
}

//Descripcion : Imprime en la consola los datos dentro del rango deseado
//Complejidad : O(n)
void DoubleLinkedList::print(long min, long max){
  cout << "Ingresa el nombre del archivo: ";
  ofstream archivo;
  string titulo;
  cin >> titulo;
  archivo.open(titulo, ios::trunc); 
  Node *curr = head;
  while(curr != nullptr){
    if(curr->getData().ipp >= min && curr->getData().ipp <= max){
      cout << (curr->getData()).linea << endl;
      archivo << (curr->getData()).linea << endl;
    }
    curr = curr->getNext();
  }
  archivo.close();
}

//Descripcion : Ordena los datos de menor a mayor
//Complejidad : O(n^2)
void DoubleLinkedList::burbuja(){
  bool interruptor = true;
  dato tmp;
  Node *curr = head;
  for (int i=0; i<size-1 && interruptor; i++) {
    interruptor = false; // no se han hecho intercambios
    curr = head;
    for (int j=0; j<size-1-i; j++){
      if ((curr->getNext())->getData().ipp < curr->getData().ipp){
        tmp = curr->getData();
        curr -> setData((curr->getNext())->getData());
        (curr->getNext()) -> setData(tmp);
        interruptor = true;
      }
      curr = curr->getNext();
    }
  }
}