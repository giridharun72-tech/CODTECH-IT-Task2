/**
 * @file main.ino
 * @brief IoT Environmental Weather Station Node
 * @domain Internet of Things (IoT) - CODTECH Internship Task 2
 * * Hardware Target: ESP32 (Simulated via Wokwi)
 * Peripherals: DHT22 Sensor & I2C LCD 16x2 Display
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// --- Hardware Pin Configurations ---
#define DHTPIN 15          // GPIO 15 linked to DHT sensor data line
#define DHTTYPE DHT22      // High-accuracy DHT22 sensor simulation

// --- Class Instances ---
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set I2C address to 0x27 for a 16x2 display
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize internal serial telemetry baud rate
  Serial.begin(115200);
  
  // Initialize peripherals
  dht.begin();
  lcd.init();
  lcd.backlight();
  
  // Flash Boot Screen
  lcd.setCursor(0, 0);
  lcd.print("  WEATHER NODE  ");
  lcd.setCursor(0, 1);
  lcd.print("   INITIALIZING   ");
  delay(2000);
  lcd.clear();
  
  Serial.println(F("============================================="));
  Serial.println(F("  SYSTEM STATUS: IoT WEATHER NODE IS ACTIVE  "));
  Serial.println(F("============================================="));
}

void loop() {
  // 1. Acquire Sensor Telemetry Matrix
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius scale

  // 2. Validate Data Integrity Integrity Checks
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("[CRITICAL ERROR] Failed to pull telemetry packet from DHT sensor!"));
    lcd.setCursor(0, 0);
    lcd.print("SENSOR ERROR    ");
    delay(2000);
    return;
  }

  // 3. Output Stream to Serial Terminal (Remote Logs)
  Serial.print(F("[TELEMETRY] Ambient Temp: "));
  Serial.print(temperature, 1);
  Serial.print(F(" °C | Relative Humidity: "));
  Serial.print(humidity, 1);
  Serial.println(F(" %"));

  // 4. Update On-Site Visual Interface Interface (LCD)
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print((char)223); // Standard ASCII character symbol code for degrees (°)
  lcd.print("C    ");

  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(humidity, 1);
  lcd.print(" %    ");

  // 5. Sensor Sampling Interval Sync Synchronization
  delay(2500); 
}
