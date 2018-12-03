

void Alarm(){
    //oled.clear();
    // implement alarm here.    
    tone(buzzer, 2000, HourlyTone);
    delay(800);
    noTone(buzzer);
    //Menu = 10;
}


void timedevents(){

   DateTime now = rtc.now();

  if (HourlyTone > 0) {  // if hourly tones are enabled, check the time
    // Double beep on the hour <-- todo make this occur once so we don't need the delay on the end
    if (now.minute() == 00 && now.second() == 00) {
      tone(buzzer, 2000, HourlyTone);
      delay(300);
      tone(buzzer, 2000, HourlyTone);
      delay(800);
      noTone(buzzer);
    }
    // Single beep on the half hour <-- todo make this occur once so we don't need the delay on the end
    if (now.minute() == 30 && now.second() == 00) {
      tone(buzzer, 2000, HourlyTone);
      delay(800);  
      noTone(buzzer);
    }
    // Alarm

    
  }
    if (alarmenabled == 1){
      if (now.hour() == alarmhour && now.minute() == alarmmin){
      alarm = 1;
      }
      else{
        alarm = 0;
      }
    }
  if (Menu > 0) {
    int1 = interval * 10;
  }
  else{

    int1 = interval;
  }
  if (millis() - previousMillis >= int1) {
    sleep();  // Turn display off because the timer ran out
  }

if (alarm == 1 && alarmstop == 0){
  Alarm();
}

}