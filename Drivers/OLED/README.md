# OLED Driver API

## About the Driver
The OLED driver allows the user to display images, text, and shapes to the SSD1306BZ OLED controller.

## How to Use
The functions below are implemented in and `ssd1306.c`.
### Initialization
```c
void ssd1306_Init(void);
```
### Fill Screen with Color
```c
void ssd1306_Fill(SSD1306_COLOR color);
```
Where `color` is an enumerator which can be either `black` or `white`.

### Draw a Pixel to the Buffer
```c
void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color);
```
### Draw string to the Buffer
```c
char ssd1306_WriteString(char* str, FontDef Font, SSD1306_COLOR color);
```
Font is a struct with attributes `uint8_t FontWidth`, `uint8_t FontHeight`, and `uint_16t *data` which is a pointer to a font data array.

### Position Cursor
```c
void ssd1306_SetCursor(uint8_t x, uint8_t y);
```

### Draw Lines, Curves, and Shapes
```c
void ssd1306_Polyline(const SSD1306_VERTEX *par_vertex, uint16_t par_size, SSD1306_COLOR color);
```
```c
void ssd1306_DrawArc(uint8_t x, uint8_t y, uint8_t radius, uint16_t start_angle, uint16_t sweep, SSD1306_COLOR color);
```
```c
void ssd1306_DrawArcWithRadiusLine(uint8_t x, uint8_t y, uint8_t radius, uint16_t start_angle, uint16_t sweep, SSD1306_COLOR color);
```
```c
void ssd1306_DrawCircle(uint8_t par_x,uint8_t par_y,uint8_t par_r,SSD1306_COLOR par_color);
```
```c
void ssd1306_FillCircle(uint8_t par_x,uint8_t par_y,uint8_t par_r,SSD1306_COLOR par_color);
```
```c
void ssd1306_DrawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color);
```
```c
void ssd1306_FillRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color);
```
```c
void ssd1306_DrawBitmap(uint8_t x, uint8_t y, const unsigned char* bitmap, uint8_t w, uint8_t h, SSD1306_COLOR color);
```

### Display Settings
```c
void ssd1306_SetContrast(const uint8_t value);
```
```c
void ssd1306_SetDisplayOn(const uint8_t on);
```
```c
uint8_t ssd1306_GetDisplayOn();
```

### Write the Buffer With the Changes to the Screen
```c
void ssd1306_UpdateScreen(void);
```

## Sample Code
Sample functions can be found in `ssd1306_tests.c`. Notably, the function that runs through all the test cases is:
```c
void ssd1306_TestAll();
```