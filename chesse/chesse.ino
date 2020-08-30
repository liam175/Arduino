#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(4);

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.display();
    display.print("liam rules");
}




