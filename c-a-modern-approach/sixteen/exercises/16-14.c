/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 16-14.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat May 16 06:10:13 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>

#define RECTANGLE 0
#define CIRCLE 1

struct point {
	int x,y;
};

struct shape {
	int shape_kind;
	struct point center;
	union {
		struct {
			int height, width;
		} rectangle;
		struct {
			int radius;
		} circle;
	} u;
} s;

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
double compute_area(struct shape s);
struct shape move_shape(struct shape s, int x, int y);
struct shape scale_shape(struct shape s, double c);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	// Leaving old code intact for convenience, as it populates values for us!
	// -------------------BEGIN OLD CODE------------------------
	
	printf("-------------------EXERCISE 16-3-------------------\n");
	printf("Shape s Basic values:\n");

	// (a)
	s.shape_kind = RECTANGLE; 
	printf("s.shape_kind: %d\n", s.shape_kind);

	// (b)
	s.center.x = 10;
	printf("s.center.x: %d\n", s.center.x);
	s.center.y = 10; // 16-14: Adding a y value

	// (c)
	s.u.rectangle.height = 25;
	printf("s.u.rectangle.height: %d\n", s.u.rectangle.height);

	// (d)
	s.u.rectangle.width = 8;
	printf("s.u.rectangle.width: %d\n\n", s.u.rectangle.width);

	// Disabling, as s.u.circle is incompatible with s.u.rectangle
	//s.u.circle.radius = 5;		// (e & f)
	//printf("s.u.circle.radius: %d\n", s.u.circle.radius);
	
	// --------------------END OLD CODE------------------------
	
	printf("-------------------EXERCISE 16-4-------------------\n");

	// (a)
	printf("(a) Area: %.1lf\n\n", compute_area(s));

	// (b)
	printf("(b) move  shape s by 2,2.\n");
	printf("    Old center: %d,%d\n\n", s.center.x);
	s = move_shape(s,2,2);
	printf("    New center: %d,%d\n\n", s.center.x);
	
	// (c)
	printf("(c) Scale shape by +30%\n");
	printf("    Old Values - Height: %d | Width: %d\n", s.u.rectangle.height, s.u.rectangle.width);
	s = scale_shape(s,1.3);
	printf("    New Values - Height: %d | Width: %d\n\n", s.u.rectangle.height, s.u.rectangle.width);
	printf("    New Area: %.1lf\n\n", compute_area(s));

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// (a)
double compute_area(struct shape s) {

	return s.u.rectangle.height * s.u.rectangle.width;
}

// (b)
struct shape move_shape(struct shape s, int x, int y) {

	s.center.x += x;
	s.center.y += y;
	
	return s;
}

// (c)
struct shape scale_shape(struct shape s, double c) {

	if (s.shape_kind == RECTANGLE) {

		s.u.rectangle.height *= c;
		s.u.rectangle.width *= c;
	} else if (s.shape_kind == CIRCLE) {
		s.u.circle.radius *= c;
	} else {
		printf("Error: Shape scale cannot occur as shape_kind cannot be blank.\n");
	}

	return s;
}
