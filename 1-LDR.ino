//Declaration and initialization of some variables
int sensorValue = 0;
int sensorValue1 = 0;
int counter = 0;

//constant variable(buzzer)- pin (9)
const int buzzer = 9; 

//Function(setup) for declaration the pinmode
void setup()
{
  // Set SensorValue - pin A0 as an input
  pinMode(A0, INPUT);
  // Set LED(Yellow) - pin 6 as an output
  pinMode(6, OUTPUT);
  // Set SensorValue1 - pin A1 as an input
  pinMode(A1, INPUT);
  // Set LED(White) - pin 11 as an output
  pinMode(11, OUTPUT);
  // Set buzzer - pin 9 as an output
  pinMode(buzzer, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{
  // read the value from the sensor
  sensorValue = analogRead(A0);
  sensorValue1 = analogRead(A1);
  
  // print the sensor reading so you know its range
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  Serial.print("Sensor Value1: ");
  Serial.println(sensorValue1);
  Serial.print("Counter: ");
  Serial.println(counter);
 
   // map the sensor reading to a range for the LED
  analogWrite(11, map(sensorValue, 0, 1023, 0, 255));
  delay(2000); // Wait for 100 millisecond(s)
  analogWrite(6, map(sensorValue1, 0, 1023, 0, 255));
  delay(2000);


  if(sensorValue > 0 && sensorValue <= 20)
  {
    counter++;
  }
  if(sensorValue1 >0 && sensorValue1 <=80)
  {
    counter--;
  }
  
  delay(1500);

//check if the counter is greater than 5 or not
  if(counter>5)
  {
   Serial.print("Alarm is on\n");
   Serial.print("The room is full\n");
   for( int i = 0; i<6;i++)
   {
    // Send 1KHz sound signal for 1 sec
    tone(buzzer, 1000); 
    delay(1000);

    //Stop the sound for 1 sec
    noTone(buzzer);     
    delay(1000);        
   }
    exit(1);
           
  }
  else
  {
    // Stop the sound
    noTone(buzzer);     
    
  }
  if(counter<=0)
  {
    Serial.print("The room is empty \n");
    counter = 0;
  }  
}
