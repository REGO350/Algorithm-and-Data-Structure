#include <stdio.h>
#include <math.h> // for sqrt()

typedef struct Point2D { //構造体Point2Dで一つの座標点を表す
  double x;
  double y;
} Point2D;

Point2D ScanPoint2D(); // 構造体 Point2D 型の関数 ScanPoint2D のプロトタイプ宣言
double Distance2D( Point2D a, Point2D b ); // 距離を計算する関数Distance2Dのプロトタイプ宣言
double InnerProd( Point2D a, Point2D b);

int main(void){
  Point2D p, q;
  double d, i;
  p = ScanPoint2D();
  q = ScanPoint2D();
  d = Distance2D( p, q );
  i = InnerProd( p, q );
  printf( "d = %lf\n", d );
  printf( "i = %lf\n", i );
  return 0;
}

Point2D ScanPoint2D(){ //座標の読み込み関数
  Point2D in;
  printf( "input 2 values:\n" );
  scanf( "%lf", &in.x );
  scanf( "%lf", &in.y );
  return( in );
}

double Distance2D( Point2D a, Point2D b ){ //2つの点を受け取って距離を返す
  double sx, sy;
  sx = (a.x - b.x) * (a.x - b.x);
  sy = (a.y - b.y) * (a.y - b.y);
  return( sqrt( sx + sy ) );
}

double InnerProd( Point2D a, Point2D b){
  return a.x*b.x + a.y*b.y;
}