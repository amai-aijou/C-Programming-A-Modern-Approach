/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 16-10.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sat May 16 01:44:29 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>
#include <stdbool.h>

struct point {
	int x, y;
};

struct rectangle {
	struct point upper_left, lower_right, center;
	int area;

} r = {{1,3}, {3,1}};

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
double compute_area(struct rectangle r);
struct point compute_center(struct rectangle r);
struct rectangle move_rectangle(struct rectangle r, int x, int y);
bool is_inside(struct rectangle r, struct point p);

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	printf("Initial values:\n");
	printf("upper_left: %d %d\n", r.upper_left.x, r.upper_left.y);		
	printf("lower_right: %d %d\n\n", r.lower_right.x, r.lower_right.y);

	printf("(a) Compute area:\n");
	r.area = compute_area(r);
	printf("area of r: %d\n\n", r.area);

	printf("(b) Compute center of rectangle:\n");
	r.center = compute_center(r);
	printf("center of r: %d %d\n\n", r.center.x, r.center.y);

	printf("(c) Move rectangle forward by 1,1 (x,y). New values:\n");
	r = move_rectangle(r,1,1);
	printf("upper_left: %d %d\n", r.upper_left.x, r.upper_left.y);		
	printf("lower_right: %d %d\n\n", r.lower_right.x, r.lower_right.y);
	printf("area of r: %d\n\n", r.area);
	printf("center of r: %d %d\n\n", r.center.x, r.center.y);

	struct point p = {3,3};
	printf("(d) Determine whether %d,%d is inside the new rectangle:\n", p.x, p.y);
	if (is_inside(r,p)) {
		printf("The point in question is inside the rectangle.\n");
	} else {
		printf("The point in question is *not* inside the rectangle.\n\n");
	}

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
// (a)
double compute_area(struct rectangle r) {

	double length, width;

	length = r.lower_right.x - r.upper_left.x;
	width = r.upper_left.y - r.lower_right.y; 

	return length * width;
}

// (b)
struct point compute_center(struct rectangle r) {
	
	struct point p;

	p.x = r.lower_right.x - (r.upper_left.x)  * .5;
	p.y = r.upper_left.y  - (r.lower_right.y) * .5;

	return p;
}

// (c)
struct rectangle move_rectangle(struct rectangle r, int x, int y) {

	r.upper_left.x += x;
	r.upper_left.y += y;

	r.lower_right.x += x;
	r.lower_right.y += y;

	// Since coordinates have changed, area and center must be updated!
	r.area = compute_area(r);
	r.center = compute_center(r);

	return r;
}

// (d)
bool is_inside(struct rectangle r, struct point p) {

	if (p.x < r.lower_right.x && p.x > r.upper_left.x 
		&& p.y < r.upper_left.y && p.y > r.lower_right.y) {

			return true;
	}

	return false;
}
