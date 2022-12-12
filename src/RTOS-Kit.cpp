#include "RTOS-Kit.h"

RTOS_Kit::RTOS_Kit() {
}

void RTOS_Kit::create(TaskFunction_t funcPtr, int priority) {
    for (int i = 0; i < maximumAppCount; i++) {
        if (funcPtrArray[i] == NULL) {
            funcPtrArray[i] = funcPtr;

            xTaskCreate(funcPtrArray[i], "app", 1000, NULL, priority,
                        &handlerArray[i]);
            vTaskSuspend(handlerArray[i]);

            break;
        }
    }
}

void RTOS_Kit::start(TaskFunction_t funcPtr) {
    for (int i = 0; i < maximumAppCount; i++) {
        if (funcPtrArray[i] == funcPtr) {
            vTaskResume(handlerArray[i]);

            break;
        }
    }
}

void RTOS_Kit::stop(TaskFunction_t funcPtr) {
    for (int i = 0; i < maximumAppCount; i++) {
        if (funcPtrArray[i] == funcPtr) {
            vTaskSuspend(handlerArray[i]);

            break;
        }
    }
}

void RTOS_Kit::startRTOS(void) {
    vTaskStartScheduler();
}

void RTOS_Kit::delay(unsigned long ms) {
    vTaskDelay(ms);
}