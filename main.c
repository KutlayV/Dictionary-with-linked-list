#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct kelime
{
    char* turkcesi;
    char* anlami;
    struct kelime *sonraki;
}kelime;


kelime Arama(kelime *Baslangic,kelime Aranan)
{
    kelime* iter;
    kelime sonuc;
    iter = (kelime *)malloc(sizeof(kelime));
    iter = Baslangic;
    while(iter->sonraki != NULL)
    {
        if(strcmp(iter->turkcesi, Aranan.turkcesi)==0)
        {
            sonuc.turkcesi = iter->turkcesi;
            sonuc.anlami = iter->anlami;
            sonuc.sonraki = iter->sonraki;
            return sonuc;
            break;
        }else if(iter->sonraki->sonraki == NULL)
        {
            sonuc.turkcesi = NULL;
            sonuc.anlami = NULL;
            sonuc.sonraki = NULL;
            return sonuc;
    }
        iter = iter->sonraki;
    }
}

int main()
{
    printf("MERHABA, KIO SOZLUGE HOSGELDINIZ!\n");
    char cev[30];
    char aranant[30];
    int g;
    kelime* baslangic;
    baslangic = (kelime *)malloc(sizeof(kelime));
    kelime* iter;
    iter = (kelime *)malloc(sizeof(kelime));
    iter = baslangic;
    kelime aranan,cevap;
    baslangic->anlami = "Apple";
    baslangic->turkcesi = "Elma";
    baslangic->sonraki = (kelime *)malloc(sizeof(kelime));
    baslangic->sonraki->turkcesi = "Araba";
    baslangic->sonraki->anlami = "Car";
    baslangic->sonraki->sonraki = (kelime *)malloc(sizeof(kelime));
    baslangic->sonraki->sonraki->turkcesi = "Fil";
    baslangic->sonraki->sonraki->anlami = "Elephant";
    baslangic->sonraki->sonraki->sonraki = (kelime *)malloc(sizeof(kelime));
    baslangic->sonraki->sonraki->sonraki->turkcesi = "Otobus";
    baslangic->sonraki->sonraki->sonraki->anlami = "Bus";
    baslangic->sonraki->sonraki->sonraki->sonraki = (kelime *)malloc(sizeof(kelime));
    baslangic->sonraki->sonraki->sonraki->sonraki->turkcesi = "Ogretmen";
    baslangic->sonraki->sonraki->sonraki->sonraki->anlami = "Teacher";
    baslangic->sonraki->sonraki->sonraki->sonraki->sonraki = NULL;
    g = 1;
    while(g==1)
    {
        printf("Kelime Eklemek Icin 'Ekle', Arama Yapmak Icin 'Ara', Sozlugu Gormek Icin 'Ac', Cikmak Icin 'Cikis' Yaziniz : ");
        scanf("%s",cev);
        if(strcmp( cev, "Ekle")==0)
        {
            iter = baslangic;
            while(iter->sonraki != NULL)
            {
                iter = iter->sonraki;
            }
            iter->sonraki = (kelime *)malloc(sizeof(kelime));
            iter = iter->sonraki;
            printf("Eklemek Istediginiz Kelimenin Turkcesi : ");
            scanf("%s",iter->turkcesi);
            printf("Eklemek Istediginiz Kelimenin Ingilizcesi : ");
            scanf("%s",iter->anlami);


        }else if(strcmp(cev, "Ac")==0)
        {
            iter = baslangic;
            while(iter != NULL)
            {
                printf("%s",iter->turkcesi);
                printf("-->");
                printf("%s",iter->anlami);
                printf("\n");
                iter = iter->sonraki;
            }
        } else if(strcmp(cev, "Ara")==0)
        {
            printf("Aramak Istediginiz Kelimenin Turkcesini Yaziniz : ");
            scanf("%s",aranant);
            aranan.turkcesi = aranant;
            aranan.anlami = NULL;
            aranan.sonraki = NULL;
            cevap = Arama(baslangic,aranan);
            if(cevap.anlami == NULL)
            {
                printf("Aradiginiz Kelime Bulunamadi! Eklemek Ister misiniz? (Eklemek Icin 'Ekle' Yaziniz : ");
                scanf("%s",cev);
                if(strcmp(cev, "Ekle")==0)
                {
                    iter = baslangic;
                    while(iter->sonraki != NULL)
                    {
                        iter = iter->sonraki;
                    }
                    iter->sonraki = (kelime *)malloc(sizeof(kelime));
                    iter = iter->sonraki;
                    printf("Eklemek Istediginiz Kelimenin Turkcesi : ");
                    scanf("%s",iter->turkcesi);
                    printf("Eklemek Istediginiz Kelimenin Ingilizcesi : ");
                    scanf("%s",iter->anlami);
                    iter->sonraki = NULL;
                }
            } else
            {
                printf("Kelimenin Turkcesi : ");
                printf("%s",cevap.turkcesi);
                printf("\nKelimenin Ingilizcesi : ");
                printf("%s",cevap.anlami);
                printf("\n");

            }
        }else if(strcmp( cev, "Cikis")==0)
        {
            g = 2;
        }else
        {
            printf("Gecersiz Bir Komut Girdiniz!");
        }
    }
}
