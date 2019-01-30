#define KEY_TYPE int

void merge_sort(KEY_TYPE a[], int p, int r) {

	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}


void merge(KEY_TYPE a[], int p, int q, int r) {

	int n1 = q - p + 1;
	int n2 = r - q;
	KEY_TYPE m[n1 + 1], n[n2 + 1];//变长数组，c99标准
	//KEY_TYPE *m = (KEY_TYPE*)malloc(sizeof(KEY_TYPE)*(n1 + 1));
	//KEY_TYPE *n = (KEY_TYPE*)malloc(sizeof(KEY_TYPE)*(n2 + 1));

	for (int i = 0; i < n1; ++i) {
		m[i] = a[p + i];
	}

	for (int j = 0; j < n2; ++j) {
		n[j] = a[q + j + 1];
	}

	m[n1] = 0;//默认a数组中不存在0
	n[n2] = 0;

	int i = 0, j = 0;
	for (int k = p; k <= r; ++k) {
		if (n[j] == 0 || m[i] <= n[j] && m[i] != 0) {
			a[k] = m[i];
			++i;
		}else {
			a[k] = n[j];
			++j;
		}
	}
}
