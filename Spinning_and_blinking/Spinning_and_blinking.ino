const unsigned int LED{17}; // define a constant for the LED pin

// add these
const unsigned int MTR_HI{13};
const unsigned int MTR_LO{14};
const unsigned int MTR_HI1{15};
const unsigned int MTR_LO1{16};
unsigned int Lo = 0;
unsigned int Hi = 75;
bool reverse = 0;


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
    analogWrite(MTR_LO, Lo);
    digitalWrite(LED, HIGH); // turn the LED on
    
    delay(1000); // wait 1 second
    
    analogWrite(MTR_HI, Hi);
    digitalWrite(LED, LOW); // turn the LED off
    
//    delay(100); // wait .1 second

    if(!reverse){
      if(Hi >= 0){
        Hi--;
        Lo++;
      }
      else{
        reverse = 1;
      }
    }
    else{
      if(Hi <= 75){
        Hi++;
        Lo--;
      }
      else{
        reverse = 0;
      }
    }
    

//    analogWrite(MTR_LO, 75);
//    digitalWrite(LED, HIGH); // turn the LED on
//    
//    delay(1000); // wait 1 second
//    
//    analogWrite(MTR_HI, 0);
//    digitalWrite(LED, LOW); // turn the LED off

    delay(1000);

}
