#include <stdio.h>
#include <math.h>

double sum();
double diff();
double product();
double quotient();
float loop();

int main()
{
    char cont="Yes";
    while (cont=="Yes" || cont=="yes" || cont=="YES")
    {
        loop();
    }

}

float loop()
{
    int input,x=0;
    char cont="Yes";   
        printf("Welcome.\nWhat would you like to do today:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
        while (x==0)
        {
            printf("Please enter the number of the action you'd li1ke to perform:");
            scanf("%d",&input);
            if ((input<6 && input>0))
            {
                if (input==1)
                {   
                    sum();
                    x++;
                } 
                else if (input==2)
                {
                    diff();
                    x++;
                }
                else if (input=3)
                {
                    product();
                    x++;
                }
                else if (input=4)
                {
                    quotient();
                    x++;
                }
                
            }
            else
            {
                printf("Please enter a valid option.");
            }
    
        printf("\nWould you like to continue(Yes/No): ");
        scanf("%s",&cont);
        }      
}

double sum()
{
    int n,x=0;
    double add=0;
    printf("How many numbers would you like to enter: ");
    scanf("%d",&n);
    while (x<n)
    {   
        double n1;
        printf("Enter the number: ");
        scanf("%lf",&n1);
        add=add+n1;
        x++;
    }
    printf("The answer is %.2f",add);
}

double diff()
{
    int n,x;
    double sub=0;
    printf("How many numbers would you like to enter: ");
    scanf("%d",&n);
    for (x=0;x<n;x++)
    {   
        double n1;
        printf("Enter the number: ");
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
    printf("How many numbers would you like to enter: ");
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
    printf("Division is only allowed for two digits.");
    printf("Enter your dividend: ");
    scanf("%lf",&n1);
    printf("Enter your second divisor: ");
    scanf("%lf",&n2);
    quo=n1/n2;  
    printf("The answer is %.2f",quo);
}
