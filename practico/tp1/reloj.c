#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t tiempo_crudo;
    struct tm *tiempo_formateado;

    printf("----- RELOJ DIGITAL -----\n");

    while (1) {
        time(&tiempo_crudo);

        tiempo_formateado = localtime(&tiempo_crudo);

        printf("\rHora: [ %02d:%02d:%02d ]", 
               tiempo_formateado->tm_hour, 
               tiempo_formateado->tm_min, 
               tiempo_formateado->tm_sec);
    }

    return 0;
}