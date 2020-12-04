#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

//Emiliano García Aguirre A00827638 
//Jesús Urquídez Calvo A00828368
//Adrian Gonzalez Saldivar A00827845


using namespace std;

struct dato{
  int key;
  string mes;
  string dia;
  string hora;
  string fecha;
}; 


//Función parte de Quick Sort
//Complejidad: O(n)
void particion(vector<dato> &vec, int ini, int fin, int &pivote){
  int elempivote = vec[ini].key, j = ini;
  dato temp;
  for (int i=ini+1; i<=fin; i++){
    if (vec[i].key < elempivote){
      j++;
      temp = vec[i];
      vec[i] = vec[j];
      vec[j] = temp;
    }
  }
  pivote = j;
  temp = vec[ini];
  vec[ini] = vec[j];
  vec[pivote] = temp;
}

//Descripcion : Ordena el arreglo de datos
//Complejidad peor caso: O(n^2) 
//Complejidad mejor caso: O(nlogn)
void Quick(int primero, int ultimo, vector<dato> &vec){
  int pivote;
  if (primero < ultimo){
    particion(vec, primero, ultimo, pivote);
    Quick(primero, pivote-1, vec);
    Quick(pivote+1, ultimo, vec);
  }
}

// Descripcion: Realiza una busqueda de datos especificos dados por el usuario en un arreglo antes ordenado
//Complejidad o(logn)
int busqBinaria(vector<dato> &v, int n, int fin){
  int ini = 0, mit = (fin+ini)/2;
  while(ini <= fin){
      mit = (fin+ini)/2;
      if(v[mit].key == n) return mit;
      if(v[mit].key > n) fin = mit - 1;
      else ini = mit + 1;
      }
  if((v[mit].key/1000000) < n/1000000)mit++;
  return mit;
}

//Descripcion: Convierte el arreglo de meses a numeros enteros
//Complejidad: O(1)
int conversionMes(string mes){
  string meses[]={"Ene","Feb","Mar","Abr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dic"};
  for (int i=0; i < 12; i++){
    if(mes == meses[i]){
      return ++i;
    }
  }
  cout <<"Error"<<endl;
  return -1;
}

//Descripcion: Convierte toda la fecha (mes, dia, hora) en numeros enteros, elimina los ":" en las horas.
//Complejidad O(1)
int conversionFecha(string fecha, string dia, string hora){
  int f=0,d,h,i = 0,fechaInt;
  f = conversionMes(fecha);
  fechaInt = (f*(100000000)) + stoi(dia+hora.substr(0,2)+hora.substr(3,2)+hora.substr(6,2));
  return fechaInt;
}


int main() {
  fstream fin;
  dato registro;
  vector<dato> orden;

  fin.open("bitacora.txt",ios::in);
  while(!fin.eof()){
    getline(fin,registro.fecha);
    orden.push_back(registro);
  }
  fin.close();

  for(int i = 0; i<orden.size(); i++){ 
    stringstream s(orden[i].fecha);
    getline(s,orden[i].mes,' ');
    getline(s,orden[i].dia,' ');
    getline(s,orden[i].hora,' ');
    orden[i].key = conversionFecha(orden[i].mes,orden[i].dia,orden[i].hora);
  }

  Quick(0,orden.size(),orden);  

  char seguir;
  string inicioMes, finalMes;
  int mesInt, inicioDia, finalDia;
  do{
    cout << "Ingresa la fecha de inicio en formato: Aug 28" << endl;
    cin >> inicioMes;
    cin >> inicioDia;
    mesInt = conversionMes(inicioMes)*100+inicioDia;
    int min=busqBinaria(orden,mesInt*1000000,orden.size()-1);

    cout << "Ingresa la fecha final en formato: Dec 25"<<endl;
    cin >> finalMes;
    cin >> finalDia;
    mesInt = conversionMes(finalMes)*100+finalDia;
    int max=busqBinaria(orden,(mesInt+1)*1000000,orden.size()-1);
    
    cout << "Ingresa el nombre del archivo: " <<endl;
    ofstream archivo;
    string titulo;
    cin >> titulo;
    archivo.open(titulo, ios::trunc); 
    for(int i=min;i<=max-1;i++){
      cout << orden[i].fecha << endl;
      archivo << orden[i].fecha << endl;
    }
    archivo.close();
    
    cout << endl << "Desea hacer otra consulta? : Y/N" << endl;
    cin >> (seguir);
    }while((toupper(seguir)) == 'Y'); 
    cout << "Terminado";
}