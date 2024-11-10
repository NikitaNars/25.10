#include <iostream>


bool isLeapYear(int year) {
   
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int daysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year))
        {
            return 29;
        }
        return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30; 
    }
    return 31; 
}


int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    
    int totalDays1 = 0;
    int totalDays2 = 0;


    for (int year = 0; year < year1; year++) {

        if (isLeapYear(year))
        {
            totalDays1 += 366;
        }
        else
        {
            totalDays1 += 365;
        }
    }

    for (int month = 1; month < month1; month++) {
        totalDays1 += daysInMonth(month, year1); 
    }

    totalDays1 += day1; 

  
    for (int year = 0; year < year2; year++) {
        
        if (isLeapYear(year))
        {
            totalDays2 += 366;
        }
        else
        {
            totalDays2 += 365;
        }
    }

    for (int month = 1; month < month2; month++) {
        totalDays2 += daysInMonth(month, year2); 
    }

    totalDays2 += day2;

   
    return abs(totalDays2 - totalDays1);
}

float arrAvg(int arr[], int size)
{
    float avg = 0;
    for (int i = 0; i < size; i++)
    {
        avg += arr[i];
    }
    return avg / size;
}

void ZeroPlusMinus(int arr[], int size)
{
    int plus = 0, minus = 0, zero = 0;

    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            plus += 1;
        }
        else if (arr[i] < 0)
        {
            minus += 1;
        }
        else
        {
            zero += 1;
        }
    }
    std::cout << "Положительных: " << plus << " Отрицательных: " << minus << " Нулевых: " << zero;
}


int main() {
  
    setlocale(LC_ALL, "ru");
    int day1 = 15, month1 = 5, year1 = 2020;
    int day2 = 25, month2 = 7, year2 = 2021;

    int difference = daysBetweenDates(day1, month1, year1, day2, month2, year2);
    std::cout << "Разность в днях между датами: " << difference << " дней.\n";

    const int size = 4;
    int arr[4]{1, 2, 3, -1};
    std::cout << arrAvg(arr, size) << "\n";
    ZeroPlusMinus(arr, size);


    return 0;
}

