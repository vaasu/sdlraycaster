#include <string>

namespace sdlraycaster {
namespace map {
const int map_w = 16;
const int map_h = 16;
const int wall_height = 2;
sdlraycaster::world_coord camera{};
const std::string map =
    "WWWWWWWWWWWWWWWWW"
    "W               W"
    "W               W"
    "W     .         W"
    "W               W"
    "W          W    W"
    "W          W    W"
    "W      WWWWW    W"
    "W               W"
    "W               W"
    "W               W"
    "W               W"
    "W               W"
    "W               W"
    "W               W"
    "Wwwwwwwwwwwwwwwww";
}  // namespace map
}  // namespace sdlraycaster