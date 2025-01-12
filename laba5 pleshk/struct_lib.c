#include "libs.h"

//extern int create_flag = 0;
int create_flag = 0;

void create_db(Ozon **product, int* products_number)
{
    free(*product);
    *product = NULL;
    *products_number = 0;
    printf("Новая база данных создана.\n");
    create_flag = 1;
}
// хз работает или нет
void load_db(Ozon **product, int* products_number)
{
    FILE *file = fopen(FILENAME1, "rb");
    if (!file)
        {
        printf("Не удалось открыть файл для чтения.\n");
        return;
    }
    fread(products_number, sizeof(int), 1, file);
    *product = (Ozon *)malloc(*products_number * sizeof(Ozon));
    if (!*product)
        {
        printf("Ошибка выделения памяти.\n");
        fclose(file);
        return;
    }

    fread(*product, sizeof(Ozon), *products_number, file);
    fclose(file);
    printf("Данные успешно загружены из файла.\n");
    create_flag = 1;
}

void save_db(Ozon **product, int* products_number)
{
    if (create_flag == 0)
    {
        printf("База данных еще не создана или не перенесена из файла\n");
        return;
    }
    FILE *file_txt = fopen(FILENAME, "w");
    FILE *file_bin = fopen(FILENAME1, "wb");
    
    if (!file_txt || !file_bin)
        {
        printf("Не удалось открыть файл для записи.\n");
        return;
    }
    for (int i = 0; i < *products_number; i++)
    {
        fprintf(file_txt, "%5ld\t%30s\t%15.2f\t%10d\t%7d%%\n", (*product)[i].article, (*product)[i].name, (*product)[i].price, (*product)[i].quantity, (*product)[i].discount);
    }
    
    
    fwrite(products_number, sizeof(int), 1, file_bin);
    fwrite(*product, sizeof(Ozon), *products_number, file_bin);
    fclose(file_txt);
    fclose(file_bin);
    printf("Данные успешно сохранены в файл.\n");
}

