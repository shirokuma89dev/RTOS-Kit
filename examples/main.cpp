#include <Arduino.h>
#include <RTOS-Kit.h>

RTOS_Kit app;

void blinkApp1(App) {
    pinMode(12, OUTPUT);
    while (1) {
        digitalWrite(12, HIGH);
        app.delay(150);
        digitalWrite(12, LOW);
        app.delay(150);
    }
}

void blinkApp2(App) {
    pinMode(13, OUTPUT);
    while (1) {
        digitalWrite(13, HIGH);
        app.delay(100);
        digitalWrite(13, LOW);
        app.delay(100);
    }
}

void mainApp(App) {
    // blinkApp1
    app.start(blinkApp1);
    app.delay(3000);

    // blinkApp2
    app.stop(blinkApp1);
    app.start(blinkApp2);
    app.delay(3000);

    // Appを全て停止
    app.stop(blinkApp2);
    app.delay(3000);

    //全て再開
    app.start(blinkApp1);
    app.start(blinkApp2);

    while (1) {
    }
}

void setup() {
    app.create(mainApp, firstPriority);
    app.create(blinkApp1);
    app.create(blinkApp2);

    app.start(mainApp);  //メインアプリを初回起動に設定
    app.startRTOS();
}

void loop() {
    // Nothing to do.
}