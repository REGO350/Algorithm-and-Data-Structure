// 単純法（⼒まかせ法）による⽂字列探索
#include <stdio.h>

int bf_match(const char txt[], const char pat[]){
  int pt = 0; // txtをなぞるカーソル
  int pp = 0; // patをなぞるカーソル

  while (txt[pt] != '\0' && pat[pp] != '\0'){ // どちらかがNULLになるまで
    if (txt[pt] == pat[pp]){
      // ⽂字が⼀致していたらカーソルを進める
      pt++; pp++;
    } else {
      // ⼀致しない場合，テキストのカーソルをパターンを進めた分 (=pp) 戻して，１つ進める
      pt = pt - pp + 1;
      pp = 0;
    }
  }
  if (pat[pp] == '\0') // パターンの最後までマッチ！
    return pt - pp; // テキストのカーソルをパターンの⻑さ分戻して返り値とする
  return -1;
}

int main(void){
  int index;
  char text[256];
  char pattern[256];
  
  printf("text : "); scanf("%s",text);
  printf("pattern : "); scanf("%s",pattern);

  index = bf_match(text,pattern);
  if (index == -1){
    printf("パターンはテキスト中に存在しません．\n");
  } else {
    printf("パターンはテキストの%d⽂字⽬からマッチします．\n",index+1);
  }

  return 0;
}