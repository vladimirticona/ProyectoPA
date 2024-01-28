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
		int mostrarMes();
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

int Tarea::mostrarMes(){
	return mes;
}

//----------------------------------------------------

class Exposicion : public Tarea{
	private:
		string tema;
	public:
		Exposicion(string,int,int,string);
		void mostrarTarea();
		
};

Exposicion::Exposicion(string _curso,int _dia,int _mes,string _tema) : Tarea(_curso,_dia,_mes){
	tema=_tema;
}

void Exposicion::mostrarTarea(){
	Tarea::mostrarTarea();
	cout<<"Tema: "<<tema<<endl;
}


//----------------------------------------------------

class Informe : public Tarea{
	private:
		string formato;
	public:
		Informe(string,int,int,string);
		void mostrarTarea();
		
};

Informe::Informe(string _curso,int _dia,int _mes, string _formato) : Tarea(_curso,_dia,_mes){
	formato=_formato;
}

void Informe::mostrarTarea(){
	Tarea::mostrarTarea();
	cout<<"Formato: "<<formato<<endl;
}

//------------------------


int main(){
	Informe *z[100];
	Exposicion *y[100];
	Tarea *x[100];
	int opcion;
	int cont=0;
	int conta=0;
	int contad=0;
	
	do{
		cout<<"----------BIENVENIDO AL ADMINISTRADOR DE TAREAS----------"<<endl;
		cout<<endl;
		cout<<"1) Ver tareas pendientes"<<endl;
		cout<<"2) Insertar nueva tarea"<<endl;
		cout<<"3) Que hago primero"<<endl;
		cout<<"4) Eliminar tarea"<<endl<<endl;
		cout<<"5) Ver exposiciones pendientes"<<endl;
		cout<<"6) Insertar nueva exposicion"<<endl;
		cout<<"7) Eliminar exposicion"<<endl<<endl;
		cout<<"8) Ver informes pendientes"<<endl;
		cout<<"9) Insertar nuevo informe"<<endl;
		cout<<"10) Eliminar informe"<<endl<<endl;
		cout<<"11) Anotar fechas o datos importantes"<<endl;
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
				
				for (int i = 1; i < cont; i++) {
        			Tarea* auxTarea = x[i];
        			int j = i - 1;
        			while (j >= 0 && x[j]->mostrarMes() > auxTarea->mostrarMes()) {
            			x[j + 1] = x[j];
            			j--;
        			}
        			x[j + 1] = auxTarea;
    				}

    			cout << "Tareas ordenadas por mes:" << endl;
    			for (int i = 0; i < cont; i++) {
        			
        			x[i]->mostrarTarea();
        			cout << "---------------------------------" << endl;
    				}
				break;
			}
			case 4:{
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
			case 5:{
				if(conta==0){
					cout<<"NO HAY EXPOSICIONES PENDIENTES...."<<endl;
				}else{
					for(int i=0;i<conta;i++){
						cout<<"Exposicion "<<i<<": "<<endl;
						y[i]->mostrarTarea();
						cout<<"---------------------------------"<<endl;
						
					}
				}
				
				break;
			}
			case 6:{
				string t;
				string g;
				int f;
				int v;
				
				cout<<"Ingresa el nombre del curso: ";
				cin>>g;
				cout<<"Ingresa el dia de la fecha de entrega: ";
				cin>>f;
				cout<<"Ingresa el mes de la fecha de entrega: ";
				cin>>v;
				cout<<"Ingresa el tema de la exposicion: ";
				cin>>t;
				
				y[conta++]= new Exposicion(g,f,v,t);
				break;
			}
			case 7:{
				if(conta==0){
					cout<<"NO HAY EXPOSICIONES PARA ELIMINAR"<<endl;
				}else{
					int num;
					cout<<"Ingresa el indice de la tarea que deseas eliminar: ";
					cin>>num;
					if(num>=0 and num<conta){
						delete y[num];
						for(int i=num;i<conta-1;i++){
							y[i]=y[i+1];
						}
						conta--;
						cout<<"EXPOSICION ELIMINADA EXITOSAMENTE"<<endl;
					}
				}
				break;
			}
			case 8:{
				if(contad==0){
					cout<<"NO HAY INFORMES PENDIENTES...."<<endl;
				}else{
					for(int i=0;i<contad;i++){
						cout<<"Informe "<<i<<": "<<endl;
						z[i]->mostrarTarea();
						cout<<"---------------------------------"<<endl;
						
					}
				}
				break;
			}
			case 9:{
				string h;
				string g;
				int f;
				int v;
				
				cout<<"Ingresa el nombre del curso: ";
				cin>>g;
				cout<<"Ingresa el dia de la fecha de entrega: ";
				cin>>f;
				cout<<"Ingresa el mes de la fecha de entrega: ";
				cin>>v;
				cout<<"Ingresa el formato del informe: ";
				cin>>h;
				
				z[contad++]= new Informe(g,f,v,h);
				
				break;
			}
			case 10:{
				if(contad==0){
					cout<<"NO HAY INFORMES PARA ELIMINAR"<<endl;
				}else{
					int num;
					cout<<"Ingresa el indice del informe que deseas eliminar: ";
					cin>>num;
					if(num>=0 and num<contad){
						delete z[num];
						for(int i=num;i<contad-1;i++){
							z[i]=z[i+1];
						}
						contad--;
						cout<<"INFORME ELIMINADO EXITOSAMENTE"<<endl;
					}
				}
				break;
			} 
			case 11:{
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
				cout<<"!!!!!NO OLVIDES REVISAR TUS APUNTES ANOTADOS!!!!!"<<endl;
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
