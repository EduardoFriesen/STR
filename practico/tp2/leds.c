#include <stdio.h>
#include <pigpio.h>

#define LED_PIN 17      // GPIO 17
#define INTERVALO 500000 // 500ms en microsegundos

int main() {
    // Inicio de la libreria, parar el proceso del pigpio
    if (gpioInitialise() < 0) {
        fprintf(stderr, "Error al inicializar pigpio\n");
        return 1;
    }

    //Configuracion del pin como salida
    gpioSetMode(LED_PIN, PI_OUTPUT);

    // Usamos un timer no bloqueante para que medir el tiempo sin parar la ejecucion del programa
    // Este es un cronometro de la libreria de pigpio
    uint32_t tiempoUltimoCambio = gpioTick();
    int estadoLed = 0;

    printf("Iniciando Blink. Presiona Ctrl+C para salir.\n");

    while (1) {
        uint32_t tiempoActual = gpioTick();

        if (tiempoActual - tiempoUltimoCambio >= INTERVALO) {
            
            estadoLed = !estadoLed;
            gpioWrite(LED_PIN, estadoLed);
            if (estadoLed) {
                printf("LED_ON\n");
            } else {
                printf("LED_OFF\n");
            }
            tiempoUltimoCambio = tiempoActual;
        }
    }

    gpioTerminate();
    return 0;
}