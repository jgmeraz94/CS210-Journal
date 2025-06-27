#include "Clock.h"
#include <string>

using namespace std;

// Initialize time to 00:00:00
Clock::Clock() : hour(0), minute(0), second(0) {}

// Returns a string formatted as two digits, e.g. "07"
std::string Clock::twoDigitString(unsigned int n) const {
    if (n < 10) {
        return "0" + to_string(n);
    }
    return to_string(n);
}

// Getters and setters
unsigned int Clock::getHour() const { return hour; }
void Clock::setHour(unsigned int h) { hour = h; }
unsigned int Clock::getMinute() const { return minute; }
void Clock::setMinute(unsigned int m) { minute = m; }
unsigned int Clock::getSecond() const { return second; }
void Clock::setSecond(unsigned int s) { second = s; }

// Increment hour, wrapping at 24
void Clock::addOneHour() {
    hour = (hour + 1) % 24;
}

// Increment minute, wrapping at 60 and incrementing hour
void Clock::addOneMinute() {
    if (minute < 59) {
        minute++;
    }
    else {
        minute = 0;
        addOneHour();
    }
}

// Increment second, wrapping at 60 and incrementing minute
void Clock::addOneSecond() {
    if (second < 59) {
        second++;
    }
    else {
        second = 0;
        addOneMinute();
    }
}

// Format time as 24-hour string "HH:MM:SS"
std::string Clock::formatTime24() const {
    return twoDigitString(hour) + ":" + twoDigitString(minute) + ":" + twoDigitString(second);
}

// Format time as 12-hour string "HH:MM:SS A M/P M"
std::string Clock::formatTime12() const {
    string period = (hour >= 12) ? " P M" : " A M";
    unsigned int hour12 = hour % 12;
    if (hour12 == 0) hour12 = 12;
    return twoDigitString(hour12) + ":" + twoDigitString(minute) + ":" + twoDigitString(second) + period;
}
