//Emiliano García Aguirre A00827638 
//Jesús Urquídez Calvo A00828368
//Adrian Gonzalez Saldivar A00827845

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#include "BST.h"

//Descripcion: Agrega 0 iniciales a cada parte de un ip para tener el mismo tamaño de datos
//Complejidad : O(n)
long ipToLong(string ip){
	int idx = 0;
	long datoFinal= 0, dato = 0;
	while (idx < ip.size()){  //10.15.170.220
		if (ip[idx]!= '.'){
			dato = dato*10 + ip[idx]-'0';
		}
		else{
			datoFinal = datoFinal*1000 + dato;
			dato = 0;
		}
		idx++;
	}
	datoFinal = datoFinal*1000 + dato;
	return datoFinal;
}

int main() {
  int accesos = 1;
  queue<long> que;
  char seguir;
  fstream fin;
  string registro, ss;
  long registroLong, registroAnterior;
  BST arbol; 
  fin.open("bitacoraOrdenada.txt",ios::in); 
  while(!fin.eof()){
    getline(fin,registro);
    stringstream s(registro);
    getline(s,ss,' ');
    getline(s,ss,' ');
    getline(s,ss,' ');
    getline(s,registro,':');
    registroLong = ipToLong(registro);
    if (registroLong == registroAnterior){ //comparar el nuevo con el anterior
      accesos++;
    }
    else{
      arbol.add(accesos, registroAnterior);
      registroAnterior = registroLong;
      accesos = 1;
    }
  }
  fin.close(); 
  arbol.printCinco();
  
  do{
  cout << endl << "Desea hacer otra consulta? : Y/N" << endl;
  cin >> (seguir);
  }while((toupper(seguir)) == 'Y'); 
  cout << "Terminado";
}