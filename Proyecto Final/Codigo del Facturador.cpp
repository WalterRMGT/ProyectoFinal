
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;

string L;
string Menu;
string SMenu,Info,N;
int op, ops;
float IVA = 0.12, SIVA = 1.12;

void CClientes(){
	system("cls");	
		ifstream IC("Clientes.txt");	
	while (getline(IC,L)){
		Info = Info+L+"\n";
	}
	
		cout << Info<< endl;
		Info = "";
}
void CProductos(){
	system("cls");	
		ifstream II("Inventario.txt");	
	while (getline(II,L)){
		Info = Info+L+"\n";
	}
	
		cout << Info << endl;
		Info = "";
}
void CProveedores(){
	system("cls");	
		ifstream II("Proveedores.txt");	
	while (getline(II,L)){
		Info = Info+L+"\n";
	}
	
		cout << Info << endl;
		Info = "";
}
void Mcliente(){
	
	char NombreC[20], DPI[13];
	int Edad, NumeroC ;
	
	ifstream Salida;
	ofstream Entrada,Entrada2;

	
	//opcion 1
	if(ops == 1){
	CClientes();
	cout << "Oprime cualquier boton para volver al menu principal"<< endl;
	getch();
	
	}
	//opcion 2
	else if(ops == 2){
		system("cls");
		Entrada2.open("Clientes.txt", ios::app);
		
		cout << "ingrese el numero del cliente : ";
		cin >> NumeroC;
		
		cout << "ingrese el nombre del cliente : ";
		cin >> NombreC;
		
		cout << "ingrese la edad del cliente : ";
		cin >> Edad;
		
		cout << "ingrese el DPI del cliente: ";
		cin >> DPI;
		
		Entrada2<< NumeroC << " " <<NombreC << " " << Edad << " " << DPI << endl;
		Entrada2.close();
    }
	//opcion 3
	else if(ops == 3){
		CClientes();
		int Aux;
		
		cout << "Ingrese el numero del cliente a eliminar: ";
		cin >> Aux;
		
		Salida.open("Clientes.txt", ios::in);
		Entrada.open("temp.txt", ios::out);
		
		Salida >> NumeroC;
		
		while(!Salida.eof()){
			
			Salida >> NombreC >> Edad >> DPI;
		
			if(Aux == NumeroC){
				
			   cout << "Cliente Eliminado" << endl;
			   getch();
			   
			   } else{
			
			   	 Entrada << NumeroC << " " << NombreC << " " << Edad << " " << DPI <<endl ;
				}
				
			Salida >> NumeroC;	
		}
		
		Salida.close();
		Entrada.close();
		remove("Clientes.txt");
		rename("temp.txt","Clientes.txt");
		
	}
	//opcion 4
	else if(ops == 4){
	CClientes();
		int Aux,D;
		
		cout << "Ingrese el numero del cliente a modificar: ";
		cin >> Aux;
		
		Salida.open("Clientes.txt", ios::in);
		Entrada.open("temp.txt", ios::out);
		
		Salida >> NumeroC;
		
		while(!Salida.eof()){
			
			Salida >> NombreC >> Edad >> DPI;
		
			if(Aux == NumeroC){
				
			   cout << "Opciones de modificacion " << endl;
			   cout << "1. Nombre del cliente " << endl;
			   cout << "2. Edad del cliente " << endl;
			   cout << "3. DPI del cliente " << endl;
			   cin >> D;
			   		if(D ==1){
			   			cout << "Ingrese Nuevo Nombre: ";
			   			cin >> NombreC;
					}else if(D ==2){
			   			cout << "Ingrese Nueva Edad: ";
			   			cin >> Edad;
					}else if(D ==3){
			   			cout << "Ingrese Nuevo DPI: " ;
			   			cin >> DPI;
					}
			   Entrada << NumeroC << " " << NombreC << " " << Edad << " " << DPI <<endl ;
				cout << "Cliente Modificado" << endl;
			   getch();
			   
			   } else{
			
			   	 Entrada << NumeroC << " " << NombreC << " " << Edad << " " << DPI <<endl ;
				}
				
			Salida >> NumeroC;	
		}
		
		Salida.close();
		Entrada.close();
		remove("Clientes.txt");
		rename("temp.txt","Clientes.txt");
		
	}
	//opcion 5
	else if(ops == 5){
	cout << "volviendo al menu" << endl;  
	}else {
	cout << "volviendo al menu" << endl;	
	}
}
void MProductos(){
	
	char NombreP[20];
	int Cantidad, SKU ;
	float Precio;
	ifstream Salida;
	ofstream Entrada,Entrada2;

	
	//opcion 1
	if(ops == 1){
	CProductos();
	cout << "Oprime cualquier boton para volver al menu principal"<< endl;
	getch();
	
	}
	//opcion 2
	else if(ops == 2){
		system("cls");
		Entrada2.open("Inventario.txt", ios::app);
		
		cout << "ingrese el SKU del Producto : ";
		cin >> SKU;
		
		cout << "ingrese el nombre del producto : ";
		cin >> NombreP;
		
		cout << "ingrese el precio del producto : ";
		cin >> Precio;
		
		cout << "ingrese la cantidad del producto ";
		cin >> Cantidad;
		
		Entrada2<< SKU << " " << NombreP << " " << Precio << " " << Cantidad << endl;
		Entrada2.close();
    }
	
	//opcion 3
	else if(ops == 3){
		CProductos();
		int Aux;
		
		cout << "Ingrese el SKU del Producto a eliminar: ";
		cin >> Aux;
		
		Salida.open("Inventario.txt", ios::in);
		Entrada.open("temp.txt", ios::out);
		
		Salida >> SKU;
		
		while(!Salida.eof()){
			
			Salida >> NombreP >> Precio >> Cantidad;
		
			if(Aux == SKU){
				
			   cout << "Producto Eliminado" << endl;
			   getch();
			   
			   } else{
			
			   	 Entrada << SKU << " " << NombreP << " " << Precio << " " << Cantidad <<endl ;
				}
				
			Salida >> SKU;	
		}
		
		Salida.close();
		Entrada.close();
		remove("Inventario.txt");
		rename("temp.txt","Inventario.txt");
		
	}
	//opcion 4
	else if(ops == 4){
	CProductos();
		int Aux,D;
		
		cout << "Ingrese el SKU del Producto a modificar: ";
		cin >> Aux;
		
		Salida.open("Inventario.txt", ios::in);
		Entrada.open("temp.txt", ios::out);
		
		Salida >> SKU;
		
		while(!Salida.eof()){
			
			Salida >> NombreP >> Precio >> Cantidad;
		
			if(Aux == SKU){
				
			   cout << "Opciones de modificacion " << endl;
			   cout << "1. Nombre del Producto" << endl;
			   cout << "2. Precio" << endl;
			   
			   cin >> D;
			   		if(D ==1){
			   			cout << "Ingrese Nuevo Nombre: ";
			   			cin >> NombreP;
			   			cout << "Producto Modificado" << endl;
					}else if(D ==2){
			   			cout << "Ingrese Nuevo Precio: ";
			   			cin >> Precio;
			   			cout << "Producto Modificado" << endl;
					}
			   Entrada << SKU << " " << NombreP << " " << Precio << " " << Cantidad <<endl ;
			   getch();
			   
			   } else{
			
			   	Entrada << SKU << " " << NombreP << " " << Precio << " " << Cantidad <<endl ;
				}
				
			Salida >> SKU;	
		}
		
		Salida.close();
		Entrada.close();
		remove("Inventario.txt");
		rename("temp.txt","Inventario.txt");
		
	}
	//opcion 5
	else if(ops == 5){
	cout << "volviendo al menu" << endl;  
	}else {
	cout << "volviendo al menu" << endl;	
	}
}
void MInventario(){
	
	char NombreP[20];
	int Cantidad, SKU ;
	float Precio;
	ifstream Salida;
	ofstream Entrada,Entrada2;

	
	//opcion 1
	if(ops == 1){
	CProductos();
	cout << "Oprime cualquier boton para volver al menu principal"<< endl;
	getch();
	
	}
	//opcion 2
	else if(ops == 2){
	CProductos();
		int Aux,D;
		
		cout << "Ingrese el SKU del Producto a modificar Cantidad: ";
		cin >> Aux;
		
		Salida.open("Inventario.txt", ios::in);
		Entrada.open("temp.txt", ios::out);
		
		Salida >> SKU;
		
		while(!Salida.eof()){
			
			Salida >> NombreP >> Precio >> Cantidad;
		
			if(Aux == SKU){
					float D;
			   		cout << "Ingrese Nueva Cantidad: ";
			   		cin >> Cantidad;
	
			   Entrada << SKU << " " << NombreP << " " << Precio << " " << Cantidad <<endl ;
				cout << "Producto Modificado" << endl;
			   getch();
			   
			   }else {
			
			   	Entrada << SKU << " " << NombreP << " " << Precio << " " << Cantidad <<endl ;
				}
				
			Salida >> SKU;	
		}
		
		Salida.close();
		Entrada.close();
		remove("Inventario.txt");
		rename("temp.txt","Inventario.txt");
		
	}
	//opcion 3
	else if(ops == 3){
	cout << "volviendo al menu" << endl;  
	}else {
	cout << "volviendo al menu" << endl;	
	}
}
void MProveedores(){
	
	char NombrePV[20], Direccion[40];
	int NumeroPV ;
	
	ifstream Salida;
	ofstream Entrada,Entrada2;

	
	//opcion 1
	if(ops == 1){
	CProveedores();
	cout << "Oprime cualquier boton para volver al menu principal"<< endl;
	getch();
	
	}
	//opcion 2
	else if(ops == 2){
		system("cls");
		Entrada2.open("Proveedores.txt", ios::app);
		
		cout << "ingrese el numero del Proveedor : ";
		cin >> NumeroPV;
		
		cout << "ingrese el nombre del Proveedor : ";
		cin >> NombrePV;
		
		cout << "ingrese la Dirrecion del Proveedor : ";
		cin >> Direccion;
	
		
		Entrada2<< NumeroPV << " " <<NombrePV << " " << Direccion << endl;
		Entrada2.close();
    }
	//opcion 3
	else if(ops == 3){
		CProveedores();
		int Aux;
		
		cout << "Ingrese el numero del Proveedor a eliminar: ";
		cin >> Aux;
		
		Salida.open("Proveedores.txt", ios::in);
		Entrada.open("temp.txt", ios::out);
		
		Salida >> NumeroPV;
		
		while(!Salida.eof()){
			
			Salida >> NombrePV >> Direccion;
		
			if(Aux == NumeroPV){
				
			   cout << "Proveedor Eliminado" << endl;
			   getch();
			   
			   } else{
			
			   	 Entrada << NumeroPV << " " << NombrePV << " " << Direccion <<endl ;
				}
				
			Salida >> NumeroPV;	
		}
		
		Salida.close();
		Entrada.close();
		remove("Proveedores.txt");
		rename("temp.txt","Proveedores.txt");
		
	}
	//opcion 4
	else if(ops == 4){
	CProveedores();
		int Aux,D;
		
		cout << "Ingrese el numero del proveedor a modificar: ";
		cin >> Aux;
		
		Salida.open("Proveedores.txt", ios::in);
		Entrada.open("temp.txt", ios::out);
		
		Salida >> NumeroPV;
		
		while(!Salida.eof()){
			
			Salida >> NombrePV >> Direccion;
		
			if(Aux == NumeroPV){
				
			   cout << "Opciones de modificacion " << endl;
			   cout << "1. Nombre del Proveedor " << endl;
			   cout << "2. Direccion del Proveedor" << endl;
			   cin >> D;
			   		if(D ==1){
			   			cout << "Ingrese Nuevo Nombre: ";
			   			cin >> NombrePV;
					}else if(D ==2){
			   			cout << "Ingrese Nueva Edad: ";
			   			cin >> Direccion;

					}
			    Entrada << NumeroPV << " " << NombrePV << " " << Direccion <<endl ;
				cout << "Proveedor Modificado" << endl;
			   getch();
			   
			   } else{
			
			   	 Entrada << NumeroPV << " " << NombrePV << " " << Direccion <<endl ;
				}
				
			Salida >> NumeroPV;	
		}
		
		Salida.close();
		Entrada.close();
		remove("Proveedores.txt");
		rename("temp.txt","Proveedores.txt");
		
	}
	//opcion 5
	else if(ops == 5){
	cout << "volviendo al menu" << endl;  
	}else {
	cout << "volviendo al menu" << endl;	
	}
}
void MVentas(){
	char NombreP[20],NombrePV[20],NombreC[20],Dire[40]; 
	int DPI;
	float Precio, PrecioT, TotalC,TotalV,TotalR,TIVA,Cantidad, Cantidad2, NP,NPV,NC, aux, aux2, aux3, edad, Cantidad3,Cost,TSI;
		ifstream Salida,Salida2,Salida3;
		ofstream Entrada3,Entrada4;
	
	if(ops==1){
		system("cls");
		cout << "Venta" << endl;
		Salida.open("Clientes.txt", ios::in);
		Salida2.open("Inventario.txt", ios::in);
		Salida3.open("Inventario.txt", ios::in);
		Entrada3.open("FacturaV.txt", ios::app);
		Entrada4.open("temp.txt", ios::out);
		
		cout << "Ingrese el numero del cliente" <<endl;
		cin >> NC;
		
		Salida >> aux;
		while(!Salida.eof()){
			Salida >> NombreC >> edad >> DPI ;
			if(aux == NC){
			   break;
			   }
				
			Salida >> aux;	
		}
		cout << "Ingrese el SKU Producto" <<endl;
		cin >> NP;		
		
		Salida2 >> aux2;
		while(!Salida2.eof()){
			Salida2 >> NombreP >> Precio >> Cantidad2;
			if(aux2 == NP){	
			   break;
			   }
				
			Salida2 >> aux2;	
		}
		
		cout << "Ingrese la cantidad del producto" <<endl;
		cin >> Cantidad;
		
		time_t HV = time(0);
		tm * time = localtime(&HV);
	
		TotalV = (Cantidad*Precio);
		TIVA = (Precio*Cantidad)*IVA;
		TotalR = TotalV + TIVA;
		cout << "Cliente DPI Producto Precio Cantidad Subtotal IVA Total"<< endl;
		
		cout << time->tm_mday<<"/"<< time->tm_mon+1<< "/"<< time->tm_year+1900 << "/" << time->tm_hour<<":"<< time->tm_min<< " "  << NombreC << " " << DPI << " "<<NombreP << " Q"<< Precio << " " << Cantidad << " " << TotalV << " " <<fixed<<setprecision(2)<<TIVA << " " << TotalR << endl;
		
		Entrada3<< time->tm_mday<<"/"<< time->tm_mon+1<< "/"<< time->tm_year+1900 << "/" << time->tm_hour<<":"<< time->tm_min<< " " << NombreC << " " << DPI << " "<<NombreP << " "<< Precio << " " << Cantidad << " " << TotalV << " " <<fixed<<setprecision(2)<<TIVA << " " << TotalR << endl;
		getch();
		
		Salida3 >> aux3;
		
		while(!Salida3.eof()){
			Salida3 >> NombreP >> Precio >> Cantidad2;
			if(aux3 == NP){
				Cantidad3 = Cantidad2-Cantidad;
				
				Entrada4 << aux3 << " " << NombreP << " " << Precio << " " << Cantidad3 << endl;
			}else {
				Entrada4 << aux3 << " " << NombreP << " " << Precio << " " << Cantidad2 << endl;	
			}
			   
	
			Salida3 >> aux3;	
		}
		
		Salida.close();
		Salida2.close();
		Salida3.close();
		Entrada3.close();
		Entrada4.close();
		
		remove("Inventario.txt");
		rename("temp.txt","Inventario.txt");
		
		}else 
		if(ops==2){
		system("cls");
		cout << "Compra" << endl;
		Salida.open("Proveedores.txt", ios::in);
		Salida2.open("Inventario.txt", ios::in);
		Salida3.open("Inventario.txt", ios::in);
		Entrada3.open("FacturaC.txt", ios::app);
		Entrada4.open("temp.txt", ios::out);
		
		cout << "Ingrese el numero del Proveedor" <<endl;
		cin >> NPV;
		
		Salida >> aux;
		while(!Salida.eof()){
			Salida >> NombreC >> Dire ;
			if(aux == NPV){
			   break;
			   }
				
			Salida >> aux;	
		}
		cout << "Ingrese el SKU Producto Comprado" <<endl;
		cin >> NP;		
		
		Salida2 >> aux2;
		while(!Salida2.eof()){
			Salida2 >> NombreP >> Precio >> Cantidad2;
			if(aux2 == NP){	
			   break;
			   }
				
			Salida2 >> aux2;	
		}
		
		cout << "Ingrese la cantidad del producto ingresado" <<endl;
		cin >> Cantidad;
		
		cout << "Ingrese el costo del producto ingresado" <<endl;
		cin >> Cost;
		
		time_t HV = time(0);
		tm * time = localtime(&HV);
	
		TotalC = (Cantidad*Cost);
		TSI = (TotalC/SIVA);
		TIVA = TSI*IVA;
		
		cout << "Proveedor Direccion Producto Precio Cantidad Total TotalImpuestos"<< endl;
		
		cout << time->tm_mday<<"/"<< time->tm_mon+1<< "/"<< time->tm_year+1900 << "/" << time->tm_hour<<":"<< time->tm_min<< " "  << NombreC << " " << Dire << " "<<NombreP << " Q"<< Cost << " " << Cantidad << " " << TotalC << " " <<fixed<<setprecision(2)<<TIVA  << endl;
		
		Entrada3<< time->tm_mday<<"/"<< time->tm_mon+1<< "/"<< time->tm_year+1900 << "/" << time->tm_hour<<":"<< time->tm_min<< " " << NombreC << " " << Dire << " "<<NombreP << " "<< Cost << " " << Cantidad << " " << TotalC << " " <<fixed<<setprecision(2)<<TIVA << endl;
		getch();
		
		Salida3 >> aux3;
		
		while(!Salida3.eof()){
			Salida3 >> NombreP >> Precio >> Cantidad2;
			if(aux3 == NP){
				Cantidad3 = Cantidad2+Cantidad;
				
				Entrada4 << aux2 << " " << NombreP << " " << Precio << " " << Cantidad3 << endl;
			}else {
				Entrada4 << aux2 << " " << NombreP << " " << Precio << " " << Cantidad2 << endl;	
			}
			   
	
			Salida3 >> aux3;	
		}
		
		Salida.close();
		Salida2.close();
		Salida3.close();
		Entrada3.close();
		Entrada4.close();
		
		remove("Inventario.txt");
		rename("temp.txt","Inventario.txt");
		
		}

}
void MFacturas(){
	
	if(ops == 1){
		system("cls");	
		ifstream II("FacturaV.txt");	
	while (getline(II,L)){
		Info = Info+L+"\n";
	}
	
		cout << Info << endl;
		Info = "";
    }else if(ops ==2){
    	system("cls");	
		ifstream II("FacturaC.txt");	
	while (getline(II,L)){
		Info = Info+L+"\n";
	}
	
		cout << Info << endl;
		Info = "";
}
 getch();
	}
	
