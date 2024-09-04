#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y);
    void display() const;
};

#endif
