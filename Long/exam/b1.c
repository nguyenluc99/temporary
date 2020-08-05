#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAXCHAR 1000
#define MAX_DIEM 1000
typedef struct Diem
{
    float x;
    float y;
} Diem;

Diem docDong(char *);
int docFileVaIn(char *, Diem *);
float doDaiGapKhuc(Diem *, int);
void diemGanNhat(Diem, Diem *, int);
int main()
{

    int tongSoDiem;
    int age;
    char ch, choice;
    Diem dsDiem[MAX_DIEM];
    Diem diemBanDau;
    do
    {
        printf("Choose an options : \n");
        printf("1. Doc va in thong tin VDV\n");
        printf("2. Tinh do dai duong gap khuc\n");
        printf("3. \n");
        printf("0. Thoat\n");
        printf("Your choice: \t");
        scanf("%[^\n]%*c", &choice);
        switch (choice)
        {
        case '1':
            tongSoDiem = docFileVaIn("Diem.txt", dsDiem);
            break;
        case '2':
            // printBestStudent(5, dsDiem, tongSoDiem);
            printf("Do dai duong gap khuc la %6.3f\n", doDaiGapKhuc(dsDiem, tongSoDiem));
            break;
        case '3':
            printf("Insert x_A: ");
            scanf("%f", &diemBanDau.x);
            
            printf("Insert y_A: ");
            scanf("%f", &diemBanDau.y);
            diemGanNhat(diemBanDau, dsDiem, tongSoDiem);
            // printf("total score of age %d is %6.3f\n", age, averageScore(age, dsDiem, tongSoDiem));
            break;
        case '0':
            printf("Quited!");
            return 0;
        default:
            choice = '-';
            break;
        }
    } while (choice != '0');
    return 0;
}

Diem docDong(char *str)
{
    Diem d;
    int i, len;
    char tmp1[10], tmp2[10], ch;
    len = strlen(str);
    for (i = 1; i < len - 1; i++)
    {
        if (isspace(str[i]))
        {
            memcpy(tmp1, str, i);
            d.x = atof(tmp1);
            memcpy(tmp2, str + i + 1, len - i - 2);
            d.y = atof(tmp2);
        }
    }
    return d;
}

int docFileVaIn(char *tenFile, Diem *dsDiem)
{
    FILE *file = fopen(tenFile, "r");
    char str[100];
    int currentSt = 0, num, i;
    if (file)
    {
        if (fgets(str, MAXCHAR, file) != NULL)
        {
            num = atoi(str);
            for (i = 0; i < num && i < MAX_DIEM; i++)
            {
                fgets(str, MAXCHAR, file);
                dsDiem[currentSt] = docDong(str);
                currentSt++;
            }
            for (i = 0; i < num && i < MAX_DIEM; i++)
            {
                printf("Diem thu %d, x = %6.3f, y = %6.3f\n", i + 1, dsDiem[i].x, dsDiem[i].y);
            }
        }
    }
    return num;
}

float doDaiGapKhuc(Diem *dsDiem, int tongSoDiem)
{
    int i;
    float sum = 0;
    for (i = 0; i < tongSoDiem - 1; i++)
    {
        sum += sqrt((dsDiem[i].x - dsDiem[i + 1].x) * (dsDiem[i].x - dsDiem[i + 1].x) + (dsDiem[i].y - dsDiem[i + 1].y) * (dsDiem[i].y - dsDiem[i + 1].y));
        printf("temp sum is %6.3f\n", sum);
    }
    return sum;
}

void diemGanNhat(Diem diemBanDau, Diem *dsDiem, int tongSoDiem) {
    int i;
    float khoangCachNN, tmp;
    Diem tmpDiem;
    FILE *fp = fopen("DiemGan.txt", "w");
    if (!tongSoDiem) return;
    khoangCachNN = (diemBanDau.x - dsDiem[0].x) * (diemBanDau.x - dsDiem[0].x) + (diemBanDau.y - dsDiem[0].y) * (diemBanDau.y - dsDiem[0].y);
    for (i = 1; i < tongSoDiem; i++) {
        tmp = (diemBanDau.x - dsDiem[i].x) * (diemBanDau.x - dsDiem[i].x) + (diemBanDau.y - dsDiem[i].y) * (diemBanDau.y - dsDiem[i].y);
        if (tmp < khoangCachNN) {
            tmpDiem.x = dsDiem[i].x;
            tmpDiem.y = dsDiem[i].y;
        };
    }
    // write to file
    fprintf(fp, "%f - %f", tmpDiem.x, tmpDiem.y);
    fclose(fp);
}
