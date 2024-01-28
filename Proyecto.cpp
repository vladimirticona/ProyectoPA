#include<bits/stdc++.h>
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

//----------------------------------------------------






int main(){
	Tarea *x[100];
	int opcion;
	int cont=0;
	
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
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		switch(opcion){
			case 1:{
				if(cont==0){
					cout<<"NO HAY TAREAS PENDIENTES...."<<endl;
				}else{
					for(int i=0;i<cont;i++){
						cout<<"Tarea "<<i<<": "<<endl;
						x[i]->mostrarTarea();
						cout<<"---------------------------------"<<endl;
						
					}
				}
				
				break;
			}
			case 2:{
				string c;
				int d;
				int m;
				
				cout<<"Ingresa el nombre del curso: ";
				cin>>c;
				cout<<"Ingresa el dia de la fecha de entrega: ";
				cin>>d;
				cout<<"Ingresa el mes de la fecha de entrega: ";
				cin>>m;
				
				x[cont++]= new Tarea(c,d,m);
				
				break;
			}
			case 3:{
				if(cont==0){
					cout<<"NO HAY TAREAS PARA ELIMINAR"<<endl;
				}else{
					int num;
					cout<<"Ingresa el indice de la tarea que deseas eliminar: ";
					cin>>num;
					if(num>=0 and num<cont){
						delete x[num];
						for(int i=num;i<cont-1;i++){
							x[i]=x[i+1];
						}
						cont--;
						cout<<"TAREA ELIMINADA EXITOSAMENTE"<<endl;
					}
				}
				break;
			}
			case 4:{
				ofstream archivo;
				string apunte;
				archivo.open("IMPORTANTE.txt",ios::app);
				if(!archivo){
					cout<<"ERROR"<<endl;
				}else{
					cout<<"Escribe tu apunte: ";
					getline(cin,apunte);
					archivo<<"DATOS IMPORTANTES: "<<endl<<endl;
					archivo<<apunte<<endl<<endl;
					archivo.close();
				}
				
				break;
			}
			case 0:{
				
				break;
			}
			default:{
				cout<<"OPCION INCORRECTA, INTENTE DE NUEVO PORFAVOR"<<endl<<endl;
				break;
			}
				
		}
		
		
		
	}while(opcion!=0);
	
	
	
	return 0;
}
