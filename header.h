#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

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

adrh createElmH(hotel info);
adrp createElmP(user data);
adr createElmR(adrh hotel, adrp person);
void createListH(listH &L);
void createListP(listP &L);
void createListR(listR &L);

void insertLastH(listH &L, adrh p);
void insertLastP(listP &L, adrp p);
void insertLastR(listR &L, adr p);

void insertFirstH(listH &L, adrh p);
void insertFirstP(listP &L, adrp p);
void insertFirstR(listR &L, adr p);

void insertAfterH(listH &L, adrh prec, adrh p);
void insertAfterP(listP &L, adrp prec, adrp p);
void insertAfterR(listR &L, adr prec, adr p);

void deleteNodeH(listH &L, adrh &p);
void deleteNodeP(listP &L, adrp &p);
void deleteNodeR(listR &L, adr &p);

adrh searchHotelByName(listH L, string nama);
adrp searchPersonByName(listP L, string np);

void printAllHotels(listH listHotel);
void printAllReviews(listR listReview);
void printAllPersons(listP listPerson);

int mainMenu();


#endif // HEADER_H_INCLUDED
