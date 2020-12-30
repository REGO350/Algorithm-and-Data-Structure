#include <stdio.h>
#include <math.h> 

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
double Area( Triangle t );

int main( void ){
  Triangle t; //インスタンス
  double d;
  double area;
  // Define triangle coordinates
  t.p1 = ScanPoint2D();
  t.p2 = ScanPoint2D();
  t.p3 = ScanPoint2D();
  area = Area( t ); //三角形tの面積を求める関数を呼ぶ
  printf( "Area of triangle: %lf\n", area);
  return 0;
}

double Area( Triangle t ){
  double len12, len23, len31, s, area;
  len12 = Distance2D(t.p1, t.p2); /*辺の長さを求める*/
  len23 = Distance2D(t.p2, t.p3); /*辺の長さを求める*/
  len31 = Distance2D(t.p3, t.p1); /*辺の長さを求める*/
  s = (len12 + len23 + len31)/2;  /*ヘロンの公式のsを求める*/
  area = sqrt(s*(s-len12)*(s-len23)*(s-len31)); /*面積*/
  return area;
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