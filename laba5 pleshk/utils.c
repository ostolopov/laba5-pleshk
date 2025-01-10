#include "libs.h"

char *product_names[] = {
    "UltraClean Detergent",
    "SmartHome Hub",
    "EcoFresh Air Purifier",
    "PowerBoost Charger",
    "CozyDream Blanket",
    "AquaPure Water Bottle",
    "FitTrack Smartwatch",
    "SafeShield Helmet",
    "BrightGlow Lamp",
    "ChillMate Cooler",
    "ZenBreeze Diffuser",
    "QuickBake Oven",
    "GlowSkin Cream",
    "MegaBass Headphones",
    "SwiftGrip Gloves",
    "PureTone Earbuds",
    "ActiveStep Shoes",
    "CloudSoft Pillow",
    "StormForce Umbrella",
    "RapidMix Blender",
    "FreshVibes Candle",
    "GourmetChef Knife",
    "ToughTrail Backpack",
    "LuxeTouch Wallet",
    "TravelMate Suitcase",
    "TrueFocus Camera",
    "HydroGuard Flask",
    "SpeedySlice Cutter",
    "SmartClean Mop",
    "BoldBrew Coffee Maker",
    "SmoothFlow Pen",
    "EasyChop Board",
    "BrightPath Flashlight",
    "MaxiCharge Power Bank",
    "LuxeStyle Watch",
    "PureGrip Tennis Racket",
    "VitalCore Supplement",
    "HeatWave Kettle",
    "DreamChic Organizer",
    "AquaEase Filter",
    "GlidePro Skateboard",
    "SolarSmart Panel",
    "StoneEdge Knife Set",
    "QuickSew Machine",
    "ProHeat Iron",
    "HomeGuard Security Camera",
    "RapidWash Washer",
    "AromaBliss Tea Set",
    "SparkClean Toothbrush",
    "GlowTime Alarm Clock",
    "SwiftCharge Adapter",
    "ChillEase Fan",
    "ZenTime Yoga Mat",
    "UltraLight Tent",
    "FreshPack Lunch Box",
    "TurboGrill BBQ Set",
    "CloudWear Hoodie",
    "EcoBreeze Fan",
    "DreamFit Socks",
    "StoneCraft Mug",
    "EasyFix Toolkit",
    "AquaStep Flip-Flops",
    "GlideEase Roller Skates",
    "MegaClean Vacuum",
    "ShineBright Mirror",
    "SwiftLift Dumbbells",
    "LuxeBrew Espresso Machine",
    "SmoothCare Shampoo",
    "BoldStep Boots",
    "TrueTone Speakers",
    "LightWave Projector",
    "ChillCloud Mattress",
    "PureComfort Chair",
    "PowerMax Extension Cord",
    "ZenGlow Night Light",
    "HydroBoost Showerhead",
    "QuickClean Scrubber",
    "GlowFresh Toothpaste",
    "AromaFlow Oil Diffuser",
    "BrightFlex Desk Lamp",
    "EcoChic Tote Bag",
    "QuickFix Adhesive",
    "GourmetGrill Pan",
    "VitalMix Blender Bottle",
    "SpeedGrip Mouse",
    "StoneBrew Teapot",
    "AquaShield Raincoat",
    "TurboWash Soap",
    "SmartFit Band",
    "CloudEase Throw",
    "LuxeSkin Serum",
    "PowerCore Battery",
    "PureChill Ice Maker",
    "GlideClean Squeegee",
    "UltraTone Microphone",
    "FreshGuard Mask",
    "StormWear Jacket",
    "ZenEase Hammock",
    "ChillWave Cooler Bag",
    "GlowTime Clock"
};

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
        
        products[i].article = i + 1000000;
        products[i].quantity = rand() % 10000;
        products[i].price = rand() % 1000000;
        products[i].discount = rand() % 100;
    }
    *product = products;
    *products_number = count;
}