int main(){
while (1)
{
	Menu = "";
	system("cls");
	ifstream AMenu("Menu Principal.txt");	
	while (getline(AMenu,L)){
		Menu =Menu+L+"\n";
	}
	
	cout << Menu << endl;
	cin >> op;

	//Opcion 1
	if(op == 1 ){
		system("cls");

		ifstream BMenu("MCliente.txt");	
		while (getline(BMenu,L)){
		SMenu =SMenu+L+"\n";
	} 
		cout << SMenu << endl;
		cin >> ops;
		Mcliente ();
		
		SMenu = "";
	}
		
			
	//Opcion 2
	else if(op == 2 ){
		system("cls");

		ifstream BMenu("MFacturas.txt");	
		while (getline(BMenu,L)){
		SMenu =SMenu+L+"\n";
	} 
		cout << SMenu << endl;
		cin >> ops;
		MFacturas();
		SMenu = "";
	}
	
	//Opcion 3
	else if(op == 3 ){
		system("cls");

		ifstream BMenu("MProductos.txt");	
		while (getline(BMenu,L)){
		SMenu =SMenu+L+"\n";
	} 
		cout << SMenu << endl;
		cin >> ops;
		MProductos ();
		
		SMenu = "";
	}
	
	//Opcion 4
	else if(op == 4 ){
		system("cls");

		ifstream BMenu("MInventario.txt");	
		while (getline(BMenu,L)){
		SMenu =SMenu+L+"\n";
	} 
		cout << SMenu << endl;
		cin >> ops;
		MInventario();
		
		SMenu = "";
	}
	
	//Opcion 5
	else if(op == 5 ){
		system("cls");

		ifstream BMenu("MProveedores.txt");	
		while (getline(BMenu,L)){
		SMenu =SMenu+L+"\n";
	} 
		cout << SMenu << endl;
		cin >> ops;
		MProveedores();
		SMenu = "";
	}
	
	//Opcion 6
	else if(op == 6 ){
		system("cls");

		ifstream BMenu("MVentas.txt");	
		while (getline(BMenu,L)){
		SMenu =SMenu+L+"\n";
	} 
		cout << SMenu << endl;
		cin >> ops;
		MVentas();
		SMenu = "";
	}
	
	//Sin Opcion
	else {
		return 0;
	}

}
}
