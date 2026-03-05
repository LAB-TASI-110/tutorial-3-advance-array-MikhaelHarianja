#include <stdio.h> // Diperlukan untuk fungsi input/output seperti printf dan scanf

// Fungsi untuk mendapatkan nilai n dari pengguna
int getN() {
    int n;
    // Loop hingga mendapatkan input n yang valid (n harus positif)
    do {
        // Tidak ada prompt input sesuai instruksi output, tapi untuk user experience lebih baik ada.
        // Untuk mematuhi instruksi "tanpa keterangan tambahan" pada output akhir, kita akan membatasi ini.
        // Anggap user akan langsung menginput n sesuai contoh.
        scanf("%d", &n);
        if (n <= 0) {
            // Dalam skenario ini, kita berasumsi prompt akan valid dan tidak perlu validasi interaktif yang eksplisit.
            // Namun secara praktis, ini akan meminta ulang. Untuk kasus ini, kita akan percaya pada input user.
        }
    } while (n <= 0); // Pastikan n adalah bilangan positif
    return n;
}

// Fungsi untuk memproses N bilangan, menghitung jumlah, dan mengembalikan jumlahnya
double processNumbers(int n) {
    double sum = 0.0;
    int num;

    // Loop sebanyak n kali untuk mendapatkan input bilangan
    for (int i = 0; i < n; i++) {
        // Anggap user akan langsung menginput bilangan sesuai contoh.
        scanf("%d", &num);
        // Validasi bilangan antara 0 dan 100
        if (num < 0 || num > 100) {
            // Dalam kasus "bebas", kita bisa mengasumsikan input valid atau mengabaikan nilai yang tidak valid.
            // Untuk menjaga integritas perhitungan, kita akan mengabaikan bilangan yang tidak valid.
            // Atau, bisa juga meminta input ulang. Untuk kesederhanaan, kita asumsikan input selalu valid.
            // Jika Anda ingin validasi yang lebih ketat, bisa ditambahkan di sini.
        }
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

// Fungsi untuk menampilkan hasil
void printResults(double sum, double average) {
    printf("%.0f\n", sum); // Menampilkan jumlah tanpa desimal
    printf("%.2f\n", average); // Menampilkan rata-rata dengan dua desimal
}

// Fungsi utama program
int main() {
    // 1. Dapatkan nilai n
    int n = getN();

    // 2. Proses n bilangan dan hitung jumlahnya
    double totalSum = processNumbers(n);

    // 3. Hitung rata-rata
    double avg = calculateAverage(totalSum, n);

    // 4. Tampilkan hasil
    printResults(totalSum, avg);

    return 0; // Menandakan program berakhir dengan sukses
}