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

#ifndef UTILS4CPP_DATETIME_TIME_HPP
#define UTILS4CPP_DATETIME_TIME_HPP

#include <cstdint>
#include <string>

#include "utils4cpp/core/Core.hpp"
#include "utils4cpp/datetime/DateTimeGlobal.hpp"

namespace utils4cpp {
namespace datetime {

/*!
	\class Time
    \since v0.0

	\brief Defines a Time class.
*/
class UTILS4CPP_EXPORT Time
{
    using milliseconds_t = std::int32_t;

public:
    Time();
    Time(milliseconds_t msecs, int dst = -1);
    Time(int h, int m, int s, int ms = 0, int dst = -1);

    bool isNull() const;
    bool isValid() const;
    static bool isValid(milliseconds_t msecs);
    static bool isValid(int h, int m, int s, int ms = 0);

    int hour() const;
    int minute() const;
    int second() const;
    int msec() const;
    bool setTime(int h, int m, int s, int ms = 0, int dst = -1);

    Time addSecs(int secs) const;
    int secsTo(const Time& t) const;
    Time addMSecs(milliseconds_t ms) const;
    int msecsTo(const Time& t) const;

    std::string toString(const char* format) const;
    std::wstring toWString(const wchar_t* format) const;
    std::string sprintfTime(const char* format) const;
    std::wstring sprintfTime(const wchar_t* format) const;

    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator< (const Time& other) const;
    bool operator<=(const Time& other) const;
    bool operator> (const Time& other) const;
    bool operator>=(const Time& other) const;
    bool isDstFlagEqual(const Time& other) const;

    static Time fromMilliseconds(milliseconds_t ms, int dst = -1);
    milliseconds_t toMilliseconds() const;

    static Time currentLocalTime();
    static Time currentGmTime();

private:
    enum { NullTime = -1 };

    milliseconds_t  m_msecs;
    int             m_isdst;
};

} // namespace datetime
} // namespace utils4cpp

#endif // UTILS4CPP_DATETIME_TIME_HPP