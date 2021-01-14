#define NMAX 1000000
static int b[NMAX]; // mergesortで用いる補助配列

void merge_sort(int *a, int l, int r) {
  int i, j, k, m;
  if (l >= r)
    return;

  m = (l+r)/2; // a[l..r] の中央を決める
  merge_sort(a, l, m); // a の左半分を整列する
  merge_sort(a, m+1, r); // a の右半分を整列する

  // 補助配列 b へ a をコピーする
  for (i=l; i<=m; i++)
    b[i] = a[i]; // a の左半分はそのまま b へコピー
  for (i=m+1; i<=r; i++) // a の右半分は逆順で b へコピー
    b[r-i+m+1] = a[i];

  // a の左半分と右半分のデータをマージする
  i=l; // bの先頭 = a の左半分の先頭
  j=r; // bの末尾 = a の右半分の先頭
  for (k=l; k<=r; k++)
    a[k] = (b[i] < b[j])?b[i++]:b[j--];
}