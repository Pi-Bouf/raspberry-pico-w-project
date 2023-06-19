#include <stdio.h> 
#include <string.h>
#include <math.h>
#include <vector>
#include <cstdlib>

#include "pimoroni-pico/libraries/pico_display_2/pico_display_2.hpp"
#include "pimoroni-pico/drivers/st7789/st7789.hpp"
#include "pimoroni-pico/libraries/pico_graphics/pico_graphics.hpp"
#include "rgbled.hpp"
#include "button.hpp"

using namespace pimoroni;

ST7789 st7789(320, 240, ROTATE_0, false, get_spi_pins(BG_SPI_FRONT));
PicoGraphics_PenRGB332 graphics(st7789.width, st7789.height, nullptr);

RGBLED led(PicoDisplay2::LED_R, PicoDisplay2::LED_G, PicoDisplay2::LED_B);

Button button_a(PicoDisplay2::A);
Button button_b(PicoDisplay2::B);
Button button_x(PicoDisplay2::X);
Button button_y(PicoDisplay2::Y);

int main()
{
  stdio_init_all();

  printf("Appui court\n\r"); 


  Pen BG = graphics.create_pen(0, 0, 0);

  while(true) {

    printf("Appui court\n\r"); 

    graphics.set_pen(BG);
    graphics.clear();

    RGB p = RGB::from_hsv((float)millis() / 5000.0f, 1.0f, 0.5f + sinf(millis() / 100.0f / 3.14159f) * 0.5f);
    led.set_rgb(p.r, p.g, p.b);

    st7789.update(&graphics);
  }

  return 0;
}
