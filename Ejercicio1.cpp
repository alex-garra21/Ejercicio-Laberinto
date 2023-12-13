/* Detalles para la realización del juego de Laberinto (Ejercicio del Curso Algoritmos)

1.  Realizar un laberinto de por lo menos 60 columnas, 20 filas

2.  Colocar 20 comidas (asteriscos) aleatorias dentro del laberinto

3. Colocar un contador que se incremente cada vez que se coma un asterisco

4. Colocar una salida del laberinto, si la nave se sale del laberinto indique FIN DEL JUEGO

DESCRIPCIÓN DEL JUEGO REALIZADO
- El usuario puede elegir la cantidad de comidas, filas y columnas que desea cada vez que se inice el juego.
- El juego cuenta con un contador, para cada comida que consuma durante la partida, por lo que al finalizar el juego, muestra cuantos consumibles se sumaron.
*/

#include <iostream>
#include <stdio.h>  
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//Inge, cambie el 0, que tenia que ser el cursor, o lo que se moviera, por una tecla especial que encontre en codigo ascii, asi como las paredes y el rellenado. :)

using namespace std;

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }

void jugarMatriz(int f, int c, int com){
	//declaracion inicial de la matriz.
	char mat[100][100];
	//Declaracioin de la posicion de inicio de la nave.
	int x=1, y=1;
	//Declaracion de la variable para leer las teclas presionadas por el teclado.
	char tecla;
	
	//logica 
	for (int i=0;i<c;i++){
		for (int j=0;j<f;j++)
		{
			mat[i][j]=char(32); // rellenando la matriz con espacios en blanco, para una mejor presentacion visual.
			// Cerrando el laberinto.
			if ((i==0)||(i==c-1)){
				if ((i==c-1) && (j==(f-2))) mat[i][j]= char(32); //Dejando la puerta para la salida.
				else mat[i][j]= char(219);
			}
			if ((j==0)||(j==f-1))
			   mat[i][j]= char(219);
	
		}
	}

		int x1, y1, k, count = 0; //Utilizado para la generacion de coordenadas aleatoreas y el contador.
		//Limites para las coordenadas aleatoreas.
		int lim_inf = 1;
		int lim_sX = c-2;
		int lim_sY = f-2;

		for (k=0;k<com;k++){ //Utilicando la variable com, para el limite definido por el usuario al iniciar el programa.
			x1 = lim_inf + (rand() % (lim_sX + 1 - lim_inf)); //numero aleatoreo para x.
			y1 = lim_inf + (rand() % (lim_sY + 1 - lim_inf)); //numero aleatoreo para y.
			mat[x1][y1] = '*'; //colocando asteriscos (comidas), en las posiciones aleatoreas.
		}

	while (tecla!=27){  //repetir hasta que se presione la tecla ESC
		if ((x==c-1) && (y==(f-2))) {
			system("cls"); //Limpiar la pantalla, para quitar la matriz y mostrar los datos finales.
			//Datos para el final del juego.
			cout<<"Fin del Juego\n";
			cout<< "Usted comio " << count << " " << char(42) <<" durante el juego, de " << com << " disponibles.\n\n";
			//Creditos
			cout<< char(184) << " Creado por Steven Reyes, para el curso de Algoritmos. (tambien ayudado por algunos videos de youtube)";
			cout<<"\nDocente, Ing. Edwin Macz\n";
			system("pause");
			break;
		}
		else {
			mat[x][y]= char(30);		//colocar la nave en la columna x fila y
			int tempX = x, tempY = y;

			//vista
			for (int i=0;i<c;i++){
				for (int j=0;j<f;j++)
				{
					gotoxy(i,j);
					cout<<mat[i][j];
				}
			}
			cout<< "\n\nCantidad de "<< '*' <<" consumidos: " << count;
			cout<< "\n\nIndicaciones: puede utilizar las siguientes teclas para movilizarse,";
			cout<< "\n'a' para la derecha, 'd' para la izquierda, 's' para abajo y 'w' para arriba";
			cout<< "\n\nSu Laberinto esta conformado por "<< f << " filas y " << c << " columnas, asi tambien cuenta con "<< com <<" comidas "<< char(42) << " disponibles.";
			cout<< "\n\nUtilice el espacio en blanco, como salida del juego.";
			cout<< "\n\n";

			tecla=getch();      //leer tecla
			if ((tecla=='d') && (mat[x+1][y]!=char(219))) //izquierda
				{
				if (mat[x+1][y]=='*') count++;
					x++;					//Avanzar una columna
				mat[tempX][tempY]=char(32);}	//Borrar rastro
				
			if ((tecla=='s') && (mat[x][y+1]!=char(219)) )  //abajo
				{
				if (mat[x][y+1]=='*') count++;
					y++;					//Avanzar una fila
				mat[tempX][tempY]=char(32);}	//Borrar rastro
				
			if ((tecla=='a')  && (mat[x-1][y]!=char(219)) )	 //derecha
				{
				if (mat[x-1][y]=='*') count++;
					x--;					//Regresar una columna
				mat[tempX][tempY]=char(32);}	//Borrar rastro
				
			if (tecla=='w'   && (mat[x][y-1]!=char(219)))  //arriba
				{
				if (mat[x][y-1]=='*') count++;
					y--;					//Regresar una fila
				mat[tempX][tempY]=char(32);}	//Borrar rastro

			// fin de la vista
		}
	}
}
 
