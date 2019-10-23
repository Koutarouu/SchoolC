#ifndef PASAJEROS_H_INCLUDED
#define PASAJEROS_H_INCLUDED

#include "Avion.h"

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>

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
	file.open(nombre.c_str(), ios::out);
	if(file.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	fflush(stdin);
	file<<"Name: "<<nombre<<endl;
	file<<"Fila: "<<f<<endl;
	file<<"Tipo: "<<t<<endl;
	file<<"Passanger number: "<<h<<endl;
	file<<"Hora de llegada: "<<endl;
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

#endif // PASAJEROS_H_INCLUDED
