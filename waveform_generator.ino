// Set pins
const int pwmPin1 = 9;
const int pwmPin2 = 10;

// Initialise variables
unsigned long lastUpdate = 0;
float frequency1 = 100.0;
float frequency2a = 3.0;
float frequency2b = 7.0;
float phase1 = 0;
float phase2a = 0;
float phase2b = 0;

void setup() {
    // Set pin mode
    pinMode(pwmPin1, OUTPUT);
    pinMode(pwmPin2, OUTPUT);

    // Set pwm freq to 31250 Hz
    TCCR1B = TCCR1B & 0b11111000 | 0x01;
    
    // Open Serial communication
    Serial.begin(115200);
}

void loop() {
    // Update time
    unsigned long currentTime = micros();
    float deltaTime = (currentTime - lastUpdate) / 1000000.0;
    lastUpdate = currentTime;
    
    // Update phase
    phase1 += 2 * PI * frequency1 * deltaTime;
    phase2a += 2 * PI * frequency2a * deltaTime;
    phase2b += 2 * PI * frequency2b * deltaTime;
    if (phase1 >= 2 * PI) phase1 -= 2 * PI;
    if (phase2a >= 2 * PI) phase2a -= 2 * PI;
    if (phase2b >= 2 * PI) phase2b -= 2 * PI;
    
    // Update output 1
    float sine1 = sin(phase1);
    int pwmValue1 = (int)((sine1 + 1.0) * 127.5); // [-1,1] -> [0,255]
    analogWrite(pwmPin1, pwmValue1);
    
    // Update output 2
    float sine2a = sin(phase2a);
    float sine2b = sin(phase2b);
    float combinedSine = (sine2a + sine2b) / 2.0;
    int pwmValue2 = (int)((combinedSine + 1.0) * 127.5);
    analogWrite(pwmPin2, pwmValue2);
}