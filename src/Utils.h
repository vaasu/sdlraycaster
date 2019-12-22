

#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_
#include <stdint.h>

namespace sdlraycaster {
uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b,
                    const uint8_t a = 255);
}

#endif