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

class Examen : public Tarea{
	private:
		int cantidad;
	public:
		Examen(string,int,int,int);
		void mostrarTarea();
};

Examen::Examen(string _curso,int _dia,int _mes,int _cantidad) : Tarea(_curso,_dia,_mes){
	cantidad=_cantidad;
}

void Examen::mostrarTarea(){
	Tarea::mostrarTarea();
	cout<<"Cantidad de preguntas: "<<cantidad<<endl;
}




//------------------------
int main(){
	Examen *p[100];
	Informe *z[100];
	Exposicion *y[100];
	Tarea *x[100];
	int opcion;
	int cont=0;
	int conta=0;
	int contad=0;
	int contado=0;
	
	do{
		cout<<"----------BIENVENIDO AL ADMINISTRADOR DE TAREAS----------"<<endl;
		cout<<endl;
		cout<<"1) Ver tareas pendientes"<<endl;
		cout<<"2) Insertar nueva tarea"<<endl;
		cout<<"3) Que tarea hago primero"<<endl;
		cout<<"4) Eliminar tarea"<<endl<<endl;
		cout<<"5) Ver exposiciones pendientes"<<endl;
		cout<<"6) Insertar nueva exposicion"<<endl;
		cout<<"7) Que exposicion hago primero"<<endl;
		cout<<"8) Eliminar exposicion"<<endl<<endl;
		cout<<"9) Ver informes pendientes"<<endl;
		cout<<"10) Insertar nuevo informe"<<endl;
		cout<<"11) Que informe hago primero"<<endl;
		cout<<"12) Eliminar informe"<<endl<<endl;
		cout<<"13) Ver examenes pendientes"<<endl;
		cout<<"14) Insertar nuevo examen"<<endl;
		cout<<"15) Que examen estudio primero"<<endl;
		cout<<"16) Eliminar examen"<<endl<<endl;
		cout<<"17) Anotar fechas o datos importantes"<<endl;
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
				for (int i = 1; i < conta; i++) {
        			Exposicion* auxExposicion = y[i];
        			int j = i - 1;
        			while (j >= 0 && y[j]->mostrarMes() > auxExposicion->mostrarMes()) {
            			y[j + 1] = y[j];
            			j--;
        			}
        			y[j + 1] = auxExposicion;
    				}

    			cout << "Exposiciones ordenadas por mes:" << endl;
    			for (int i = 0; i < conta; i++) {
        			
        			y[i]->mostrarTarea();
        			cout << "---------------------------------" << endl;
    				}
				break;
			}
			case 8:{
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
			case 9:{
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
			case 10:{
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
			case 11:{
				for (int i = 1; i < contad; i++) {
        			Informe* auxInforme = z[i];
        			int j = i - 1;
        			while (j >= 0 && z[j]->mostrarMes() > auxInforme->mostrarMes()) {
            			z[j + 1] = z[j];
            			j--;
        			}
        			z[j + 1] = auxInforme;
    				}

    			cout << "Informes ordenados por mes:" << endl;
    			for (int i = 0; i < contad; i++) {
        			
        			z[i]->mostrarTarea();
        			cout << "---------------------------------" << endl;
    				}
				break;
			}
			case 12:{
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
			case 13:{
				if(contado==0){
					cout<<"NO HAY EXAMENES PENDIENTES...."<<endl;
				}else{
					for(int i=0;i<contado;i++){
						cout<<"Examen "<<i<<": "<<endl;
						p[i]->mostrarTarea();
						cout<<"---------------------------------"<<endl;
						
					}
				}
				break;
			}
			case 14:{
				int o;
				string g;
				int f;
				int v;
				
				cout<<"Ingresa el nombre del curso: ";
				cin>>g;
				cout<<"Ingresa el dia de la fecha de entrega: ";
				cin>>f;
				cout<<"Ingresa el mes de la fecha de entrega: ";
				cin>>v;
				cout<<"Ingresa la cantidad de preguntas del examen: ";
				cin>>o;
				
				p[contado++]= new Examen(g,f,v,o);
				
				break;
			}
			case 15:{
				for (int i = 1; i < contado; i++) {
        			Examen* auxExamen = p[i];
        			int j = i - 1;
        			while (j >= 0 && p[j]->mostrarMes() > auxExamen->mostrarMes()) {
            			p[j + 1] = p[j];
            			j--;
        			}
        			p[j + 1] = auxExamen;
    				}

    			cout << "Examenes ordenados por mes:" << endl;
    			for (int i = 0; i < contado; i++) {
        			
        			p[i]->mostrarTarea();
        			cout << "---------------------------------" << endl;
    				}
				break;
			}
			case 16:{
				if(contado==0){
					cout<<"NO HAY EXAMENES PARA ELIMINAR"<<endl;
				}else{
					int num;
					cout<<"Ingrese el indice del examen que deseas eliminar: ";
					cin>>num;
					if(num>=0 and num<contado){
						delete p[num];
						for(int i=num;i<contado-1;i++){
							p[i]=p[i+1];
						}
						contado--;
						cout<<"EXAMEN ELIMINADO EXITOSAMENTE"<<endl;
					}
				}
				break;
			}
			case 17:{
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
