template <class Elem>
inline void swap(Elem A[], int i, int j){
	Elem temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

template <class Elem>
inline void swap(Elem &e1, Elem &e2){
	Elem temp = e1;
	e1 = e2;
	e2 = temp;
}

/******************************************************
Quick Sort
******************************************************/
template <class Elem> int FindPivot(Elem A[], int i, int j){ return (i+j)/2; }

// pivot is supposed to be located at the end i.e. position r by convention
template <class Elem, class Comp>
int Partition(Elem A[], int l, int r, Elem& pivot){
	--l;
	do {
		while (Comp::lt(A[++l], pivot));
		while ((r!=0) && Comp::gt(A[--r], pivot));
		swap(A,l,r);
	} while (l<r);
	swap(A,l,r);
	return l;
}

// Initial call: QuickSort(array,0,n-1)
template <class Elem, class Comp>
void QuickSort(Elem A[], int i, int j){
	if (j<=i) return;
	int pivotidx = FindPivot<Elem>(A,i,j);
	swap(A,pivotidx,j); // Put the pivot at the end
	int k = Partition<Elem,Comp>(A,i,j,A[j]);
	swap(A,k,j);
	QuickSort<Elem,Comp>(A,i,k-1);
	QuickSort<Elem,Comp>(A,k+1,j);
}

/******************************************************
END Quick Sort
******************************************************/

/******************************************************
Merge Sort
******************************************************/
template <class Elem, class Comp>
void MergeSort(Elem A[], Elem temp[], int left, int right) {
	int mid = (left + right) / 2;
	if (left == right) return;
	MergeSort<Elem, Comp>(A, temp, left, mid);
	MergeSort<Elem, Comp>(A, temp, mid+1, right);
	for (int i = left; i <= right; ++i)
		temp[i] = A[i];
	int i1 = left; int i2 = mid + 1;
	for (int curr = left; curr <= right; ++curr) {
		if (i1 == mid+1)
			A[curr] = temp[i2++];
		else if (i2 > right)
			A[curr] = temp[i1++];
		else if (Comp::lt(temp[i1], temp[i2]))
			A[curr] = temp[i1++];
		else A[curr] = temp[i2++];
	}
}
/******************************************************
ENMerge Sort
******************************************************/

// Insertion sort
template <class Elem, class Comp>
void InsertionSort(Elem A[], int n) {
	for (int i = 1; i < n; ++i) {
		int temp = i;
		while (Comp::lt(A[temp], A[temp-1]) && temp!=0) {
			swap(A, temp, temp-1);
			--temp;
		}
	}
}

// Bubble sort
template <class Elem, class Comp>
void BubbleSort(Elem A[], int n) {
	for (int j = 1; j <= n; ++j) {
		for (int i = n-1; i >= j; --i) {
			if (Comp::lt(A[i], A[i-1]))
				swap(A, i, i-1);
		}
	}
}

// Selection Sort
template <class Elem, class Comp>
void SelectionSort(Elem A[], int n) {
	for (int i = 0; i < n; ++i) {
		int max_index = i;
		for (int j = i; j < n; ++j) {
			if (Comp::lt(A[j], A[max_index]))
					max_index = j;
		}
		swap(A, i, max_index);
	}
}

// Shell Sort
// Modified version of Insertion Sort
template <class Elem, class Comp>
void inssort2(Elem A[], int n, int incr) {
	for (int i = incr; i < n; i += incr)
		for (int j = i; (j>=incr) && (Comp::lt(A[j], A[j-incr])); j-=incr)
			swap(A, j, j-incr);
}

template <class Elem, class Comp>
void ShellSort(Elem A[], int n) {
	for (int i = n/2; i > 2; i/=2) {
		for (int j=0; j<i; ++j) {
			inssort2<Elem, Comp>(&A[j], n-j, i);
			inssort2<Elem, Comp>(A, n, 1);
		}
	}
}
