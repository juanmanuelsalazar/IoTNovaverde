/* -------------------------------------------------------------------
 * AdminESP - Juan Salazar
 * Plataforma ESP32
 * Proyecto NovaverdeControlSystem
 * -------------------------------------------------------------------
*/


// -------------------------------------------------------------------
// Guardar los estados de los Relays
// -------------------------------------------------------------------
boolean settingsSaveRelays(){
    // Guarda configuración de los Relays
    StaticJsonDocument<200> jsonConfig;
    File file = SPIFFS.open(F("/settingrelays.json"), "w+");
    if (file){
        jsonConfig["Relay01_status"] = Relay01_status;
        jsonConfig["Relay02_status"] = Relay02_status;
        serializeJsonPretty(jsonConfig, file);
        file.close();
        log(F("Info: Estado de los Relay guardado"));
        serializeJsonPretty(jsonConfig, Serial);
        return true;
    }else{
        log(F("Error: Falló el guardado del estado de los Relay"));
        return false;
    }
}
