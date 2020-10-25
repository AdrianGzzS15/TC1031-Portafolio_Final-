//Emiliano García Aguirre A00827638 
//Jesús Urquídez Calvo A00828368
//Adrian Gonzalez Saldivar A00827845

#include <fstream>
#include <sstream>
#include <string>

//meotdo inordenC
using namespace std;

#include "BST.h"

//Descripcion: Agrega 0 iniciales a cada parte de un ip para tener el mismo tamaño de datos
//Complejidad : O(n)
long ipToLong(string ip){
	int idx = 0;
	long datoFinal= 0, dato = 0;
	while (idx < ip.size()){
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
  //long n, last, minimo, maximo;
  int accesos = 0;
  //string mini, maxi;
  queue<long> que;
  char seguir;
  fstream fin;
  string registro;
  long registroLong, registroAnterior;
  BST arbol; 
  string ss;
  fin.open("bitacoraOrdenada.txt",ios::in); 
  while(!fin.eof()){
    getline(fin,registro);
    stringstream s(registro);
    getline(s,ss,' ');
    getline(s,ss,' ');
    getline(s,ss,' ');
    getline(s,registro,':');
   //getline(s,ss,'.');
   // getline(s,registro,':');//2
    registroLong = ipToLong(registro);
    if (registroLong == registroAnterior){ //comparar el nuevo con el anterior
      accesos++;
    }
    else{
      arbol.add(accesos, registroLong);
      registroAnterior = registroLong;
      accesos = 0;
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