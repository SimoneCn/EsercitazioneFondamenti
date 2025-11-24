#include <stdio.h>
#define NMAX 50

struct Studente{
    int matricola;
    int voto;
    int cfu;
};

// Vede se la matricola è già stata usata, serve ad evitare che due studenti abbiano la stessa matricola
int matricolaUsata(struct Studente v[],int n, int mat){
    int trovato=0;
    for(int i=0;i<n;i++){
        if(v[i].matricola==mat){
            trovato=1;
        }
    }
    return trovato;
}

int inserisci_studente(struct Studente v[],int n){
    if(n>=NMAX){
        printf("Hai già raggiunto il numero massimo di studenti \n");
        return n;
    }
    else {
        int mat;
        do{
            printf("Inserisci il numero di matricola dello studente: ");
            scanf("%d",&v[n].matricola);
        }while(matricolaUsata(v,n,v[n].matricola));
        do{
            printf("Inserisci il voto dello studente: ");
            scanf("%d",&v[n].voto);
        }while(v[n].voto<17 || v[n].voto>30);
        printf("Inserisci il numero di CFU: ");
        scanf("%d",&v[n].cfu);
    }
    return n+1;
}

void stampa_studenti(struct Studente v[], int n){
    if(n>0){
        for(int i=0;i<n;i++){
            printf("[%d] Matricola: %d, Voto: %d, CFU: %d \n",i+1,v[i].matricola,v[i].voto,v[i].cfu);
        }
    }
    else {
        printf("Non ci sono studenti al momento \n");
    }
}

float media_voti(struct Studente v[], int n){
    if(n>0){
        float media=0;
        for(int i=0;i<n;i++){
            media+=v[i].voto;
        }
        return media/n;
    }
    else{
        printf("Non ci sono studenti al momento \n");
    }
    return 0;
}

int cerca_per_matricola(struct Studente v[], int n, int matricola){
    for(int i=0;i<n;i++){
        if(v[i].matricola==matricola){
            return i; 
        }
    }
    return -1;
}

int indice_voto_massimo(struct Studente v[], int n){
    //Se non ci sono studenti restituisci errore
    if(n==0){
        return -1;
    }
    int indicemax=0;
    for(int i=1;i<n;i++){
        if(v[indicemax].voto<v[i].voto){
            indicemax=i;
        }
    }
    return indicemax;
}

//Stampa un singolo studente, non necessario, ma utile per evitare codice ripetuto
void stampaStudente(struct Studente v[],int i){
    printf("[%d] Matricola: %d, Voto: %d, CFU: %d \n",i,v[i].matricola,v[i].voto,v[i].cfu);
}

int main(){
    struct Studente lista [NMAX];
    int studentiAttuali=0;
    int selezione;
    float media;
    do{
        printf("--------------------------\n");
        printf("1) Inserisci un nuovo studente \n");
        printf("2) Stampa tutti gli studenti \n");
        printf("3) Calcola e stampa la media dei voti \n");
        printf("4) Cerca studente per matricola \n");
        printf("5) Trova e stampa lo studente con il voto massimo \n");
        printf("0) Esci \n");
        scanf("%d",&selezione);
        printf("--------------------------\n");
        int indice,ricerca;
        switch(selezione){
            case 1: 
                studentiAttuali=inserisci_studente(lista, studentiAttuali);
                break;
            case 2: 
                stampa_studenti(lista,studentiAttuali);
                break;
            case 3: 
                if(studentiAttuali!=0){
                    media=media_voti(lista,studentiAttuali);
                    printf("La media e' %.2f \n",media);
                } else{
                    printf("Non ci sono studenti al momento \n");
                }
                break;
            case 4: 
                printf("Quale numero di matricola vuoi cercare? ");
                scanf("%d",&ricerca);
                indice=cerca_per_matricola(lista,studentiAttuali,ricerca);
                if(indice==-1){
                    printf("Non ho trovato lo studente \n");
                }else{
                    printf("Ho trovato lo studente all'indice %d \n",indice);
                    stampaStudente(lista, indice);
                }
                break;
            case 5: 
                indice=indice_voto_massimo(lista,studentiAttuali);
                if(indice==-1){
                    printf("Non ci sono studenti al momento \n");
                } else{
                    printf("Lo studente col voto massimo e': \n");
                    stampaStudente(lista,indice);
                }
                break;
            case 0:
                printf("Esco dal programma \n"); 
                break;
            default: 
                printf("Hai inserito un valore non valido.");
        }
    }while(selezione!=0);
    return 0;
}
