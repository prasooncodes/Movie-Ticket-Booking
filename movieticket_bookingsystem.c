//Online Movie Ticket Booking Project
#include<stdio.h>   //standard header
#include<string.h>  //header for using string
#include<stdlib.h>  //header for using file
#include<windows.h> //header for using sleep()

struct booker_information   //structure for customer (booker) information
{
    char u_name[100];
    char u_phone[11];
    char u_mail[100];
    char u_address[200];
} var;

char movie_1[] = "Inception";  //declaring strings as global for easy changing when necessary
char movie_2[] = "The Dark Knight";
char movie_3[] = "Interstellar";
char movie_4[] = "Tenet";
char movie_5[] = "Dune";

char upmov_1[] = "Oppenheimer";
char upmov_2[] = "No Time to Die";
char upmov_3[] = "The Batman";
char upmov_4[] = "Spider-Man: No Way Home";
char upmov_5[] = "Top Gun: Maverick";

char time_1[] = "9:00 AM";
char time_2[] = "11:00 AM";
char time_3[] = "1:00 PM";
char time_4[] = "3:00 PM";
char time_5[] = "5:00 PM";
char time_6[] = "7:00 PM";
char time_7[] = "9:00 PM";
char time_8[] = "11:00 PM";

char dim_1[] = "IMAX";
char dim_2[] = "3D";
char dim_3[] = "2D";

char request[1000];

void cur_mov();     //function for showing current movies
void upc_mov();     //function for showing upcoming movies
void time_sel();    //function for showing show times

