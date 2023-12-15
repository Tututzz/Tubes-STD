#include "header.h"

int main() {
    listH listHotel;
    createListH(listHotel);

    listP listPerson;
    createListP(listPerson);

    listR listReview;
    createListR(listReview);

    // Input data hotel
    hotel hotel1 = {"Hotel A", "Kota A", "Alamat A", 100.0, 3};
    hotel hotel2 = {"Hotel B", "Kota B", "Alamat B", 150.0, 4};
    hotel hotel3 = {"Hotel C", "Kota C", "Alamat C", 200.0, 5};

    adrh hotelNode1 = createElmH(hotel1);
    adrh hotelNode2 = createElmH(hotel2);
    adrh hotelNode3 = createElmH(hotel3);

    insertLastH(listHotel, hotelNode1);
    insertLastH(listHotel, hotelNode2);
    insertLastH(listHotel, hotelNode3);

    // Input data person
    user person1 = {"Person X", "08123456789", "personX@email.com", 25};
    user person2 = {"Person Y", "08234567890", "personY@email.com", 30};
    user person3 = {"Person Z", "08345678901", "personZ@email.com", 22};

    adrp personNode1 = createElmP(person1);
    adrp personNode2 = createElmP(person2);
    adrp personNode3 = createElmP(person3);

    insertLastP(listPerson, personNode1);
    insertLastP(listPerson, personNode2);
    insertLastP(listPerson, personNode3);

    // Input data review
    adr reviewNode1 = createElmR(hotelNode1, personNode1);
    reviewNode1->review = "Hotel bagus!";
    insertLastR(listReview, reviewNode1);

    adr reviewNode2 = createElmR(hotelNode1, personNode2);
    reviewNode2->review = "Sarapan enak!";
    insertLastR(listReview, reviewNode2);

    adr reviewNode3 = createElmR(hotelNode2, personNode3);
    reviewNode3->review = "Pelayanan ramah!";
    insertLastR(listReview, reviewNode3);

    int choice;
    do {
        choice = mainMenu();

        switch (choice) {
            ;
            case 1: {
                system("CLS");
                // Tambah Hotel
                hotel hotelInfo;
                cout << "Masukkan Nama Hotel: ";
                cin.ignore();
                getline(cin, hotelInfo.nama);
                cout << "Masukkan Kota Hotel: ";
                cin >> hotelInfo.kota;
                cout << "Masukkan Alamat Hotel: ";
                cin.ignore();
                getline(cin, hotelInfo.alamat);
                cout << "Masukkan Harga Hotel: ";
                cin >> hotelInfo.harga;
                cout << "Masukkan Bintang Hotel: ";
                cin >> hotelInfo.bintang;

                adrh hotelNode = createElmH(hotelInfo);
                insertFirstH(listHotel, hotelNode);
                break;
            }
            case 2: {
                system("CLS");
                // Tampilkan Semua Hotel
                printAllHotels(listHotel);
                break;
            }
            case 3 : {
                system("CLS");
                printAllPersons(listPerson);
                break;
            }
            case 4 : {
                system("CLS");
                printAllReviews(listReview);
                break;
            }
            case 5: {
                system("CLS");
                string hotelName;
                cout << "Masukkan Nama Hotel: ";
                cin.ignore();
                getline(cin,hotelName);
                adrh foundHotel = searchHotelByName(listHotel, hotelName);
                if (foundHotel == NULL){
                    cout << "Hotel tidak ditemukan" << endl;
                }else {
                    deleteHotel(listHotel,listReview,foundHotel);
                    cout << "Hotel berhasil dihapus" << endl;
                }
                break;
            }
            case 6: {
                system("CLS");
                string hotelName;
                cout << "Masukkan Nama Hotel: ";
                cin.ignore();
                getline(cin, hotelName);
                adrh foundHotel = searchHotelByName(listHotel, hotelName);
                if (foundHotel == NULL){
                    cout << "Hotel tidak ditemukan" << endl;
                }else {
                    cout << "Nama Hotel: " << foundHotel->info.nama << endl;
                    cout << "Kota: " << foundHotel->info.kota << endl;
                    cout << "Alamat: " << foundHotel->info.alamat << endl;
                    cout << "Harga: " << foundHotel->info.harga << endl;
                    cout << "Bintang: " << foundHotel->info.bintang << endl;
                }
                break;
            }
            case 7: {
                system("CLS");
                string personName;
                cout << "Masukkan nama pengguna: ";
                cin.ignore();
                getline(cin, personName);
                adrp foundPengguna = searchPersonByName(listPerson, personName);
                if (foundPengguna == NULL){
                    cout << "Pengguna tidak ditemukan" << endl;
                }else {
                    cout << "Nama: " << foundPengguna->info.nama << endl;
                    cout << "No Telp: " << foundPengguna->info.noTelp << endl;
                    cout << "Email: " << foundPengguna->info.email << endl;
                    cout << "Umur: " << foundPengguna->info.umur << endl;
                }
                break;
            }
            case 8: {
                system("CLS");
                // Tambah Person
                user personInfo;
                cout << "Masukkan Nama Person: ";
                cin.ignore();
                getline(cin, personInfo.nama);
                cout << "Masukkan No Telp Person: ";
                cin >> personInfo.noTelp;
                cout << "Masukkan Email Person: ";
                cin >> personInfo.email;
                cout << "Masukkan Umur Person: ";
                cin >> personInfo.umur;

                adrp personNode = createElmP(personInfo);
                insertFirstP(listPerson, personNode);
                break;
            }
            case 9: {
                system("CLS");
                // Tambah Review
                string hotelName, personName, reviewText;

                cout << "Masukkan Nama Hotel: ";
                cin.ignore();
                getline(cin, hotelName);

                cout << "Masukkan Nama Person: ";
                getline(cin, personName);

                adrh foundHotel = searchHotelByName(listHotel, hotelName);
                adrp foundPerson = searchPersonByName(listPerson, personName);

                if (foundHotel != NULL && foundPerson != NULL) {
                    cout << "Masukkan Review: ";
                    getline(cin, reviewText);
                    adr reviewNode = createElmR(foundHotel, foundPerson);
                    reviewNode->review = reviewText;
                    insertFirstR(listReview, reviewNode);
                    cout << "Review berhasil ditambahkan!" << endl;
                } else {
                    cout << "Hotel atau person tidak ditemukan. Review tidak dapat ditambahkan." << endl;
                }
                break;
            }
            case 10: {
                system("CLS");
                printAllHotelWithReviewers(listHotel, listReview);
                break;
            }
            case 11: {
                system("CLS");
                string personName;
                string hotelName;

                cout << "Masukkan Nama Hotel: ";
                cin.ignore(32767, '\n');
                getline(cin, hotelName);

                cout << "Masukkan nama pengguna: ";
                getline(cin, personName);

                bool found = Reviewerhoteltertentu(listReview, listHotel, listPerson, personName, hotelName);
                if (found){
                    cout << "Pengguna pernah mereview pada hotel tersebut" << endl;
                }else {
                    cout << "Pengguna tidak pernah mereview pada hotel tersebut" << endl;
                }
                break;
            }
            case 12:{
                system("CLS");
                string personName;
                cout << "Masukkan Nama Person: ";
                cin.ignore(); // Menggunakan ignore untuk mengabaikan karakter '\n' pada buffer
                getline(cin, personName);
                adrp foundPerson = searchPersonByName(listPerson, personName);
                if(foundPerson){
                    deletePerson(listPerson, listReview, foundPerson);
                    cout << "Pengguna berhasil dihapus" << endl;
                }else {
                    cout << "Pengguna tidak ditemukan" << endl;
                }
                break;
            }
            case 13: {
                system("CLS");
                string hotelName;
                cout << "Masukkan Nama Hotel: ";
                cin.ignore();
                getline(cin, hotelName);
                adrh foundHotel = searchHotelByName(listHotel, hotelName);
                if (foundHotel) {
                    cout << "Jumlah: " << JumlahReviewerhoteltertentu(listReview,hotelName) << endl;
                }else {
                    cout << "Hotel tidak ditemukan!" << endl;
                }
                break;
            }
            case 14: {
                system("CLS");
                cout << "Terima Kasih" << endl;
                break;
            }
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
                system("CLS");
        }
    } while (choice != 14);

    return 0;
}
