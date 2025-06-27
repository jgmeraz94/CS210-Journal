#ifndef CLOCK_H
#define CLOCK_H

#include <string>

// Clock class to manage time and display in 12-hour and 24-hour formats
class Clock {
private:
    unsigned int hour;
    unsigned int minute;
    unsigned int second;

    // Helper: returns a two-digit string representation of a number
    std::string twoDigitString(unsigned int n) const;

public:
    Clock();

    // Getters and setters for time components
    unsigned int getHour() const;
    void setHour(unsigned int h);
    unsigned int getMinute() const;
    void setMinute(unsigned int m);
    unsigned int getSecond() const;
    void setSecond(unsigned int s);

    // Increment time by one hour, minute, or second
    void addOneHour();
    void addOneMinute();
    void addOneSecond();

    // Return formatted time strings
    std::string formatTime24() const;
    std::string formatTime12() const;
};

#endif
