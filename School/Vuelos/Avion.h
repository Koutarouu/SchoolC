#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
#include<iostream>
#include<string.h>

#include "pasajeros.h"

using namespace std;

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

#endif // AVION_H_INCLUDED
