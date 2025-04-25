#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

#include "sorting.h" 

#pragma comment(lib, "psapi.lib")

#define MAX_DATA 2000000
#define MAX_WORD_LENGTH 100

// Array global untuk menyimpan data angka dan kata
int data_int[MAX_DATA], temp_int[MAX_DATA];
char data_word[MAX_DATA][MAX_WORD_LENGTH], *temp_word[MAX_DATA];

/// Menghitung waktu eksekusi dalam satuan detik
double get_time(clock_t start, clock_t end) {
    return (double)(end - start) / CLOCKS_PER_SEC;
}

/// Mengambil jumlah memori yang digunakan oleh program saat ini (dalam KB)
long get_memory_kb() {
    PROCESS_MEMORY_COUNTERS memInfo;
    GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
    return memInfo.WorkingSetSize / 1024;
}

/// Menyalin data integer dari array sumber ke array tujuan
void copy_int(int dest[], int src[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

/// Menyalin data string dari array 2 dimensi ke array pointer
void copy_word(char *dest[], char src[][MAX_WORD_LENGTH], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

/// Menampilkan hasil waktu dan memori setelah eksekusi algoritma sorting
void show_result(const char *name, clock_t start, clock_t end) {
    double waktu = get_time(start, end);
    long mem = get_memory_kb();
    printf("| %-17s | %8.3f s | %8ld KB |\n", name, waktu, mem);
}

/// Menjalankan fungsi sorting untuk data integer, lalu mencatat waktu dan memori
void run_sort_int(const char *name, void (*sort)(int[], int), int src[], int n) {
    copy_int(temp_int, src, n);
    clock_t t1 = clock();
    sort(temp_int, n);
    clock_t t2 = clock();
    show_result(name, t1, t2);
}

/// Menjalankan fungsi sorting untuk data string, lalu mencatat waktu dan memori
void run_sort_str(const char *name, void (*sort)(char*[], int), char *src[], int n) {
    copy_word(temp_word, data_word, n);
    clock_t t1 = clock();
    sort(temp_word, n);
    clock_t t2 = clock();
    show_result(name, t1, t2);
}

/// Membaca data integer dari file dan menyimpannya ke dalam array
int load_int_data(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) { perror("File angka tidak dapat dibuka"); return 0; }
    int n = 0;
    while (n < MAX_DATA && fscanf(fp, "%d", &data_int[n]) != EOF) n++;
    fclose(fp);
    return n;
}

/// Membaca data kata dari file dan menyimpannya ke dalam array
int load_word_data(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) { perror("File kata tidak dapat dibuka"); return 0; }
    int n = 0;
    while (n < MAX_DATA && fscanf(fp, "%s", data_word[n]) != EOF) n++;
    for (int i = 0; i < n; i++) temp_word[i] = data_word[i];
    fclose(fp);
    return n;
}

/// Fungsi utama program: memuat data, meminta jumlah data, dan menjalankan semua algoritma sorting
int main() {
    int jumlah;
    printf("Masukkan jumlah data yang ingin disorting (maks 2.000.000): ");
    scanf("%d", &jumlah);

    // Memuat data dari file
    int total_int = load_int_data("data_angka.txt");
    int total_word = load_word_data("data_kata.txt");

    // Validasi apakah jumlah data cukup
    if (jumlah > total_int || jumlah > total_word) {
        printf("Jumlah data tidak cukup.\n");
        return 1;
    }

    // Menampilkan hasil sorting untuk data integer
    printf("\n====== HASIL SORTING ANGKA (%d data) ========\n", jumlah);
    printf("| %-17s | %-10s | %-10s  |\n", "Algoritma", "Waktu", "Memori");
    printf("|-------------------|------------|-------------|\n");
    run_sort_int("Bubble Sort", bubble_sort_int, data_int, jumlah);
    run_sort_int("Selection Sort", selection_sort_int, data_int, jumlah);
    run_sort_int("Insertion Sort", insertion_sort_int, data_int, jumlah);
    run_sort_int("Merge Sort", merge_sort_wrapper, data_int, jumlah);
    run_sort_int("Quick Sort", quick_sort_wrapper, data_int, jumlah);
    run_sort_int("Shell Sort", shell_sort_int, data_int, jumlah);

    // Menampilkan hasil sorting untuk data string
    printf("\n====== HASIL SORTING KATA (%d data) =========\n", jumlah);
    printf("| %-17s | %-10s | %-10s  |\n", "Algoritma", "Waktu", "Memori");
    printf("|-------------------|------------|-------------|\n");
    run_sort_str("Bubble Sort", bubble_sort_str, temp_word, jumlah);
    run_sort_str("Selection Sort", selection_sort_str, temp_word, jumlah);
    run_sort_str("Insertion Sort", insertion_sort_str, temp_word, jumlah);
    run_sort_str("Merge Sort", merge_sort_str_wrapper, temp_word, jumlah);
    run_sort_str("Quick Sort", quick_sort_str_wrapper, temp_word, jumlah);
    run_sort_str("Shell Sort", shell_sort_str, temp_word, jumlah);

    return 0;
}
