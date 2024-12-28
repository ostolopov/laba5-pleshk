#include "libs.h"

void dialog(void)
{
    Ozon *products = NULL;
    int products_number = 0;
    int dialog_number = -1;
    int check;
    int db_load = 0;
    while (dialog_number != 0)
    {
        for (int i = 0; i < count_messages; i++)
            printf("%s", messages[i]);
        printf("Выберите пункт:\n");
        
    }
}

int choose_option (int dialog_number)
{
    
    return 0;
}

void exit_dialog (Ozon **product, int* products_number)
{
    if (*product == NULL)
        return;
    
    
    printf("Работа программы завершена!\n");
}
