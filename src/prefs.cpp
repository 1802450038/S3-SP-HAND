#include <Arduino.h>
#include <Preferences.h>
#include "prefs.h"

Preferences preferences;

void initPrefs()
{
    preferences.begin("settings", false);
}

int loadValue(char *key, int defaultValue)
{
    Serial.println("Carregando valor : " + String(key));
    return preferences.getInt(key, 0);
}

void storeValue(char *key, int value)
{
    Serial.println("Salvando valor : " + String(key));
    preferences.putInt(key, value);
}
