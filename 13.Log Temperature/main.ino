// Read temperture and return it via API
//   

double temperature = 0.0;

void setup()
{
  // Use serial port for debug print
  Serial.begin(9600);

  // register API variable
  Spark.variable("temperature", &temperature, DOUBLE);
  pinMode(A7, INPUT);
}

void loop()
{
  int analogValue = analogRead(A7);
  double voltage = 3.3 * ((double)analogValue / 4095.0);

  // http://www.analog.com/static/imported-files/data_sheets/TMP35_36_37.pdf
  temperature = (voltage - 0.5) * 100;
  Serial.print(temperature);
  Serial.print(";");
  delay(500);
}
