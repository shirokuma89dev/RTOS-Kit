#include "RTOS-Kit.h"

RTOS_Kit::RTOS_Kit() {
}

void RTOS_Kit::create(TaskFunction_t funcPtr, int priority) {
    for (int i = 0; i < maximumAppCount; i++) {
        if (funcPtrArray[i] == NULL) {
            funcPtrArray[i] = funcPtr;
            priorityArray[i] = priority;

            xTaskCreate(funcPtrArray[i], "app", 256, NULL, priority,
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

void RTOS_Kit::restart(TaskFunction_t funcPtr) {
    for (int i = 0; i < maximumAppCount; i++) {
        if (funcPtrArray[i] == funcPtr) {
            vTaskDelete(handlerArray[i]);
            xTaskCreate(funcPtrArray[i], "app", 256, NULL, priorityArray[i],
                        &handlerArray[i]);
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