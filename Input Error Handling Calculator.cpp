#include<iostream>
#include<cstdlib>
#include<limits>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{
    if(!std::cin)
    {
        if(std::cin.eof())
        {
            std::exit(0);
        }

        std::cin.clear();
        ignoreLine();

        return true;
    }
    return false;
}

double getDouble()
{
    while(true)
    {
        double num {};
        std::cout << "Enter a decimal number: " << std::endl;
        std::cin >> num;

        if(clearFailedExtraction())
        {
            std::cout << "Oops, that input is invalid. Please try again" << std::endl;
            continue;
        }
        ignoreLine();
        return num;
    }
}

char getOperator()
{
    while(true)
    {
        char operation {};
        std::cout << "Enter one of the following: (+, -, *, /): " << std::endl;
        std::cin >> operation;
        
        if(!clearFailedExtraction())
        {
            ignoreLine();
        }

        switch(operation)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            return operation;

            default:
                std::cout << "Oops, that input is invalid. Please try again." << std::endl;
        }
    }
}

void printResult(double x, char operation, double y)
{
    std::cout << x << " " << operation << " " << y << " is " << std::endl;

    switch(operation)
    {
        case '+':
        {
            std::cout << x + y << '\n' << std::endl;
            return;
        }

        case '-':
        {
            std::cout << x - y << '\n' << std::endl;
            return;
        }

        case '*':
        {
            std::cout << x * y << '\n' << std::endl;
            return;
        }

        case '/':
        {
            if(y == 0.0)
            {
                break;
            }

            std::cout << x / y << '\n' << std::endl;
            return;
        }
    }
    std::cout << "????" << std::endl;
}

int main()
{
    double x {getDouble()};
    char operation {getOperator()};
    double y {getDouble()};

    while(operation == '/' && y == 0.0)
    {
        std::cout << "The denominator cannot be zero. Try Again" << std::endl;
        y = getDouble();
    }
    printResult(x, operation, y);

    return 0;
}