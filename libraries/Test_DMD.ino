#include <DMD.h>
#include <DMD_TextDisplay.h>

#define UNUSED -1

DMD dmd(
  1 /*rows*/, 2 /*cols*/,
  8 /*row data (dark blue)*/, 9 /*row clock (red)   */, 
  7 /*col data (blue)     */, 6 /*col clock (orange)*/, 
  3 /*latch    (green)    */, 2 /*output EN (black) */, UNUSED /*reset (yellow)*/
);

DMD_TextDisplay td(&dmd, "Send your message!    ");

void setup() {
  Serial.begin(9600);
  dmd.init();
  td.setSpeed(90);
}

void loop() {
  td.dispFrame();
  
  if (Serial.available() > 0)
    td.setText(Serial.readString());
}