main(){  
	int f, c, com, k;
	char tecla;

	while (tecla!=32){
		system("cls"); //Limpiar la pantalla para una buena presentacion inicial.

		// Titulo del Juego.
		for (k=1; k<=81; k++){
			gotoxy(k,1);cout<<char(176);
		}
		for (k=1; k<=81; k++){
			gotoxy(k,5);cout<<char(176);
		}
		gotoxy(0,2);cout<<" "<<char(176);
		gotoxy(80,2);cout<<" "<<char(176);
		gotoxy(0,3);cout<<" "<<char(176);
		gotoxy(80,3);cout<<" "<<char(176);
		gotoxy(0,4);cout<<" "<<char(176);
		gotoxy(80,4);cout<<" "<<char(176);
		gotoxy(30,3);cout<<"LABERINTO V 2.0";

		//ingreso de datos por el usuario, para iniciar el juego.
		gotoxy(2,7);cout<<"Para iniciar el juego, ingrese los datos que se le solicitan a continuacion. \n";
		gotoxy(2,9);cout<<"Ingrese un numero entre 20 y 30, para las filas que desee en el laberinto: ";
		cin>>f; //Numero de filas ingresadas para la matriz que formara el laberinto.
		gotoxy(2,10);cout<<"Ingrese un numero entre 60 y 100, para las columnas que desee en el laberinto: ";
		cin>>c; //Numero de columnas ingresadas para la matriz que formara el laberinto.
		gotoxy(2,11);cout<<"Ingrese un numero entre 20 y 50, para la cantidad de comidas "<< char(42) << " para que aparezcan en el laberinto: ";
		cin>>com; //Numero de comestibles ingresado para que aparezcan de manera aleatorea en el laberinto.
		if ((f>=20) && (f<=30) && (c>=60) && (c<=100) && (com>=20) && (com<=50)){
			gotoxy(2,13);cout<< "BIENVENIDO";
			gotoxy(2,15);cout<< "Su juego iniciara con con un laberinto conformado por "<< f << " filas y " << c << " columnas, asi tambien tendra "<< com <<" comidas "<< char(42) << " disponibles.";
			gotoxy(2,17);cout<< "Presiones la tecla espacio, para iniciar el juego... o presione cualquier otra tecla para volver a ingresar datos...";
			tecla = getch();
		}
		else {
			gotoxy(2,13);cout<< "los datos ingresados estan fuera del rango permitido";
			gotoxy(2,15);cout<< "Presione cualquier tecla para volver a ingresar datos...";
			tecla = getch();
		}
	}

	system("cls"); //Limpiar la pantalla antes de iniciar el juego.
	jugarMatriz(f, c, com);

}
