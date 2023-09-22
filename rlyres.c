#include<stdio.h>
#include"conio2.h"
#include "rlyres.h"
#include<string.h>
#include<ctype.h>


int enterchoice()
{
    int i;
    int choice;
    clrscr();
    textcolor(YELLOW);
    for(i=1;i<=80;i++)
        printf("-");

    gotoxy(30,1);
    printf("\nRAILWAY RESERVATION SYSTEM\n");

    for(i=1;i<=80;i++)
        printf("-");
    printf("\nSelect an Option: \n\n");
    printf("1- View Trains\n");
    printf("2- Book Ticket\n");
    printf("3- View Ticket\n");
    printf("4- Search Ticket No.\n");
    printf("5- View all Bookings\n");
    printf("6- view Train Bookings\n");
    printf("7- Cancel Ticket\n");
    printf("8- Cancel Train\n");
    printf("9- Quit\n\n");

    printf("Enter choice: ");
    scanf("%d",&choice);
    return choice;
}

void add_trains()
{
    Train alltrains[4]={
              {"123","BPL","GWA",2100,1500},
              {"546","BPL","DEL",3500,2240},
              {"345","HBJ","AGR",1560,1135},
              {"896","HBJ","MUM",4500,3360},
              };
    FILE *fp=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\alltrains.dat","rb");
    if(fp==NULL)
    {
        fp=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        printf("File saved successfully\n");
		fclose(fp);
    }
    else
    {
        printf("File already present\n");
        fclose(fp);
    }
}

void view_trains()
{
    int i;
    clrscr();
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FARE\tSECOND AC FARE\n");
    for(i=1;i<=80;i++)
        printf("-");
    FILE *fp=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\alltrains.dat","rb");
    Train tr;

    while(fread(&tr,sizeof(tr),1,fp)==1)
        printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);

    printf("\n");
    for(i=0;i<80;i++)
        printf("-");
    printf("\n\n");
    fclose(fp);
}

int check_train_no(char *train_no)
{
    FILE *fp = fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,train_no)==0)
        {
                fclose(fp);
                return 1;
        }
    }
    fclose(fp);
    return 0;
}

int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
        return 0;
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
            return 0;
        p_mob++;
    }
    return 1;
}

Passenger * get_passenger_details()
{
    clrscr();
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 For Exit");

    gotoxy(1,1);
    textcolor(YELLOW);
    static Passenger p;
    printf("Enter Passenger Name: ");
    fflush(stdin);
    fgets(p.p_name,20,stdin);
    if(p.p_name[0]=='0'||strlen(p.p_name)==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Reservation cancel!");
            getch();
            clrscr();
            return NULL;
        }
    char* pos = strchr(p.p_name,'\n');
    *pos='\0';

    int valid;
    printf("Enter gender(M/F): ");
    do
    {
        valid = 1;
        fflush(stdin);
        scanf("%c",&p.gender);
        if(p.gender=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation cancel!");
            getch();
            clrscr();
            return NULL;
        }
        if(p.gender!='M'&&p.gender!='F')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Invalid Gender! It should be in Uppercase(M/F)");
            valid=0;
            getch();
            gotoxy(19,2);
            printf("  \b");
            textcolor(YELLOW);
        }

    }while(valid==0);

    gotoxy(1,3);
    printf("Enter train number: ");
    do
    {
        fflush(stdin);
        scanf("%s",p.train_no);
        if(p.train_no[0]=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation cancel!");
            getch();
            clrscr();
            return NULL;
        }
        valid = check_train_no(p.train_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Invalid Train No.");
            getch();
            gotoxy(20,3);
            printf("\t\t\t\t\t\t\t");
            gotoxy(20,3);
            textcolor(YELLOW);
        }

    }while(valid==0);

    gotoxy(1,4);
    printf("Enter Travelling class(F_AC:-F / S_AC:-S): ");
    do
    {
        valid = 1;
        fflush(stdin);
        scanf("%c",&p.p_class);
        if(p.p_class=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation cancel!");
            getch();
            clrscr();
            return NULL;
        }
        if(p.p_class!='S'&&p.p_class!='F')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Invalid Train class! It should be in Uppercase(F/S)");
            valid=0;
            getch();
            gotoxy(43,4);
            printf("  \b");
            textcolor(YELLOW);
        }

    }while(valid==0);

    gotoxy(1,5);
    printf("Enter Address: ");
    fflush(stdin);
    fgets(p.address,50,stdin);
    if(p.address[0]=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation cancel!");
            getch();
            clrscr();
            return NULL;
        }
    pos = strchr(p.address,'\n');
    *pos='\0';

    printf("Enter Age: ");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%d",&p.age);
        if(p.age==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation cancel!");
            getch();
            clrscr();
            return NULL;
        }
        if(p.age<0||p.age>125)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Invalid Age!");
            valid=0;
            getch();
            gotoxy(11,6);
            printf("\t\t\t\t\t\t\t");
            gotoxy(11,6);
            textcolor(YELLOW);
        }
    }while(valid==0);

    gotoxy(1,7);
    printf("Enter Mobile number: ");
    do
    {
        fflush(stdin);
        fgets(p.mob_no,12,stdin);
        pos=strchr(p.mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
        if(p.mob_no[0]=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation cancel!");
            getch();
            clrscr();
            return NULL;
        }
        valid = check_mob_no(p.mob_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Invalid Mobile number!");
            valid=0;
            getch();
            gotoxy(22,7);
            printf("\t\t\t\t\t\t\t");
            gotoxy(22,7);
            textcolor(YELLOW);
        }
     }while(valid==0);
     return &p;
}

