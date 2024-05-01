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
	
	cout<<"Elija una opción"<<endl;
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
			break;
			case 4: 
			break;
			case 5: 
				
			break;
			case 6: 
				cout<<"Cerrando sesión :)";
			break;
			
			default: 
				cout<<"Opción invalida"<<endl;
		}
	}while(opcion!=6);
	
	return 0;
}