int main(){
    FILE *fp1;
    fp1 = fopen("tick_info.txt", "a+");
    FILE *fp2;
    fp2 = fopen("request_info.txt", "a+");
    int pass;
    char user[50];
    login_prompt:
    printf("\n\nPlease login first ----\n");    //Login part
    printf("\nEnter your username = ");
    scanf("%s", &user);
    printf("Enter your password = ");//default password is 123
    scanf("%d", &pass);
    if (pass != 123)
    {
        printf("Enter a valid password to login\n");
        goto login_prompt;
    }
    else if (pass == 123)
    {
        system("cls");
        int user_in, time, dim, ticket, mov, pay_amount, bank_num, bank_pin;
        printf("\n\nLogin successful\nWelcome\n");
        Sleep(1000);//after 1000 milliseconds, the screen will be clear
        system("cls");
        main_menu:  // primary menu with every function
        system("cls");
        printf("\nFTN CINEPLEX\n");
        printf("Online Movie Ticket Booking Portal\n");
        printf("Type the corresponding number to your requirements\n");
        printf("<1> - Currently Showing Movie List\n");
        printf("<2> - Ticket Booking\n");
        printf("<3> - Upcoming Movie Premiers\n");
        printf("<4> - Movie Request to Re-Screen or Premier\n");
        printf("<5> - Exit\n");
        printf("\nEnter your input = ");
        scanf("%d", &user_in);
        switch (user_in)
        {
        case 1:         //currently showing section
            system("cls");
            menu1:
            printf("\nCurrently Showing - \n");
            cur_mov();
            printf("\nType '0' to return to main menu\n");
            printf("\nType '1' to go to ticket booking \n");
            printf("\nEnter your input = ");
            scanf("%d", &user_in);
            switch (user_in)
            {
            case 0:         //returns to main menu
                goto main_menu;

            case 1:         //switches to ticket booking
                goto menu2;

            default:           //returns to currently showing
                printf("Enter valid number\n");
                goto menu1;
            }
        case 2:             //ticket booking section
            system("cls");
            menu2:
            printf("\nTicket Booking - \n");
            printf("\nType the corresponding movie number to book ticket\n");
            cur_mov();
            printf("\nType '0' to return to main menu \n");
            printf("\nEnter your input = "); //movie selection
            scanf("%d", &mov);
            switch (mov)    //movie selection storing
            {
            case 1:
                goto dim_select_des;

            case 2:
                goto dim_select_des;

            case 3:
                goto dim_select_des;

            case 4:
                goto dim_select_des;

            case 5:
                goto dim_select_des;

            case 0:
                goto main_menu;

            default:
                printf("\nEnter a valid number\n");
                goto menu2;
            }
            dim_select_des:
            system("cls");
            printf("\nWhich dimension would you like to see the movie in?\n"); //descending sort
            printf("\nEnter the corresponding number for the dimension (price sorted in descending order) \n");
            printf("\n<1> - IMAX ------- Rs. 1000/ticket\n");
            printf("\n<2> - 3D   ------- Rs. 500/ticket\n");
            printf("\n<3> - 2D   ------- Rs. 300/ticket\n");
            printf("\nEnter 0 to sort the prices in ascending order\n");
            printf("\nEnter your input = ");
            scanf("%d", &dim);
            if (dim==0)
            {
                dim_select_asc:
                system("cls");
                printf("\nWhich dimension would you like to see the movie in?\n"); //ascending sort
                printf("\nEnter the corresponding number for the dimension (price sorted in ascending order) \n");
                printf("\n<1> - 2D   ------- Rs. 300/ticket\n");
                printf("\n<2> - 3D   ------- Rs. 500/ticket\n");
                printf("\n<3> - IMAX ------- Rs. 1000/ticket\n");
                printf("\nEnter 0 to sort the prices in descending order\n");
                printf("\nEnter your input = ");
                scanf("%d", &dim);
                if (dim==0)
                {
                    goto dim_select_des;
                }
                else if (dim==1)
                {
                    dim=3;
                }
                else if (dim==3)
                {
                    dim = 1;
                }
                if (dim<0 || dim>3 )
                {
                printf("\nEnter a valid input\n");
                goto dim_select_asc;
                }
            }
            if (dim<0 || dim>3 )
            {
                printf("\nEnter a valid input\n");
                goto dim_select_des;
            }
            system("cls");
            printf("\nEnter the corresponding time for the show\n");  //time select
            time_sel();
            printf("\nEnter your input = ");
            scanf("%d", &time);
            system("cls");
            printf("\nEnter the number of tickets for the show = ");  //ticket select
            scanf("%d", &ticket);
            system("cls");
            printf("\nEnter personal information\n"); //personal info
            printf("\nEnter your name = ");
            scanf("%s", &var.u_name);
            printf("\nEnter your phone number = ");
            scanf("%s", &var.u_phone);
            printf("\nEnter your email address = ");
            scanf("%s", &var.u_mail);
            printf("\nEnter your current address = ");
            scanf("%s", &var.u_address);
            if (dim == 1)
            {
                pay_amount = 1000 * ticket;
            }
            else if (dim == 2)
            {
                pay_amount = 500 * ticket;
            }
            else if (dim == 3)
            {
                pay_amount = 300 * ticket;
            }
            printf("\nTotal payable money = %d Rupees\n", pay_amount);
            before_pay:     //going to payment
            printf("\nType 1 to go for payment\n");
            printf("\nType 0 to cancel booking and return to main menu\n");
            printf("\nEnter your input = ");
            scanf("%d", &user_in);
            switch (user_in)
            {
            case 1:
                goto pay;

            case 0:
                goto main_menu;

            default:
                printf("\nEnter a valid number");
                goto before_pay;
            }
            pay:
            system("cls");
            printf("\nAmount to pay = %d Rupees\n", pay_amount);
            printf("\nEnter your mobile banking account number = ");
            scanf("%d", &bank_num);
            printf("\nEnter your account pin number = ");
            scanf("%d", &bank_pin);
            printf("\nTransaction successful\n");
            Sleep(1000);
            printf("\nTicket Booking Confirmed\n");     //booking confirmation
            Sleep(1000);
            system("cls");
            printf("\n\nBooking Details --- \n\n");
            fprintf(fp1,"\n\nBooking Details --- \n\n");
            switch (mov)
            {
            case 1:
                printf("\nMovie Name = %s\n", movie_1);
                fprintf(fp1, "\nMovie Name = %s\n", movie_1);
                break;
            case 2:
                printf("\nMovie Name = %s\n", movie_2);
                fprintf(fp1, "\nMovie Name = %s\n", movie_2);
                break;
            case 3:
                printf("\nMovie Name = %s\n", movie_3);
                fprintf(fp1, "\nMovie Name = %s\n", movie_3);
                break;
            case 4:
                printf("\nMovie Name = %s\n", movie_4);
                fprintf(fp1, "\nMovie Name = %s\n", movie_4);
                break;
            case 5:
                printf("\nMovie Name = %s\n", movie_5);
                fprintf(fp1, "\nMovie Name = %s\n", movie_5);
                break;
            }
            switch (time)
            {
            case 1:
                printf("\nShow Time = %s\n", time_1);
                fprintf(fp1, "\nShow Time = %s\n", time_1);
                break;
            case 2:
                printf("\nShow Time = %s\n", time_2);
                fprintf(fp1, "\nShow Time = %s\n", time_2);
                break;
            case 3:
                printf("\nShow Time = %s\n", time_3);
                fprintf(fp1, "\nShow Time = %s\n", time_3);
                break;
            case 4:
                printf("\nShow Time = %s\n", time_4);
                fprintf(fp1, "\nShow Time = %s\n", time_4);
                break;
            case 5:
                printf("\nShow Time = %s\n", time_5);
                fprintf(fp1, "\nShow Time = %s\n", time_5);
                break;
            case 6:
                printf("\nShow Time = %s\n", time_6);
                fprintf(fp1, "\nShow Time = %s\n", time_6);
                break;
            case 7:
                printf("\nShow Time = %s\n", time_7);
                fprintf(fp1, "\nShow Time = %s\n", time_7);
                break;
            case 8:
                printf("\nShow Time = %s\n", time_8);
                fprintf(fp1, "\nShow Time = %s\n", time_8);
                break;
            }
            switch (dim)
            {
            case 1:
                printf("\nDimension = %s\n", dim_1);
                fprintf(fp1, "\nDimension = %s\n", dim_1);
                break;
            case 2:
                printf("\nDimension = %s\n", dim_2);
                fprintf(fp1, "\nDimension = %s\n", dim_2);
                break;
            case 3:
                printf("\nDimension = %s\n", dim_3);
                fprintf(fp1, "\nDimension = %s\n", dim_3);
                break;
            }
            printf("\nNumber of tickets booked = %d\n", ticket);
            printf("\nTotal paid amount = %d\n", pay_amount);
            printf("\nBooker Name = %s\n", var.u_name);
            printf("\nBooker Phone = %s\n", var.u_phone);
            printf("\nBooker Mail = %s\n", var.u_mail);
            printf("\nBooker Address = %s\n", var.u_address);
            printf("\nHave a great day\n\n");
            fprintf(fp1,"\nNumber of tickets booked = %d\n", ticket);
            fprintf(fp1,"\nTotal paid amount = %d\n", pay_amount);
            fprintf(fp1,"\nBooker Name = %s\n", var.u_name);
            fprintf(fp1,"\nBooker Phone = %s\n", var.u_phone);
            fprintf(fp1,"\nBooker Mail = %s\n", var.u_mail);
            fprintf(fp1,"\nBooker Address = %s\n", var.u_address);
            fprintf(fp1,"\nHave a great day\n\n");
            printf("\nPress any key to return to main menu ");
            getch();
            goto main_menu;

        case 3:             //upcoming movies section
            system("cls");
            menu3:
            printf("\nUpcoming Movie Premiers - \n");
            upc_mov();
            printf("\nType '0' to return to main menu \n");
            printf("\nType '1' to request any movie \n");
            printf("\nEnter your input = ");
            scanf("%d", &user_in);
            switch (user_in)
            {
            case 0:
                goto main_menu;

            case 1:
                goto menu4;

            default:
                printf("Enter valid number\n");
                goto menu3;
            }

        case 4:             //movie request section
            system("cls");
            menu4:
            printf("\nRequest for any movie to re-screen or premier - \n");
            printf("\nType the movie name you want to request = ");
            scanf("%s", request);
            fprintf(fp2,"%s\n", request);
            printf("\nRequest sent\n");
            printf("\nType '0' to return to main menu \n");
            printf("\nType '1' to request more movie \n");
            printf("\nEnter your input = ");
            scanf("%d", &user_in);
            switch (user_in)
            {
            case 0:
                goto main_menu;

            case 1:
                goto menu4;

            default:
                printf("Enter valid number\n");
                goto menu4;
            }

        case 5:
            exit(0);

        default:
            printf("Enter valid number\n");
            goto main_menu;
        }
    }
    return 0;
}

void cur_mov()   //currently showing function
{
    printf("\n<1> - %s", movie_1);
    printf("\n<2> - %s", movie_2);
    printf("\n<3> - %s", movie_3);
    printf("\n<4> - %s", movie_4);
    printf("\n<5> - %s\n", movie_5);
}

void upc_mov()   //upcoming movies function
{
    printf("\n<1> - %s", upmov_1);
    printf("\n<2> - %s", upmov_2);
    printf("\n<3> - %s", upmov_3);
    printf("\n<4> - %s", upmov_4);
    printf("\n<5> - %s\n", upmov_5);
}

void time_sel()   //show time function
{
    printf("\n<1> - %s", time_1);
    printf("\n<2> - %s", time_2);
    printf("\n<3> - %s", time_3);
    printf("\n<4> - %s", time_4);
    printf("\n<5> - %s", time_5);
    printf("\n<6> - %s", time_6);
    printf("\n<7> - %s", time_7);
    printf("\n<8> - %s\n", time_8);
}
