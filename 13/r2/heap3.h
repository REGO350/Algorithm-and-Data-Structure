typedef int Data;

void buildHeap(Data *, int);
void upHeap(Data *, int, int);
void heapQ(Data *a, int n); // 新たに追加したもの
void downHeap(Data *a, int i, int k);