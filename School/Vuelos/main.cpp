#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include <time.h>
//#include "Avion.h"
//#include "pasajeros.h"

/*Escriba un programa para asignar asientos a los pasajeros de un vuelo.
Suponga que el avion tiene la siguiente numeracion:

1 A B   C D
2 A B   C D
3 A B   C D
4 A B   C D
5 A B   C D
Si un asiento esta ocupado marcar con una X, Mostrar los asientos disponibles, pedir al usuario el asiento que desee, y si no esta ocupado, reservando junto con los datos del pasajero.
*/

using namespace std;


class Pasajero{
    private:
        string nombre,ape_ma,ape_pa;
        int fila_Asiento,numero_telefono,hora;
        char tipo_Asiento;
    public:
        void asignar_asiento(int,char,int);
        void pedirDatos();
    	void printdata();
    friend class Avion;
};


void Pasajero::pedirDatos(){
	fflush(stdin);
	cout<<"Digite su nombre: "<<endl;
	getline(cin,nombre);
	cout<<"Digite su apellido paterno: "<<endl;
	getline(cin,ape_pa);
	cout<<"Digite su apellido materno: "<<endl;
	getline(cin,ape_ma);
	cout<<"Numero de telefono: "<<endl;
	cin>>numero_telefono;
}

void Pasajero::asignar_asiento(int f,char t,int h){
	ofstream file;
	string a = "./tickets/";
	a=a+nombre;
	file.open(a.c_str(), ios::out);
	
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	
	if(file.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	fflush(stdin);
	file<<"Name: "<<nombre<<" "<<ape_pa<<" "<<endl;
	file<<"Fila: "<<f<<endl;
	file<<"Tipo: "<<t<<endl;
	file<<"Passenger number: "<<h<<endl;
	file<<"Current local time and date: "<<asctime(timeinfo)<<endl;
    fila_Asiento=f;
    tipo_Asiento=t;
    hora=h;
    
    file.close();
}

void Pasajero::printdata(){
    cout<<"Nombre completo del pasajero: "<<nombre<<" "<<ape_pa<<" "<<ape_ma<<endl;
    cout<<"Numero telefonico: "<<numero_telefono<<endl;
    cout<<"Con el asiento: "<<fila_Asiento<<"-"<<tipo_Asiento<<endl;
}

class Avion{
    private:
        char** asientos;
        int filas;
        int columnas;
        Pasajero pv[17];
        int cnt;
    public:
        Avion(int,int);
        ~Avion();
        void Printasientos();
        void asignarAsiento(char*);
        void printPasajeros();
        void enlistar_hora();
        void enlistar_Apellidos();
        void busqueda_Especifica(string);

};

Avion::Avion(int f, int c){
    filas=f;
    columnas=c;
    cnt=0;
    asientos = new char*[filas];
    for(int i=0;i<filas;i++) asientos[i]= new char[columnas];

    for(int i=0;i<filas;i++)
        for(int j=0;j<columnas;j++){
            if(j==0) asientos[i][j]='0'+(i+1);
            else asientos[i][j] = 'A'+(j-1);
        }

}

void Avion::Printasientos(){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++) cout<<asientos[i][j]<<" ";
        cout<<endl;
    }
}

void Avion::asignarAsiento(char* asiento){
    bool resp;
    if(cnt<17){
    	Pasajero p;
	    for(int j=1; j<columnas; j++){
	        if(asientos[(asiento[0]-'0')-1][j]==asiento[1]){
	            cout<<"El asiento esta disponible. "<<endl;
	            cout<<"Quiere reservarlo? (0-para no/1-para si)";
	            cin>>resp;
	            if(resp){
	            	p.pedirDatos();
	            	p.asignar_asiento(asiento[0]-'0',asientos[(asiento[0]-'0')-1][j],cnt);
	            	pv[cnt]=p;
					asientos[(asiento[0]-'0')-1][j]='X';
					cnt++;
	    		}
	            return;
	        }
	    }
	    cout<<"El asiento esta ocupado"<<endl;
	}else cout<<"El Avion esta lleno";

}

void Avion::printPasajeros(){
	if(cnt>0)
		for(int i=0; i<cnt; i++) pv[i].printdata();
	else cout<<"No hay pasajeros";
}

void Avion::enlistar_hora(){
	if(cnt>0){
		int iMin;
		for(int i=0; i<cnt-1; i++){
			iMin=i;
			for(int j=i+1; j<cnt; j++)
				if(pv[j].hora < pv[iMin].hora) iMin=j;
			Pasajero temp=pv[i];
	        pv[i]=pv[iMin];
	        pv[iMin]=temp;
		}
		printPasajeros();
	}else cout<<"No hay pasajeros";
}

void Avion::enlistar_Apellidos(){
	if(cnt>0){
		int iMin;
		for(int i=0; i<cnt-1; i++){
			iMin=i;
			for(int j=i+1; j<cnt; j++)
				if(pv[j].ape_pa < pv[iMin].ape_pa) iMin=j;
			Pasajero temp=pv[i];
	        pv[i]=pv[iMin];
	        pv[iMin]=temp;
		}
		printPasajeros();
	}else cout<<"No hay pasajeros";
}

void Avion::busqueda_Especifica(string s){
    bool band=false;
    for(int i=0;i<cnt;i++){
        if((pv[i].fila_Asiento==(s[0]-'0'))&&(pv[i].tipo_Asiento==s[1])){
           pv[i].printdata();
           band=true;
        }
    }
    if(band){ cout<<"Pasajero encontrado correctamente."<<endl; }
    else {cout<<"Pasajero no encontrado"<<endl;}
}

Avion::~Avion(){
    cout<<"Liberando memoria"<<endl;
    for(int i=0;i<filas;i++){
		delete[] asientos[i];
	}
	delete[] asientos;
}

int main(){
    int f,c,opc;
    char fila,tipo,resp;
    char asiento[2];
    string fl;

    cout<<"Cuantos asientos tiene su avion? "<<endl;
    cin>>f>>c;
    Avion a(f,c);

	a.Printasientos();

	do{
		cout<<"MENU."<<endl;
		cout<<"1)Ver espacios disponibles"<<endl;
		cout<<"2)Reservar asiento"<<endl;
		cout<<"3)Enlistar Pasajeros en orden de llegada."<<endl;
		cout<<"4)Enlistar por Apellidos."<<endl;
		cout<<"5)Busqueda especifica."<<endl;
		cout<<"0) Salir"<<endl;
		cout<<"Digite su opcion: ";
		cin>>opc;

		switch(opc){

			case 1:
				a.Printasientos();
				break;
			case 2:
				a.Printasientos();
				cout<<"que Asiento desea de los que estan disponibles Digite"<<endl;
				cout<<"Fila: "; cin>>fila;
				cout<<"Tipo: "; cin>>tipo;
			    asiento[0]=toupper(fila); asiento[1]=toupper(tipo);
			    a.asignarAsiento(asiento);
				break;
			case 3:
				a.enlistar_hora();
				break;
			case 4:
				a.enlistar_Apellidos();
				break;
            case 5:
                fflush(stdin);
                cout<<"Que asiento es el que quiere buscar? "<<endl;
                getline(cin,fl);
                a.busqueda_Especifica(fl);
                break;
			case 0:
				return 1;
			default: cout<<":)"; break;
		}

	    cout<<"LLego un nuevo cliente? (s/n)"<<endl;
	    cin>>resp;
	    system("cls");
	}while(resp!='S' || resp!='s');


    return 0;
}
