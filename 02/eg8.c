#include <stdio.h>
#include <math.h> // for sqrt()

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
double PerimeterTriangle( Triangle t );

int main( void ){
  Triangle a;
  double d;
  // Define triangle coordinates
  a.p1 = ScanPoint2D();
  a.p2 = ScanPoint2D();
  a.p3 = ScanPoint2D();
  d = PerimeterTriangle( a );
  printf( "perimeter = %f\n", d );
  return 0;
}

double PerimeterTriangle( Triangle t ){
  double peri = 0;
  peri += Distance2D( t.p1, t.p2 );
  peri += Distance2D( t.p2, t.p3 );
  peri += Distance2D( t.p3, t.p1 );
  return peri;
}

Point2D ScanPoint2D( void ){
  Point2D p;
  printf( "input 2 values:\n" );
  scanf( "%lf", &p.x );
  scanf( "%lf", &p.y );
  return( p );
}