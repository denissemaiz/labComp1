#ifndef FUNCIONES2_H_INCLUDED
#define FUNCIONES2_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<windows.h>

using namespace std;


/// DECLARACIÓN/PROTOTIPO DE FUNCIONES

int inicioJuego(); ///da inicio a todos los juegos preguntando cuántas rondas se jugarán

void cargarJugadores(char v[][25], int tam); ///pide los nombres de los jugadores

void mostrarJugadores(char v[][25], int tam); ///muestra los nombres de los jugadores

int cantJugadores (); ///pide ingreso de cantidad de jugadores

void puntajeTot (int v[], int tam); ///muestra los puntajes totales de cada jugador al finalizar la partida

void entreTurno (int ronda, char jugador[25], int puntaje, int tiradas);  ///muestra los resultados obtenidos hasta el momento antes de empezar el turno de cada jugador.

void turno(int v[]); ///realiza las tres tiradas que implica cada turno. devuelve el puntaje obtenido y la cant de tiradas.

/// Desarrollo de funciones

int inicioJuego ()
{
    int cant;
    cout<<"------------------------------------------------"<<endl;
    cout<<"BIENVENIDOS A BARCO, CAPITAN , TRIPULACION!"<<endl;
    cout<<"------------------------------------------------"<<endl<<endl;
    cout<<"> CUANTAS RONDAS SE JUGARAN?: ";
    cin>>cant;
    return cant;
}

void cargarJugadores(char v[][25], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cout<<"> JUGADOR "<<i+1<<", INGRESE SU NOMBRE: ";
        cin>>v[i];
    }
}

void cargarJugadoresAuto(char v[][25], char nom[8], int tam)
{
    int i;
    for(i=1; i<tam; i++)
    {
        cout<<"> JUGADOR "<<i+1<<", INGRESE SU NOMBRE: ";
        strcpy(v[i], nom);
        Sleep(500);
        cout<<v[i]<<" "<<i<<endl;
        Sleep(1000);
    }
}

void mostrarJugadores(char v[][25], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        cout<<v[i]<<"\t";
    }
}

int cantJugadores ()
{
    int cant;
    cin>>cant;
    if (cant<3||cant>10)
    {
        system("cls");
        cout<<endl;
        cout<<"-------ERROR-------"<<endl<<endl;
        system("pause");
        return 0;
    }
    else
    {
        return cant;
    }
}

void puntajeTot (int v[], int tam)
{
    int i;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"PUNTAJE TOTAL: "<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    for (i=0; i<=tam-1; i++)
    {
        cout<<"> JUGADOR "<<i+1<<": "<<v[i]<<endl;
    }
    cout<<"-----------------------------------------------------"<<endl;
}

