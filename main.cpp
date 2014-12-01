#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>
#include<stdio.h>
#include<stdlib.h>         // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{
    if(raiz==NULL)  //Si la Raiz o el nodo cuando se llama de nuevo SUMA es NULA retorna 0 y para el programa
    return 0;

    int acum=raiz->num; //Guarda Valor de la raiz o nodo en el acumulador
    int suma_izq= suma(raiz->hijo_izq); //Guardando nodo en variable y haciendo llamada recursiva a suma
    int suma_der=suma(raiz->hijo_der);  //Guardando nodo en variable y haciendo llamada recursiva a suma

    acum=acum+suma_izq+suma_der; // Haciendo suma de las llamadas recursivas
    return acum; //Retornar valor de la suma
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
    if(raiz==NULL)  //Si la Raiz o el nodo cuando se llama de nuevo SUMA es NULA retorna 0 y para el programa
    return 0;

    int contador=1; //Asigna el valor del contador
    if(raiz->hijo_izq!=NULL)  //Verifica que no sea Nulo la Raiz o Nodo
    {
         contador+=cantidadNodos(raiz->hijo_izq);//Acumula valor y hace llamada recursiva.


    }
    if(raiz->hijo_der!=NULL)//Verifica que no sea Nulo la Raiz o Nodo
    {
        contador+=cantidadNodos(raiz->hijo_der);//Acumula valor y hace llamada recursiva.


    }


    return contador; // Retorna el contador
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
    return suma(raiz) / cantidadNodos(raiz); //Usa las funcionas ya establecidas y hace su llamada recursiva y al finalizar devuelve el promedio
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
    return -1;
}

//Devuelve verdadero si el arbol dado esta ordenado estilo AVL, de lo contrario devuelve falso.
bool esAVL(NodoArbolBinario* raiz)
{

    if(raiz==NULL)  //Si la Raiz o el nodo cuando se llama de nuevo SUMA es NULA retorna 0 y para el programa
    return true;

 // int cont =0;
//  int raiz = raiz->num;
  //NodoArbolBinario* raiz2;
//  cout<<"Raiz "<<raiz2->num<<endl;
 /* if((raiz->hijo_izq->num>raiz->num||raiz->hijo_der->num<raiz->num))
  {
  //cout<< "Entre a falso"<<endl;
  return true;
  }*/

  if(raiz->hijo_izq !=NULL && raiz->hijo_izq->num>raiz->num || raiz->hijo_der!=NULL && raiz->hijo_der->num<raiz->num) //si el hijo de la raiz izquierda es mayor a la raiz o el hijo de la derecha es menor se termina la funcion.
                                                                                                                      //Porque ya no es un arbol AVL.
  return false;

  return esAVL(raiz->hijo_izq)&& esAVL(raiz->hijo_der);//LLamada recursiva para buscar lo que sigue.
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
