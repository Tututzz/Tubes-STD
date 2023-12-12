#include "header.h"

int main() {
    listH listHotel;
    createListH(listHotel);

    listP listPerson;
    createListP(listPerson);

    listR listReview;
    createListR(listReview);

    int choice;
    do {
        choice = mainMenu();

        switch (choice) {
            case 1: {
                // Tambah Hotel
                hotel hotelInfo;
                cout << "Masukkan Nama Hotel: ";
                cin >> hotelInfo.nama;
                cout << "Masukkan Kota Hotel: ";
                cin >> hotelInfo.kota;
                cout << "Masukkan Alamat Hotel: ";
                cin >> hotelInfo.alamat;
                cout << "Masukkan Harga Hotel: ";
                cin >> hotelInfo.harga;
                cout << "Masukkan Bintang Hotel: ";
                cin >> hotelInfo.bintang;

                adrh hotelNode = createElmH(hotelInfo);
                insertLastH(listHotel, hotelNode);
                break;
            }
            case 2: {
                // Tambah Person
                user personInfo;
                cout << "Masukkan Nama Person: ";
                cin >> personInfo.nama;
                cout << "Masukkan No Telp Person: ";
                cin >> personInfo.noTelp;
                cout << "Masukkan Email Person: ";
                cin >> personInfo.email;
                cout << "Masukkan Umur Person: ";
                cin >> personInfo.umur;

                adrp personNode = createElmP(personInfo);
                insertLastP(listPerson, personNode);
                break;
            }
            case 3: {
                // Tambah Review
                string hotelName, personName, reviewText;
                cout << "Masukkan Nama Hotel: ";
                cin >> hotelName;
                cout << "Masukkan Nama Person: ";
                cin >> personName;
                cout << "Masukkan Review: ";
                cin.ignore(); // Menggunakan ignore untuk mengabaikan karakter '\n' pada buffer
                getline(cin, reviewText);

                adrh foundHotel = searchHotelByName(listHotel, hotelName);
                adrp foundPerson = searchPersonByName(listPerson, personName);
                if (foundHotel != NULL && foundPerson != NULL) {
                    adr reviewNode = createElmR(foundHotel, foundPerson);
                    reviewNode->review = reviewText;
                    insertLastR(listReview, reviewNode);
                    cout << "Review berhasil ditambahkan!" << endl;
                } else {
                    cout << "Hotel atau person tidak ditemukan. Review tidak dapat ditambahkan." << endl;
                }
                break;
            }
            case 4: {
                // Tampilkan Semua Hotel
                printAllHotels(listHotel);
                break;
            }
            case 5: {
                // Tampilkan Semua Person
                printAllPersons(listPerson);
                break;
            }
            case 6: {
                // Tampilkan Semua Review
                printAllReviews(listReview);
                break;
            }
            case 7:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }

    } while (choice != 7);

    return 0;
}
