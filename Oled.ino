#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Keypad.h>

#define ANCHO 128
#define ALTO 64
Adafruit_SSD1306 display(ANCHO, ALTO, &Wire, -1);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'7', '8', '9', 'A'},
  {'4', '5', '6', 'B'},
  {'1', '2', '3', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {10, 9, 8, 7};
byte colPins[COLS] = {13, 12, 11, 6};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String inputString = ""; // Variable para almacenar los números ingresados

void setup() {
  Serial.begin(9600);
  
  // Inicializa la pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("No se encontró la pantalla");
    for (;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Presiona Tecla:");
  display.display();
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    // Agregar la tecla presionada a la cadena de entrada
    inputString += key;
    
    // Limpiar y mostrar el texto actualizado
    display.setCursor(0, 10);
    display.print("                "); // Limpiar la línea anterior
    display.setCursor(0, 10);
    display.print(inputString); // Mostrar el número acumulado
    display.display();
  }
}
