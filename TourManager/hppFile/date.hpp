#ifndef _Date_H
#define _Date_H
//#pragma once

#include<iostream>
#include<string>
using namespace std;

bool isLeapYear(int year);

class Date{
private:
    int m_Day,m_Month,m_Year;
public:
    Date();

    Date(int day, int month, int year);

    ~Date();

    Date operator+(int day);

    Date operator-(int day);

    Date operator++();

    Date operator--();

    friend bool operator<(Date& date1, Date& date2);

    int operator - (Date& date1);

    friend std::istream& operator>>(std::istream& in, Date& date);

    friend std::ostream& operator<<(std::ostream& out, const Date& date);
};


#endif