int get_booked_ticket_count(char *train_no,char tc)
{
    FILE * fp = fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    Passenger pr;
    int count = 0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0&&pr.p_class==tc)
            ++count;
    }
    fclose(fp);
    return count;
}

int last_ticket_no()
{
    FILE * fp = fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    fseek(fp,-1L*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}

int book_ticket(Passenger p)
{
    int ticket_count = get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==2)
    {
        textcolor(LIGHTRED);
        printf("All Seats in train no (%s) in class (%c) are FULL. ",p.train_no,p.p_class);
        return -1;
    }
    int ticket_no = last_ticket_no()+1;
    p.ticketno = ticket_no;
    FILE *fp = fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! SERVER DOWN......");
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}

int accept_ticket_no()
{
    printf("Enter a valid ticket no: ");
    int valid;
    int ticket_no;
    do
    {
        valid = 1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelling Input...!");
            getch();
            clrscr();
            return 0;
        }
        if(ticket_no<0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Invalid ticket number!");
            valid=0;
            getch();
            gotoxy(25,1);
            printf("\t\t\t\t\t\t\t");
            gotoxy(25,1);
            textcolor(YELLOW);
        }
    }while(valid==0);
    return ticket_no;
}

void view_ticket(int ticket_no)
{
    FILE *fp = fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry! No Bookings yet DONE....");
        return ;
    }
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticketno==ticket_no)
        {
            printf("\nNAME: %s\nGENDER: %c\nTRAIN NO.: %s\nCLASS: %c\nADDRESS: %s\nAGE: %d\nMOBILE NO.: %s\nTICKET NO.:%d\n",
                   pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticketno);
            found=1;
            break;
        }
    }
    if(!found)
    {
        textcolor(LIGHTRED);
        printf("Details of ticket no: %d \nNot found",ticket_no);
    }
    fclose(fp);
}

char*accept_mob_no()
{
    static char mob_no[12];
    char *pos;
    int valid;
    printf("Enter valid mobile no.: ");
    do
    {
        fflush(stdin);
        fgets(mob_no,13,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
        if(mob_no[0]=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("CANCELLING INPUT!");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;
        }
        valid = check_mob_no(mob_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Invalid Mobile number!");
            getch();
            gotoxy(24,1);
            printf("\t\t\t\t\t\t\t");
            gotoxy(24,1);
            textcolor(YELLOW);
        }
     }while(valid==0);
     clrscr();
     return mob_no;
}


int *get_ticket_no(char *p_mob_no)
{
    int count=0;
    FILE *fp=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("NO Bookings");
        textcolor(WHITE);
        printf("\nPress Any Key to CONTINUE...");
        getch();
        return NULL;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp))
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            ++count;
        }
    }
    if(!count)
    {
        fclose(fp);
        return NULL;
    }
    int *p=(int *)malloc((count+1)*sizeof(int));
    rewind(fp);
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp))
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            *(p+i)=pr.ticketno;
            i++;
        }
    }
    *(p+i)=-1;
    fclose(fp);
    return p;
}

void view_all_tickets(char *pmob_no,int *pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("NO Ticket Booked on this Number");
        textcolor(WHITE);
        printf("\n Press any key to CONTINUE");
        textcolor(YELLOW);
        getch();
        return ;
    }
    printf("Following tickets are of number: %s",pmob_no);
    int i;
    printf("\n\n\t TICKETS NUMBER\n");
    printf("-----------------------------------------");
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n%d",*(pticket_no+i));
    textcolor(WHITE);
    printf("\nPress any key to CONTINUE...");
    textcolor(YELLOW);
    getch();
    free(pticket_no);
}

