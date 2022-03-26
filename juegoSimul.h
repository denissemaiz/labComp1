#ifndef FUNCIONESSIMUL_H_INCLUDED
#define FUNCIONESSIMUL_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cstring>

using namespace std;

/// DECLARACIÓN/PROTOTIPO DE FUNCIONES

void turnoSimulado (int v[]); ///realiza las tres tiradas que implica cada turno. devuelve el puntaje obtenido y la cant de tiradas.

int modoSimulado(char name[2][25], int v1[], int v2[]); ///juego simulado

/// Desarrollo de funciones

void turnoSimulado (int valores [2])
{
    int conseguidos, continuar;
    int dados [5], puntaje=0, tiradas=0;
    bool frenar=false;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"TIRADA N°1"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    tiradas+=1;
    cout<<endl;
    cargarVector(dados,5);
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
        cargarVector(dados,5);
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
            cargarVector(dados,4);
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
                cargarVector(dados,3);
                mostrarVector(dados,3);
                cout<<endl;
            }
            else
            {
                conseguidos=3;
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
                    cargarVector(dados,2);
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
                        cargarVector(dados,2);
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
                cargarVector(dados,5);
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
                    cargarVector(dados,4);
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
                        cargarVector(dados,3);
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
                            cargarVector(dados,2);
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
                cargarVector(dados,4);
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
                    cargarVector(dados,3);
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
                        cargarVector(dados,2);
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
                cargarVector(dados,3);
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
                    cargarVector(dados,2);
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
                    frenar=true;
                    cout<<"-----------------------------------------------------"<<endl;
                    cout<<"BARCO, CAPITAN Y TRIPULACION. TODO LISTO PARA ZARPAR!!!"<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    puntaje=sumarVector(dados,4)-9;
                    cout<<endl;
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
                frenar=true;
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
    cout<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"PUNTAJE: "<<puntaje<<" PUNTOS"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"CANTIDAD DE TIRADAS: "<<tiradas<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    system("pause>null");
}

int modoSimulado(char jugador [][25], int puntaje[2], int tiradas[2])
{
    int cantRondas=0, i, j, nroRonda=0, ganador=0, repetidos=0;
    int resultados[2];
    ponerCero(puntaje,2);
    ponerCero(tiradas,2);
    cantRondas=inicioJuego();
    cout<<endl;
    cargarJugadores(jugador, 2);
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
    for (i=1; i<=cantRondas; i++)
    {
        nroRonda+=1;
        for (j=0; j<=1; j++)
        {
            ponerCero(resultados,2);
            entreTurno(nroRonda, jugador[j], puntaje[j], tiradas[j]);
            cout<<"TURNO DE "<<jugador[j]<<" | ";
            cout<<"RONDA N° "<<nroRonda<<" | ";
            cout<<"PUNTAJE ACUMULADO: "<<puntaje[j]<<" PUNTOS"<<endl;
            Sleep(1000);
            cout<<endl;
            turnoSimulado(resultados);
            puntaje[j]+=resultados[0];
            tiradas[j]+=resultados[1];
            system("pause>null");
            system("cls");
        }
    }
    puntajeTot(puntaje, 2);
    ganador=maximoVector(puntaje,2);
    repetidos=contarNumerosRepetidos(puntaje, 2, puntaje[ganador]);
    if (repetidos!=1)
    {
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"EL GANADOR (ESTA VEZ) ES "<<jugador[ganador]<<endl;
        cout<<"SU PUNTAJE FUE: "<<puntaje[ganador]<<" PUNTOS"<<endl;
        cout<<"LO ALCANZO EN "<<tiradas[ganador]<<" TIRADAS"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        return ganador;
    }
    else
    {
        if(tiradas[0]!=tiradas[1])
        {
            if (tiradas[0]<tiradas[1])
            {
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"EL GANADOR (ESTA VEZ) ES "<<jugador[0]<<endl;
                cout<<"SUS PUNTAJES FUERON IDENTICOS! TOTAL: "<<puntaje[0]<<" PUNTOS"<<endl;
                cout<<"PERO EL LO ALCANZO EN "<<tiradas[0]<<" TIRADAS"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                return 0;
            }
            else
            {
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"EL GANADOR (ESTA VEZ) ES "<<jugador[1]<<endl;
                cout<<"SUS PUNTAJES FUERON IDENTICOS! TOTAL: "<<puntaje[1]<<" PUNTOS"<<endl;
                cout<<"PERO EL LO ALCANZO EN "<<tiradas[1]<<" TIRADAS"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                return 1;
            }
        }
        else
        {
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"EMPATE!!"<<endl;
            cout<<"SU PUNTAJE FUE: "<<puntaje[ganador]<<" PUNTOS"<<endl;
            cout<<"LO ALCANZARON EN "<<tiradas[ganador]<<" TIRADAS"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            return -1;
        }
    }
}

#endif // FUNCIONESSIMUL_H_INCLUDED
