#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void menu(){
	
	cout<<"\nElija una opciÃ³n"<<endl;
	cout<<"1-Crear"<<endl;
	cout<<"2-Leer"<<endl;
	cout<<"3-Editar"<<endl;
	cout<<"4-Eliminar"<<endl;
	cout<<"5-Traducir"<<endl;
	cout<<"6-Salir"<<endl;
	
}
void Crear(){
	system("cls");
	ofstream archivo("translate.txt", ios::app);
	if (archivo.is_open()){
		string palabra, traduccion, funcion;
		cout<<"Ingrese palabra: ";
		cin>>palabra;
		cout<<"Ingrese traduccion: ";
		cin>>traduccion;
		cout<<"Ingrese funcion: ";
		cin.ignore();
		getline(cin, funcion);
		archivo<<palabra<<","<<traduccion<<","<<funcion<<endl;
		
		
		archivo.close();
	}else{
		cout<<"Syntaxis Error"<<endl;
	}
	
}
void Leer(){
	ifstream archivo("translate.txt");
	if(archivo.is_open()){
		string linea;
			while(getline(archivo, linea)){
				vector<string>palabras=split(linea, ',');
				if (palabras.size()==3){
					string palabra=palabras[0];
					string traduccion=palabras[1];
					string funcion=palabras[2];
					
					cout<<"Tu palabra es: "<<palabra<<endl;
					cout<<"Su traduccion es: "<<traduccion<<endl;
					cout<<"Su funcion es: "<<funcion<<endl;
					cout<<endl;
				}
			}
		archivo.close(); 	
	}else{
		cout<<"Syntaxis Error"<<endl;
	}
}
void Editar(){
	fstream archivo("translate.txt", ios::in | ios::out);
	if(archivo.is_open()){
		string palabra, npalabra, ntraduccion, nfuncion, linea;
		bool encontro=false;
		cout<<"Ingrese la palabra a editar: ";
		cin>>palabra;
		while(getline(archivo,linea)){
			vector<string>palabras=split(linea, ',');
			if(palabras.size() == 3 && palabras[0] == palabra){
				encontro=true;
				cout<<"Ingrese la nueva palabra: ";
				cin>>npalabra;
				cout<<"Ingrese la nueva traduccion: ";
				cin>>ntraduccion;
				cout<<"Ingrese la nueva funcion: ";
				cin.ignore();
				getline(cin, nfuncion);
				linea=npalabra+","+ntraduccion+","+nfuncion;
				break;
			}	
		}
		if(encontro){
			ofstream temp("translate_temp.txt");
			if(temp.is_open()){
			    archivo.clear();
                archivo.seekg(0);
				string linea_original;
				while(getline(archivo, linea_original)){
					vector<string>spliteado=split(linea_original, ',');
					if(spliteado[0]!=palabra){
						temp<<linea_original<<endl;
					}
				}							
				temp << linea << endl;
				temp.close();
				archivo.close();
				remove("translate.txt");
				rename("translate_temp.txt","translate.txt");
				cout<<"\nEditado exitosamente :)";
			}
		}else{
			cout<<"No fue posible aperturar el archivo";
		}
	}else{
		cout<<"No fue posible aperturar el archivo";
	}
	
}
void Eliminar(){
	fstream archivo("translate.txt", ios::in | ios::out);
	if(archivo.is_open()){
		string palabra, linea;
		bool encontro=false;
		cout<<"Ingrese la palabra a eliminar: ";
		cin>>palabra;
		while(getline(archivo,linea)){
			vector<string>palabras=split(linea, ',');
			if(palabras.size() == 3 && palabras[0] == palabra){
				encontro=true;
				break;
			}	
		}
		if(encontro){
			ofstream temp("translate_temp.txt");
			if(temp.is_open()){
			    archivo.clear();
                archivo.seekg(0);
				string linea_original;
				while(getline(archivo, linea_original)){
					vector<string>spliteado=split(linea_original, ',');
					if(spliteado[0]!=palabra){
						temp<<linea_original<<endl;
					}
				}							
				temp.close();
				archivo.close();
				remove("translate.txt");
				rename("translate_temp.txt","translate.txt");
				cout<<"\nEliminado exitosamente :)";
			}
		}else{
			cout<<"No fue posible aperturar el archivo";
		}
	}else{
		cout<<"No fue posible aperturar el archivo";
	}
}
	
void Traductor(){
	string codigo,texto;
	
	cout<<"Ingrese codigo por favor: ";
	/*cin.ignore();
	getline(cin,codigo);*/
	while (getline(cin, codigo)) {
    texto += codigo + "\n"; // Agrega la línea con un salto de línea
  }

  // Elimina el último salto de línea (opcional)
  if (!texto.empty()) {
    texto.erase(texto.size() - 1);
  }	
	vector<string>palabras=split(texto,' ');
	for (int i=0; i<palabras.size();i++){
		cout<<"el valor de "<<palabras[i]<<endl;
	}			
}

int main(){
	int opcion=0;
	
	do{
		menu();
		cin>>opcion;
		switch(opcion){
			case 1:
				Crear(); 
			break;
			case 2: 
				Leer();
			break;
			case 3:
				Editar(); 
			break;
			case 4: 
				Eliminar();
			break;
			case 5: 
				Traductor();
			break;
			case 6: 
				cout<<"Cerrando sesionn :)";
			break;
			
			default: 
				cout<<"OpciÃ³n invalida"<<endl;
		}
	}while(opcion!=6);
	
	return 0;
}

