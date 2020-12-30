#include <stdio.h>
#include <stdlib.h>
#define NO 1 /* 番号（入力用）*/
#define NAME 2 /* 氏名（入力用）*/

/*--- メニュー ---*/
typedef enum {
  Term, Insert, Delete, SrcNo, Dump
} Menu;

/*---【新】要素の状態 ---*/
typedef enum {
  Occupied, Empty, Deleted
} Status;

/*--- データ ---*/
typedef struct {
  int no; /* 番号 */
  char name[10]; /* 氏名 */
} Data;

/*---【新】要素 ---*/
typedef struct {
  Data data; /* データ */
  Status stat; /* 要素の状態 */
} Bucket;

/*--- ハッシュ表 ---*/
typedef struct {
  int size; /* ハッシュ表の大きさ */
  Bucket *table; /* ハッシュ表の先頭要素へのポインタ */
} Hash;

/*--- ハッシュ関数（keyのハッシュ値を返す） ---*/
int hash(int key){
  return (key % 13);
}

/*---【新】 再ハッシュ関数 ---*/
int rehash(int key){
  return ((key + 1) % 13);
}

/*---【新】 ノードの各メンバに値を設定---*/
void SetBucket(Bucket *n, Data x, Status stat){
  n->data = x;
  n->stat = stat;
}

/*---【変更】 ハッシュ表を初期化 ---*/
int InitHash(Hash *h, int size){
  int i;
  h->size = 0;
  if((h->table = calloc(size, sizeof(Bucket))) == NULL) /* calloc = ヒープからメモリを確保 */
    return (0);
  h->size = size; /* バケット数をセット */
  for(i=0; i<size; i++)
    h->table[i].stat = Empty; /* 全バケットを初期化 */
  return (1);
}

/*---【変更】 ハッシュ表を後始末 ---*/
void TermHash(Hash *h){
 free(h->table);
}

/*---【変更】 探索 ---*/
Bucket *SearchBucket(Hash *h, Data x){
  int i;
  int key = hash(x.no); /* 探索するデータのハッシュ値 */
  Bucket *p = &h->table[key]; /* 着目バケット */
  for(i=0; (p->stat != Empty) && (i < h->size); i++){
    if(p->stat == Occupied && p->data.no == x.no)
      return (p);
    key = rehash(key);
    p = &h->table[key];
  }
  return (NULL); /* 探索失敗 */
}

/*---【変更】 データの追加 ---*/
int InsertBucket(Hash *h, Data x){
  int i;
  int key = hash(x.no); /* 追加するデータのハッシュ値 */
  Bucket *p = &h->table[key]; /* 着目バケット */
  if(SearchBucket(h, x)) /* このキーは登録済み */
    return (1);
  for(i=0; i < h->size; i++){
    if(p->stat == Empty || p->stat == Deleted){ /* 空か削除済みならば書き込む */
      SetBucket(p, x, Occupied);
      return (0);
    }
    key = rehash(key);
    p = &h->table[key];
  }
  return (2); /* ハッシュ表が満杯 */
}

/*---【更新】 データの削除 ---*/
int DeleteBucket(Hash *h, Data x){
  Bucket *p = SearchBucket(h, x);
  if(p == NULL)
    return (1); /* そのキー値は存在しない */
  p->stat = Deleted;
  return (0);
}

/* ハッシュ表をダンプ */
void DumpHash(Hash *h){
  int i;
  for(i=0; i<h->size; i++){
    printf("%02d ", i);
    switch(h->table[i].stat){
      case Occupied :
        printf("%d (%s)\n", h->table[i].data.no, h->table[i].data.name);
        break;
      case Empty :
        printf("--- 未登録 ---\n");
        break;
      case Deleted :
        printf("--- 削除済み ---\n");
        break;
    }
  }
}

/*--- データの番号と氏名を表示 ---*/
void PrintData(Data x){
  printf("%d %s\n", x.no, x.name);
}

/*--- データの入力 ---*/
Data Read(char *message, int sw){
  Data temp;
  printf("%sするデータを入力してください\n", message);
  if(sw & NO) {printf("番号："); scanf("%d", &temp.no);}
  if(sw & NAME) {printf("名前："); scanf("%s", temp.name);}
  return (temp);
}

/*--- メニュー選択 ---*/
Menu SelectMenu(void){
  int i, ch;
  do{
    printf("(1) 追加 (2) 削除 (3) 探索 (4) ダンプ (0) 終了：");
    scanf("%d", &ch);
  } while (ch < Term || ch > Dump);
  return((Menu)ch);
}

/*---【少し変更】 メイン ---*/
int main(void){
  Menu menu;
  Hash hash;
  InitHash(&hash, 13); /* ハッシュ表の初期化 */
  do{
    int result;
    Data x;
    Bucket *temp;
    switch(menu = SelectMenu()){
      case Insert : x = Read("追加", NO | NAME);
        result = InsertBucket(&hash, x);
        if(result)
          printf("追加に失敗しました（%s）.\n", (result == 1) ? "登録済み" : "表は満杯");
        break;
      case Delete : x = Read("削除", NO);
        result = DeleteBucket(&hash, x);
        if(result == 1)
          printf("その番号のデータは存在しません.\n");
        break;
      case SrcNo : x = Read("探索", NO);
        temp = SearchBucket(&hash, x);
        if(temp == NULL)
          printf("探索に失敗しました.\n");
        else {
          printf("探索に成功しました.\n");
          PrintData(temp->data);
        }
        break;
      case Dump : DumpHash(&hash);
        break;
    }
  } while (menu != Term);
  TermHash(&hash); /* ハッシュ表の後始末 */
  return (0);
}