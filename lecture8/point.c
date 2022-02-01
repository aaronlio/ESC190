#include <math.h>
#include <stdio.h>

typedef struct Point {
	double x;
	double y;
} Point;

double euclidean_dist(Point p1, Point p2){
	return pow(pow(p1.x - p2.x, 2) + pow(p1.y- p2.y, 2), 0.5);
}

void change_point_to_origin(Point* p){
	p->x = 0; // (*p).x = 0
	p->y = 0; // (*p).y = 0
}

int main(){
	Point point1;
	point1.x = 10.0;
	point1.y = 5.0;
	
	Point point2;
	point2.x = 5.0;
	point2.y = 5.0;
	
	double result = euclidean_dist(point1, point2);
	fprintf(stdout, "%0.2f \n", result);
	
	Point p;
	p.x = 1;
	p.y = 2;
	
	fprintf(stdout, "p is at x: %0.2f, y: %0.2f\n", p.x, p.y);
	change_point_to_origin(&p);
	fprintf(stdout, "p is at x: %0.2f, y: %0.2f\n", p.x, p.y);
	return 0;
}