//Emiliano García Aguirre A00827638 
//Jesús Urquídez Calvo A00828368
//Adrian Gonzalez Saldivar A00827845

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//Recopila la información de acceso de las direcciones en un unordered_map
//Complejidad: O(n)
void accesos(unordered_map<string, pair<int, vector<string>>> &nodos_ips){
  ifstream fin;
  char seguir;
  string registro, ss, ip, descripcion, ipentrada;
  fin.open("bitacora.txt", ios::in); 
  // almacena la bitacora 
  while(!fin.eof()){
		getline(fin,registro);
    stringstream s(registro);
    getline(s, descripcion, ' ');
    getline(s, ss, ' ');
    descripcion = descripcion + " " + ss;
    getline(s, ss, ' ');
    descripcion = descripcion + " " + ss;
    getline(s, ipentrada, ':');
    getline(s, ss, ' ');
    getline(s, ss, '\n');
    descripcion = descripcion + " " + ss;
    if(nodos_ips[ipentrada].second.empty()){
      nodos_ips[ipentrada].first = 0;
    }
    nodos_ips[ipentrada].first++; 
    nodos_ips[ipentrada].second.push_back(descripcion);
	}
  
  fin.close();

  //Ciclo de consultas
  do{ 
    cout << "Introduce la ip: ";
    cin >> ip;
    cout << "entradas: " <<nodos_ips[ip].first << endl;
    cout << "descripciones: " << endl;
    for(int i = 0; i < nodos_ips[ip].second.size(); i++){
      cout << nodos_ips[ip].second[i] << endl;
    }
    cout << "Quieres seguir Y/N: ";
    cin >> seguir;
  }while((toupper(seguir)) == 'Y'); 
  cout << "Terminado";
}

int main(){
  unordered_map<string, pair<int, vector<string>>> nodos_ips;
  accesos(nodos_ips);
  return 0;
}