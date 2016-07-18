#include <SPI.h>
#include <SD.h>
const int chipSelect = 10;
long int counter = 0;
File dataFile;
String final;
long int startTime,currTime;
bool sdCheck;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial){
    ; // wait for stuff to happen
  }

  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  Serial.print("Initializing SD card ...\n");
  startTime = millis();
  while ((millis() - startTime) < 5000) {
    sdCheck = SD.begin(chipSelect);
    if (sdCheck) {
      // SD Starter Check
      break;
    }
  }
  // If can't get SD card to work. Try to use SDCard class to make work.

  if (sdCheck) {
    Serial.println("Card Initialized.");
  }
  else {
    Serial.println("Card failed, or not present\n");
  }

  if (SD.exists("datalog.csv")) {
    Serial.println("HERE");
    SD.remove("datalog.csv");
  }
  
  dataFile = SD.open("datalog.csv", FILE_WRITE);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  counter ++;

  if (counter < 1000){
    String dataString;
    dataString = String(counter);
    final = "This Data," + dataString + "," + millis();
    dataFile.println(final);
  }
  else if (dataFile) {
    dataFile.close();
    Serial.println("Done\n");
  }
  
}
