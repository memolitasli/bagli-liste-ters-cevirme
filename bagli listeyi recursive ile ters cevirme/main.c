//Mehmet Taþlý 17010011024

#include <stdio.h>
#include <stdlib.h>
typedef struct n{
int data;
struct n *next;
}node;
node * root=NULL;

node * ekle(node * r)
{
    if(r == NULL)
    {
        r = (node *)malloc(sizeof(node));
        printf("Eklenecek tam sayiyi giriniz :");
        scanf("%d",&r->data);
        r->next = NULL;
        return r;
    }
  else if(r->next ==NULL)
    {
        node * temp = (node *)malloc(sizeof(node));
        printf("Eklenecek tam sayiyi giriniz :");
        scanf("%d",&temp->data);
        r->next = temp;
        temp->next =NULL;
        return r;

    }
    else{
    node * iter = r;
    node * temp = (node *)malloc(sizeof(node));
    printf("Eklenecek tam sayiyi giriniz :");
        scanf("%d",&temp->data);
    while(iter->next!= NULL)
        iter = iter->next;
    iter->next = temp;
    temp->next = NULL;
    return r;
}
}
void listele(node * r)
{
    node * iter = r;
    int sayac = 0;
    while(iter!= NULL)
    {
        printf("%d . eleman = %d \n",sayac,iter->data);
        iter = iter->next;
        sayac++;
    }
}

node * terscevir(node * r)
{

   if(r == NULL)
   {
    return NULL;
   }
    if(r->next == NULL)
    {
        return r;
    }
    node * r1 = terscevir(r->next);
    r->next->next = r;
    r->next = NULL;
    return r1;
}

int main()
{

    int a =1,secim;
    while(a == 1)
    {
        printf("Baslamak icin herhangi bir tusa basiniz...");
        getch();
        system("CLS");

        printf("\n 1->Bagli listeye tam sayi ekle \n 2->bagli listeyi yazdir \n 3->bagli listeyi terse cevir \n secim : ");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
            root =ekle(root);
            break;

        case 2 :
            listele(root);
            break;
        case 3:
            root= terscevir(root);

            break;
        default :
            printf("\n hatali giris yapriniz...");
            break;
        }
    }
    return 0;
}
