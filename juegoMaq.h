#ifndef FUNCIONESMAQ_H_INCLUDED
#define FUNCIONESMAQ_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<windows.h>

using namespace std;

/// DECLARACIÓN/PROTOTIPO DE FUNCIONES

void turnoVsMaq(int v[]); ///realiza las tres tiradas que implica cada turno AUTOMATICAMENTE. devuelve el puntaje obtenido y la cant de tiradas.

int juegoVsMaq(char name[2][25], int v1[], int v2[]); ///juego para 1 participante y una máquina.

int juegoVsXMaq (char name [][25], int v1[], int v2[]); ///juego para 1 participante y x máquinas

/// Desarrollo de funciones

void turnoMaq(int valores[2])
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
        Sleep(1500);
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
            Sleep(1500);
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
                Sleep(1500);
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
                Sleep(1500);
                cout<<"DESEA TIRAR DE NUEVO? SI [1] / NO [0]: "<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                Sleep(1500);
                if (sumarVector(dados,5)-15<6)
                {
                    cout<<"1"<<endl;
                    continuar=1;
                }
                else
                {
                    cout<<"0"<<endl;
                    continuar=0;
                }
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
                    Sleep(1500);
                    if (sumarVector(dados,5)-15<6)
                    {
                        cout<<"1"<<endl;
                        continuar=1;
                    }
                    else
                    {
                        cout<<"0"<<endl;
                        continuar=0;
                    }
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
                Sleep(1500);
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
                    Sleep(1500);
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
                        Sleep(1500);
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
                        Sleep(1500);
                        cout<<"DESEA TIRAR DE NUEVO? SI [1] / NO [0]: "<<endl;
                        cout<<"-----------------------------------------------------"<<endl;
                        Sleep(1500);
                        if (sumarVector(dados,5)-15<6)
                        {
                            cout<<"1"<<endl;
                            continuar=1;
                        }
                        else
                        {
                            cout<<"0"<<endl;
                            continuar=0;
                        }
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
                Sleep(1500);
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
                    Sleep(1500);
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
                    Sleep(1500);
                    cout<<"DESEA TIRAR DE NUEVO? SI [1] / NO [0]: "<<endl;
                    cout<<"-----------------------------------------------------"<<endl;
                    Sleep(1500);
                    if (sumarVector(dados,5)-15<6)
                    {
                        cout<<"1"<<endl;
                        continuar=1;
                    }
                    else
                    {
                        cout<<"0"<<endl;
                        continuar=0;
                    }
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
                Sleep(1500);
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
                Sleep(1500);
                cout<<"DESEA TIRAR DE NUEVO? SI [1] / NO [0]: "<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                Sleep(1500);
                if (sumarVector(dados,5)-15<6)
                {
                    cout<<"1"<<endl;
                    continuar=1;
                }
                else
                {
                    cout<<"0"<<endl;
                    continuar=0;
                }
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
    cout<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"PUNTAJE: "<<puntaje<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"CANTIDAD DE TIRADAS: "<<tiradas<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    Sleep(1500);
}

int juegoVsMaq (char jugador [2][25], int puntaje[2], int tiradas[2])
{
    int cantRondas=0, i, nroRonda=0, ganador=0, repetidos=0;
    int resultados[2];
    char jugadorAuto[8]="MAQUINA";
    ponerCero(puntaje,2);
    ponerCero(tiradas,2);
    cantRondas=inicioJuego();
    cout<<endl;
    system("cls");
    cout<<endl;
    cargarJugadores(jugador, 1);
    cout<<endl;
    cout<<"> JUGADOR 2: "<<jugadorAuto<<endl;
    strcpy(jugador[1], jugadorAuto);
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
    for (i=1; i<=cantRondas; i++)
    {
        nroRonda+=1;
        ponerCero(resultados,2);
        entreTurno(nroRonda, jugador[0], puntaje[0], tiradas[0]);
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"TURNO DE "<<jugador[0]<<" | ";
        cout<<"RONDA N° "<<nroRonda<<" | ";
        cout<<"PUNTAJE ACUMULADO: "<<puntaje[0]<<" PUNTOS"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        Sleep(1000);
        cout<<endl;
        turno(resultados);
        puntaje[0]+=resultados[0];
        tiradas[0]+=resultados[1];
        system("cls");
        ponerCero(resultados,2);
        entreTurno(nroRonda, jugador[1], puntaje[1], tiradas[1]);
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"TURNO DE "<<jugador[1]<<" | ";
        cout<<"RONDA N° "<<nroRonda<<" | ";
        cout<<"PUNTAJE ACUMULADO: "<<puntaje[1]<<" PUNTOS"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        Sleep(1000);
        cout<<endl;
        turnoMaq(resultados);
        puntaje[1]+=resultados[0];
        tiradas[1]+=resultados[1];
        system("cls");
    }
    puntajeTot(puntaje, 2);
    ganador=maximoVector(puntaje,2);
    repetidos=contarNumerosRepetidos(puntaje, 2, puntaje[ganador]);
    if (repetidos!=1)
    {
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"EL GANADOR (ESTA VEZ) ES "<<jugador[ganador]<<endl;
        cout<<"SU PUNTAJE FUE: "<<puntaje[ganador]<<endl;
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
                cout<<"SUS PUNTAJES FUERON IDENTICOS! TOTAL: "<<puntaje[0]<<endl;
                cout<<"PERO EL LO ALCANZO EN "<<tiradas[0]<<" TIRADAS"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                return 0;
            }
            else
            {
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"EL GANADOR (ESTA VEZ) ES "<<jugador[1]<<endl;
                cout<<"SUS PUNTAJES FUERON IDENTICOS! TOTAL: "<<puntaje[1]<<endl;
                cout<<"PERO EL LO ALCANZO EN "<<tiradas[1]<<" TIRADAS"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                return 1;
            }
        }
        else
        {
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"EMPATE!!"<<endl;
            cout<<"SU PUNTAJE FUE: "<<puntaje[ganador]<<endl;
            cout<<"LO ALCANZARON EN "<<tiradas[ganador]<<" TIRADAS"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            return -1;
        }
    }
}

