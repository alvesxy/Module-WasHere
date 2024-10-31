#ifndef CARD_H
#define CARD_H

#include <Arduino.h>
#include <MFRC522.h>

class Card {

    private:

        long id;
        String name;

    public:

        Card (MFRC522 &rfid) {

            String struid = "";

            for (byte i = 0; i < rfid.uid.size; i++) {
                struid += String(rfid.uid.uidByte[i], HEX);
            }

            this->id = strtol(struid.c_str(), NULL, 16);

            rfid.PICC_HaltA();
        }

        long getId () {
            return this->id;
        }

        String getName () {
            return this->name;
        }

        void setId (long id) {
            this->id = id;
        }

        void setName (String name) {
            this->name = name;
        }
        
};

#endif