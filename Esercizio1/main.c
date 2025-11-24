
/* Scrivere un programma in C che:
Chiede all’utente di inserire una sequenza di numeri interi (positivi, negativi o zero).
La sequenza termina quando l’utente inserisce 0 (lo 0 non va considerato nei calcoli).
Alla fine il programma deve stampare:


quanti numeri sono stati inseriti
la somma dei numeri
la media (float)
il valore massimo e il minimo
quanti numeri sono pari e quanti sono dispari


Vincoli:
Utilizzare istruzioni condizionali (if, else).
Utilizzare un ciclo (while, do…while o for).
Gestire il caso in cui il primo numero inserito sia 0 (nessun dato valido).
*/

#include <stdio.h>
#include <limits.h>

int main(){
    int max=INT_MIN, min=INT_MAX, somma=0, npari=0, ndispari=0, temp=1;
    printf("Avvio l'inserimento dei numeri (0 per uscire) \n");
    do{
        printf("Inserisci il prossimo numero: ");
        scanf("%d",&temp);
        if(temp==0 && somma==0){
            printf("Non hai inserito alcun dato valido. \n");
            break;
        } 
        else if (temp==0){
            printf("Procedo alla chiusura del programma \n");
            break;
        }
        else {
            somma+=temp;
            if(max<temp){
                max=temp;
            }
            if(min>temp){
                min=temp;
            }
            if(temp%2==0){
                npari++;
            }
            else{
                ndispari++;
            }
        }
    } while(temp!=0);
    //Controllo che somma sia diverso da zero, perché l'unico caso in cui può accadere è quando non hai inserito nemmeno un valore
    if(somma!=0){
        printf("In totale hai inserito %d numeri: \n",npari+ndispari);
        printf("La somma dei tuoi valori e': %d \n",somma);
        printf("La media dei tuoi valori e': %f \n",(float)somma/(npari+ndispari));
        printf("Il valore massimo e': %d, mentre quello minimo: %d \n",max,min);
        printf("In totale ci sono %d numeri pari e %d numeri dispari \n",npari,ndispari);
    }
    return 0;
}