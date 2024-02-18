#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


//50/50 di uscire o 1 o 0
int cinquantacinquanta(void) {
    if (rand() % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
}


// verifica se arrpirma e arr sono uguali
int sonouguali(int n, int arr[], int arrprima[]) {
    for (int i = 0; i < n * n; i++) {
        if (arrprima[i] != arr[i]) {
            return 0;
        }
    }
    return 1;
}


//copia arr in arrprima
void copiarr(int n, int arr[], int arrprima[]) {
    for (int i = 0; i < n * n; i++) {
        arrprima[i] = arr[i];
    }
}


// stampa array andando a capo alle righe giusrte e sostituisci gli 0 con spazi
void stampa(int n, int arr[]) {
    for (int i = 0; i < n * n; i++) {
        if (arr[i] == 1) {
        printf("%i  ", arr[i]);
        }
        if (arr[i] == 0) {
        printf("   ", arr[i]);
        }
        if ((i + 1) % n == 0) {
            printf("\n");
        }
    }
}


//inizializza array con tutti 0
void inizializzaArr(int n, int arr[]) {
    for (int i = 0; i < n * n; i++) {
        arr[i] = 0;
    }
}


//fa scendere gli 1
void grav(int n, int arr[]) {

    //for con i che parte dal fondo e arriva a 0 
    for (int i = (n * n - 1); i >= 0; i--) {

        //se è nell'ultima riga non scende
        if (i <= (n * n) - 1 - n) {

            //solo se sotto di se ha uno 0
            if (arr[i + n] == 0) {

                //se è 1 tira giù
                if (arr[i] == 1 ) {
                    arr[i + n] = 1;
                    arr[i] = 0;
                }   

            }

            //se sotto ha 1
            if (arr[i + n] == 1) {

                //se è uno sposta a caso a destra o a sinistra di 1
                if (arr[i] == 1) {
                    

                    int zeroouno = cinquantacinquanta();

                    //destra
                    if(zeroouno == 0 && arr[i + n + 1] == 0 && (i + 1) % n != 0) {
                        arr[i + n + 1] = 1;
                        arr[i] = 0;
                    }

                    //sinistra
                    if(zeroouno == 1 && arr[i + n - 1] == 0 && (i + 1 - 1) % n != 0) {
                        arr[i + n - 1] = 1;
                        arr[i] = 0;
                    }

                    
                }

            }

        }

    }

}





int main(void) {


    //dichiarazione variaibli

    //lungherzza lato del quadrato 
    int n = 33;
    //arr con dentro tutto
    int arr[n * n];
    //arr per vedere se sono uguali dopo un iterazione e fermare
    int arrprima[n * n];


    //inizializza arr
    inizializzaArr(n, arr);


    //inizializza srand
    srand(time(0));


    //hardcoding sabbia
    arr[7] = 1;


    //algoritmo per continuare frame per frame
    do {   


        //ritardo di un secondino per vedere bene cosa succede
        sleep(1);

        //spawna sabbia in posizione 3
        if (cinquantacinquanta() == 0) {
            arr[10] = 1;
        }

        //stampa arr
        stampa(n, arr);

        //copia arr in arrprima
        copiarr(n, arr, arrprima);


        //fai gravità
        grav(n, arr);
        printf("\n");


    //fai fino a che non è uguale per due frame
    } while (sonouguali(n, arr, arrprima) == 0);


    //stampa arr
    //stampa(n, arr);


    return 0;
}