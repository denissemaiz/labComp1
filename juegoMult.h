#ifndef FUNCIONESJUGMULT_H_INCLUDED
#define FUNCIONESJUGMULT_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cstring>

using namespace std;

/// DECLARACION DE FUNCIONES

int juego2Part(char name [2][25], int v1[], int v2[]); ///juego para 2 participantes

void juegoXPart(); ///juego para X participantes

/// DESARROLLO DE FUNCIONES

int juego2Part (char jugador [2][25], int puntaje[2], int tiradas[2])
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
            cartelTurno(jugador[j], nroRonda, puntaje[j]);
            turno(resultados);
            puntaje[j]+=resultados[0];
            tiradas[j]+=resultados[1];
            system("pause>null");
            system("cls");
        }
    }
    puntajeTot(puntaje, 2);
    ganador=maximoVector(puntaje, 2);
    repetidos=contarNumerosRepetidos(puntaje, 2, puntaje[ganador]);
    if (repetidos==1)
    {
        ganadorPuntos(jugador[ganador], puntaje[ganador], tiradas[ganador]);
        return ganador;
    }
    else
    {
        if(tiradas[0]!=tiradas[1])
        {
            if (tiradas[0]<tiradas[1])
            {
                ganadorTiradas(jugador[0], puntaje[0], tiradas[0]);
                return 0;
            }
            else
            {
                ganadorTiradas(jugador[1], puntaje[1], tiradas[1]);
                return 1;
            }
        }
        else
        {
            empate(puntaje[ganador], tiradas[ganador]);
            return -1;
        }
    }
}

int juegoXPart (char jugador [][25], int puntaje[], int tiradas[])
{
    int cantRondas=0, i, j, cantJug=0, nroRonda=0, repetidos=0, ganador=0;
    int resultados[2];
    cantRondas=inicioJuego();
    cout<<endl;
    cout<<endl;
    system("pause");
    system("cls");
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"ESTA MODALIDAD PERMITE JUGAR DE A 3 A 10 JUGADORES."<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"> INGRESE LA CANTIDAD DE JUGADORES: ";
    cantJug=cantJugadores();
    if (cantJug!=0)
    {
        ponerCero(puntaje,cantJug);
        ponerCero(tiradas,cantJug);
        cout<<endl;
        cargarJugadores(jugador, cantJug);
        cout<<endl;
        cout<<endl;
        system("pause");
        system("cls");
        for (i=1; i<=cantRondas; i++)
        {
            nroRonda++;
            for (j=0; j<=cantJug-1; j++)
            {
                ponerCero(resultados,2);
                entreTurno(nroRonda, jugador[j], puntaje[j], tiradas[j]);
                cartelTurno(jugador[j], nroRonda, puntaje[j]);
                turno(resultados);
                puntaje[j]+=resultados[0];
                tiradas[j]+=resultados[1];
                system("pause>null");
                system("cls");
            }
        }
        puntajeTot(puntaje, cantJug);
        ganador=maximoVector(puntaje, cantJug);
        repetidos=contarNumerosRepetidos(puntaje, cantJug, puntaje[ganador]);
        if (repetidos==1)
        {
            ganadorPuntos(jugador[ganador], puntaje[ganador], tiradas[ganador]);
            return ganador;
        }
        else ///FALTA COMPARAR CANTIDAD DE TIRADAS DE TODOS LOS JUGADORES EN CASO DE EMPATE X PUNTOS
        {
            empate(puntaje[ganador], tiradas[ganador]);
            return -1;
        }
    }
}

#endif // FUNCIONESJUGMULT_H_INCLUDED
