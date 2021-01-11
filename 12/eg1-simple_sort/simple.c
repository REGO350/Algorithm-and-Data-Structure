void simplesort(int *data, int N) {
  int i, j;

  for (i = 0; i < N-1; i++) {
    for (j = i+1; j < N; j++){
      if (data[i] > data[j]) {
        swap(data, i, j);
      }
    }
  }
}