/*   A computer manufacturing company has the following monthly compensation policy to their sales persons:
                Minimum base salary				: 1500.00
                Bonus for every computer sold		: 200.00
                Commission on the total monthly sales	:2%
    Since the prices of computers are changing, the sales price of each computer is fixed at the beginning of every month.
    Given the base salary, bonus and commission rate, write a C program to calculate the Gross salary as per the following equation:

    Gross Salary = base salary + (quantity * bonus) + (quantity * Price) * commission,
    where the Price of each computer and the number sold during the month will be taken from the user as inputs.
*/

#include<stdio.h>

int main()
{
    float base_salary, bonus, commission;
    base_salary = 1500.00;
    bonus= 200.00;
    commission= 0.02;

    int quantity;
    float price;

    printf("\nEnter the Price of each computer sold: ");
    scanf("%f", &price);
    printf("\nEnter the Quantity of computers sold: ");
    scanf("%d", &quantity);


    float gross_salary = base_salary + (quantity*bonus) + (quantity*price)*commission;
    printf("\nGross Salary: %.2f", gross_salary);

    return 0;
}