void entreTurno (int ronda, char jugador[25], int puntaje, int tiradas)
{
    cout<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"RONDA NRO. "<<ronda<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"PROXIMO TURNO: "<<jugador<<endl;
    cout<<"PUNTAJE ACUMULADO: "<<puntaje<<" PUNTOS"<<endl;
    cout<<"CANTIDAD DE TIRADAS: "<<tiradas<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

void turno(int valores[2])
{
    int conseguidos, continuar;
    int dados [5], puntaje=0, tiradas=0;
    bool frenar=false;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"TIRADA N°1"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    tiradas+=1;
    cout<<endl;
    cargarAleatorio(dados,5,6);
    mostrarVector(dados,5);
    cout<<endl;
    cout<<endl;
    if (posicionNumeroEnVector(dados,5,6)==-1)
    {
        conseguidos=0;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"NADA :("<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        system("pause>null");
        cout<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"TIRADA N°2"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        tiradas+=1;
        cout<<endl;
        cargarAleatorio(dados,5,6);
        mostrarVector(dados,5);
        cout<<endl;
    }
    else
    {
        if (posicionNumeroEnVector(dados,5,5)==-1)
        {
            conseguidos=1;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"CONSEGUISTE EL BARCO!"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            system("pause>null");
            cout<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"TIRADA N°2"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            tiradas+=1;
            cout<<endl;
            cargarAleatorio(dados,4,6);
            mostrarVector(dados,4);
            cout<<endl;
        }
        else
        {
            if (posicionNumeroEnVector(dados,5,4)==-1)
            {
                conseguidos=2;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"CONSEGUISTE EL BARCO Y CONTRATASTE AL CAPITAN!"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                system("pause>null");
                cout<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"TIRADA N°2"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                tiradas+=1;
                cout<<endl;
                cargarAleatorio(dados,3,6);
                mostrarVector(dados,3);
                cout<<endl;
            }
            else
            {
                conseguidos=3;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"BARCO, CAPITAN Y TRIPULACION. TODO LISTO PARA ZARPAR!"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                Sleep(1000);
                cout<<"DESEA TIRAR DE NUEVO? SI [1] / NO [0]: "<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cin>>continuar;
                switch(continuar)
                {
                case 1:
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"TIRADA N°2"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    tiradas+=1;
                    cout<<endl;
                    cargarAleatorio(dados,2,6);
                    mostrarVector(dados,2);
                    cout<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"DESEA TIRAR DE NUEVO? SI [1] / NO [0]: "<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cin>>continuar;
                    switch(continuar)
                    {
                    case 1:
                        frenar=true;
                        cout<<"-----------------------------------------------------"<<endl;
                        cout<<"TIRADA N°3"<<endl;
                        cout<<"-----------------------------------------------------"<<endl;
                        tiradas+=1;
                        cout<<endl;
                        cargarAleatorio(dados,2,6);
                        mostrarVector(dados,2);
                        cout<<endl;
                        cout<<endl;
                        puntaje=sumarVector(dados,2);
                        break;
                    case 0:
                        frenar=true;
                        puntaje=sumarVector(dados,2);
                        break;
                    default:
                        cout<<endl;
                        cout<<"-------ERROR-------"<<endl<<endl;
                        break;
                    }
                    break;
                case 0:
                    frenar=true;
                    puntaje=sumarVector(dados,5)-15;
                    break;
                default:
                    cout<<endl;
                    cout<<"-------ERROR-------"<<endl<<endl;
                    break;
                }
            }
        }
    }
    cout<<endl;
    if (frenar==false)
    {
        switch(conseguidos)
        {
        case 0:
            if (posicionNumeroEnVector(dados,5,6)==-1)
            {
                conseguidos=0;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"NADA :("<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                system("pause>null");
                cout<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"TIRADA N°3"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                tiradas+=1;
                cout<<endl;
                cargarAleatorio(dados,5,6);
                mostrarVector(dados,5);
                cout<<endl;
                cout<<endl;
            }
            else
            {
                if (posicionNumeroEnVector(dados,5,5)==-1)
                {
                    conseguidos=1;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"CONSEGUISTE EL BARCO!"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    system("pause>null");
                    cout<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"TIRADA N°3"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    tiradas+=1;
                    cout<<endl;
                    cargarAleatorio(dados,4,6);
                    mostrarVector(dados,4);
                    cout<<endl;
                    cout<<endl;
                }
                else
                {
                    if (posicionNumeroEnVector(dados,5,4)==-1)
                    {
                        conseguidos=2;
                        cout<<"-----------------------------------------------------"<<endl;
                        cout<<"CONSEGUISTE EL BARCO Y CONTRATASTE AL CAPITAN!"<<endl;
                        cout<<"-----------------------------------------------------"<<endl;
                        system("pause>null");
                        cout<<endl;
                        cout<<"-----------------------------------------------------"<<endl;
                        cout<<"TIRADA N°3"<<endl;
                        cout<<"-----------------------------------------------------"<<endl;
                        tiradas+=1;
                        cout<<endl;
                        cargarAleatorio(dados,3,6);
                        mostrarVector(dados,3);
                        cout<<endl;
                        cout<<endl;
                    }
                    else
                    {
                        frenar=true;
                        cout<<"-----------------------------------------------------"<<endl;
                        cout<<"BARCO, CAPITAN Y TRIPULACION. TODO LISTO PARA ZARPAR!"<<endl;
                        cout<<"-----------------------------------------------------"<<endl;
                        Sleep(1000);
                        cout<<"DESEA TIRAR DE NUEVO? SI [1] / NO [0]: "<<endl;
                        cout<<"-----------------------------------------------------"<<endl;
                        cin>>continuar;
                        switch(continuar)
                        {
                        case 1:
                            frenar=true;
                            cout<<"-----------------------------------------------------"<<endl;
                            cout<<"TIRADA N°3"<<endl;
                            cout<<"-----------------------------------------------------"<<endl;
                            tiradas+=1;
                            cout<<endl;
                            cargarAleatorio(dados,2,6);
                            mostrarVector(dados,2);
                            cout<<endl;
                            cout<<endl;
                            puntaje=sumarVector(dados,2);
                            break;
                        case 0:
                            frenar=true;
                            puntaje=sumarVector(dados,5)-15;
                            break;
                        default:
                            cout<<endl;
                            cout<<"-------ERROR-------"<<endl<<endl;
                            break;
                        }
                    }
                }
            }
            break;
        case 1:
            if (posicionNumeroEnVector(dados,4,5)==-1)
            {
                conseguidos=1;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"SEGUIMOS BUSCANDO CAPITAN"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                system("pause>null");
                cout<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"TIRADA N°3"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                tiradas+=1;
                cout<<endl;
                cargarAleatorio(dados,4,6);
                mostrarVector(dados,4);
                cout<<endl;
                cout<<endl;
            }
            else
            {
                if (posicionNumeroEnVector(dados,4,4)==-1)
                {
                    conseguidos=2;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"CONTRATASTE AL CAPITAN!"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    system("pause>null");
                    cout<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"TIRADA N°3"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    tiradas+=1;
                    cout<<endl;
                    cargarAleatorio(dados,3,6);
                    mostrarVector(dados,3);
                    cout<<endl;
                    cout<<endl;
                }
                else
                {
                    frenar=true;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"BARCO, CAPITAN Y TRIPULACION. TODO LISTO PARA ZARPAR!"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    Sleep(1000);
                    cout<<"DESEA TIRAR DE NUEVO? SI [1] / NO [0]: "<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cin>>continuar;
                    switch(continuar)
                    {
                    case 1:
                        frenar=true;
                        cout<<"-----------------------------------------------------"<<endl;
                        cout<<"TIRADA N°3"<<endl;
                        cout<<"-----------------------------------------------------"<<endl;
                        tiradas+=1;
                        cout<<endl;
                        cargarAleatorio(dados,2,6);
                        mostrarVector(dados,2);
                        cout<<endl;
                        cout<<endl;
                        puntaje=sumarVector(dados,2);
                        break;
                    case 0:
                        frenar=true;
                        puntaje=sumarVector(dados,4)-9;
                        break;
                    default:
                        cout<<endl;
                        cout<<"-------ERROR-------"<<endl<<endl;
                        break;
                    }
                }
            }
            break;
        case 2:
            if (posicionNumeroEnVector(dados,3,4)==-1)
            {
                conseguidos=2;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"TODAVIA SIN TRIPULACION"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                system("pause>null");
                cout<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"TIRADA N°3"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                tiradas+=1;
                cout<<endl;
                cargarAleatorio(dados,3,6);
                mostrarVector(dados,3);
                cout<<endl;
                cout<<endl;
            }
            else
            {
                frenar=true;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"BARCO, CAPITAN Y TRIPULACION. TODO LISTO PARA ZARPAR!"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                Sleep(1000);
                cout<<"DESEA TIRAR DE NUEVO? SI [1] / NO [0]: "<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cin>>continuar;
                switch(continuar)
                {
                case 1:
                    frenar=true;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"TIRADA N°3"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    tiradas+=1;
                    cout<<endl;
                    cargarAleatorio(dados,2,6);
                    mostrarVector(dados,2);
                    cout<<endl;
                    cout<<endl;
                    puntaje=sumarVector(dados,2);
                    break;
                case 0:
                    frenar=true;
                    puntaje=sumarVector(dados,3)-4;
                    break;
                default:
                    cout<<endl;
                    cout<<"-------ERROR-------"<<endl<<endl;
                    break;
                }
            }
            break;
        }
    }
    if (frenar==false)
    {
        switch(conseguidos)
        {
        case 0:
            if (posicionNumeroEnVector(dados,5,6)==-1)
            {
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"NADA :("<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<endl;
            }
            else
            {
                if (posicionNumeroEnVector(dados,5,5)==-1)
                {
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"CONSEGUISTE EL BARCO, PERO NO ALCANZO."<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<endl;
                }
                else
                {
                    if (posicionNumeroEnVector(dados,5,4)==-1)
                    {
                        cout<<"-----------------------------------------------------"<<endl;
                        cout<<"QUE SON UN BARCO Y UN CAPITAN SIN SU TRIPULACION?"<<endl;
                        cout<<"-----------------------------------------------------"<<endl;
                        cout<<endl;
                    }
                    else
                    {
                        frenar=true;
                        cout<<"-----------------------------------------------------"<<endl;
                        cout<<"BARCO, CAPITAN Y TRIPULACION. TODO LISTO PARA ZARPAR!"<<endl;
                        cout<<"-----------------------------------------------------"<<endl;
                        puntaje=sumarVector(dados,5)-15;
                    }
                }
            }
            break;
        case 1:
            if (posicionNumeroEnVector(dados,4,5)==-1)
            {
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"TE QUEDASTE SOLO CON EL BARCO </3"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<endl;
            }
            else
            {
                if (posicionNumeroEnVector(dados,4,4)==-1)
                {
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"QUE SON UN BARCO Y UN CAPITAN SIN SU TRIPULACION?"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<endl;
                }
                else
                {
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"BARCO, CAPITAN Y TRIPULACION. TODO LISTO PARA ZARPAR!!!"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    puntaje=sumarVector(dados,4)-9;
                }
            }
            break;
        case 2:
            if (posicionNumeroEnVector(dados,3,4)==-1)
            {
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"QUE SON UN BARCO Y UN CAPITAN SIN SU TRIPULACION?"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<endl;
            }
            else
            {
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"BARCO, CAPITAN Y TRIPULACION. TODO LISTO PARA ZARPAR!"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                puntaje=sumarVector(dados,3)-4;
            }
            break;
        }
    }
    valores[0]=puntaje;
    valores[1]=tiradas;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"PUNTAJE: "<<puntaje<<" PUNTOS"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"CANTIDAD DE TIRADAS: "<<tiradas<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    Sleep(2000);
}
#endif // FUNCIONES2_H_INCLUDED
