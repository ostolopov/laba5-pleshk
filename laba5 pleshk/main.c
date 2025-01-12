#include "libs.h"

int main(void)
{
    Ozon *products = NULL;
    int products_number = 0;
    int case_number = 0;
    printf(
           "(1) Создать новую БД (пункт всегда активен).\n"
           "(2) Загрузить данные из БД (все остальные пункты меню должны стать активными только послезагрузки данных или создания новой БД)\n"
           "(3) Сохранить БД (БД всегда находится в одном и том же файле)\n("
           "4) Добавить товар\n"
           "(5) Вывести все товары в формате Артикул Наименование Цена Количество Скидка.\n"
           "(6) Поиск товара по артикулу\n"
           //"(3.1) Изменение данных в найденном товаре\n"
           //"(3.2) Удаление товара\n"
           "(7) Вывести все товары со скидкой\n"
           "(8) Вывести все товары, которых нет в наличии\n"
           "(9) Отсортировать все товары по указанному полю (Наименование, Артикул, Количество, Цена)\n"
           "(10) Очистить консоль\n\n");
    while (get_int(&case_number, 0 ,11) != -1  && case_number != 0)
    {
        switch (case_number)
        {
            case 1:
                create_db (&products, &products_number);
                break;
            case 2:
                load_db (&products, &products_number);
                break;
            case 3:
                save_db (&products, &products_number);
                break;
            case 4:
                add_product (&products, &products_number);
                break;
            case 5:
                print_products (&products, &products_number);
                break;
            case 6:
                search_article_products (&products, &products_number);
                break;
            case 7:
                print_discount_products (&products, &products_number);
                break;
            case 8:
                print_not_avalable_products (&products, &products_number);
                break;
            case 9:
                products_sort (&products, &products_number);
                break;
            case 10:
                system("clear");
                break;
            case 11:
                generate_products (&products, &products_number);
                break;
            default:
                
                break;
        }
        printf(
                   "(1) Создать новую БД (пункт всегда активен).\n"
                   "(2) Загрузить данные из БД (все остальные пункты меню должны стать активными только послезагрузки данных или создания новой БД)\n"
                   "(3) Сохранить БД (БД всегда находится в одном и том же файле)\n("
                   "4) Добавить товар\n"
                   "(5) Вывести все товары в формате Артикул Наименование Цена Количество Скидка.\n"
                   "(6) Поиск товара по артикулу\n"
                   //"(3.1) Изменение данных в найденном товаре\n"
                   //"(3.2) Удаление товара\n"
                   "(7) Вывести все товары со скидкой\n"
                   "(8) Вывести все товары, которых нет в наличии\n"
                   "(9) Отсортировать все товары по указанному полю (Наименование, Артикул, Количество, Цена)\n"
                   "(10) Очистить консоль\n\n");
    }
    return 0;
}
