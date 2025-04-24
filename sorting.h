#ifndef SORTING_H
#define SORTING_H

#include <string.h>

//
// Bubble Sort Section
//

// Bubble Sort untuk array integer.
// Menukar elemen bersebelahan jika urutannya salah, diulang hingga tersortir.
void bubble_sort_int(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Bubble Sort untuk array string (char*).
// Menukar string bersebelahan jika tidak urut secara leksikografis.
void bubble_sort_str(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//
// Insertion Sort Section
//

// Insertion Sort untuk array integer.
// Menyisipkan elemen ke posisi yang sesuai dalam bagian array yang sudah terurut.
void insertion_sort_int(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Insertion Sort untuk array string.
// Menyisipkan string pada posisi yang tepat dalam urutan leksikografis.
void insertion_sort_str(char *arr[], int n) {
    for (int i = 1; i < n; i++) {
        char *key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

//
// Selection Sort Section
//

// Selection Sort untuk array integer.
// Memilih elemen terkecil dari sisa array lalu menukarnya ke posisi yang sesuai.
void selection_sort_int(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Selection Sort untuk array string.
// Memilih string terkecil secara leksikografis dan menukarnya ke posisi yang sesuai.
void selection_sort_str(char *arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        }
        char *temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

//
// Merge Sort Section
//

// Merge Sort untuk array integer
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort_int(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_int(arr, l, m);
        merge_sort_int(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Wrapper agar bisa dipanggil dari main.c
void merge_sort_wrapper(int arr[], int n) {
    merge_sort_int(arr, 0, n - 1);
}

// Merge Sort untuk array string (char*)
void merge_str(char *arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    char *L[n1], *R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (strcmp(L[i], R[j]) <= 0) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void merge_sort_str(char *arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_str(arr, l, m);
        merge_sort_str(arr, m + 1, r);
        merge_str(arr, l, m, r);
    }
}

// Wrapper agar bisa dipanggil dari main.c
void merge_sort_str_wrapper(char *arr[], int n) {
    merge_sort_str(arr, 0, n - 1);
}

//
// Quick Sort Section
//

// Quick Sort untuk array integer
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = tmp;
    return i + 1;
}

void quick_sort_int(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_int(arr, low, pi - 1);
        quick_sort_int(arr, pi + 1, high);
    }
}

// Wrapper agar bisa dipanggil dari main.c
void quick_sort_wrapper(int arr[], int n) {
    quick_sort_int(arr, 0, n - 1);
}

// Quick Sort untuk array string
int partition_str(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            char *tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    char *tmp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = tmp;
    return i + 1;
}

void quick_sort_str(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition_str(arr, low, high);
        quick_sort_str(arr, low, pi - 1);
        quick_sort_str(arr, pi + 1, high);
    }
}

// Wrapper agar bisa dipanggil dari main.c
void quick_sort_str_wrapper(char *arr[], int n) {
    quick_sort_str(arr, 0, n - 1);
}

//
// Shell Sort Section
//

// Shell Sort untuk array integer.
// Menggunakan gap untuk mempercepat proses penyisipan dibanding insertion sort biasa.
void shell_sort_int(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Shell Sort untuk array string.
// Mengurutkan string dengan metode gap sorting berdasarkan urutan leksikografis.
void shell_sort_str(char *arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char *temp = arr[i];
            int j;
            for (j = i; j >= gap && strcmp(arr[j - gap], temp) > 0; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

#endif // SORTING_H
