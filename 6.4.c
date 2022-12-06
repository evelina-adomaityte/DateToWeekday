#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100

int main()
{
    printf("The program will check if the entered date's format is correct and report which weekday it is!\n\n");

    FILE *myFile;
    int year,
        month,
        day,
        length[7];
    char character,
         weekdays[7][CAPACITY];

    //-----------------------getting_data_from_file-----------------------
    myFile = fopen("week.txt", "r");
    for(int i = 0; i < 7; ++i)
    {
        int index = 0;
        char sym;

        fscanf(myFile, "%c", &sym);
        while(sym != '\n')
        {
            weekdays[i][index] = sym;
            ++index;
            fscanf(myFile, "%c", &sym);
        }
        length[i] = index;
    }
    fclose(myFile);

    //-----------------------date_input_computations_results-----------------------
    printf("Please enter a date as yyyy-mm-dd (the numbers must be separated by '-')!\n");
    while(1)
    {
        if(scanf("%d-%d-%d%c", &year, &month, &day, &character) == 4)
        {
            int copy = year,
                quantity = 0;

            while(copy != 0)
            {
                ++quantity;
                copy = copy / 10;
            }

            if(month == 2 && year % 4 == 0 && day > 29 || month == 2 && year % 4 != 0 && day > 28 || month == 4 && day > 30 || month == 6 && day > 30 || month == 9 && day > 30 || month == 11 && day > 30)
                printf("This date does not exist!\nPlease enter an existing date as yyyy-mm-dd!\n");
            else if(quantity < 5 && year >= 0 && month <= 12 && month >= 0 && day <= 31 && day >= 0 && character == '\n')
            {
                printf("The date has been entered correctly!\n\n");

                printf("%d-", year);
                if(month < 10)
                    printf("0%d-", month);
                else
                    printf("%d-", month);
                if(day < 10)
                    printf("0%d is a ", day);
                else
                    printf("%d is a ", day);

                int weekday = (day += month < 3 ? year-- : year - 2, 23 * month / 9 + day + 4 + year / 4 - year / 100 + year / 400) % 7;

                if(weekday == 0)
                    for(int i = 0; i < length[6]; ++i)
                        printf("%c", weekdays[6][i]);
                else
                    for(int i = 0; i < length[weekday - 1]; ++i)
                        printf("%c", weekdays[weekday - 1][i]);
                printf("!\n");
                break;
            }
            else
                printf("This date does not exist!\nPlease enter an existing date as yyyy-mm-dd!\n");
        }
        else
        {
            printf("The input is incorrect!\nPlease enter the date as yyyy-mm-dd with no other symbols besides '-'!\n");
            scanf("%*[^\n]");
        }
    }
    return 0;
}
while(copy != '@')
            {
                ++eta_index;
                copy = email[eta_index];
            }

            while(copy != '.')
            {
                ++eta_index;
                copy = email[eta_index];
            }
