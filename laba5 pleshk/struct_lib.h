#ifndef struct_lib_h
#define struct_lib_h

typedef struct Ozon {
    char name[80];
    long article;
    int quantity;
    double price;
    char discount;
} Ozon;

void create_db (Ozon **product, int* products_number);
void load_db (Ozon **product, int* products_number);
void save_db (Ozon **product, int* products_number);
void add_product (Ozon **product, int* products_number);
void print_products (Ozon **product, int* products_number);
void search_article_products (Ozon **product, int* products_number);
void print_discount_products (Ozon **product, int* products_number);
void print_not_avalable_products (Ozon **product, int* products_number);
void products_sort (Ozon **product, int* products_number);

#endif
