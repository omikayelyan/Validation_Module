#include <iostream>
#include <string>
#include <regex>

std::string ValidEmail(const std::string&);
bool ValidDate(int, int, int);
bool LeapYear(int);
bool MobileValid(std::string);
bool ValidURL(std::string);
bool ValidCard(long int);
void validation();

std::string ValidEmail(const std::string& email)
{
    const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if (regex_match(email, pattern))
    {
       return "Valid Email";
    }
    else
    {
        return "Invalid Email";
    }
}

bool LeapYear(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool ValidDate(int day, int month, int year)
{
    const int maxYear = 2022;
    const int minYear = 1800;
    if (year < minYear || year > maxYear)
    {
        return false;
    }
    if (day < 1 || day > 31)
    {
        return false;
    }
    if (month < 1 || month > 12)
    {
        return false;
    }
    if (month == 2)
    {
        if (LeapYear(year))
        {
            return (day <= 29);
        }
        else
        {
            return (day <= 28);
        }
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return (day <= 30);
    }
    return true;
}

bool MobileValid(std::string number)
{
    const std::regex pattern("(091|099|096|043|033|079|055|095|041|044|066|050|093|094|077|098|049|022)?[0-9]{6}");
    if (regex_match(number, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ValidURL(std::string url)
{
    const std::regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
    if (regex_match(url, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getNumber(int number)
{
    if (number < 9)
    {
        return number;
    }
    else
    {
        return number / 10 + number % 10;
    }
}

int getSize(long size)
{
    std::string num = std::to_string(size);
    return num.size();
}

long getPrefix(long number, int k)
{
    if (getSize(number) > k)
    {
        std::string num = std::to_string(number);
        return std::stol(num.substr(0, k));
    }
    return number;
}

bool prefixMatched(long number, int n)
{
    return getPrefix(number, getSize(n)) == n;
}

int sumOfEven(long number)
{
    int sum = 0;
    std::string num = std::to_string(number);
    for (int i = getSize(number) - 2; i >= 0; i -= 2)
    {
        sum += getNumber(int(num[i] - '0') * 2);
    }
    return sum;
}

int sumOfOdd(long number)
{
    int sum = 0;
    std::string num = std::to_string(number);
    for (int i = getSize(number) - 1; i >= 0; i -= 2)
    {
        sum += num[i] - '0';
    }
    return sum;
}

bool ValidCard(long number)
{
    return (getSize(number) >= 13 && getSize(number) <= 16) &&
	(prefixMatched(number, 4) || prefixMatched(number, 5) ||
	prefixMatched(number, 37) || prefixMatched(number, 6)) &&
	((sumOfEven(number) + sumOfOdd(number)) % 10 == 0);
}

void validation()
{
    std::string email;
    std::cout << "Enter your email address: ";
    std::cin >> email;
    std::cout << ValidEmail(email) << std::endl;
    int day;
    int month;
    int year;
    std::cout << "Day: ";
    std::cin >> day;
    std::cout << "Month: ";
    std::cin >> month;
    std::cout << "Year: ";
    std::cin >> year;
    if (ValidDate(day, month, year))
    {
        std::cout << "Valid date" << std::endl;
    }
    else
    {
        std::cout << "Invalid date" << std::endl;
    }
    std::string mobile;
    std::cout << "Enter your mobile number: ";
    std::cin >> mobile;
    if (MobileValid(mobile))
    {
        std::cout << "Valid mobile number" << std::endl;
    }
    else
    {
        std::cout << "Invalid mobile number" << std::endl;
    }
    std::string link;
    std::cout << "Enter yout website link:";
    std::cin >> link;
    if (ValidURL(link))
    {
        std::cout << "Valid URL" << std::endl;
    }
    else
    {
        std::cout << "Invalid URL" << std::endl;
    }
    long card;
    std::cout << "Enter yout card number: ";
    std::cin >> card;
    if (ValidCard(card))
    {
        std::cout << "Valid Card Number" << std::endl;
    }
    else
    {
        std::cout << "Invalid Card Number" << std::endl;
    }
}

int main()
{
    validation();
}