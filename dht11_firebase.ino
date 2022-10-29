#include <FirebaseESP8266.h>
#include <DHT.h>
#include  <ESP8266WiFi.h>

#define FIREBASE_HOST "https://smartwarehouse-95f00-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "Ux2acATW6OPFu6E8uQfXP8aDVjAUFM3ou8WCI2fx"
#define WIFI_SSID "RIVE_2.4G" // Wifi Name : Joy 3_3725
#define WIFI_PASSWORD "@t8vanson" // Wifi Pass : 11111111
#define DHTPIN 5    // DHT 11 foot data, with NodeMCU foot D1 GPIO is 5
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
FirebaseData fbdo;

void setup() {

  Serial.begin(9600);
  delay(1000);
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Dang ket noi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  dht.begin();
  Serial.println ("");
  Serial.println ("Da ket noi WiFi!");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();  // Read the C mode

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;

  }

  Serial.print("Nhiet do: ");
  Serial.print(t);
  Serial.print("*C  ");
  Serial.print("Do am: ");
  Serial.print(h);
  Serial.println("%  ");

  Firebase.setFloat( fbdo,"Nhiet do", t);

  Firebase.setFloat ( fbdo,"Do am", h);

  delay(200);

}
