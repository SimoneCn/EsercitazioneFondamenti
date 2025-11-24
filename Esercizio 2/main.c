/*
Esercizio 2 – Temperature, array e funzioni
Scrivere un programma in C che gestisce temperature giornaliere.
Chiedere all’utente il numero di giorni N (1 <= N <= 31).
Dichiarare un array di float di dimensione N.
Leggere da tastiera le temperature dei N giorni.
Implementare le seguenti funzioni:


float calcola_media(float v[], int n);
float trova_massimo(float v[], int n);
float trova_minimo(float v[], int n);
int conta_maggiori_di_media(float v[], int n);

Nel main:


stampare la media delle temperature
stampare massimo e minimo
stampare quanti giorni hanno una temperatura maggiore della media


Vincoli:
Non usare variabili globali.
Le elaborazioni devono avvenire nelle funzioni, non nel main.
Utilizzare cicli for per scorrere l’array.

*/

#include <stdio.h>

float calcola_media(float v[], int n){
    float media=0;
    for(int i=0;i<n;i++){
        media+=v[i];
    }
    return media/n;
}

float trova_massimo(float v[], int n){
    float max=v[0];
    for(int i=1;i<n;i++){
        if(max<v[i]){
            max=v[i];
        }
    }
    return max;
}

float trova_minimo(float v[], int n){
    float min=v[0];
    for(int i=1;i<n;i++){
        if(min>v[i]){
            min=v[i];
        }
    }
    return min;
}

int conta_maggiori_di_media(float v[], int n){
    float media= calcola_media(v,n);
    int nmaggiori=0;
    for(int i=0;i<n;i++){
        if(v[i]>media){
            nmaggiori++;
        }
    }
    return nmaggiori;
}

int main(){
    int ngiorni=0;
    do{
        printf("Inserisci un numero di giorni valido (Da 1 a 31): ");
        scanf("%d",&ngiorni);
    }while(ngiorni<1 || ngiorni>31);
    float valori[ngiorni];
    for(int i=0;i<ngiorni;i++){
        printf("Inserisci la temperatura del giorno %d : ",i+1);
        scanf("%f",&valori[i]);
    }
    printf("La media delle temperature e' %f \n",calcola_media(valori,ngiorni));
    printf("La temperatura massima e' %f \n",trova_massimo(valori,ngiorni));
    printf("La temperatura minima e' %f \n",trova_minimo(valori,ngiorni));
    printf("In totale %d giorni/o hanno avuto una temperatura superiore alla media \n",conta_maggiori_di_media(valori,ngiorni));

    return 0;
}