void add_product(Ozon **product, int* products_number)
{
    if (create_flag == 0)
    {
        printf("База данных еще не создана или не перенесена из файла\n");
        return;
    }
    int is_article = 0;
    Ozon new_product;
    printf("Введите наименование (до 80 символов): ");
    getchar();
    fgets(new_product.name, INT_MAX, stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0;
    if (strlen(new_product.name) == 0)
    {
        printf("Наименование не может быть пустым.\n");
        return;
    }
    
    while (is_article != 1)
    {
        int count = 0;
        printf("Введите артикул: ");
        get_everything(&new_product.article, 1, 999999);
        for (int i = 0; i < *products_number; i++)
        {
            if (new_product.article + 1000000 == (*product)[i].article)
            {
                printf("такой артикул уже присвоен.\n");
                break;
            }
            count++;
        }
        if (count == *products_number)
        {
            new_product.article += 1000000;
            is_article = 1;
        }
    }
    printf("Введите количество: ");
    get_everything(&new_product.quantity, 0, INT_MAX);
    printf("Введите цену: ");
    get_everything(&new_product.price, 0, DBL_MAX);
    printf("Введите скидку (0-100): ");
    get_everything(&new_product.discount, 0, 100);
    
    *product = (Ozon *)realloc(*product, (*products_number + 1) * sizeof(Ozon));
    if (!*product)
    {
        printf("Ошибка выделения памяти.\n");
        return;
    }
    (*product)[*products_number] = new_product;
    (*products_number)++;
    printf("Товар успешно добавлен.\n");
}

void print_products(Ozon **product, int* products_number)
{
    if (create_flag == 0)
    {
        printf("База данных еще не создана или не перенесена из файла\n");
        return;
    }
    printf("\nАртикул\t\t\t\t\tНаименование\t\t\tЦена\t\tКоличество\tСкидка\n");
    for (int i = 0; i < *products_number; i++) {
        printf("%5ld\t%30s\t%15.2f\t%10d\t%7d%%\n",
               (*product)[i].article, (*product)[i].name, (*product)[i].price, (*product)[i].quantity, (*product)[i].discount);
    }
}

void search_article_products(Ozon **product, int* products_number)
{
    if (create_flag == 0)
    {
        printf("База данных еще не создана или не перенесена из файла\n");
        return;
    }
    long article;
    printf("Введите артикул: ");
    scanf("%ld", &article);

    for (int i = 0; i < *products_number; i++)
        {
        if ((*product)[i].article == article)
            {
            printf("Товар найден: %s\n", (*product)[i].name);
            printf("(1) Изменить данные\n(2) Удалить товар\nВыберите действие: ");
            int case_number;
                while (get_int(&case_number, 0 ,2) != -1  && case_number != 0)
                {
                    switch (case_number)
                    {
                        case 1:
                            printf("Введите новое наименование: ");
                            getchar();
                            fgets((*product)[i].name, INT_MAX, stdin);
                            (*product)[i].name[strcspn((*product)[i].name, "\n")] = 0;
                            
                            printf("Введите новое количество: ");
                            get_everything(&(*product)[i].quantity, 0, 10000);
                            
                            printf("Введите новую цену: ");
                            get_everything(&(*product)[i].price, 0, 1000000);
                            
                            printf("Введите новую скидку: ");
                            get_everything(&(*product)[i].discount, 0, 100);
                            printf("Данные успешно обновлены.\n");
                            break;
                        case 2:
                            for (int j = i; j < *products_number - 1; j++) {
                                (*product)[j] = (*product)[j + 1];
                            }
                            (*products_number)--;
                            printf("Товар удален.\n");
                            break;
                        default:
                            printf("Ошибка ввода!\n");
                            break;
                    }
                    return;
                }
            //return;
        }
    }
    printf("Товар с указанным артикулом не найден.\n");
}

void print_discount_products(Ozon **product, int* products_number)
{
    if (create_flag == 0)
    {
        printf("База данных еще не создана или не перенесена из файла\n");
        return;
    }
    printf("\nТовары со скидкой:\n");
    for (int i = 0; i < *products_number; i++)
    {
        if ((*product)[i].discount > 0)
      {
          printf("%5ld\t%30s\t%15.2f\t%10d\t%7d%%\n",
                 (*product)[i].article, (*product)[i].name, (*product)[i].price, (*product)[i].quantity, (*product)[i].discount);
        }
    }
}

void print_not_avalable_products(Ozon **product, int* products_number)
{
    int count = 0;
    if (create_flag == 0)
    {
        printf("База данных еще не создана или не перенесена из файла\n");
        return;
    }
    printf("\nТовары, которых нет в наличии:\n");
    for (int i = 0; i < *products_number; i++)
    {
        if ((*product)[i].quantity == 0)
      {
          count++;
          printf("%5ld\t%30s\t%15.2f\t%10d\t%7d%%\n",
                 (*product)[i].article, (*product)[i].name, (*product)[i].price, (*product)[i].quantity, (*product)[i].discount);
        }
    }
    if (count == 0)
        printf("Товаров которых нет в наличии - нет.\n");
}

int compare_name(const void *a, const void *b) {
    const Ozon *ozon_a = (const Ozon *)a;
    const Ozon *ozon_b = (const Ozon *)b;
    return strcmp(ozon_a->name, ozon_b->name);
}

int compare_article(const void *a, const void *b) {
    const Ozon *ozon_a = (const Ozon *)a;
    const Ozon *ozon_b = (const Ozon *)b;
    if (ozon_a->article < ozon_b->article) return -1;
    if (ozon_a->article > ozon_b->article) return 1;
    return 0;
}

int compare_quantity(const void *a, const void *b) {
    const Ozon *ozon_a = (const Ozon *)a;
    const Ozon *ozon_b = (const Ozon *)b;
    return ozon_a->quantity - ozon_b->quantity;
}

int compare_price(const void *a, const void *b) {
    const Ozon *ozon_a = (const Ozon *)a;
    const Ozon *ozon_b = (const Ozon *)b;
    if (ozon_a->price < ozon_b->price) return -1;
    if (ozon_a->price > ozon_b->price) return 1;
    return 0;
}

void products_sort(Ozon **product, int *products_number) {
    if (create_flag == 0) {
        printf("База данных еще не создана или не перенесена из файла\n");
        return;
    }

    int case_number;
    int (*compare[])(const void *a, const void *b) = {
        compare_name,
        compare_article,
        compare_quantity,
        compare_price
    };

    printf("\nВыберите поле для сортировки.\n(1) Наименование\n(2) Артикул\n(3) Количество\n(4) Цена\nВаш выбор: ");

    while (scanf("%d", &case_number) != EOF && case_number != 0) {
        if (case_number >= 1 && case_number <= 4) {
            qsort(*product, *products_number, sizeof(Ozon), compare[case_number - 1]);
            printf("Сортировка выполнена.\n");
        } else {
            printf("Ошибка ввода!\n");
        }
        printf("\nВыберите поле для сортировки.\n(1) Наименование\n(2) Артикул\n(3) Количество\n(4) Цена\nВаш выбор: ");
    }
}

/*
int compare_name (const void *a, const void *b)
{
    
    return 0;
}

int compare_article (const void *a, const void *b)
{
    
    return 0;
}
int compare_quantity (const void *a, const void *b)
{
    
    return 0;
}

int compare_price (const void *a, const void *b)
{
    
    return 0;
}

void products_sort(Ozon **product, int* products_number)
{
    if (create_flag == 0)
    {
        printf("База данных еще не создана или не перенесена из файла\n");
        return;
    }
    int case_number;
    int (*compare[])(const void *a, const void *b) = {
        compare_name,
        compare_article,
        compare_quantity,
        compare_price
    };
    printf("\nВыберите поле для сортировки.\n(1) Наименование\n(2) Артикул\n(3) Количество\n(4) Цена\nВаш выбор: ");
    while (get_int(&case_number, 0 ,4) != -1  && case_number != 0)
    {
        switch (case_number)
        {
            case 1:
                qsort(*product, *products_number, sizeof(Ozon), compare[case_number - 1]);
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            default:
                printf("Ошибка ввода!\n");
                break;
        }
        return;
    }
}

*/



