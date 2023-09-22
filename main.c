#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h"

int main()
{
    int choice,ticket_no,result;
    Passenger *ptr;
    char *pmob_no;
    char *train_no;
    int *ptickets_no;
    add_trains();
    while(1)
    {
        choice = enterchoice();
        if (choice==9)
            exit(0);
        switch(choice)
        {
        case 1:
            view_trains();
            textcolor(WHITE);
            printf("PRESS ANY KEY TO CONTINUE.....");
            getch();
            clrscr();
            break;
        case 2:
            ptr = get_passenger_details();
            if(ptr!=NULL)
            {
                ticket_no=book_ticket(*ptr);
                if(ticket_no==-1)
                {
                    textcolor(LIGHTRED);
                    printf("Bookings failed");
                }
                else
                {
                    textcolor(LIGHTGREEN);
                    printf("Ticket successfully booked\n your ticket no is: %d ",ticket_no);
                }
                textcolor(WHITE);
                printf("\n Press any key to CONTINUE");
                getch();
                clrscr();
            }
            break;
        case 3:
            clrscr();
            ticket_no = accept_ticket_no();
            if(ticket_no!=0)
                view_ticket(ticket_no);
            textcolor(WHITE);
            printf("\nPress any key to CONTINUE...");
            getch();
            clrscr();
            break;
        case 4:
            clrscr();
            pmob_no = accept_mob_no();
            if(pmob_no!=NULL)
            {
                ptickets_no = get_ticket_no(pmob_no);
                if(ptickets_no!=NULL)
                    view_all_tickets(pmob_no,ptickets_no);
            }
            clrscr();
            break;
        case 5:
            clrscr();
            view_all_bookings();
            textcolor(WHITE);
            printf("\n\nPress any key to CONTINUE...");
            getch();
            break;
        case 6:
            clrscr();
            train_no = accept_train_no();
            view_booking(train_no);
            break;
        case 7:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
            {
                result=cancel_ticket(ticket_no);
                if(result==0)
                {
                    textcolor(LIGHTRED);
                    printf("Sorry! No ticket Booked of ticket no: %d",ticket_no);

                }
                else if(result==1)
                {
                    textcolor(LIGHTGREEN);
                    printf("ticket cancel successfully");
                }
                else if(result==2)
                {
                    textcolor(LIGHTRED);
                    printf("ERROR in cancellation");
                }

                textcolor(WHITE);
                printf("\n\n Press any key to CONTINUE...");
            }
            getch();
        break;
        case 8:
            clrscr();
            train_no = accept_train_no();
            if(train_no!=NULL)
                cancel_train(train_no);
            getch();
            break;
        default:
            textcolor(LIGHTRED);
            printf("Invalid Option! \n\tTry Again...");
            getch();
        }
    }

    return 0;
}