char* accept_train_no()
{
   static char train_no[10];
   int valid;
   printf("Enter train number: ");
    do
    {
        fflush(stdin);
        scanf("%s",train_no);
        if(train_no[0]=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Searching cancel.....");
            return NULL;
        }
        valid = check_train_no(train_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Invalid Train No.");
            getch();
            gotoxy(21,1);
            printf("\t\t\t\t\t\t\t");
            gotoxy(21,1);
            textcolor(YELLOW);
        }
    }while(valid==0);
    return train_no;
}

void view_booking(char *train_no)
{
    FILE *fp=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat","rb");
    int found=0;
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("File not open");
        return ;
    }
    Passenger pr;
    printf("\nTICKET NO.\tCLASS\tNAME\tGENDER\tAGE\tMOBILE NO.\n",
                pr.ticketno,pr.p_class,pr.p_name,pr.gender,pr.age,pr.mob_no);
            printf("--------------------------------------------------------------------");
    while(fread(&pr,sizeof(pr),1,fp))
    {
        if(strcmp(train_no,pr.train_no)==0)
        {
            ++found;
            printf("\n%d \t\t%c \t%s \t%c \t%d \t%s",pr.ticketno,pr.p_class,pr.p_name,pr.gender,pr.age,pr.mob_no);
        }
    }
    if(!found)
    {
        clrscr();
        textcolor(WHITE);
        printf("\n\tNo Tickets FOUND of Train No: %s ",train_no);
    }
    textcolor(WHITE);
    printf("\n\nPress any key to CONTINUE...");
    fclose(fp);
    getch();
}

int cancel_ticket(int ticket_no)
{
    int result;
    FILE *fp=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n No Bookings Done");
        return -1;
    }
    FILE *fp2=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\temp.dat","wb");
    Passenger pr;
    int found = 0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticketno==ticket_no)
            {
                found = 1;
            }
        else
            {
                fwrite(&pr,sizeof(pr),1,fp2);
            }
    }
    fclose(fp);
    fclose(fp2);
    if(found==0)
    {
        remove("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\temp.dat");

    }
    else
    {
        result = remove("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat");
        if(result!=0)
        {
            perror("caused by");
            return 2;
        }
        result = rename("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\temp.dat",
                        "D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat");
        if(result!=0)
            return 2;

    }
    return found;
}

void view_all_bookings()
{
    int i;
    FILE *fp=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n file cannot open");
        return ;
    }
    int found=0;
    Passenger pr;
    printf("\nTICKET NO.\tCLASS\tNAME\tGENDER\tAGE\tMOBILE NO.\n",
                pr.ticketno,pr.p_class,pr.p_name,pr.gender,pr.age,pr.mob_no);
    for(i=0;i<80;i++)
        printf("-");
    while(fread(&pr,sizeof(pr),1,fp))
    {
            ++found;
            printf("\n%d \t\t%c \t%s \t%c \t%d \t%s",pr.ticketno,pr.p_class,pr.p_name,pr.gender,pr.age,pr.mob_no);
    }
    printf("\n");
    for(i=0;i<80;i++)
        printf("-");
    if(!found)
    {
        clrscr();
        printf("\nNo records found");
    }
    fclose(fp);
}

void cancel_train_tickets(char *train_no)
{
    int  train_booking = 0;
    FILE *ffp=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat","rb");
    if(ffp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n file(all bookings) cannot open");
        return ;
    }
    FILE *ffp2=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\newallbookings.dat","wb");
    if(ffp2==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n file(new all bookings) cannot open");
        return ;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,ffp)==1)
    {
        if(strcmp(pr.train_no,train_no)!=0)
            fwrite(&pr,sizeof(pr),1,ffp2);
        else
            train_booking += 1;
    }
    fclose(ffp);
    fclose(ffp2);
    if(!train_booking)
    {
        remove("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\newallbookings.dat");
    }
    else
    {
        remove("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat");
        rename("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\newallbookings.dat",
                "D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\allbookings.dat");
    }
}

void cancel_train(char *train_no)
{
    FILE *fp=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\alltrains.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n file(all trains) not open");
        return ;
    }
    FILE *fp2=fopen("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\temp1.dat","wb");
    Train tr;
    int found = 0;
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,train_no)==0)
            {
                cancel_train_tickets(train_no);
                found = 1;
            }
        else
            {
                fwrite(&tr,sizeof(tr),1,fp2);
            }
    }
    fclose(fp);
    fclose(fp2);
    if(found==0)
    {
        remove("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\temp1.dat");
        textcolor(LIGHTGREEN);
        printf("\n\nNo Train found...!!");

    }
    else
    {
        remove("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\alltrains.dat");
        rename("D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\temp1.dat",
               "D:\\project - C 2k20-2\\Railway Reservation System\\all_data_files\\alltrains.dat");
        textcolor(LIGHTGREEN);
        printf("\n\nTrain cancel successfully!");
    }
    textcolor(WHITE);
    printf("\nPress any key to CONTINUE...");
}
