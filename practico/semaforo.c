#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>



int kbhit(void) {
    struct termios oldt, newt; //Estas estructuras guardan las configuraciones de la terminal
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt); //Traemos la configuracion actual y la guardamos en oldt.
    newt = oldt; //hacemos una copia de la configuracion para modificarla.
    newt.c_lflag &= ~(ICANON); //Apagamos el modo canonico mediante una operacion a nivel de bits, 
                               //la terminal ya no espera el enter para procesar datos por teclado.
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);//aplicamos la nueva configuracion.
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0); //Traemos las reglas de uso de teclado de C que se esta usando actualmente.
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK); // Modifcamos las reglas del teclado para que no se bloquee
                                                     // mediante una operacion OR

    ch = getchar(); // Gracias a lo hecho anteriormente la funcion getchar() ya no se bloquea espereando un enter
                    // sino que esta leyendo constantemente esperando el ingreso de un caracter

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // retrotraemos los cambios que le hicimos a la terminal en ese mismo instante
    fcntl(STDIN_FILENO, F_SETFL, oldf); // retrotraemos los cambios que le hicimos al teclado

    if (ch != EOF) { // Verificamos si se toco alguna tecla, si no se toco el ch = EOF
        ungetc(ch, stdin); // vaciamos el contenedor de la tecla
        return 1; //delvolvemos un 1 en caso exitoso
    }
    return 0;
}

int main() {
    char tecla;
    int peaton_esperando = 0;

    printf("------- SEMAFORO -------\n");
    printf("Presiona p en cualquier momento para pedir cruce peatonal.\n");
    printf("Presiona q para salir.\n\n");

    while (1) {
        printf("VERDE\n");
        
        for (int i = 0; i < 10; i++) {
            sleep(1);
            if (kbhit()) {
                tecla = getchar();
                if (tecla == 'q') return 0;
                if (tecla == 'p') {
                    peaton_esperando = 1;
                    printf("\nPeaton detectado. Acortando luz verde\n");
                    break;
                }
            }
        }
        printf("AMARILLO\n");
        sleep(2);

        if (peaton_esperando) {
            printf("ROJO\n");
            sleep(7);
            peaton_esperando = 0;
        } else {
            printf("ROJO\n");
            sleep(5);
        }
        printf("\n------------------------------------------------\n");
    }

    return 0;
}