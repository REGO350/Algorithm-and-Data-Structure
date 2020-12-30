#include <stdio.h>
#include <math.h> // for sqrt()
#define MATH_PI 3.141592653589793238462643383279

typedef struct Point2D {
  double x;
  double y;
} Point2D;

typedef struct Triangle {
  Point2D p1;
  Point2D p2;
  Point2D p3;
} Triangle;

Point2D ScanPoint2D( void );
double Distance2D( Point2D a, Point2D b );
// double PerimeterTriangle( Triangle t );
double Angle( Triangle t );

int main( void ){
  Triangle a;
  double d;
  double p1_angle;
  // Define triangle coordinates
  a.p1 = ScanPoint2D();
  a.p2 = ScanPoint2D();
  a.p3 = ScanPoint2D();
  // d = PerimeterTriangle( a );
  p1_angle = Angle( a );
  // printf( "perimeter = %f\n", d );
  printf( "angle at p1 = %lf\n", p1_angle);
  return 0;
}

double Angle( Triangle t ){
  double angle, cos_angle, len12, len23, len31;
  len12 = Distance2D(t.p1, t.p2);
  len23 = Distance2D(t.p2, t.p3);
  len31 = Distance2D(t.p3, t.p1);
  cos_angle = ( powf(len12,2) + powf(len31,2) - powf(len23,2) ) / (2 * len12 * len31);
  angle = acos(cos_angle);
  angle = angle * 180 / MATH_PI;
  return angle;
}

Point2D ScanPoint2D( void ){
  Point2D p;
  printf( "input 2 values:\n" );
  scanf( "%lf", &p.x );
  scanf( "%lf", &p.y );
  return( p );
}

double Distance2D( Point2D a, Point2D b ){
  double sx, sy;
  sx = (a.x - b.x) * (a.x - b.x); 
  sy = (a.y - b.y) * (a.y - b.y);
  
  return( sqrt( sx + sy ) );
}