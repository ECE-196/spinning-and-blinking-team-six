const unsigned int LED{17}; // define a constant for the LED pin

// add these
const unsigned int MTR_HI{13};
const unsigned int MTR_LO{14};
unsigned int Lo = 0;
unsigned int Hi = 75;
bool reverse = 0;


unsigned long previousMillis = 0;
unsigned long ledInterval = 500; // Interval for LED blinking (500ms on/off)

unsigned long motorPreviousMillis = 0;
unsigned long motorInterval = 50; // Interval for updating motor speed (50ms)

bool ledState = LOW; // Keep track of the LED state

void setup() 
{
    pinMode(LED, OUTPUT); // configure the LED pin to be an output
      
    pinMode(MTR_HI, OUTPUT);
    pinMode(MTR_LO, OUTPUT);
    
    // configure pins to spin the motor in a direction
    digitalWrite(MTR_HI, HIGH);
    digitalWrite(MTR_LO, LOW);
}

void loop() 
{
    unsigned long currentMillis = millis();
    
    // LED blinking logic
    if (currentMillis - previousMillis >= ledInterval) {
        previousMillis = currentMillis;
        
        // Toggle the LED state
        ledState = !ledState;
        digitalWrite(LED, ledState);
    }

    // Motor control logic
    if (currentMillis - motorPreviousMillis >= motorInterval) {
        motorPreviousMillis = currentMillis;
        
        analogWrite(MTR_LO, Lo);
        analogWrite(MTR_HI, Hi);

        if(!reverse) {
            if(Hi > 0) {
                Hi--;
                Lo++;
            }
            else {
                reverse = 1; // Start reversing
            }
        }
        else {
            if(Hi < 75) {
                Hi++;
                Lo--;
            }
            else {
                reverse = 0; // Start forward again
            }
        }
    }
}
