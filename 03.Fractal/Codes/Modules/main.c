#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "fractal.h"

int main(int argc, char* argv[])
{
    image_p img = create_image(300, 300);

    fill_random(img);

    for(pixel_coord p = 2; p < 300 - 2; ++p)
        for(int offs = -2; offs < 2; ++offs)
            set_pixel(img, p, p + offs, (pixel_data) p);
    /*
    for (int flag=1; flag<=2; flag++) {
        for (int limit_level=1; limit_level<=7; limit_level++) {
            empty_fractal(img, flag, limit_level);
        }
    }
    */
    empty_fractal(img, atoi(argv[1]), atoi(argv[2]));
    save_pgm(img, "test.pgm");
    return 0;
}