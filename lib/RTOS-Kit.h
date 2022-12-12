#ifndef _RTOSKIT_H_
#define _RTOSKIT_H_

#define App void *rtosKit
#define maximumAppCount 10

#define firstPriority 4
#define secondPriority 3
#define defaultPriority 2
#define lowPriority 1

class RTOS_Kit {
   public:
    RTOS_Kit();
    void create(TaskFunction_t funcPtr, int priority = defaultPriority);
    void start(TaskFunction_t funcPtr);
    void stop(TaskFunction_t funcPtr);

    void startRTOS(void);

    void delay(unsigned long ms);

    int mainAppNumber  = 0;

    TaskFunction_t funcPtrArray[maximumAppCount];
    TaskHandle_t handlerArray[maximumAppCount];

   private:
};

#endif