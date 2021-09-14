#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct medicin
{
    int code;
    float rate;
    int quantity ;
    char name[50];

};
void menu();
void start();
void back();
void addrecord();
void searchrecord();
void cal_bill() ;

int main()
{
    start();
    return 0;
}
void back()
{
    start();
}
void start()
{
    menu();
}
void menu()
{
printf("\n\t\t**********Pharmacy************");

printf("\n\n\t\t\t>>>>>>MENU<<<<<<\t\t\n\n");
printf("\n\t\t\t*1.Add New  \n\n\t\t\t*2.Search_the_medicine_by_name  \n\n\t\t\t*3.Exit \n\n\t\t\t*4.Calculate bill\n");

switch(getch())
{
    case '1':

            addrecord();
    break;
   case '2': searchrecord();
    break;
    case '3': exit(0);
    break;
   case '4' :cal_bill() ;
   break ;
    default:

                printf("\nEnter 1 to 4 only");
                printf("\n Enter any key");
                getch();
system("cls") ;
menu();

}
}
        void addrecord()
{
        FILE *f;
        struct medicin p;
        f=fopen("project2.txt","ab+");
        printf("\n Enter product code: ");
        scanf("%d",&p.code);
        fflush(stdin);
        printf("\nEnter name of item: ");
        gets(p.name);
        fflush(stdin);
        printf("\nEnter the Medicine price: ");
        scanf("%f",&p.rate);
        printf("\nEnter Quantity of Medicine: ");
        scanf("%d",&p.quantity) ;
        fwrite(&p,sizeof(p),1,f);
        fclose(f);
        printf("\nRecord saved");
    printf("\n\nEnter any key\n");

	 getch();
    system("cls") ;
     menu();
}

void searchrecord()
{
    struct medicin p;
FILE *f;
char name[50];
int ft ;

f=fopen("project2.txt","r+b");
if(f==NULL)
{
    printf("\n error in opening\a\a\a\a");
    exit(1);

}
printf("\nEnter name of Medicine to search\n");
gets(name) ;
while(fread(&p,sizeof(p),1,f)==1)
{
    if(strcmp(p.name,name)==0)
    {
        printf("\n\t**Detail Information About %s**\n",name);
        printf("\n\tCode of Medicine= %d\n\n\tName of medicine=%s\n\n\tPrice  of  Medicine= %0.2f tk\n\n\tquantity of that medicine= %d\n\t",p.code,p.name,p.rate,p.quantity);

    }
}
 fclose(f);
   printf("\n Enter any key\n\n");
   getch();
   system("cls") ;
   menu();
}
void cal_bill()
{
    int q;
    float total ;
    char name[50] ;

    struct medicin p ;
    FILE *f ;
    f=fopen("project2.txt","r+b");
    if(f==NULL)
{
    printf("\n error in opening\a\a\a\a\n");
    exit(1);

}
printf("\n\n\tEnter name of Medicine for calculate:\n\t");
gets(name) ;
while(fread(&p,sizeof(p),1,f)==1)
{
if(strcmp(p.name,name)==0)
  {
    printf("***you have that medicine now you can calculate total bill...\n") ;
    printf("\nEnter quantity of Medicine \n=");
    scanf("%d",&q) ;
    total=((p.rate/p.quantity)*q) ;
    printf("Name of medicine= %s\n\nPrice of Medicine= %0.2f tk\n\nQuantity of that medicine= %d\n\nThe total bill= %0.2f tk\n",p.name,p.rate,p.quantity,total) ;
  }
}


   fclose(f);
   printf("\n Enter any key\n\n");
   getch();
   system("cls") ;
   menu();
}
