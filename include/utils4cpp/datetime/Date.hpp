/************************************************************************************
**
**  BSD 3-Clause License
**
**  Copyright (c) 2019, shaoguang. All rights reserved.
**
**  Redistribution and use in source and binary forms, with or without
**  modification, are permitted provided that the following conditions are met:
**
**  1. Redistributions of source code must retain the above copyright notice, this
**     list of conditions and the following disclaimer.
**
**  2. Redistributions in binary form must reproduce the above copyright notice,
**     this list of conditions and the following disclaimer in the documentation
**     and/or other materials provided with the distribution.
**
**  3. Neither the name of the copyright holder nor the names of its
**     contributors may be used to endorse or promote products derived from
**     this software without specific prior written permission.
**
**  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
**  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
**  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
**  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
**  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
**  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
**  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
**  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
**  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
************************************************************************************/

#ifndef UTILS4CPP_DATETIME_DATE_HPP
#define UTILS4CPP_DATETIME_DATE_HPP

#include <cstdint>
#include <ctime>
#include <iostream>

#include "utils4cpp/core/Core.hpp"
#include "utils4cpp/datetime/DateTimeGlobal.hpp"

namespace utils4cpp {
namespace datetime {

/*!
    \class Date
    \since v0.0

    \brief The Date class provides date functions.
*/
class UTILS4CPP_EXPORT Date
{
    /*! Structure holding a calendar date broken down into its components. */
    struct dt 
    {
        int mday;               //!< day of the month - [1, 31]
        int mon;                //!< month of the year now - [1, 12]
        int year;               //!< year now
        int wday;               //!< weekday (Monday to Sunday) - [1, 7]
        int yday;               //!< days since January 1 - [0, 365]
        int isdst;              //!< daylight savings time flag. The value is positive if DST is in effect, zero if not and negative if no information is available.
    };
    dt m_dt;

public:

public:
    Date();
    Date(int y, int m, int d, int dst = -1);
    Date(const std::tm& tm);

    int year() const;
    int month() const;
    int day() const;
    int dst() const;
    int dayOfWeek() const;
    int dayOfYear() const;
    int daysInMonth() const;
    int daysInYear() const;

    bool isValid() const;
    bool setDate(int year, int month, int day, int isdst = -1);
    void getDate(int& year, int& month, int& day) const;

    void fromTm(const std::tm& tm);
    std::tm toTm();

    std::int64_t toJulianDay() const;
    static Date fromJulianDay(std::int64_t julianDay);
    std::int64_t daysTo(const Date& d) const;

    Date addDays(std::int64_t days) const;
    Date addMonths(int months) const;
    Date addYears(int years) const;
	
	std::string toString(const char* format);
    std::wstring toWString(const wchar_t* format);
    std::string toString(DateFormat format = TextDate) const;
    std::wstring toWString(DateFormat format = TextDate) const;

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator< (const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator> (const Date& other) const;
    bool operator>=(const Date& other) const;
    bool isDstFlagSameTo(const Date& other) const;

    static bool is31Days(int month);
    static bool is30Days(int month);
    static bool isValid(int year, int month, int day);
    static bool isLeapYear(int year);
    static bool beforGregorianCalendar(int year, int month, int day);
    static bool beforGregorianCalendar(const Date& d);
    static int dayOfYear(int year, int month, int day);
    static int dayOfWeek(int year, int month, int day);

    static Date currentLocalDate();
    static Date currentGmDate();

    friend UTILS4CPP_EXPORT std::ostream& operator<<(std::ostream& os, const Date& date);
private:
    void makeInvalid();

    enum Month {
        Jan = 1,                //!< January
        Feb,                    //!< February
        Mar,                    //!< March
        Apr,                    //!< April
        May,                    //!< May
        June,                   //!< June
        July,                   //!< July
        Aug,                    //!< August
        Sept,                   //!< September
        Oct,                    //!< October
        Nov,                    //!< November  
        Dec                     //!< December
    };
};

} // namespace datetime
} // namespace utils4cpp

#endif // UTILS4CPP_DATETIME_DATE_HPP