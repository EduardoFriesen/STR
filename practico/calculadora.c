#include <stdio.h>

float suma(float, float);
float resta(float, float);
float division(float, float);
float multiplicacion(float, float);

float suma (float a, float b){
    return a + b;
}

float resta (float a, float b){
    return a - b;
}

float division (float a, float b){
    return a / b;
}

float multiplicacion (float a, float b){
    return a * b;
}

int main() {         
    float a, b, resultado;
    char opcion;
    printf("----------- Calculadora -----------\n");
    do{
        printf("------------- Opciones -------------\n");
        printf("a. suma\n");
        printf("b. resta\n");
        printf("c. division\n");
        printf("d. multiplicacion\n");
        printf("q. salir\n");
        printf("ingrese una opcion: ");
        scanf(" %c", &opcion);
        switch (opcion)
        {
            case 'a':
                printf("\n----------- Suma -----------\n");
                printf("ingrese el primer numero \n");
                scanf("%f", &a);
                printf("ingrese el segundo numero\n");
                scanf("%f", &b);
                resultado = suma(a,b);
                printf("El resultado de la suma es: %.2f\n", resultado);
                break;
            case 'b':
                printf("\n----------- Resta -----------\n");
                printf("ingrese el primer numero\n");
                scanf("%f", &a);
                printf("ingrese el segundo numero\n");
                scanf("%f", &b);
                resultado = resta(a,b);
                printf("El resultado de la resta es: %.2f\n", resultado);
                break;
            case 'c':
                printf("\n----------- Division -----------\n");
                printf("ingrese el primer numero: \n");
                scanf("%f", &a);
                printf("ingrese el segundo numero: \n");
                scanf("%f", &b);
                resultado = division(a,b);
                printf("El resultado de la division es: %.2f\n", resultado);
                break;
            case 'd':
                printf("\n----------- Multiplicacion -----------\n");
                printf("ingrese el primer numero: \n");
                scanf("%f", &a);
                printf("ingrese el segundo numero: \n");
                scanf("%f", &b);
                resultado = multiplicacion(a,b);
                printf("El resultado de la multiplicacion es: %.2f\n", resultado);
                break;
            case 'q':
                printf("----- Hasta la Proxima -----");
                break;
            default:
                printf("Opcion %d invalida ", opcion);
                break;
    }
    }while(opcion != 'q');
    
    return 0;
}