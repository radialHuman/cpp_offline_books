//
// Created by RAHULDAMANI on 25-07-2019.
//

#ifndef TRY2_COMMON_FUNCTIONS_H
#define TRY2_COMMON_FUNCTIONS_H



// printing out anything made easy
void print(std::string s)
{
    std::cout << s << std::endl;
}

// comparision function for descending sort
bool desc(double x, double y)
{
    return x>y;
}

// template to find maximum of two elements
template <class T>
T max(const T& x, const T& y)
{
    if(x>y)
        return(x);
    else
        return(y);
}

// class for date
class Date
{
private:
    int date,month,year;
public:
    Date(int x, int y, int z)
        :date(x), month(y), year(z)
    {
        std::cout<< "The date today is :" <<date << "/" << month << "/" << year << std::endl;
    }

};


#endif //TRY2_COMMON_FUNCTIONS_H
