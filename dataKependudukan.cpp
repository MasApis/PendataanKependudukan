#include <iostream>
using namespace std;

struct penduduk{
    string nik;
    string namaLengkap;
    string tanggalLahir;
    string jenisKelamin;
    string pekerjaan;
    string status;
    string alamat;
};

const int MAX_SIZE = 100;
penduduk dataPenduduk[MAX_SIZE];
int jumlahDataPenduduk = 0;

void tambahPenduduk() {

    int batas;

    cout << "berapa jumlah data yang ingin anda masukkan ? (MAX 100) : ";
    cin >> batas;
    while (batas < 1 || batas > 100) {
        cout << "Jumlah data harus antara 1 dan 100. Silakan masukkan lagi: ";
        cin >> batas;
    }
    cin.ignore();
    for(int i = 0; i < batas; i++) {
        cout << "Data penduduk ke " << i + 1 << endl;
        cout << "Masukkan nik            : ";
        getline(cin, dataPenduduk[i].nik);
        cout << "Masukkan nama lengkap   : ";
        getline(cin, dataPenduduk[i].namaLengkap);
        cout << "Masukkan tanggal lahir  : ";
        getline(cin, dataPenduduk[i].tanggalLahir);
        cout << "Masukkan jenis kelamin  : ";
        getline(cin, dataPenduduk[i].jenisKelamin);
        cout << "Masukkan pekerjaan      : ";
        getline(cin, dataPenduduk[i].pekerjaan);
        cout << "Masukkan status         : ";
        getline(cin, dataPenduduk[i].status);
        cout << "Masukkan alamat         : ";
        getline(cin, dataPenduduk[i].alamat);

        jumlahDataPenduduk++;

        cout << endl;
    }
}

void menampilkanDataPenduduk() {

    if(jumlahDataPenduduk == 0) {
        cout << "DATA KEPENDUDUKAN KOSONG!!!!!!1" << endl;
        return;
    }

    cout << "DATA PENDUDUK" << endl;
    cout << "NIK" << "\t" << "NAMA LENGKAP" << "\t" << "TANGGAL LAHIR" << "\t" << "JENIS KELAMIN" << "\t" << "\t" << "PEKERJAAN" << "\t" << "STATUS" << "\t" << "ALAMAT" << endl;
    for(int i = 0; i < jumlahDataPenduduk; i++) {
        cout << dataPenduduk[i].nik << "\t" << dataPenduduk[i].namaLengkap << "\t" << dataPenduduk[i].tanggalLahir << dataPenduduk[i].jenisKelamin << "\t" << "\t" << dataPenduduk[i].pekerjaan << "\t" << dataPenduduk[i].status << "\t" << dataPenduduk[i].alamat << "\t" << endl;  
    }
    cout << "JUMLAH DATA PENDUDUK ADALAH : " << jumlahDataPenduduk << endl;

}

void mencariDataPenduduk() {

    string nikPenduduk;

    cout << "masukkan nik penduduk yang ingin dicari : ";
    cin >> nikPenduduk;
    bool ditemukan = false;

    cout << "NIK" << "\t" << "NAMA LENGKAP" << "\t" << "TANGGAL LAHIR" << "\t" << "JENIS KELAMIN" << "\t" << "\t" << "PEKERJAAN" << "\t" << "STATUS" << "\t" << "ALAMAT" << endl;
    for(int i = 0; i < jumlahDataPenduduk; i++) {
        if(nikPenduduk == dataPenduduk[i].nik) {
            ditemukan = true;
            cout << dataPenduduk[i].nik << "\t" << dataPenduduk[i].namaLengkap << "\t" << dataPenduduk[i].tanggalLahir << dataPenduduk[i].jenisKelamin << "\t" << "\t" << dataPenduduk[i].pekerjaan << "\t" << dataPenduduk[i].status << "\t" << dataPenduduk[i].alamat << "\t" << endl;   
        }
    }

    if(!ditemukan) {
        cout << "maaf data anda tidak ditemukan/data masih kosong" << endl;
    }

}

