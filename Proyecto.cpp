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

int main(){
	
	return 0;
}
