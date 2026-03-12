#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int tmp;
    int limite;
    int flag;
    int contador = 0;
    printf("\nIngrese la cantidad de numeros que quiere ordenar: ");
    scanf(" %d", &n);
    int a[n];
    for(int i=0;i < n; i++){
            printf("\nIngrese el valor %d: ", i);
            scanf(" %d", &tmp);
            a[i] = tmp;
        }
    limite = n - 1;
    do{
        flag = 0;
        for(int i=0;i < limite; i++){
            if(a[i] > a[i+1]){
                tmp = a[i+1];
                a[i+1]=a[i];
                a[i]=tmp;
                flag = 1;
            }
        }
        contador ++;
        limite--;
    }while(flag > 0);
    printf("\nNumeros ordenados");
    for(int i = 0; i < n; i++){
        printf(" %d - ", a[i]);
    }
    printf("\nRequirio %d Pasadas\n", contador);
    return 0;
}