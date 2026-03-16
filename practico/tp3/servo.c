#include <stdio.h>
#include <pigpio.h>
#include <unistd.h>

#define SERVO_PIN 24      
#define BUTTON_PIN 17    
int contador = 0;


void manejar_boton(int gpio, int level, uint32_t tick_evento) {

    int movimiento = 0;
    if (level == 0) { 
        contador++;
        if(contador <= 6){
            movimiento = 500 + contador * 333;
            printf("Movimiento %d\n", movimiento);
            gpioServo(SERVO_PIN, movimiento); 
        } else {
            contador = 0;
            movimiento = 500;
            printf("Movimiento %d\n", movimiento);
            gpioServo(SERVO_PIN, movimiento);
    }
}

int main() {
    if (gpioInitialise() < 0) {
        fprintf(stderr, "Error al inicializar pigpio\n");
        return 1;
    }
    gpioSetMode(BUTTON_PIN, PI_INPUT);
    gpioServo(SERVO_PIN, 500);
    gpioGlitchFilter(BUTTON_PIN, 200000);
    gpioSetAlertFunc(BUTTON_PIN, manejar_boton);

    while (1) {
        sleep(100);
    }

    gpioTerminate();
    return 0;
}
