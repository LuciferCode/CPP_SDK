#pragma once
#include <chrono>
#include "time_define.h"

using TimePointS = std::chrono::time_point<std::chrono::system_clock, DURATION_TYPE_SECOND>;

class DateTime
{
public:
	DateTime();
	DateTime(time_t tm);
	DateTime(const TimePointS& tp);
	~DateTime() = default;

	static DateTime MakeDateTime(int year, int month, int day, int hour = 0, int mintue = 0, int second = 0);
	static DateTime Now();

	int operator-(const DateTime& dt) const { return static_cast<int>(this->Timestamp() - dt.Timestamp()); }
	void operator+=(long long seconds) { this->time_point_ += DURATION_TYPE_SECOND(seconds); }
	void operator-=(long long seconds) { this->time_point_ -= DURATION_TYPE_SECOND(seconds); }

	time_t Timestamp() const { return this->time_point_.time_since_epoch().count(); }
	DateTime GetZeroClock() const;
	int GetDiffDays(const DateTime& dt) const;
	bool IsSameDay(const DateTime& dt) const { return !GetDiffDays(dt); }

private:
	static TimePointS Convert(const std::chrono::time_point<std::chrono::system_clock>& tps);

	TimePointS time_point_;
};
