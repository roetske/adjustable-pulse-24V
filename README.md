# adjustable-pulse-24V
make pulses adjustabale on 0-2s off 0-1s

I am a technician. On installations 24v is the standard for inputs.  <br />
Sometimes it is helpful to make a blinker 24v to test the input and then you can see  <br />
or check on plc or io island.  <br />
The first one i made was with 555 fix pulse but i wanted faster pulse this was not possible in the range i wanted. <br />
(yes add potentiometer but circuit was already made and implementing the potentiometer was not ideal)  <br />
I made this little project using nano ,oled with 2 potentiometers and confirm button.  <br />
The nano allows you to have flexible timing more than with 555.<br />
So i can choose set my timing whatever i want.<br />

# How does it work
you connect power with m12 4 pins connector at one end and you connect the power to the 3 port terminal  <br />
brown 24v  <br />
blue 0v  <br />
white or black you choose to signal <br />
When the unit is powered up you get the on and off time on the oled. <br />
you set on an off time of your choosing and than validate with the pusbutton <br />
The yellow led will start blinking at the rate you want <br />
And the 24v output will be switched to the pulse you set <br />
I put a scope on it the timing is pretty accurate lol  <br />
I set the timing choice to 0-2 s for on time en 0-1 s for offtime <br />

# components
nano  <br />
2 potentiometers  <br />
oled 0.91 inch 164x32  <br />
pushbutton <br />
bc547  <br />
bc327  <br />
3 10k resistors <br />
4k7 resistor  <br />
1k resistor  <br />
diode 1n4007  <br />
yellow led  <br />
dcdc converter 6v output <br />
3port screw terminal pitch5  <br />
m2 distance spacers  <br />
ptc fuse 0.5 A  <br />
2 pcb 50mmx70mm  <br />

# Remark

Firts time i powered the nano with 5V in Vin. <br />
Nok nano was not working properly. I found on the net you should use at least 6V for Vin. <br />
This due to voltage loss by the regualor in the nano <br />
If you have only 5V available you should connect directly to 5V pin on the nano.<br />


