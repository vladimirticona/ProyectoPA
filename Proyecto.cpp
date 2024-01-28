#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Tarea{
	private:
		string curso;
		int dia;
		int mes;
	public:
		Tarea(string,int,int);
		virtual void mostrarTarea();
};
Tarea::Tarea(string _curso,int _dia,int _mes){
	curso=_curso;
	dia=_dia;
	mes=_mes;
}
void Tarea::mostrarTarea(){
	cout<<"Curso: "<<curso<<endl;
	cout<<"Fecha de entrega: "<<dia<<" / "<<mes<<" / 2024"<<endl;
}

//---------------------------------------

int main(){
	int opcion;
	do{
		cout<<"----------BIENVENIDO AL ADMINISTRADOR DE TAREAS----------"<<endl;
		cout<<endl;
		cout<<"1) Ver tareas pendientes"<<endl;
		cout<<"2) Insertar nueva tarea"<<endl;
		cout<<"3) Eliminar tarea"<<endl;
		cout<<"4) Anotar fechas o datos importantes"<<endl;
		cout<<"0) Salir"<<endl<<endl;
		cout<<"Elije una opcion: ";
		cin>>opcion;	
	}while(opcion!=0);
	
	
	return 0;
}
