#include "mbed.h"
#include "DHT.h"
#include "AQM0802A.h"
//#include "TextLCD.h"

//I2C i2c_lcd(p28,p27);
AQM0802A lcd(p28, p27);
Serial pc(USBTX, USBRX);
//AQM0802 lcd(p28, p27);
//TextLCD_I2C lcd(&i2c_lcd, 0x7C, TextLCD::LCD8x2, TextLCD::ST7032_3V3);

DHT sensor(p23, DHT11);

int main()
{
    int error = 0;
    float h = 0.0f, c = 0.0f;
    while(1) {
        wait(2.0f);
        error = sensor.readData();
        if (0 == error) {
            c   = sensor.ReadTemperature(CELCIUS);
            //f   = sensor.ReadTemperature(FARENHEIT);
            //k   = sensor.ReadTemperature(KELVIN);
            h   = sensor.ReadHumidity();
            //dp  = sensor.CalcdewPoint(c, h);
            //dpf = sensor.CalcdewPointFast(c, h);
            pc.printf("Celcius: %4.2f\n",c);
            pc.printf("Humidity is %4.2f\n", h);
            lcd.cls();
            lcd.setCursor(0,0);
            lcd.printf("%.1f oC",c);
            lcd.setCursor(0,1);
            lcd.printf("%.1f %%",h);
            //lcd.lcd_setCursor(0,0);
            //lcd.print("%2.2f",c);
            //lcd.printf("hello");
            //lcd.lcd_setCursor(0,1);
            //lcd.print("%2.2f",h);
            //lcd.lcd_printStr("1E");
        } else {
            printf("Error: %d\n", error);
        }
    }
}
/*
#include <mbed.h>
#include <AQM0802A.h>

AQM0802A lcd(p28, p27); // <-- this !
Ticker   ticker;

void tick() {
    static int count = 0;
    lcd.cls();
    lcd.printf("Hello\n %d", count++);
}

int main() {
    ticker.attach(&tick, 0.1);
    while(1) {
    }
}
*/
