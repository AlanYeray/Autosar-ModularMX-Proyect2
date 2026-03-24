# ModularMx - AUTOSAR BSW Stack para S32K144

Implementacion modular del stack de Basic Software (BSW) bajo el estandar AUTOSAR 4.7 RTD 2.0.0, orientada al microcontrolador NXP S32K144 (ARM Cortex-M4). El proyecto sirve como referencia practica para el desarrollo de firmware embebido en el ecosistema automotriz, integrando drivers MCAL, capas de abstraccion de hardware y un scheduler cooperativo custom.

## Caracteristicas principales

El proyecto implementa una arquitectura AUTOSAR completa que incluye la capa MCAL con drivers para ADC, DIO, GPT, PWM, Port, Mcu, SPI, CAN y Platform. Sobre esta capa se construye una abstraccion de hardware (IoHwAb) que expone interfaces de alto nivel para botones con deteccion de single-click, double-click y hold, LEDs con control de toggle, potenciometros via ADC y un buzzer controlado por PWM.

El sistema de ejecucion se basa en un scheduler cooperativo con tick de 10ms que gestiona tareas periodicas y timers por software con callbacks. Para diagnostico en tiempo real se integra SEGGER RTT, eliminando la necesidad de semihosting.

## Estructura del proyecto

```
Autosar/          Modulos del stack AUTOSAR (MCAL, IoHwAb, Os, Det, EcuM, Bfx)
Build/            Artefactos de compilacion y headers de configuracion (Build/cfg/)
Rtt/              Fuentes de SEGGER RTT y System View
Test/             Tests unitarios (Ceedling + Unity + CMock)
config/           Archivos de configuracion .xdm para los modulos
mock/             Mocks generados para testing
main.c            Punto de entrada de la aplicacion
makefile          Sistema de build con GNU Make
project.yml       Configuracion de Ceedling para unit testing
```

## Modulos AUTOSAR implementados

**MCAL:** Mcu, Port, Dio, Adc, Gpt, Pwm, Platform, Can, Spi

**BSW Services:** Det (Default Error Tracer), EcuM (ECU State Manager), Bfx (Bitfield operations)

**Abstraccion:** IoHwAb con sub-modulos para Buttons, Leds, Pots y Buzzer

**Comunicacion:** CanIf (stub)

## Toolchain y build

El proyecto se compila con arm-none-eabi-gcc 10.2 usando el estandar C99. La configuracion del compilador incluye soporte para FPU por hardware (`-mfloat-abi=hard -mfpu=fpv4-sp-d16`) y flags de cumplimiento MISRA.

```bash
# Compilar el proyecto
make all

# Ejecutar tests unitarios
ceedling test:all

# Cobertura de codigo
ceedling gcov:all
```

La salida de compilacion genera los archivos `temp.elf`, `temp.hex` y `temp.map` en el directorio Build.

## Testing

Se utiliza Ceedling como framework de testing con Unity para aserciones y CMock para generacion de mocks. Los tests actuales cubren las operaciones de bitfield del modulo Bfx tanto en 8 como en 32 bits. El mock de OsIf permite testear modulos que dependen del timer del sistema de forma aislada.

## Flujo de inicializacion

La secuencia de arranque sigue el patron AUTOSAR a traves de `EcuM_Init()`: configuracion del MCU y arbol de clocks a 48 MHz, inicializacion de la plataforma e interrupciones, configuracion de timers y system tick, setup de puertos, ADC y PWM, y finalmente inicializacion de la capa IoHwAb. Despues el scheduler toma control del flujo de ejecucion.

## Comportamiento de la aplicacion

La aplicacion de ejemplo demuestra la interaccion entre las capas del stack. Los botones se procesan cada 10ms mediante una maquina de estados que detecta tres tipos de eventos: al soltar un boton se hace toggle del LED asociado, un doble-click lee el valor del potenciometro correspondiente y lo reporta via RTT, y un hold activa o desactiva el buzzer con un tono configurable por canal.

## Requisitos

- Toolchain: arm-none-eabi-gcc 10.2 o superior
- Hardware: NXP S32K144 EVB o compatible
- Debug: SEGGER J-Link (para RTT)
- Testing: Ruby + Ceedling (para unit tests en host)

## Autor

**Alan Yeray Olivas** - Desarrollo de firmware y sistemas embebidos

## Licencia

Copyright (c) 2024. Todos los derechos reservados.
