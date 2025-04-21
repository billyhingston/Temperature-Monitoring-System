void setup() {
  // put your setup code here, to run once:

  //Setup input pin
  pinMode(A0, INPUT);

  //Setup serial monitor
  Serial.begin(9600);
}

void loop() {

 //Read-in A0 Value
 int a_in = analogRead(A0);

 // Calibrate analog input voltage range of the Arduino's ADC.
 double V_USB = 5.101;
 
 //Convert the ADC output back to voltage.
 //Be sure to convert to double by typecasting:
 double in_voltage = ((double)a_in*V_USB)/1023.0; // The input voltage is in Volts.

 // Convert the voltage to temperature.
 double temp = in_voltage*100.0/V_USB;

  //Print all output to the serial monitor:
  Serial.print("ADC output value: ");
  Serial.print(a_in);
  Serial.print(", Voltage (V): ");
  Serial.print(in_voltage); 
  Serial.print(", Temperature (C): ");
  Serial.println(temp);

  //Delay 1 sec:
  delay(1000);
}
