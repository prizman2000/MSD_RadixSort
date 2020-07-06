#ifndef RADIXSORT_MSD_RADIXSORT_MSD_H
#define RADIXSORT_MSD_RADIXSORT_MSD_H

#include <iostream>
#include <fstream>

const int BITS_PER_BYTE = 8;
const int BITS_PER_INT = 32;
const int R = 256;
const int CUTOFF = 15;

void exch(int *a, int i, int j);
void insertion(int *a, int lo, int hi, int d);
void MSDIntegerSort(int *a, int lo, int hi, int d, int *aux);
void MSDIntegerSort(int *a, int n);
void readFromFile(std::ifstream &file, int *mass, int n);
void print(int *a, int n);

//_________________________________________________________________

char charAt(std::string s, int pos);
int charrAt(std::string s, int d);
void exch(std::string *a, int i, int j);
bool lesss(std::string v, std::string w, int d);
void insertion(std::string *a, int lo, int hi, int d);
void MSDStringSort(std::string *a, int lo, int hi, int d, std::string *aux);
void MSDStringSort(std::string *a, int n);
void readFromFile(std::ifstream &file, std::string *mass, int n);
void print(std::string *a, int n);

#endif //RADIXSORT_MSD_RADIXSORT_MSD_H
