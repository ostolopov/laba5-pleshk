#include "libs.h"

int get_int(int *number, int min, int max)
{
        int check = 0, number_check, flag = 0;
        while(flag == 0){
                check = scanf("%d" , &number_check);
                switch(check){
                        case EOF:
                                printf("Работа программы прекращена.\n");
                                flag = 1;
                                break;
                        case 1 :
                                if (number_check < min || number_check > max)
                                {
                                    printf("Число вышло за разрешенный диапазон. Попробуйте еще раз!\n");
                                    scanf("%*[^\n]");
                                    flag = 0;
                                    break;
                                }
                                *number = number_check;
                                scanf("%*[^\n]");
                                flag = 1;
                                break;
                        case 0:
                                printf("Число неверно. Попробуйте еще раз!\n");
                                scanf("%*[^\n]");
                                flag = 0;
                                break;
                        
                }
        }
        return check;
}

int get_long(long *number, long min, long max)
{
        int check = 0, flag = 0;
        long number_check;
        while(flag == 0){
                check = scanf("%ld" , &number_check);
                switch(check){
                        case EOF:
                                printf("Работа программы прекращена.\n");
                        flag = 1;
                        break;
                        case 1 :
                                if (number_check < min || number_check > max)
                                {
                                        printf("Число вышло за разрешенный диапазон. Попробуйте еще раз!\n");
                                        scanf("%*[^\n]");
                                        flag = 0;
                                        break;
                                }
                        *number = number_check;
                        scanf("%*[^\n]");
                        flag = 1;
                        break;
                        case 0:
                                printf("Число неверно. Попробуйте еще раз!\n");
                        scanf("%*[^\n]");
                        flag = 0;
                        break;

                }
        }
        return check;
}

int get_double (double *number, double min, double max)
{
        int check = 0, flag = 0;
        double number_check;
        while(flag == 0){
                check = scanf("%lf" , &number_check);
                switch(check){
                        case EOF:
                                printf("Работа программы прекращена.\n");
                        flag = 1;
                        break;
                        case 1 :
                                if (number_check < min || number_check > max)
                                {
                                        printf("Число вышло за разрешенный диапазон. Попробуйте еще раз!\n");
                                        scanf("%*[^\n]");
                                        flag = 0;
                                        break;
                                }
                        *number = number_check;
                        scanf("%*[^\n]");
                        flag = 1;
                        break;
                        case 0:
                                printf("Число неверно. Попробуйте еще раз!\n");
                        scanf("%*[^\n]");
                        flag = 0;
                        break;

                }
        }
        return check;
}

int get_char (char *number, int min, int max)
{
    
        int check = 0, flag = 0;
        int number_check;
        while(flag == 0){
                check = scanf("%d" , &number_check);
                switch(check){
                        case EOF:
                                printf("Работа программы прекращена.\n");
                        flag = 1;
                        break;
                        case 1 :
                                if (number_check < min || number_check > max)
                                {
                                        printf("Число вышло за разрешенный диапазон. Попробуйте еще раз!\n");
                                        scanf("%*[^\n]");
                                        flag = 0;
                                        break;
                                }
                        *number = (char) number_check;
                        scanf("%*[^\n]");
                        flag = 1;
                        break;
                        case 0:
                                printf("Число неверно. Попробуйте еще раз!\n");
                        scanf("%*[^\n]");
                        flag = 0;
                        break;

                }
        }
        return check;
}

void generate_products(Ozon **product, int *products_number)
{
    Ozon *products = NULL;
    int count = 0;
    get_int(&count, 0, INT_MAX);
    products = malloc(count * sizeof(Ozon));
    if (products == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < count; i++)
    {
        strncpy(products[i].name, product_names[rand() % 100], sizeof(products[i].name) - 1);
        products[i].name[sizeof(products[i].name) - 1] = '\0';
        
        products[i].article = i + 1000001;
        products[i].quantity = rand() % 10000;
        products[i].price = rand() % 1000000;
        products[i].discount = rand() % 100;
    }
    *product = products;
    *products_number = count;
}
