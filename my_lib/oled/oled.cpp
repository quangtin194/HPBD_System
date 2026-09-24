#include "oled.h"

static Adafruit_SSD1306 display(SCREEN_W, SCREEN_H, &Wire, -1);

void Oled_init(uint8_t sda, uint8_t scl)
{
    Wire.begin(sda, scl);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("OLED init failed");
        return;
    }

    Serial.println("OLED init OK");
    display.clearDisplay();
    display.display();
}

void Oled_display(const char *text1, const char *text2)
{
    int16_t x1, y1;
    uint16_t w, h;
    int16_t x;

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // Dòng 1
    display.getTextBounds(text1, 0, 0, &x1, &y1, &w, &h);
    x = (128 - w) / 2;

    if (text2 == NULL || text2[0] == '\0')
    {
        display.setCursor(x, 28);
        display.print(text1);
    }
    else
    {
        display.setCursor(x, 20);
        display.print(text1);

        // Dòng 2
        display.getTextBounds(text2, 0, 0, &x1, &y1, &w, &h);
        x = (128 - w) / 2;

        display.setCursor(x, 44);
        display.print(text2);
    }

    // Đẩy framebuffer lên OLED
    display.display();
}