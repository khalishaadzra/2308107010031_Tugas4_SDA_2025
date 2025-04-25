# Tugas 4 - Implementasi dan Analisis Performa Algoritma Sorting

## Informasi Mahasiswa
- Nama: Khalisha Adzraini Arif  
- NPM: 2308107010031  

## Deskripsi Tugas
Tugas ini bertujuan untuk mengimplementasikan dan menganalisis performa dari beberapa algoritma sorting dalam bahasa pemrograman C. Algoritma yang diuji meliputi:

- Bubble Sort  
- Selection Sort  
- Insertion Sort  
- Merge Sort  
- Quick Sort  
- Shell Sort  

Pengujian dilakukan terhadap data acak dalam bentuk angka dan kata dengan skala besar, hingga 2.000.000 baris. Mahasiswa diminta mengukur waktu eksekusi dan penggunaan memori dari setiap algoritma, lalu membandingkannya dalam bentuk tabel dan grafik.

## Petunjuk Implementasi
- Setiap algoritma diimplementasikan sebagai fungsi terpisah dalam file header (`.h`), lengkap dengan komentar penjelas prinsip kerjanya.
- File utama (`main.c`) berisi pemanggilan fungsi-fungsi sorting dan proses pengujian data.
- Data angka dan kata dibangkitkan satu kali menggunakan fungsi khusus.
- Analisis dilakukan pada ukuran data: 10.000, 50.000, 100.000, 250.000, 500.000, 1.000.000, 1.500.000, dan 2.000.000.

## Hasil dan Analisis
Eksperimen dilakukan untuk mengukur performa berdasarkan waktu eksekusi dan penggunaan memori. Hasil menunjukkan bahwa algoritma dengan kompleksitas waktu O(n log n) (seperti Merge Sort dan Quick Sort) lebih efisien dibandingkan algoritma O(n²) seperti Bubble Sort dan Selection Sort. Shell Sort berada di tengah-tengah dan memberikan hasil yang cukup baik.

## Kesimpulan
Algoritma terbaik untuk data skala besar adalah Quick Sort dan Merge Sort karena konsisten menunjukkan hasil paling cepat dan efisien dalam penggunaan memori. Bubble Sort adalah yang paling lambat dan boros memori, sehingga kurang direkomendasikan untuk dataset besar.
