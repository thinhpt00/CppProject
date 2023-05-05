#include "date.hpp"

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) return true;
            else return false;
        }
        else return true;
    }
    else return false;
}

Date::Date() : m_Day(1), m_Month(1), m_Year(1900) {}

Date::Date(int day,int month, int year) : m_Day(day), m_Month(month), m_Year(year) {}

Date::~Date(){m_Day = m_Month = m_Year = 0;}

Date Date::operator+(int day){
    Date newDate;
    newDate.m_Year = this->m_Year;
    newDate.m_Month = this->m_Month;
    //newDate.m_Day = this->m_Day;
    day = day + this->m_Day; 
    while(day >= 366){
        if(isLeapYear(newDate.m_Year) == true){
            newDate.m_Year++;
            day = day - 366;
        }
        else{
            newDate.m_Year++;
            day = day - 365;
        }
    }

    while(day >= 31){
        if(newDate.m_Month == 12){
            newDate.m_Year++;
            newDate.m_Month = 1;
            day = day - 31;
        }
        else if((newDate.m_Month) == 2){
            if(isLeapYear(this->m_Year) == true){
                day = day - 29;
                newDate.m_Month++;
            }
            else{
                day = day - 28;
                newDate.m_Month++;
            }
        }
        else if((newDate.m_Month) == 4 || (newDate.m_Month) == 6 || (newDate.m_Month) == 9 || (newDate.m_Month) == 11){
            day = day - 30;
            newDate.m_Month++;
        }
        else {
            day = day - 31;
            newDate.m_Month++;
        }

    }
        
    newDate.m_Day = day;
    
    return newDate;
}

Date Date::operator-(int day){
    Date newDate;
    newDate.m_Year = this->m_Year;
    newDate.m_Month = this->m_Month;

    while(day >= 366){
        if(isLeapYear(newDate.m_Year) == true){
            newDate.m_Year--;
            day = day - 366;
        }
        else{
            newDate.m_Year--;
            day = day - 365;
        }
    }

    while(day >= 31){
        if(newDate.m_Month == 1){
            newDate.m_Year--;
            newDate.m_Month = 12;
            day = day - 31;
        }
        else if((newDate.m_Month) == 2){
            if(isLeapYear(this->m_Year) == true){
                day = day - 29;
                newDate.m_Month--;
            }
            else{
                day = day - 28;
                newDate.m_Month--;
            }
        }
        else if((newDate.m_Month) == 4 || (newDate.m_Month) == 6 || (newDate.m_Month) == 9 || (newDate.m_Month) == 11){
            day = day - 30;
            newDate.m_Month--;
        }
        else {
            day = day - 31;
            newDate.m_Month--;
        }

    }
    
    if(day >= this->m_Day){
        if((newDate.m_Month) == 1){
            newDate.m_Year--;
            newDate.m_Month = 12;
            day = 31 - (day - this->m_Day);
        }
        else if((newDate.m_Month) == 2){
            if(isLeapYear(this->m_Year) == true){
                day = 29 - (day - this->m_Day);
                newDate.m_Month--;
            }
            else{
                day = 28 - (day - this->m_Day);
                newDate.m_Month--;
            }
        }
        else if((newDate.m_Month) == 4 || (newDate.m_Month) == 6 || (newDate.m_Month) == 9 || (newDate.m_Month) == 11){
                day = 30 - (day - this->m_Day);
                newDate.m_Month--;
        }
        else{
                day = 31 - (day - this->m_Day);
                newDate.m_Month--;
        }
    }
    else{
        day = this->m_Day - day;
    }        

    newDate.m_Day = day;
    
    return newDate;
}

Date Date::operator++(){

    if((this->m_Month) == 12){
        if((this->m_Day) == 31){
            this->m_Day = 1;
            this->m_Month = 1;
            this->m_Year++;
        }
    }
    else if((this->m_Month) == 2){
        if((this->m_Day) == 28){
            if(isLeapYear((this->m_Year) == true)){
                this->m_Day++;
            }
            else{
                this->m_Day = 1;
                this->m_Month++;
            }
        }
        else{
            this->m_Day++;
        }
    }
    else if((this->m_Month) == 4 || (this->m_Month) == 6 || (this->m_Month) == 9 || (this->m_Month) == 11){
        if((this->m_Day) == 30){
            this->m_Day = 1;
            this->m_Month++;
        }
        else{
            this->m_Day++;
        }
    }
    else{
        if((this->m_Day) == 31){
            this->m_Day = 1;
            this->m_Month++;
        }
        else{
            this->m_Day++;
        }
    }
    
    return *this;
}

Date Date::operator--(){

    if((this->m_Month) == 1){
        if((this->m_Day) == 1){
            this->m_Day = 31;
            this->m_Month = 12;
            this->m_Year--;
        }
    }
    else if((this->m_Month) == 3){
        if((this->m_Day) == 1){
            if(isLeapYear(this->m_Year) == true){
                this->m_Day = 29;
                this->m_Month--;
            }
            else{
                this->m_Day = 28;
                this->m_Month--;
            }
        }
        else{
            this->m_Day--;
        }
    }
    else if((this->m_Month) == 5 || (this->m_Month) == 7 || (this->m_Month) == 10 || (this->m_Month) == 12){
        if((this->m_Day) == 1){
            this->m_Day = 30;
            this->m_Month--;
        }
        else{
            this->m_Day--;
        }
    }
    else{
        if((this->m_Day) == 1){
            this->m_Day = 31;
            this->m_Month--;
        }
        else{
            this->m_Day--;
        }
    }
    
    return *this;
}

bool operator<(Date& date1, Date& date2){
    if(date1.m_Year == date2.m_Year){
        if(date1.m_Month == date2.m_Month){
            if(date1.m_Day == date2.m_Day){
                return false;
            }
            else if(date1.m_Day < date2.m_Day) return true;
            else return false;
        }
        else if(date1.m_Month < date2.m_Month){
            return true;
        }
        else return false;
    }
    else if(date1.m_Year < date2.m_Year){
        return true;
    }
    else{
        return false;
    }
}

int Date::operator-(Date& date1){
    int count = 0;
    Date temp = *this;
    while(temp < date1){
        temp = temp + 1;
        count++;
    }
    while(date1 < temp){
        date1 = date1 + 1;
        count++;
    }

    return count;
}

std::istream& operator>>(std::istream& in, Date& date){
    in >> date.m_Day >> date.m_Month >> date.m_Year;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Date& date){
    out << date.m_Day << "-" << date.m_Month << "-" << date.m_Year;
    return out;
}