int juegoVsXMaq (char jugador[][25], int puntaje[], int tiradas[])
{
    int cantRondas=0, i, j, cantMaq=0, nroRonda=0, ganador=0, repetidos=0;
    int resultados[2], jugadoresAuto[10];
    char jugadorAuto[8]="MAQUINA";
    cantRondas=inicioJuego();
    cout<<endl;
    system("cls");
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"ESTA MODALIDAD PERMITE JUGAR CONTRA HASTA 9 JUGADORES AUTOMATICOS."<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"> CONTRA CUANTOS JUGADORES AUTOMATICOS QUIERE JUGAR?: ";
    cantMaq=cantJugadores();
    system("cls");
    ponerCero(puntaje,cantMaq+1);
    ponerCero(tiradas,cantMaq+1);
    cout<<endl;
    cargarJugadores(jugador, 1);
    cargarJugadoresAuto(jugador, jugadorAuto, cantMaq+1);
    cout<<endl;
    system("pause");
    system("cls");
    for (i=1; i<=cantRondas; i++)
    {
        nroRonda++;
        ponerCero(resultados,2);
        entreTurno(nroRonda, jugador[0], puntaje[0], tiradas[0]);
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"TURNO DE "<<jugador[0]<<" | ";
        cout<<"RONDA N° "<<nroRonda<<" | ";
        cout<<"PUNTAJE ACUMULADO: "<<puntaje[0]<<" PUNTOS"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        Sleep(1000);
        cout<<endl;
        turno(resultados);
        puntaje[0]+=resultados[0];
        tiradas[0]+=resultados[1];
        system("cls");
        for (j=1; j<=cantMaq; j++)
        {
            ponerCero(resultados,2);
            cout<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"RONDA N°: "<<nroRonda<<endl;
            cout<<"PROXIMO TURNO: "<<jugador[j]<<" "<<j<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"PUNTAJE ACUMULADO: "<<puntaje[j]<<" PUNTOS"<<endl;
            cout<<"CANTIDAD DE TIRADAS: "<<tiradas[j]<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<endl;
            system("pause");
            system("cls");
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"TURNO DE "<<jugador[j]<<" "<<j<<" | ";
            cout<<"RONDA N° "<<nroRonda<<" | ";
            cout<<"PUNTAJE ACUMULADO: "<<puntaje[j]<<" PUNTOS"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            Sleep(1000);
            cout<<endl;
            turnoMaq(resultados);
            puntaje[j]+=resultados[0];
            tiradas[j]+=resultados[1];
            system("cls");
        }
    }
    if (cantMaq!=0)
    {
        puntajeTot(puntaje, cantMaq+1);
        ganador=maximoVector(puntaje, cantMaq+1);
        mostrarVector(puntaje, cantMaq+1);
        repetidos=contarNumerosRepetidos(puntaje, cantMaq+2, puntaje[ganador]);
        if (repetidos!=1)                                            ///FALTA COMPARAR CANTIDAD DE TIRADAS EN CASO DE EMPATE
        {
            cout<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"EL GANADOR (ESTA VEZ) ES "<<jugador[ganador];
            if (ganador!=0)
            {
                cout<<" "<<ganador<<endl;
            }
            else
            {
                cout<<endl;
            }
            cout<<"SU PUNTAJE FUE: "<<puntaje[ganador]<<endl;
            cout<<"LO ALCANZO EN "<<tiradas[ganador]<<" TIRADAS"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            return ganador;
        }
        else
        {
            cout<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"EMPATE!!"<<endl;
            cout<<"SU PUNTAJE FUE: "<<puntaje[ganador]<<endl;
            cout<<"LO ALCANZARON EN "<<tiradas[ganador]<<" TIRADAS"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            return -1;
        }
    }
}

#endif // FUNCIONESMAQ_H_INCLUDED
