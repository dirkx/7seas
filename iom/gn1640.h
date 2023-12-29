#include <stdint.h>

typedef enum Brightness {
    BRIGHTNESS_OFF = 0x81,
    BRIGHTNESS_01  = 0x88,
    BRIGHTNESS_02  = 0x89,
    BRIGHTNESS_04  = 0x8A,
    BRIGHTNESS_10  = 0x8B,
    BRIGHTNESS_11  = 0x8C,
    BRIGHTNESS_12  = 0x8D,
    BRIGHTNESS_13  = 0x8E,
    BRIGHTNESS_14  = 0x8F
} brightness;

void gn1640_setBrightness(brightness b);
void gn1640_sendBytes(uint8_t data[], uint8_t length, uint8_t adr);
void gn1640_init(brightness b);

