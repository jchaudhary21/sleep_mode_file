int value = 1 ;                                                // initializing the value as high

void setup() {                                                
  
  pinMode(33,INPUT_PULLUP);                                    // making RTC pin 33 as HIGH default   
  serial.begin(9600);                                          // initalizing serial monitor 
}


void loop() {
 Serial.println("In wake up mode");                           // printing values in serial monitor
 value =  digitalRead(33);                                    // reading 33 pin value's
 
 if(value == 0){                                              
  esp_deep_sleep_start();                                    //  if  33 pin's input is low then it will go into sleep mode    
 }
 esp_sleep_enable_ext0_wakeup(GPIO_NUM_33,1);               // if value is high then it will remain in wakeup mode
}
