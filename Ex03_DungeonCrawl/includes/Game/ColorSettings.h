#pragma once

#define BLINKING_ON 0
#define COLORS_ON 1

#if BLINKING_ON
# define BLINKING_CHARS ";5"
#else
# define BLINKING_CHARS ""
#endif

#if COLORS_ON
# define PUT_COLOR(color) color
#else
# define PUT_COLOR(color)
#endif
