#ifndef struct_lib_h
#define struct_lib_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WB {
    char name[80];
    long articul;
    int count;
    double cost;
    char sale;
}WB;

void create_db ();
void make_db ();
void save_db ();
void add_db ();
void search_articul_db ();
void print_sale_db ();
void print_not_avalable_db ();
void db_sort ();

#endif
