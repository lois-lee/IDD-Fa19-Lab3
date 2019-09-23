# Data Logger (and using cool sensors!)

*A lab report by Lois Lee.*


## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

 0-1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

10 bit, you can read this from the data sheet.

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

[RGB LED](https://drive.google.com/drive/folders/1-oG2M18nJ7WUeI-lWXmDg_21EHhnDYSS)


## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

[FSR connected to LED](https://drive.google.com/drive/folders/1-oG2M18nJ7WUeI-lWXmDg_21EHhnDYSS)

**a. What voltage values do you see from your force sensor?**

I see from 0-4 V and 0-1010 for analog value. 

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

Linear.

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

I mapped the values from 0-1023 from the flex sensor to 0-255 for the LED

```  
  brightness = analogRead(A0);
  val = map(brightness, 0, 1023, 0, 255);
  analogWrite(led, val);
```

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**



**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

Linear.

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

[Code for RGB with accelerometer](https://github.com/lois-lee/IDD-Fa19-Lab3/blob/master/accel+disp.ino)

[Accelerometer and RGB with Display I](https://drive.google.com/file/d/1vO_NLwlGVpFAzzwcWWcIxq7nDz3DyJvq/view?usp=sharing)

[Accelerometer and RGB with Display II](https://drive.google.com/file/d/1PHEh3p-tdwJnNnu8z0y6Cf7bUc0lwdtE/view?usp=sharing)

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

![](1.png)

[FSR + OLED Video](https://drive.google.com/file/d/1xwJhXTCkBJB-e8LdeofHwDhNpxahLR7x/view?usp=sharing)

[FSR + OLED Code](https://github.com/lois-lee/IDD-Fa19-Lab3/blob/master/fsr%2Boled.ino)

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
