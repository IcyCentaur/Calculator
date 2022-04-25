#include <stdio.h>
#include <math.h>

double sum();
double diff();
double product();
double quotient();
float loop();

int main()
{
    loop();
}

float loop()
{
    int input,x=0;
        printf("Welcome.\nWhat would you like to do today:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit");
        while (x==0)
        {
            printf("\nPlease enter the number of the action you'd like to perform:");
            scanf("%d",&input);
            if ((input<6 && input>0))
            {
                if (input==1)
                {   
                    sum();
                } 
                else if (input==2)
                {
                    diff();
                }
                else if (input==3)
                {
                    product();
                }
                else if (input==4)
                {
                    quotient();
                }
                else if (input==5)
                    break;
            }
            else
            {
                printf("\nPlease enter a valid option.");
            }
        }      
}

double sum()
{
    int n,x=0;
    double add=0;
    printf("\nHow many numbers would you like to enter: ");
    scanf("%d",&n);
    while (x<n)
    {   
        double n1;
        printf("\nEnter the number: ");
        scanf("%lf",&n1);
        add=add+n1;
        x++;
    }
    printf("\nThe answer is %.2f",add);
}

double diff()
{
    int n,x;
    double sub=0;
    printf("\nHow many numbers would you like to enter: ");
    scanf("%d",&n);
    for (x=0;x<n;x++)
    {   
        double n1;
        printf("\nEnter the number: ");
        scanf("%lf",&n1);
        if (x==0)
        {
            sub=n1;
        }
        else 
        {
            sub=sub-n1;
        }
    }
    printf("The answer is %.2f",sub);
}

double product()
{
    int n,x=0;
    double prod=1;
    printf("\nHow many numbers would you like to enter: ");
    scanf("%d",&n);
    while (x<n)
    {   
        double n1;
        printf("Enter the number: ");
        scanf("%lf",&n1);
        prod=prod*n1;
        x++;
    }
    printf("The answer is %.2f",prod);
}

double quotient()
{
    double n1,n2,quo;
    printf("\nDivision is only allowed for two digits.");
    printf("\nEnter your dividend: ");
    scanf("%lf",&n1);
    printf("\nEnter your second divisor: ");
    scanf("%lf",&n2);
    quo=n1/n2;  
    printf("The answer is %.2f",quo);
}
