#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h> // Diperlukan untuk fungsi malloc dan free

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

// Fungsi baru untuk menghitung berapa banyak bilangan di atas rata-rata
int countNumbersAboveAverage(int n, int *arr, double average) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > average) {
            count++;
        }
    }
    return count;
}

// Fungsi untuk menampilkan hasil
void printResults(double sum, double average, int countAboveAverage) {
    printf("%.0f\n", sum);
    printf("%.2f\n", average);
    printf("%d\n", countAboveAverage); // Output baru
}

// Fungsi utama program
int main() {
    // 1. Dapatkan nilai n
    int n = getN();

    // Alokasikan memori secara dinamis untuk menyimpan n bilangan
    // Ini penting karena kita perlu mengakses bilangan dua kali (untuk sum/avg dan untuk count above avg)
    int *numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        // Penanganan error jika alokasi memori gagal
        return 1;
    }

    // 2. Baca n bilangan, simpan ke array, dan hitung jumlahnya
    double totalSum = readAndStoreNumbers(n, numbers);

    // 3. Hitung rata-rata
    double avg = calculateAverage(totalSum, n);

    // 4. Hitung jumlah bilangan di atas rata-rata
    int aboveAverageCount = countNumbersAboveAverage(n, numbers, avg);

    // 5. Tampilkan hasil
    printResults(totalSum, avg, aboveAverageCount);

    // Bebaskan memori yang dialokasikan
    free(numbers);
    numbers = NULL; // Hindari dangling pointer

    return 0; // Menandakan program berakhir dengan sukses
}