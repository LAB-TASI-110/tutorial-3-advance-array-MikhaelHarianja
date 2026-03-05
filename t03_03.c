#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h> // Diperlukan untuk fungsi malloc dan free
#include <limits.h> // Diperlukan untuk INT_MAX dan INT_MIN (untuk inisialisasi min/max)

// Fungsi untuk mendapatkan nilai n dari pengguna
int getN() {
    int n;
    // Asumsi input n valid dan positif berdasarkan contoh
    scanf("%d", &n);
    return n;
}

// Fungsi untuk membaca n bilangan dan menyimpannya ke dalam array
// Mengembalikan jumlah total dari bilangan yang valid
double readAndStoreNumbers(int n, int *arr) {
    double sum = 0.0;
    int num;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        // Asumsi bilangan selalu antara 0 dan 100 berdasarkan instruksi dan contoh
        // Dalam skenario "bebas" dan tidak ada validasi eksplisit, kita percayakan input user
        arr[i] = num; // Simpan bilangan ke array
        sum += num;
    }
    return sum;
}

// Fungsi untuk menghitung rata-rata
double calculateAverage(double sum, int n) {
    if (n == 0) {
        return 0.0; // Hindari pembagian dengan nol
    }
    return sum / n;
}

// FUNGSI INI MENGHITUNG berapa banyak bilangan di atas ATAU SAMA DENGAN rata-rata
int countNumbersAboveOrEqualToAverage(int n, int *arr, double average) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        // Logika perbandingan yang diperbaiki: dari '>' menjadi '>='
        if (arr[i] >= average) {
            count++;
        }
    }
    return count;
}

// Fungsi baru untuk menemukan nilai minimum dari array
int findMinimum(int n, int *arr) {
    if (n <= 0) return INT_MAX; // Mengembalikan nilai max int jika array kosong atau tidak valid
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

// Fungsi baru untuk menemukan nilai maksimum dari array
int findMaximum(int n, int *arr) {
    if (n <= 0) return INT_MIN; // Mengembalikan nilai min int jika array kosong atau tidak valid
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Fungsi untuk menampilkan hasil
void printResults(double sum, double average, int countAboveOrEqualToAverage, int minMaxDiff) {
    printf("%.0f\n", sum);
    printf("%.2f\n", average);
    printf("%d\n", countAboveOrEqualToAverage);
    printf("%d\n", minMaxDiff); // Output baru: selisih min-max
}

// Fungsi utama program
int main() {
    // 1. Dapatkan nilai n
    int n = getN();

    // Alokasikan memori secara dinamis untuk menyimpan n bilangan
    int *numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        // Penanganan error jika alokasi memori gagal
        return 1;
    }

    // 2. Baca n bilangan, simpan ke array, dan hitung jumlahnya
    double totalSum = readAndStoreNumbers(n, numbers);

    // 3. Hitung rata-rata
    double avg = calculateAverage(totalSum, n);

    // 4. Hitung jumlah bilangan di atas ATAU SAMA DENGAN rata-rata
    int aboveOrEqualToAverageCount = countNumbersAboveOrEqualToAverage(n, numbers, avg);

    // 5. Hitung selisih antara nilai tertinggi dan terendah
    int minVal = findMinimum(n, numbers);
    int maxVal = findMaximum(n, numbers);
    int minMaxDifference = maxVal - minVal;

    // 6. Tampilkan hasil
    printResults(totalSum, avg, aboveOrEqualToAverageCount, minMaxDifference);

    // Bebaskan memori yang dialokasikan
    free(numbers);
    numbers = NULL; // Hindari dangling pointer

    return 0; // Menandakan program berakhir dengan sukses
}