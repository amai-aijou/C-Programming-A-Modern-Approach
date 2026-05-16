/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 16-9.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Fri May 15 06:24:43 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdbool.h>

struct color {
	int red;
	int green;
	int blue;
};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
struct color make_color(int red, int green, int blue);
int range_limiter(int color);
void print_color(struct color c);
int getRed(struct color c);
bool equal_color(struct color color1, struct color color2);
struct color brighter(struct color c);
struct color darker(struct color c);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	// (a)
	// const struct color MAGENTA = {255,0,255};
	
	// (b) C99 Designated Initializer
	const struct color MAGENTA = {.red = 255, .blue = 255};	
	print_color(MAGENTA);

	// (c)
	struct color WHITE = make_color(255,255,256);
	print_color(WHITE);
	equal_color(WHITE,WHITE);

	// (d)
	struct color DARK_BLUE = make_color(0,102,255);
	print_color(DARK_BLUE);
	DARK_BLUE = brighter(DARK_BLUE);
	print_color(DARK_BLUE);

	// (e)
	struct color PINK = make_color(255,204,255);
	print_color(PINK);
	PINK = darker(PINK);
	print_color(PINK);
	
	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// (a) Returns a color structure containing specified values 0-255
struct color make_color(int red, int green, int blue) {

	struct color c1;

	c1.red = range_limiter(red);
	c1.green = range_limiter(green);
	c1.blue = range_limiter(blue);

	return c1;
}

// (a) Numbers falling outside this range are auto-adjusted to fit
int range_limiter(int color) {
	
	if (color > 255) {
		color = 255;
	}

	if (color < 0) {
		color = 0;
	}

	return color;
}

void print_color(struct color c) {
	
	printf("Red: %d | Green: %d | Blue: %d\n", c.red, c.green, c.blue);
}

// (b)
int getRed(struct color c) {

	return c.red;
}

// (c)
bool equal_color(struct color color1, struct color color2) {

	if ((color1.red == color2.red) && (color1.green == color2.green) 
			&& (color1.blue == color2.blue)) {
		return true;
	}

	return false;
}

// (d)
struct color brighter(struct color c) {

	// If all three colors are 0, set all to 3, then exit
	if ((c.red == 0) && (c.green == 0) && (c.blue == 0)) {

		c.red = 3;
		c.green = 3;
		c.blue = 3;

		return c;
	}

	// If all three colors are greater than 0...
	if ((c.red >= 0) && (c.green >= 0) && (c.blue >= 0)) {

		// ...and less than 3, set each to three, then let the function continue
		if ((c.red <= 3) && (c.green <= 3) && (c.blue <= 3)) {

			c.red = 3;
			c.green = 3;
			c.blue = 3;
		} 
	}

	c.red = range_limiter(c.red / .7);
	c.green = range_limiter(c.green / .7);
	c.blue = range_limiter(c.blue / .7);

	return c;
}

// (e)
struct color darker(struct color c) {

	// If all three colors are 0, set all to 3, then exit
	if ((c.red == 0) && (c.green == 0) && (c.blue == 0)) {

		c.red = 3;
		c.green = 3;
		c.blue = 3;

		return c;
	}

	// If all three colors are greater than 0...
	if ((c.red >= 0) && (c.green >= 0) && (c.blue >= 0)) {

		// ...and less than 3, set each to three, then let the function continue
		if ((c.red <= 3) && (c.green <= 3) && (c.blue <= 3)) {

			c.red = 3;
			c.green = 3;
			c.blue = 3;
		} 
	}

	c.red = range_limiter(c.red * .7);
	c.green = range_limiter(c.green * .7);
	c.blue = range_limiter(c.blue * .7);

	return c;
}
