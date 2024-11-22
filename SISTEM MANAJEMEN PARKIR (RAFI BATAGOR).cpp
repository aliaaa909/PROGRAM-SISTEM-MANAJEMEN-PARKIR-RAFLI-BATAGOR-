#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const int BARIS = 4;  // Jumlah baris slot parkir
const int KOLOM = 5;  // Jumlah kolom slot parkir
const int TOTAL_SLOT = BARIS * KOLOM;  // Total slot parkir

 struct Kendaraan {
    string jenis = "kosong"; // Jenis kendaraan, default "kosong" berarti slot kosong
    string platNomor;
    int jamMasuk = -1,menitMasuk, jamKeluar, menitKeluar;// Jam masuk, -1 menandakan slot kosong
    char t;
    bool tes;

};

//===============================================================================================
//===============================================================================================

// Fungsi untuk mengisi slot parkir
void masukParkir(Kendaraan slot[BARIS][KOLOM]) {
    int pilihanSlot;
    string jenis, platNomor;
    int jamMasuk,menitMasuk;
    char t;

    cout <<" =================================================================" << endl;
    cout <<" |                          MASUK PARKIR                          " << endl;
    cout <<" =================================================================" << endl;
    cout <<" | Masukkan nomor slot yang ingin diisi (1-20):    " << endl;
    cout << " | " ; cin >> pilihanSlot;
    cout <<" =================================================================" << endl;

    if (pilihanSlot < 1 || pilihanSlot > TOTAL_SLOT) {
        cout << endl;
        cout <<" | Nomor slot tidak valid!" << endl;
        do
        {
        cout << " | Kembali ke menu utama?(y/n) : "; cin >>t;
            cin.ignore();
             if(t == 'y' || t == 'Y')
            {
                system("cls");
                return;
            }
            else if (t == 'n' || t == 'N')
            {
                cout << endl;
                system ("cls");
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            }
            else
            {
                cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
         }
        while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
            system("cls");
    }

    int indexBaris = (pilihanSlot - 1) / KOLOM;
    int indexKolom = (pilihanSlot - 1) % KOLOM;


    if (slot[indexBaris][indexKolom].jenis != "kosong") {
        cout << " | Slot sudah terisi!" << endl;
        do
        {
        cout<< " | Kembali ke menu utama?(y/n) : "; cin >>t;
            cin.ignore();
             if(t == 'y' || t == 'Y')
            {
                system("cls");
                return;
            }
            else if (t == 'n' || t == 'N')
            {
                cout << endl;
                system ("cls");
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            }
            else
            {
                cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
         }
        while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
            system("cls");
    }

    do {
    cout << " | Masukkan jenis kendaraan yang akan parkir (motor/mobil) : ";
    cin >> jenis;
        if (jenis != "motor" && jenis != "mobil") {
            cout << " | jenis kendaraan tidak valid!";
            cout << endl;
        }
    } while (jenis != "motor" && jenis != "mobil");

    cout << " | Masukkan plat nomor kendaraan : ";
    cin >> platNomor;
    cout << " | Masukkan jam masuk kendaraan (0-23) : ";
    cin >> jamMasuk;
    cout << " | Masukkan menit masuk kendaraan (0-59) : ";
    cin >> menitMasuk;

    slot[indexBaris][indexKolom] = {jenis, platNomor, jamMasuk, menitMasuk};

    cout <<"  =================================================================" << endl;
    cout << "\n" <<" | Kendaraan berhasil parkir di slot " << pilihanSlot << "." << endl;
    do
        {
        cout<< " | Kembali ke menu utama?(y/n) : "; cin >>t;
            cin.ignore();
             if(t == 'y' || t == 'Y')
            {
                system("cls");
                return;
            }
            else if (t == 'n' || t == 'N')
            {
                cout << endl;
                system ("cls");
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            }
            else
            {
                cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
        }
        while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
            system("cls");



}

//===============================================================================================
//===============================================================================================


// Fungsi untuk menampilkan seluruh slot parkir dan memeriksa slot tertentu
void tampilkanDanCekSlot(Kendaraan slot[BARIS][KOLOM]) {
    char t;
    bool tes;

    cout <<" ==================================================" << endl;
    cout <<" |              Slot Parkir Saat Ini:              |" << endl;
    cout <<" ==================================================" << endl;
    cout<<endl;
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            if (slot[i][j].jenis == "kosong") {
                cout << setw(10) << "[kosong] ";
            } else {
                cout << setw(10) << "[terisi] ";
            }
        }
        cout << endl;
    }

    int pilihanSlot;
    cout <<" ==================================================" << endl;
    cout << "\n Masukkan Slot Parkir Yang Ingin Dicek (1-20) : ";
    cin >> pilihanSlot;

    if (pilihanSlot == 0) {
        return; // Kembali ke menu utama
    }

    if (pilihanSlot < 1 || pilihanSlot > TOTAL_SLOT) {
        cout << " Nomor slot tidak valid!" << endl;
        cout << " ================================================== " << endl;
        do
        {
        cout<< " | Kembali ke menu utama?(y/n) : "; cin >>t;
            cin.ignore();
             if(t == 'y' || t == 'Y')
            {
                system("cls");
                return;
            }
            else if (t == 'n' || t == 'N')
            {
                cout << endl;
                system ("cls");
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            }
            else
            {
                cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
        }
        while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
            system("cls");
    }

    int indexBaris = (pilihanSlot - 1) / KOLOM;
    int indexKolom = (pilihanSlot - 1) % KOLOM;

    if (slot[indexBaris][indexKolom].jenis == "kosong") {
        cout << " Slot " << pilihanSlot << " kosong." << endl;
        cout << " ==================================================" << endl;
        do
        {
        cout<< " | Kembali ke menu utama?(y/n) : "; cin >>t;
            cin.ignore();
             if(t == 'y' || t == 'Y')
            {
                system("cls");
                return;
            }
            else if (t == 'n' || t == 'N')
            {
                cout << endl;
                system ("cls");
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            }
            else
            {
                cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
        }
        while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
            system("cls");
    } else {

        cout <<" ==================================================" << endl;
        cout << "Slot " << pilihanSlot << ":\n";
        cout << "Jenis Kendaraan : " << slot[indexBaris][indexKolom].jenis << endl;
        cout << "Plat Nomor : " << slot[indexBaris][indexKolom].platNomor << endl;
        cout << "Pukul Masuk : " << slot[indexBaris][indexKolom].jamMasuk << ":" << slot[indexBaris][indexKolom].menitMasuk << " WIB" << endl;
        cout << endl;
        do
        {
        cout<< " | Kembali ke menu utama?(y/n) : "; cin >>t;
            cin.ignore();
             if(t == 'y' || t == 'Y')
            {
                system("cls");
                return;
            }
            else if (t == 'n' || t == 'N')
            {
                cout << endl;
                system ("cls");
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            }
            else
            {
                cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
        }
        while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
            system("cls");
    }
}


//===============================================================================================
//===============================================================================================


// Fungsi untuk mengosongkan slot parkir dan menghitung tarif parkir
void keluarParkir(Kendaraan slot[BARIS][KOLOM]) {
    int pilihanSlot;
    int jamKeluar;
    int menitKeluar;
    char t;
    bool tes;

    cout << " ================================================================= " << endl;
    cout << " |                        Keluar Parkir                           | " << endl;
    cout << " =================================================================" << endl;
    cout << " | Masukkan nomor slot yang ingin dikosongkan (1-20): ";
    cin >> pilihanSlot;

    if (pilihanSlot < 1 || pilihanSlot > TOTAL_SLOT) {
        cout << " | Nomor slot tidak valid!" << endl;
        do
        {
        cout<< " | Kembali ke menu utama?(y/n) : "; cin >>t;
            cin.ignore();
             if(t == 'y' || t == 'Y')
            {
                system("cls");
                return;
            }
            else if (t == 'n' || t == 'N')
            {
                cout << endl;
                system ("cls");
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            }
            else
            {
                cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
        }
        while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
            system("cls");
    }

    int indexBaris = (pilihanSlot - 1) / KOLOM;
    int indexKolom = (pilihanSlot - 1) % KOLOM;

    if (slot[indexBaris][indexKolom].jenis == "kosong") {
        cout << " | Slot sudah kosong!" << endl;
        do
        {
        cout<< " | Kembali ke menu utama?(y/n) : "; cin >>t;
            cin.ignore();
             if(t == 'y' || t == 'Y')
            {
                system("cls");
                return;
            }
            else if (t == 'n' || t == 'N')
            {
                cout << endl;
                system ("cls");
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            }
            else
            {
                cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
        }
        while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
            system("cls");
    }

    cout << " | Masukkan jam keluar kendaraan (0-23) : ";
    cin >> jamKeluar;
    cout << " | Masukkan menit keluar kendaraan (0-59) : ";
    cin >> menitKeluar;

    int jamMasuk = slot[indexBaris][indexKolom].jamMasuk;
    int durasi = jamKeluar - jamMasuk;

    if (durasi < 0) {
        durasi += 24; // Untuk menangani kasus jam masuk lebih besar dari jam keluar (misalnya: parkir semalam)
    }

    int tarifPerJam = (slot[indexBaris][indexKolom].jenis == "motor") ? 2000 : 5000;
    int tarifTotal = tarifPerJam * durasi;


    cout << "\n================================"<< endl;
    cout << "         Struk Parkir             "<< endl;
    cout << "================================\n"<< endl;
    cout << "Jenis Kendaraan  : " << slot[indexBaris][indexKolom].jenis<<endl;
    cout << "Plat Nomor       : " << slot[indexBaris][indexKolom].platNomor<<endl;
    cout << "Keluar Dari Slot : " << pilihanSlot << "." << endl;
    cout << "Jam Masuk        : " << slot[indexBaris][indexKolom].jamMasuk << ":" << slot[indexBaris][indexKolom].menitMasuk << " WIB" << endl;
    cout << "Jam Keluar       : " << jamKeluar << ":" << menitKeluar << " WIB" << endl;
    cout << "Tarif parkir: Rp : " << tarifTotal << endl;
    cout << "\n===============================" << endl;
    cout << "           Terimakasih           " <<endl;
    cout << "        Hati-hati di jalan       "<< endl;
    cout << "=================================" << endl;
    cout << endl;
  slot[indexBaris][indexKolom] = {"kosong", "", -1};  // Kosongkan slot
    do
        {
        cout<< " | Kembali ke menu utama?(y/n) : "; cin >>t;
            cin.ignore();
             if(t == 'y' || t == 'Y')
            {
                system("cls");
                return;
            }
            else if (t == 'n' || t == 'N')
            {
                cout << endl;
                system ("cls");
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            }
            else
            {
                cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
        }
        while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
            system("cls");

   
}

//===========================================================================================
//===========================================================================================

//===========================================================================================
void cariKendaraan(Kendaraan slot[BARIS][KOLOM]){
    string platNomor;

    cout << " ===========================================================" << endl;
    cout << " |                 MENCARI KENDARAAN BY PLAT                | " << endl;
    cout << " ===========================================================" << endl;
    cout << " | Masukkan plat nomor :" << endl;
    cout << " | " ; cin >> platNomor;

    char t;
    bool tes;
    bool ditemukan = false;

    for (int i = 0; i < BARIS; i++){
        for (int j = 0; j < KOLOM; j++) {

            if (slot[i][j].platNomor == platNomor && slot[i][j].jenis != "kosong") {
                cout << " | Kendaraan ditemukan di slot : " << (i * KOLOM + j + 1) << endl;
                cout << " | Jenis kendaraan             : " << slot[i][j].jenis << endl;
                cout << " | Plat nomor                  : " << slot[i][j].platNomor << endl;
                cout << " | Jam masuk                   : " << slot[i][j].jamMasuk << ":" << slot[i][j].menitMasuk << "WIB" << endl;
                ditemukan = true;
                break;
            }
        }
        if (ditemukan) break;
    }
    if (!ditemukan) {
        cout << " | Kendaraan dengan plat nomor : " << platNomor << " tidak ditemukan di area parkir ! " << endl;
    }
      do
        {
        cout<< " | Kembali ke menu utama?(y/n) : "; cin >>t;
            cin.ignore();
             if(t == 'y' || t == 'Y')
            {
                system("cls");
                return;
            }
            else if (t == 'n' || t == 'N')
            {
                cout << endl;
                system ("cls");
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            }
            else
            {
                cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
        }
        while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
            system("cls");
}
//=====================================================================================
//=====================================================================================

//fungsi catat transaksi

void catatTransaksi(Kendaraan slot[BARIS][KOLOM]) {
    bool adaTransaksi = false;
    char t;
    bool tes;

    cout << "===================================" << endl;
    cout << "\n    Catatan Transaksi Parkir     " << endl;
    cout << "===================================" << endl;
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            if (slot[i][j].jenis != "kosong" && slot[i][j].jamMasuk != -1) {
                adaTransaksi = true;
                cout << "Slot: " << (i * KOLOM + j + 1) << endl;
                cout << "Jenis Kendaraan: " << slot[i][j].jenis << endl;
                cout << "Plat Nomor: " << slot[i][j].platNomor << endl;
                cout << "Waktu Masuk: " << slot[i][j].jamMasuk << ":" << slot[i][j].menitMasuk << " WIB" << endl;
                if (slot[i][j].jamKeluar != -1) {  // Cek apakah kendaraan sudah keluar
                    cout << "Waktu Keluar: " << slot[i][j].jamKeluar << ":" << slot[i][j].menitKeluar << " WIB" << endl;
                    int durasi = (slot[i][j].jamKeluar - slot[i][j].jamMasuk + 24) % 24;
                    cout << "Durasi Parkir: " << durasi << " jam" << endl;
                }
                cout << "--------------------------------" << endl;

            }

        }


    }
    if (!adaTransaksi) {
        cout << "Tidak ada transaksi yang tercatat." << endl;
    }
         do
        {
        cout<< " | Kembali ke menu utama?(y/n) : "; cin >>t;
            cin.ignore();
             if(t == 'y' || t == 'Y')
            {
                system ("cls");
            }
            else if (t == 'n' || t == 'N')
            {
                cout << endl;
                system ("cls");
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            }
            else
            {
                cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
            }
        }
        while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
            system("cls");
            return ;
}





//=================================================================================================================
//=================================================================================================================
//fungsi laporan harian
void laporanHarian(Kendaraan slot[BARIS][KOLOM]) {

     cout<<  "===================================" << endl;
     cout << "|\n        Laporan Harian          |" << endl;
     cout << "===================================" << endl;

    char t;
    bool tes;
    int totalPendapatan = 0;
    for (int i = 0; i < BARIS; i++) {
        for (int j = 0; j < KOLOM; j++) {
            if (slot[i][j].jenis != "kosong") {
                int durasi = (slot[i][j].jamKeluar - slot[i][j].jamMasuk + 24) % 24;
                int tarifPerJam = (slot[i][j].jenis == "motor") ? 2000 : 5000;
                totalPendapatan += tarifPerJam * durasi;
            }
        }
    }
cout << " | total pendapatan : Rp. " << totalPendapatan << endl;
cout << endl;

char pilihan;
do {
cout << " | ingin melihat detail transaksi hari ini? (y/n) "; cin >> pilihan;
if (pilihan == 'y' || pilihan == 'Y'){
        catatTransaksi(slot);
        return;
    } else if (pilihan == 'n' || pilihan == 'N'){
        system("cls");
        return ;
    } else
    {
        cout << " | Pilihan tidak valid. Masukkan 'y' untuk ya atau 'n' untuk tidak.\n";
    }
    } while (t != 'y' && t != 'Y' && t != 'n' && t != 'N');
return;
    system("cls");
}




////=================================================================================================================
////=================================================================================================================

int main() {
    Kendaraan slot[BARIS][KOLOM];

    int pilihan;
    char t;
    bool tes;

    while (true) {
        cout << "|================================================|" << endl;
        cout << "|     SISTEM PARKIR KEDAI BATAGOR RAFLI 1B       |" << endl;
        cout << "|================================================|" << endl;
        cout << "|                 Selamat Datang!                |" << endl;
        cout << "| Menu utama :                                   |" << endl;
        cout << "|                                                |" << endl;
        cout << "|  1. Masuk parkir                               |" << endl;
        cout << "|  2. Lihat data parkir                          |" << endl;
        cout << "|  3. Keluar parkir                              |" << endl;
        cout << "|  4. Cari kendaraan                             |" << endl;
        cout << "|  5. Laporan Harian                             |" << endl;
        cout << "|  6. Catatan Transaksi                          |" << endl;
        cout << "|  7. keluar dari sistem                         |" << endl;
        cout << "|                                                |" << endl;
        cout << "| Masukkan pilihan opsi anda (1-7) :             |" << endl;
        cout << "|                                                |" << endl;
        cout << "|================================================|" << endl;
        cin >> pilihan;
        system("cls");

        switch (pilihan) {
            case 1:
                masukParkir(slot);
                break;
            case 2:
                tampilkanDanCekSlot(slot);
                break;
            case 3:
                keluarParkir(slot);
                break;
            case 4:
                cariKendaraan(slot);
                break;
            case 5:
               laporanHarian(slot);
                break;
            case 6:
                catatTransaksi(slot);
                break;
            case 7:
                cout << endl;
                cout << "  Keluar dari sistem..." << endl;
                exit(0);
            default:
                cout << endl;
                cout << " | Pilihan tidak valid! " << endl;
                cout << " | Silahkan masukan angka yang tersedia: " << endl;
                cout << endl;
                break;

        }

    }
}

//========================================================================================
