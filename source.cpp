#include "header.h"

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



int mainMenu() {
    int choice;
    cout << "=========== Main Menu ===========" << endl;
    cout << "1. Tambah Hotel" << endl;
    cout << "2. Tambah Person" << endl;
    cout << "3. Tambah Review" << endl;
    cout << "4. Tampilkan Semua Hotel" << endl;
    cout << "5. Tampilkan Semua Person" << endl;
    cout << "6. Tampilkan Semua Review" << endl;
    cout << "7. Keluar" << endl;
    cout << "Pilih menu (1-7): ";
    cin >> choice;
    return choice;
}
