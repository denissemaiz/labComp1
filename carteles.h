#ifndef CARTELES_H_INCLUDED
#define CARTELES_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
using namespace std;

/// DECLARACION DE FUNCIONES

void cartelTurno(char nom[25], int ronda, int punt); ///cartel durante el turno

void ganadorPuntos(char nom[25], int punt, int tir); ///cartel de 1 ganador (por cant de puntos)

void ganadorTiradas(char nom[25], int punt, int tir); ///cartel de 1 ganador (por cant de tiradas)

void empate(int punt, int tir); ///cartel empate

/// DESARROLLO DE FUNCIONES

void cartelTurno(char nom[25], int ronda, int punt)
{
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"TURNO DE "<<nom<<" | ";
    printf("RONDA N%c ",167);
    cout<<ronda<<" | ";
    cout<<"PUNTAJE ACUMULADO: "<<punt<<" PUNTOS"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    Sleep(1000);
    cout<<endl;
}

void ganadorPuntos(char nom[25], int punt, int tir)
{
    cout<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"EL GANADOR (ESTA VEZ) ES "<<nom<<endl;
    cout<<"SU PUNTAJE FUE: "<<punt<<" PUNTOS"<<endl;
    cout<<"LO ALCANZO EN "<<tir<<" TIRADAS"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
}

void ganadorTiradas(char nom[25], int punt, int tir)
{
    cout<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"EL GANADOR (ESTA VEZ) ES "<<nom<<endl;
    cout<<"SUS PUNTAJES FUERON IDENTICOS! TOTAL: "<<punt<<" PUNTOS"<<endl;
    cout<<"PERO EL LO ALCANZO EN "<<tir<<" TIRADAS"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
}

void empate(int punt, int tir)
{
    cout<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"EMPATE!!"<<endl;
    cout<<"SU PUNTAJE FUE: "<<punt<<" PUNTOS"<<endl;
    cout<<"LO ALCANZARON EN "<<tir<<" TIRADAS"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
}

#endif // CARTELES_H_INCLUDED
