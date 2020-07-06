#include "radixSort_MSD.h"


void exch(int *a, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void insertion(int *a, int lo, int hi, int d){
    for(int i = lo; i<= hi; i++){
        for(int j = i; j> lo && a[j] < a[j-1]; j--){
            exch(a,j,j-1);
        }
    }
}

void MSDIntegerSort(int *a, int lo, int hi, int d, int *aux){
    if (hi <= lo + CUTOFF){
        insertion(a,lo,hi,d);
        return;
    }

    auto *count = new int[R+1];
    int mask = R-1;
    int shift = BITS_PER_INT - BITS_PER_BYTE*d - BITS_PER_BYTE;

    for (int i = lo; i<=hi; i++){
        int c = (a[i]>>shift)&mask;
        count[c+1]++;
    }

    for (int r = 0; r<R; r++){
        count[r+1] += count[r];
    }

    for (int i = lo; i<= hi; i++){
        int c = (a[i]>>shift)&mask;
        aux[count[c]++] = a[i];
    }

    for (int i = lo; i<=hi; i++){
        a[i] = aux[i-lo];
    }

    if(d==4)return;

    if(count[0]>0){
        MSDIntegerSort(a,lo,lo+count[0]-1, d+1, aux);
    }

    for (int r = 0; r<R; r++){
        if(count[r+1] > count[r]){
            MSDIntegerSort(a, lo+count[r], lo+count[r+1]-1, d+1, aux);
        }
    }
}

void MSDIntegerSort(int *a, int n){
    int *aux = new int[n];
    MSDIntegerSort(a,0,n-1,0,aux);
}

void readFromFile(std::ifstream &file, int *mass, int n) {

    for (int i = 0; i < n; i++) {
        file >> mass[i];
    }
}

void print(int *a, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << std::endl;
    }
}

//______________________

char charAt(std::string s, int pos) {
    return s[pos];
}

int charrAt(std::string s, int d) {
    assert(d >= 0 && d <= s.length());
    if (d == s.length())
        return -1;
    return charAt(s, d);
}

void exch(std::string *a, int i, int j){
    std::string temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

bool lesss(std::string v, std::string w, int d){
    for (int i = d; i<std::min(v.length(), w.length()); i++){
        if(charAt(v,i) < charAt(w,i)) return true;
        if(charAt(v,i) > charAt(w,i)) return false;
    }
    return v.length() < w.length();
}

void insertion(std::string *a, int lo, int hi, int d){
    for (int i = lo; i<=hi; i++){
        for(int j = i; j>lo && lesss(a[j], a[j-1], d); j--){
            exch(a,j,j-1);
        }
    }
}

void MSDStringSort(std::string *a, int lo, int hi, int d, std::string *aux) {

    if (hi <= lo + CUTOFF) {
        insertion(a, lo, hi, d);
        return;
    }

    int *count = new int[R + 2];

    for (int i = lo; i <= hi; i++) {
        int c = charrAt(a[i], d);
        count[c + 2]++;
    }

    for (int r = 0; r < R + 1; r++) {
        count[r + 1] += count[r];
    }

    for (int i = lo; i <= hi; i++) {
        int c = charrAt(a[i], d);
        aux[count[c + 1]++] = a[i];
    }

    for (int i = lo; i <= hi; i++) {
        a[i] = aux[i - lo];
    }

    for (int r = 0; r < R; r++) {
        MSDStringSort(a, lo + count[r], lo + count[r + 1] - 1, d + 1, aux);
    }
}


void MSDStringSort(std::string *a, int n) {
    auto *aux = new std::string[n];
    MSDStringSort(a, 0, n - 1, 0, aux);
}

void readFromFile(std::ifstream &file, std::string *mass, int n) {

    for (int i = 0; i < n; i++) {
        file >> mass[i];
    }
}

void print(std::string *a, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << std::endl;
    }
}