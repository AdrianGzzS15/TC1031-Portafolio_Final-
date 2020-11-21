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


//Lee el archivo, separa los ips y arcos, llena una lista de adyacencia y imprime aquellos que tienen el fan out más grande
//Complejidad: (V + E)
void fanOut(vector<vector<int>> &listAdj, unordered_map<string, pair<int,int> > &nodos_ips){
  //Declaracion de Variables
  ifstream fin;
  string registro, ss, ip, ipsalida, ipentrada;
  int mayor, n, m;
  pair<int,int> dato_ip;
  
  fin.open("bitacora.txt", ios::in); 
  fin >> n >> m;  
  listAdj.resize(n);
  
  for(int i = 0; i < n; i++){
    fin >> ip;
    dato_ip.first = i; //pair <i, int>
    dato_ip.second = 0; //pair <int, 0>
    nodos_ips[ip] = dato_ip;  //asigna lo que esta en el pair en ip
  }
  
  //Introduce los datos dentro de lista de adyacencia, el contador de fan out y encuentra el mayor de esto
	for (int i = 0; i <= m; i++){
		getline(fin,registro);
    stringstream s(registro);
    getline(s, ss, ' ');
    getline(s, ss, ' ');
    getline(s, ss, ' ');
    getline(s, ipsalida, ':');
    getline(s, ss, ' ');
    getline(s, ipentrada, ':');
    nodos_ips[ipsalida].second++; //contador de fan out incrementa
    listAdj[nodos_ips[ipsalida].first].push_back(nodos_ips[ipentrada].first); //first contiene el ip 
    if (mayor < nodos_ips[ipsalida].second) mayor = nodos_ips[ipsalida].second;
	}
  
  fin.close();

  //Itera a través del mapa e imprime aquellos que tienen el mayor número de fan out
  unordered_map<string,pair<int, int>>::iterator it;
  for (it = nodos_ips.begin(); it != nodos_ips.end(); ++it){
    if ((it -> second).second == mayor){
      cout << "Ip: " << it -> first << endl;
      cout << "Master: " << (it -> second).second <<endl;
    }
  }
}

int main(){
  vector< vector<int> > listAdj;
  unordered_map<string, pair<int, int>> nodos_ips; //pair <indice, outdegree>
  fanOut(listAdj, nodos_ips);
  return 0;
}