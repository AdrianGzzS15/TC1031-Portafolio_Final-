//Emiliano García Aguirre A00827638 
//Jesús Urquídez Calvo A00828368
//Adrian Gonzalez Saldivar A00827845

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "DoubleLinkedList.h"

//Descripcion: Agrega 0 iniciales a cada parte de un ip para tener el mismo tamaño de datos
//Complejidad : O(n)
void ahoraSi(dato &v){
  while(v.ip.length() < 3) v.ip = '0' + v.ip;
  while(v.ip2.length() < 2) v.ip2 = '0' + v.ip2;
  while(v.ip3.length() < 3) v.ip3 = '0' + v.ip3;
  while(v.ip4.length() < 2) v.ip4 = '0' + v.ip4;; 
  v.ipp = stoi(v.ip + v.ip2 + v.ip3);
  v.ipp = v.ipp*1000000 + stoi(v.ip4 + v.ip5);
}

//Descripcion: Agrega 0 iniciales a cada parte del número para tener el mismo tamaño de datos que los ip
//Complejidad : O(n)
long yaSi(string num, string num2, string num3, string num4, string num5){
  long nume;
  while(num.length() < 3) num = '0' + num;
  while(num2.length() < 2) num2= '0' + num2;
  while(num3.length() < 3) num3 = '0' + num3;
  while(num4.length() < 2) num4 = '0' + num4;
  nume = stoi(num + num2 + num3);
  return nume = (nume*1000000 + stoi(num4 + num5));
}

//Descripcion: Separa la variable numero en 5 string y lo manda a yaSi
//Complejidad: O(1)
long convertir(string numero){
  string num, num2, num3, num4, num5;
  stringstream s(numero);
  getline(s, num, '.');//3
  getline(s,num2,'.');//2
  getline(s,num3,'.');//3
  getline(s,num4,':');//2
  getline(s,num5);//4
  return yaSi(num,num2,num3,num4,num5);
}

int main() {
  long n, last, minimo, maximo;
  string mini, maxi;
  char seguir;
  fstream fin;
  dato registro;
  DoubleLinkedList lista;
  string ss;
  fin.open("bitacora.txt",ios::in); 
  // Duración con "datos.txt" (fragmento de bitácora)= instantáneo
  // Duración con "bitacora.txt" = 28 minutos  
  while(!fin.eof()){
    getline(fin,registro.linea);
    stringstream s(registro.linea);
    getline(s,ss,' ');
    getline(s,ss,' ');
    getline(s,ss,' ');
    getline(s,registro.ip, '.');//3
    getline(s,registro.ip2,'.');//2
    getline(s,registro.ip3,'.');//3
    getline(s,registro.ip4,':');//2
    getline(s,registro.ip5,' ');//4
    ahoraSi(registro);
    lista.addFirst(registro);
  }
  lista.burbuja();
  fin.close(); 
  do{
  cout << endl << "Ingresa los valores de búsqueda de ip: ";
  cin >> mini;
  cout << "Ingresa los valores del rango final de ip: ";
  cin >> maxi;
  n = convertir(mini);
  last = convertir(maxi);
  lista.print(n,last); 
  cout << endl << "Desea hacer otra consulta? : Y/N" << endl;
  cin >> (seguir);
  }while((toupper(seguir)) == 'Y'); 
  cout << "Terminado";
}