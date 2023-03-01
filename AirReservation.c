
// this is air ticket reservation system///

#include <stdio.h>
int main()
{
    int seat[10][4], x[10][4];
    int i, j, q = 1, choice;
    int a, b, c, d;
    int fare = 0;
    int bs = 0, e = 0; // bs for bussiness class and e for economy class counter

    // giving seat numbersss

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 4; j++)
        {
            x[i][j] = seat[i][j] = q;
            q++;
        }
    }

    // show available seats

available:
    printf("Available seats are Following\n");
    for (c = 0; c < 10; c++)
    {
        for (d = 0; d < 4; d++)
        {
            if (seat[c][d] != 0)
            {
                printf("%7d", seat[c][d]);
            }
            else
            {
                printf(" Booked");
            }
        }
        printf("\n");

    }
    printf("**********************************************************************\n");

    // take user choice

    printf("Enter seat Number you want to book\n");
    printf("1st and Last Row is Window seat\n");
    printf("Seat 1 to 25 are Economy  Class\nSeat 26 to 40 are Bussiness Class\n");
    printf("Enter 200 to exit\n");
    scanf("%d", &choice);

    if (choice != 200)
    {
        for (a = 0; a < 10; a++)
        {

            for (b = 0; b < 4; b++)
            {
                if (choice == seat[a][b] && seat[a][b] != 0)
                {
                    printf("Seat number %d has been Booked for you\n", seat[a][b]);
                    if (choice >= 1 || choice <= 25)
                    {
                        if (seat[a][b] % 4 == 0 || seat[a][b] % 4 == 1)
                        {
                            fare += 25000;
                            e++;
                        }
                        else
                        {
                            fare += 20000;
                            bs++;
                        }
                    }
                    if (choice >= 26 || choice <= 40)
                    {
                        if (seat[a][b] % 4 == 0 || seat[a][b] % 4 == 1)
                        {
                            fare += 45000;
                        }
                        else
                        {
                            fare += 40000;
                        }
                    }
                    seat[a][b] = 0;
                    break;
                }

                if (choice == x[a][b] && seat[a][b] == 0)
                {
                    printf("This seat is already booked\n");
                    break;
                }
            }
        }
        goto available;
    }
    else
    {
        goto end;
    }

end:
    printf("**********************************************************************\n");
    printf("You booked %d Economy class Tickets\n", e);
    printf("You booked %d Bussiness class Tickets\n", bs);
    printf("Total Fare is %d\n", fare);
    getchar();
    return 0;
}