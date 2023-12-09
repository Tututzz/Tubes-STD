#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct hotel {
    string nama,kota,alamat;
    float harga;
    int bintang;
};

typedef struct elmH *adrh;

struct elmH{
    hotel info;
    adrh next;
};

struct user {
    string nama, noTelp, email;
    int umur;
};

typedef struct elmP *adrp;

struct elmP{
    user info;
    adrp next;
};

typedef struct elmR *adr;

struct elmR{
    adrh hotel;
    adrp person;
    adr next;
    string review;
};


struct listH{
    adrh first;
};
struct listP{
    adrp first;
};
struct listR{
    adr first;
};

adrh createElmH(hotel info) {
    adrh p = new elmH;
    p->info = info;
    p->next = NULL;
    return p;
}

adrp createElmP(user data) {
    adrp p = new elmP;
    p->info = data;
    p->next = NULL;
    return p;
}

adr createElmR(adrh hotel, adrp person) {
    adr p = new elmR;
    p->hotel = hotel;
    p->person = person;
    p->next = NULL;
    return p;
}

void createListH(listH &L) {
    L.first = NULL;
}

void createListP(listP &L) {
    L.first = NULL;
}

void createListR(listR &L) {
    L.first = NULL;
}

// 1. Insert data parent dari depan/belakang (5)
void insertLastH(listH &L, adrh p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        adrh last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
}

void insertLastP(listP &L, adrp p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        adrp last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
}

void insertLastR(listR &L, adr p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        adr last = L.first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
}

// Fungsi untuk menambahkan elemen di awal list
void insertFirstH(listH &L, adrh p) {
    p->next = L.first;
    L.first = p;
}

void insertFirstP(listP &L, adrp p) {
    p->next = L.first;
    L.first = p;
}

void insertFirstR(listR &L, adr p) {
    p->next = L.first;
    L.first = p;
}

// Fungsi untuk menambahkan elemen setelah suatu elemen tertentu
void insertAfterH(listH &L, adrh prec, adrh p) {
    p->next = prec->next;
    prec->next = p;
}

void insertAfterP(listP &L, adrp prec, adrp p) {
    p->next = prec->next;
    prec->next = p;
}

void insertAfterR(listR &L, adr prec, adr p) {
    p->next = prec->next;
    prec->next = p;
}

// Fungsi untuk menghapus elemen dari list
void deleteNodeH(listH &L, adrh &p) {
    if (L.first == p) {
        L.first = p->next;
        delete p;
    } else {
        adrh temp = L.first;
        while (temp->next != NULL && temp->next != p) {
            temp = temp->next;
        }
        if (temp->next == p) {
            temp->next = p->next;
            delete p;
        }
    }
}


void deleteNodeP(listP &L, adrp &p) {
    if (L.first == p) {
        L.first = p->next;
        delete p;
    } else {
        adrp temp = L.first;
        while (temp->next != NULL && temp->next != p) {
            temp = temp->next;
        }
        if (temp->next == p) {
            temp->next = p->next;
            delete p;
        }
    }
}

void deleteNodeR(listR &L, adr &p) {
    if (L.first == p) {
        L.first = p->next;
        delete p;
    } else {
        adr temp = L.first;
        while (temp->next != NULL && temp->next != p) {
            temp = temp->next;
        }
        if (temp->next == p) {
            temp->next = p->next;
            delete p;
        }
    }
}

// 4. Mencari data parent (5)
adrh searchHotelByName(listH L, string nama) {
    adrh p = L.first;
    while (p != NULL) {
        if (p->info.nama == nama) {
            return p;
        }
        p = p->next;
    }
    return NULL; // Jika tidak ditemukan
}

adrp searchPersonByName(listP L, string np) {
    adrp p = L.first;
    while (p != NULL) {
        if (p->info.nama == np) {
            return p;
        }
        p = p->next;
    }
    return NULL; // Jika tidak ditemukan
}

// 2. Show all data parent (5)
void printAllHotels(listH listHotel) {
    adrh currentHotel = listHotel.first;

    cout << "Daftar Hotel:" << endl;
    cout << "--------------------------------------" << endl;

    while (currentHotel != NULL) {
        cout << "Nama Hotel: " << currentHotel->info.nama << endl;
        cout << "Kota: " << currentHotel->info.kota << endl;
        cout << "Harga: " << currentHotel->info.harga << endl;
        cout << "Bintang: " << currentHotel->info.bintang << endl;
        cout << "--------------------------------------" << endl;

        currentHotel = currentHotel->next;
    }

    cout << endl;
}

