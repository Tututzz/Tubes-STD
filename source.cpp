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
        cout << "Alamat: " << currentHotel->info.alamat << endl;
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

void printAllHotelWithReviewers(listH listHotel, listR listReview) {
    adrh currentHotel = listHotel.first;

    cout << "Daftar Hotel dan Reviewers:" << endl;
    cout << "--------------------------------------" << endl;

    while (currentHotel != NULL){
        cout << "Nama Hotel: " << currentHotel->info.nama << endl;
        cout << "Kota: " << currentHotel->info.kota << endl;
        cout << "Alamat: " << currentHotel->info.alamat << endl;
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

bool Reviewerhoteltertentu(listR LR,listH LH, listP LP, string orang, string hotel){
    adr p = LR.first;
    adrh ph =searchHotelByName(LH,hotel);
    adrp pp = searchPersonByName(LP,orang);
    if (ph == NULL || pp == NULL){
        return false;
    }
    while (p!=NULL) {
        if (p->hotel == ph && p->person == pp){
            return true;
        }
        p= p->next;
    }
    return false;
}

int JumlahReviewhoteltertentu(listR LR,listH LH, listP LP, string hotel){
    adrh ph =searchHotelByName(LH,hotel);
    adr p = LR.first;
    int c=0;
    if (ph == NULL){
        cout <<"orang tidak ada atau hotel tidak ada"<<endl;
        return c;
    }
    while (p!=NULL) {
        if (p->hotel == ph){
            c++;
        }
        p= p->next;
    }
    return c;
}

int JumlahReviewerhoteltertentu(listR LR,string hotel){
    adr p = LR.first;
    int counter =0;
    while(p !=NULL){
        if (p->hotel->info.nama == hotel && isnotDuplikatReview(p)){
            counter++;
        }
        p=p->next;
    }
    return counter;
}

bool isnotDuplikatReview(adr p){
    adr q = p->next;
    while(q!=NULL){
        if (q->person->info.nama == p->person->info.nama && q->hotel->info.nama == p->hotel->info.nama){
            return false;
        }
        q= q->next;
    }
    return true;
};

adr searchPersonRelasi(listR L, string nama) {
    adr p = L.first;
    while (p != NULL) {
        if (p->person->info.nama == nama) {
            return p;
        }
        p = p->next;
    }
    return NULL; // Jika tidak ditemukan
}


int mainMenu() {
    int choice;
    cout << "=========== Main Menu ===========" << endl;
    cout << "1. Tambah data hotel" << endl;
    cout << "2. Tampilkan semua hotel" << endl;
    cout << "3. Tampilkan semua person" << endl;
    cout << "4. Tampilkan semua review" << endl;
    cout << "5. Menghapus data hotel beserta review" << endl;
    cout << "6. Mencari data hotel" << endl;
    cout << "7. Mencari data pengguna" << endl;
    cout << "8. Tambah data pengguna" << endl;
    cout << "9. Tambah review" << endl;
    cout << "10. Tampilkan data hotel beserta review pengguna" << endl;
    cout << "11. Mencari data pengguna pada hotel tertentu"<<endl;
    cout << "12. Menghapus data pengguna beserta reviewnya"<<endl;
    cout << "13. Menghitung jumlah reviewer pada hotel tertentu" << endl;
    cout << "14. Exit" << endl;
    cout << "Pilih menu (1-14):";
    cin >> choice;
    return choice;
}

