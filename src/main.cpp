#include <Card.h>
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 22
#define SS_PIN 21

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {

    Serial.begin(115200);
    SPI.begin();
    rfid.PCD_Init(); 

}

void loop() {

    if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
      return;
    }

    Card card(rfid);

    Serial.println(card.getId());

}