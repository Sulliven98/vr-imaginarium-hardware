// ESP32 Serial Pattern Trigger
// Receives a single command over Serial and triggers a pattern on VTA and Fan pins

const int thumbVTA = 32;
const int indexVTA = 33;
const int middleVTA = 25;
const int ringVTA = 26;
const int littleVTA = 27;
const int fanPWM = 14;

void setup() {
    Serial.begin(115200);
    pinMode(thumbVTA, OUTPUT);
    pinMode(indexVTA, OUTPUT);
    pinMode(middleVTA, OUTPUT);
    pinMode(ringVTA, OUTPUT);
    pinMode(littleVTA, OUTPUT);
    pinMode(fanPWM, OUTPUT);

    Serial.println("ESP32 Ready. Awaiting command from Unity...");
}

void loop() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();

        if (command == "ACTIVATE_PATTERN") {
            triggerPattern();
        }
    }
}

void triggerPattern() {
    analogWrite(thumbVTA, 160);  // 62% PWM
    analogWrite(indexVTA, 190);  // 75% PWM
    analogWrite(middleVTA, 220); // 86% PWM
    analogWrite(ringVTA, 120);   // 47% PWM
    analogWrite(littleVTA, 140); // 55% PWM
    analogWrite(fanPWM, 200);    // 78% PWM
    delay(3000);

    // Turn all off
    analogWrite(thumbVTA, 0);
    analogWrite(indexVTA, 0);
    analogWrite(middleVTA, 0);
    analogWrite(ringVTA, 0);
    analogWrite(littleVTA, 0);
    analogWrite(fanPWM, 0);
}
