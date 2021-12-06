#ifndef FUNCIONESJUGMULT_H_INCLUDED
#define FUNCIONESJUGMULT_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cstring>

using namespace std;

/// DECLARACIÓN/PROTOTIPO DE FUNCIONES

int juego2Part(char name [2][25], int v1[], int v2[]); ///juego para 2 participantes

void juegoXPart(); ///juego para X participantes

/// Desarrollo de funciones

int juego2Part (char jugador [2][25], int puntaje[2], int tiradas[2])
{
    int cantRondas=0, i, j, nroRonda=0, ganador=0, repetidos=0;
    int resultados[2];
    ponerCero(puntaje,2);
    ponerCero(tiradas,2);
    cantRondas=inicioJuego();
    cout<<endl;
    cargarJugadores(jugador, 2);
    system("pause");
    system("cls");
    for (i=1; i<=cantRondas; i++)
    {
        nroRonda+=1;
        for (j=0; j<=1; j++)
        {
            ponerCero(resultados,2);
            entreTurno(nroRonda, jugador[j], puntaje[j], tiradas[j]);
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"TURNO DE "<<jugador[j]<<" | ";
            cout<<"RONDA N° "<<nroRonda<<" | ";
            cout<<"PUNTAJE ACUMULADO: "<<puntaje[j]<<" PUNTOS"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            Sleep(1000);
            cout<<endl;
            turno(resultados);
            puntaje[j]+=resultados[0];
            tiradas[j]+=resultados[1];
            system("pause>null");
            system("cls");
        }
    }
    puntajeTot(puntaje, 2);
    ganador=maximoVector(puntaje,2);
    repetidos=contarNumerosRepetidos(puntaje, 2, puntaje[ganador]); ///REVISAR ESTO MUESTRA MAL LOS CARTELES
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

int juegoXPart (char jugador [][25], int puntaje[], int tiradas[])
{
    int cantRondas=0, i, j, cantJug=0, nroRonda=0, repetidos=0, ganador=0;
    int resultados[2];
    cantRondas=inicioJuego();
    cout<<endl;
    system("cls");
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"ESTA MODALIDAD PERMITE JUGAR DE A 3 A 10 JUGADORES."<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"> INGRESE LA CANTIDAD DE JUGADORES: ";
    cantJug=cantJugadores();

    if (cantJug!=0)
    {
        system("cls");
        ponerCero(puntaje,cantJug);
        ponerCero(tiradas,cantJug);
        cout<<"------------------------------------------------"<<endl;  ///vuelve aca
        cargarJugadores(jugador, cantJug);
        cout<<"------------------------------------------------"<<endl;
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
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"TURNO DE "<<jugador[j]<<" | ";
                cout<<"RONDA NRO. "<<nroRonda<<" | ";
                cout<<"PUNTAJE ACUMULADO: "<<puntaje[j]<<" PUNTOS"<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                Sleep(1000);
                cout<<endl;
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
        if (repetidos!=1)           ///FALTA COMPARAR CANTIDAD DE TIRADAS EN CASO DE EMPATE
        {
            cout<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"EL GANADOR (ESTA VEZ) ES "<<jugador[ganador]<<"!!!"<<endl;
            cout<<"SU PUNTAJE FUE: "<<puntaje[ganador]<<" PUNTOS"<<endl;
            cout<<"LO ALCANZO EN "<<tiradas[ganador]<<" TIRADAS"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            return ganador;

        }
        else
        {
            cout<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"EMPATE!!"<<endl;
            cout<<"SU PUNTAJE FUE: "<<puntaje[ganador]<<" PUNTOS"<<endl;
            cout<<"LO ALCANZARON EN "<<tiradas[ganador]<<" TIRADAS"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            return -1;
        }
    }
}

#endif // FUNCIONESJUGMULT_H_INCLUDED