void ubahData() {

    string nikPenduduk;
    short pilihanUbah;
    bool ditemukan = false;

    cout << "masukkan nik penduduk yang ingin diubah : ";
    cin >> nikPenduduk;

    for(int i = 0; i < jumlahDataPenduduk; i++) {
        if(nikPenduduk == dataPenduduk[i].nik) {
            ditemukan = true;
            cout << "pilih data yang ingin diubah : " << endl;;
            cout << "1. Nama" << endl;
            cout << "2. tanggal lahir" << endl;
            cout << "3. jenis kelamin" << endl;
            cout << "4. pekerjaan" << endl;
            cout << "5. status" << endl;
            cout << "6. alamat" << endl;
            cout << "======================" << endl;
            cout << "pilihan : ";
            cin >> pilihanUbah;
            cout << "======================" << endl;

            cin.ignore();
            if(pilihanUbah == 1) {
                cout << "ubah nama anda : ";
                getline(cin, dataPenduduk[i].namaLengkap);
                cout << "selamat nama anda sudah diubah" << endl;
            } else if(pilihanUbah == 2) {
                cout << "ubah tanggal lahir anda : ";
                getline(cin, dataPenduduk[i].tanggalLahir);
                cout << "selamat tanggal lahir anda sudah diubah" << endl;
            } else if(pilihanUbah == 3) {
                cout << "ubah jenis kelamin : ";
                getline(cin, dataPenduduk[i].jenisKelamin);
                cout << "selamat jenis kelamin anda sudah diubah" << endl;
            } else if(pilihanUbah == 4) {
                cout << "ubah pekerjaan anda : ";
                getline(cin, dataPenduduk[i].pekerjaan);
                cout << "selamat pekerjaan anda sudah diubah" << endl;
            } else if(pilihanUbah == 5) {
                cout << "ubah status anda : ";
                getline(cin, dataPenduduk[i].status);
                cout << "selamat status anda sudah diubah" << endl;
            } else if(pilihanUbah == 6) {
                cout << "ubah alamat anda : ";
                getline(cin, dataPenduduk[i].alamat);
                cout << "selamat alamat anda sudah diubah" << endl;
            } else {
                cout << "maaf menu yang ada pilih tidak ada" << endl;
            }
        }
    }

    if(!ditemukan) {
        cout << "Maaf nik yang anda masukkan tidak ditemukan/data masih kosong" << endl;
    }


}

void menghapusData() {

    string nikPenduduk;
    char konfirmasi;
    bool ditemukan = false;

    cout << "masukkan nik penduduk yang ingin dihapus : ";
    cin >> nikPenduduk;

    for(int i = 0; i < jumlahDataPenduduk; i++) {
        if(nikPenduduk == dataPenduduk[i].nik) {
            ditemukan = true;
            cout << "data ditemukan" << endl;
            cout << "NIK           : " << dataPenduduk[i].nik << endl;
            cout << "NAMA LENGKAP  : " << dataPenduduk[i].namaLengkap << endl;
            cout << "TANGGAL LAHIR : " << dataPenduduk[i].tanggalLahir << endl;
            cout << "JENIS KELAMIN : " << dataPenduduk[i].jenisKelamin << endl;
            cout << "PEKERJAAN     : " << dataPenduduk[i].pekerjaan << endl;
            cout << "STATUS        : " << dataPenduduk[i].status << endl;
            cout << "ALAMAT        : " << dataPenduduk[i].status << endl;

            cout << endl;

            cout << "apakah and yakin ingin menghapus data ini ? (y/n) : ";
            cin >> konfirmasi;
            if('y' == konfirmasi || konfirmasi == 'Y') {
                for(int j = i; j < jumlahDataPenduduk - 1; j++) {
                    dataPenduduk[j] = dataPenduduk[j + 1];
                }

                cout << "selamat data anda sudah di hapus" << endl;
            } else {
                cout << "penghapusan dibatalkan" << endl;
            }

            jumlahDataPenduduk--;
            break;

        }
    } 

    if(!ditemukan) {
        cout << "Maaf nik yang anda masukkan tidak ditemukan" << endl;
    }

}


int main() {
    
    short pilihan;
    char ulang;
    
    do
    {
        cout << "================================================================" << endl;
        cout << "SELAMAT DATANG DI SISTEM PENDATAAN KEPENDUDUKAN KABUPATEN BINTAN" << endl;
        cout << "================================================================" << endl;
        cout << "1. Tambah penduduk" << endl;
        cout << "2. Lihat semua data penduduk" << endl;
        cout << "3. Cari penduduk" << endl;
        cout << "4. Ubah data penduduk" << endl;
        cout << "5. Hapus data penduduk" << endl;
        cout << "6. Keluar" << endl;
        cout << "================================================================" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        cout << "================================================================" << endl;

        switch (pilihan)
        {
        case 1:
            tambahPenduduk();
            break;
        case 2:
            menampilkanDataPenduduk();
            break;
        case 3:
            mencariDataPenduduk();
            break;
        case 4:
            ubahData();
            cout << endl;
            break;
        case 5:
            menghapusData();
            cout << endl;
            break;
        default:
            cout << "TERIMAKASIH" << endl;
            break;
        }

        cout << "Apakah anda ingin kembali ke menu utama ? (y/n) : ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');
    
}