void printAllReviews(listR listReview) {
    adr currentReview = listReview.first;

    cout << "Daftar Review:" << endl;
    cout << "--------------------------------------" << endl;

    while (currentReview != NULL) {
        cout << "Review: " << currentReview->review << endl;
        cout << "Hotel: " << currentReview->hotel->info.nama << endl;
        cout << "Person: " << currentReview->person->info.nama << endl;
        cout << "--------------------------------------" << endl;

        currentReview = currentReview->next;
    }

    cout << endl;
}

// Prosedur untuk menampilkan semua data person
void printAllPersons(listP listPerson) {
    adrp currentPerson = listPerson.first;

    cout << "Daftar Person:" << endl;
    cout << "--------------------------------------" << endl;

    while (currentPerson != NULL) {
        cout << "Nama: " << currentPerson->info.nama << endl;
        cout << "No Telp: " << currentPerson->info.noTelp << endl;
        cout << "Email: " << currentPerson->info.email << endl;
        cout << "Umur: " << currentPerson->info.umur << endl;
        cout << "--------------------------------------" << endl;

        currentPerson = currentPerson->next;
    }

    cout << endl;
}
//3. Menghapus data parent beserta relasinya (15)
void deleteHotel(listH &LH, listR &LR, adrh p){
    adr q= LR.first;
    adr q2;
    while (q!=NULL){
        if(q->hotel == p){
            q2 = q;
            q = q->next;
            deleteNodeR(LR,q2);
        }else{
            q = q->next;
        }
    }
    deleteNodeH(LH, p);
}

void deletePerson(listP &LP, listR &LR, adrp p){
    adr q= LR.first;
    adr q2;
    while (q!=NULL){
        if(q->person == p){
            q2 = q;
            q = q->next;
            deleteNodeR(LR,q2);
        }else{
            q = q->next;
        }
    }
    deleteNodeP(LP, p);
}



// 7. Menghubungkan data parent ke data child (5)
void printAllHotelWithReviewers(listH listHotel, listR listReview) {
    adrh currentHotel = listHotel.first;

    cout << "Daftar Hotel dan Reviewers:" << endl;
    cout << "--------------------------------------" << endl;

    while (currentHotel != NULL) {
        cout << "Nama Hotel: " << currentHotel->info.nama << endl;
        cout << "Kota: " << currentHotel->info.kota << endl;
        cout << "Harga: " << currentHotel->info.harga << endl;
        cout << "Bintang: " << currentHotel->info.bintang << endl;
        adr currentReview = listReview.first;
        bool hasReview = false;
        while (currentReview != NULL) {
            if (currentReview->hotel == currentHotel) {
                cout << "Reviewer: " << currentReview->person->info.nama << endl;
                cout << "Review: " << currentReview->review << endl;
                cout << "--------------------------------------" << endl;
                hasReview = true;
            }

            currentReview = currentReview->next;
        }
        if (!hasReview) {
            cout << "Belum ada review untuk hotel ini." << endl;
            cout << "--------------------------------------" << endl;
        }
        currentHotel = currentHotel->next;
    }

    cout << endl;
}

int mainMenu() {
    int choice;
    cout << "=========== Main Menu ===========" << endl;
    cout << "1. Tambah Hotel" << endl;
    cout << "2. Tambah Person" << endl;
    cout << "3. Tambah Review" << endl;
    cout << "4. Tampilkan Semua Hotel" << endl;
    cout << "5. Tampilkan Semua Person" << endl;
    cout << "6. Tampilkan Semua Review" << endl;
    cout << "7. Menghapus parent dan relasi(delete hotel dan review)" << endl;
    cout << "8. Keluar" << endl;
    cout << "9. Print data Parent beserta childnya(printallhotelbesertareview)"<<endl;
    cout << "10. Hapus data pengguna dan reviewnya (poin 10)"<<endl;
    cout << "Pilih menu (1-10):";
    cin >> choice;
    return choice;
}

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
            case 7: {
                string hotelName;
                cout << "Masukkan Nama Hotel: ";
                cin.ignore();
                getline(cin,hotelName);
                adrh foundHotel = searchHotelByName(listHotel, hotelName);
                deleteHotel(listHotel,listReview,foundHotel);
                break;
            }
            case 8: {
                cout << "Terima kasih!" << endl;
                break;
            }
            case 9:{
                printAllHotelWithReviewers(listHotel,listReview);
                break;
            }
            case 10:{
                string personName;
                cout << "Masukkan Nama Person: ";
                cin.ignore(); // Menggunakan ignore untuk mengabaikan karakter '\n' pada buffer
                getline(cin, personName);
                adrp foundPerson = searchPersonByName(listPerson, personName);
                deletePerson(listPerson, listReview, foundPerson);
                break;
            }

            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
        }

    } while (choice != 8);

    return 0;
}
