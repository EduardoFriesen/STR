#include <stdio.h>
int main(){
    int contador = 0;
    char anterior;
    char cadena[255];
    printf("Ingrese una cadena de palabras: \n");
    fgets(cadena, 255, stdin);
    for(int i = 0; i < 255; i ++){
        if(cadena[i] == ' ' && anterior != ' '){
            contador ++;
        }
        anterior = cadena[i];
    }
    printf("Hay %d palabras", contador);
    return 0;
}