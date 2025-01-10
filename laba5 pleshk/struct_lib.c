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

void load_db(Ozon **product, int* products_number)
{
    FILE *file = fopen(FILENAME, "r");
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
// не работает
void save_db(Ozon **product, int* products_number)
{
    if (create_flag == 0)
    {
        printf("База данных еще не создана или не перенесена из файла\n");
        return;
    }
    FILE *file = fopen(FILENAME, "w");
    if (!file)
        {
        printf("Не удалось открыть файл для записи.\n");
        return;
    }

    fwrite(products_number, sizeof(int), 1, file);
    fwrite(*product, sizeof(Ozon), *products_number, file);
    fclose(file);
    printf("Данные успешно сохранены в файл.\n");
}

void add_db(Ozon **product, int* products_number)
{
    if (create_flag == 0)
    {
        printf("База данных еще не создана или не перенесена из файла\n");
        return;
    }
    
    Ozon new_product;
    
    printf("Введите наименование (до 80 символов): ");
    
    getchar();
    
    fgets(new_product.name, INT_MAX, stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0;
    
    if (strlen(new_product.name) == 0) {
        printf("Наименование не может быть пустым.\n");
        return;
    }
    
    printf("Введите артикул: ");
    get_everything(&new_product.article, 0, LONG_MAX);
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

void print_db(Ozon **product, int* products_number)
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

void search_article_db(Ozon **product, int* products_number)
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
            printf("1. Изменить данные\n2. Удалить товар\nВыберите действие: ");
            int action;
            scanf("%d", &action);

            if (action == 1)
                {
                printf("Введите новое наименование: ");
                getchar();
                fgets((*product)[i].name, INT_MAX, stdin);
                (*product)[i].name[strcspn((*product)[i].name, "\n")] = 0;

                printf("Введите новое количество: ");
                scanf("%d", &(*product)[i].quantity);

                printf("Введите новую цену: ");
                scanf("%lf", &(*product)[i].price);

                printf("Введите новую скидку: ");
                scanf(" %c", &(*product)[i].discount);
                printf("Данные успешно обновлены.\n");
            } else if (action == 2) {
                for (int j = i; j < *products_number - 1; j++) {
                    (*product)[j] = (*product)[j + 1];
                }
                (*products_number)--;
                printf("Товар удален.\n");
            }
            return;
        }
    }
    printf("Товар с указанным артикулом не найден.\n");
}

void print_discount_db(Ozon **product, int* products_number)
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
            printf("%ld\t%s\t%.2f\t%d\t%d%%\n",
                   (*product)[i].article, (*product)[i].name, (*product)[i].price,
                   (*product)[i].quantity, (*product)[i].discount);
        }
    }
}

void print_not_avalable_db(Ozon **product, int* products_number)
{
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
            printf("%ld\t%s\t%.2f\t%d\t%d%%\n",
                   (*product)[i].article, (*product)[i].name, (*product)[i].price,
                   (*product)[i].quantity, (*product)[i].discount);
        }
    }
}


void db_sort(Ozon **product, int* products_number)
{
    if (create_flag == 0)
    {
        printf("База данных еще не создана или не перенесена из файла\n");
        return;
    }

}

/*
void db_sort (Ozon **product, int* products_number) {
    printf("\nВыберите поле для сортировки:\n");
    printf("1. Наименование\n2. Артикул\n3. Количество\n4. Цена\nВаш выбор: ");
    int choice;
    scanf("%d", &choice);

    int (*compare[])(const void *, const void *) = {
        compare_name,
        compare_article,
        compare_quantity,
        compare_price
    };

    if (choice < 1 || choice > 4) {
        printf("Неверный выбор.\n");
        return;
    }

    qsort(*product, *products_number, sizeof(Ozon), compare[choice - 1]);
    printf("Товары успешно отсортированы.\n");
}

*/
