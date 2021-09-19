/*  Write a program in C which accepts retail price of a good and calculates the price to be displayed on the product
    and a discounted price for the customer.

    The seller wants to keep 15% profit over the retail price and wants that a 5% discount is given to the customer.

    Then calculate and print the price that will be displayed on the product and the discounted price that the customer has to pay
*/

#include<stdio.h>

int main()
{
    float retail_price, display, discount, discounted_price;

    printf("Enter the Retail Price: ");
    scanf("%f", &retail_price);

    display = retail_price + (15.0/100)*retail_price;
    discount = (5.0/100)*display;
    discounted_price = display;
    display = display + discount;

 // printf("\nRetail price :     %.2f \n", retail_price);
    printf("\nDisplay price:     %.2f \n", display);
 // printf("Discount:          %.2f \n", discount);
    printf("\nDiscounted price:  %.2f \n", discounted_price);

    return 0;
}
