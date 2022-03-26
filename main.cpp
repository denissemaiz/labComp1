#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>

using namespace std;

#include "funciones.h"
#include "funciones2.h"
#include "carteles.h"
#include "juegoSimul.h"
#include "juegoMult.h"
#include "juegoMaq.h"

int main()
{
    int opc;
    char jugador [10][25];
    int puntaje [10], tiradas [10], maxGanador=-2;
    while (true)
    {
        system("cls");
        cout<<"------------------------"<<endl;
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1. JUEGO NUEVO ENTRE DOS PARTICIPANTES"<<endl;
        cout<<"2. JUEGO NUEVO ENTRE X PARTICIPANTES"<<endl;
        cout<<"3. JUEGO NUEVO CONTRA LA MAQUINA"<<endl;
        cout<<"4. JUEGO NUEVO CONTRA X MAQUINAS"<<endl;
        cout<<"5. MOSTRAR PUNTUACION MAS ALTA"<<endl;
        cout<<"6. MODO SIMULADO"<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            maxGanador=juego2Part(jugador, puntaje, tiradas);
            break;
        case 2:
            maxGanador=juegoXPart(jugador, puntaje, tiradas);
            break;
        case 3:
            maxGanador=juegoVsMaq(jugador, puntaje, tiradas);
            break;
        case 4:
            maxGanador=juegoVsXMaq(jugador, puntaje, tiradas);
            break;
        case 5:
            if (maxGanador==-2)
            {
                cout<<endl;
                cout<<"MMM... AUN NO HAS INICIADO UN JUEGO.";
            }
            else
            {
                if (maxGanador==-1)   ///FALTA COMPARAR PUNTAJES DE DISTINTOS JUEGOS
                {
                    cout<<endl;
                    cout<<"EMPATE! EL PUNTAJE MAS ALTO ES DE AMBOS"<<endl;
                    cout<<"PUNTAJE MAS ALTO: "<<puntaje[maxGanador]<<endl;  ///ACÁ HAY UN PROBLEMA
                    cout<<"CANTIDAD DE TIROS: "<<tiradas[maxGanador]<<endl;
                }
                else
                {
                    cout<<endl;
                    cout<<"> JUGADOR "<<jugador[maxGanador]<<endl;
                    cout<<"PUNTAJE MAS ALTO: "<<puntaje[maxGanador]<<endl;
                    cout<<"CANTIDAD DE TIROS: "<<tiradas[maxGanador]<<endl;
                }
            }
            break;
        case 6:
            maxGanador=modoSimulado(jugador,puntaje,tiradas);
            break;
        case 0:
            return 0;
            break;
        default:
            cout<<endl;
            cout<<"-------ERROR-------"<<endl<<endl;
            break;
        }
        system("pause>null");
    }
    return 0;
}

