#ifndef dialog_h
#define dialog_h
// пока что не нужно, использую switch case
/*
void dialog (void);
int choose_option (int dialog_number);
void exit_dialog (Ozon **product, int* products_number);

static const char *messages[] = {
    "(0) Выход",
    "(1) Создать новую БД (пункт всегда активен).",
    "(2) Загрузить данные из БД (все остальные пункты меню должны стать активными только послезагрузки данных или создания новой БД)",
    "(3) Сохранить БД (БД всегда находится в одном и том же файле)",
    "(4) Добавить товар",
    "(5) Вывести все товары в формате Артикул Наименование Цена Количество Скидка.",
    "(6) Поиск товара по артикулу\n(3.1) Изменение данных в найденном товаре\n(3.2) Удаление товара",
    "(7) Вывести все товары со скидкой",
    "(8) Вывести все товары, которых нет в наличии",
    "(9) Отсортировать все товары по указанному полю (Наименование, Артикул, Количество, Цена)"
};

static const char *sorts[] = {
    "(0) Выход",
    "(1)",
    "(2)",
    "(3)",
    "(4)"
};

static const int count_messages = sizeof(messages) / sizeof(messages[0]);
static void (*func_num[])(Ozon **product, int* products_number) = {exit_dialog, create_db , load_db , save_db , add_db , search_article_db , print_discount_db , print_not_avalable_db , db_sort};

static const int count_sorts = sizeof(sorts) / sizeof(sorts[0]);
static void (*sort_num[])(const void *a, const void *b) = {};
 */
#endif
