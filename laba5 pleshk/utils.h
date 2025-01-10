#ifndef utils_h
#define utils_h

int get_int(int *number, int min, int max);
int get_long(long *number, long min, long max);
int get_double (double *number, double min, double max);
int get_char (char *number, int min, int max);

#define get_everything(X, Y, Z) _Generic((X), \
    int*: get_int, \
    long*: get_long, \
    double*: get_double, \
    char*: get_char \
)(X, Y, Z)

void generate_products (Ozon **product, int* products_number);


#endif
