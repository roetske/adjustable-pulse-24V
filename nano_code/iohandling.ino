void read_io ()
{

an1value = analogRead(an1);//rode
an2value = analogRead(an2);//gele
bpushbutton =digitalRead(pushbutton);
boutput = digitalRead(Soutput);
Ontime = map(an2value, 0, 1023, 0, 2000);
Oftime= map(an1value, 0, 1023, 0, 1000);

//Serial.println("R: " + String(variableR) + ", G: " + String(variableG) + ", B: " + String(variableB));
Serial.println("---------------------------------------");
Serial.println("an1: " + String(an1value) + ", an2: " + String(an2value) + ", pushbutton: " + String(bpushbutton));
Serial.println("an1: " + String(an1value) + ", an2: " + String(an2value) + ", pushbutton: " + String(bpushbutton));
Serial.println("output:"+ String(boutput));
Serial.println("****************************************");
}