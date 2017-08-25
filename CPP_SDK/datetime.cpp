#include "datetime.h"

DateTime::DateTime()
{
	this->time_point_ = DateTime::Convert(std::chrono::system_clock::from_time_t(0));
}

DateTime::DateTime(time_t tm)
{
	this->time_point_ = DateTime::Convert(std::chrono::system_clock::from_time_t(tm));
}

DateTime::DateTime(const TimePointS& tp)
{
	this->time_point_ = tp;
}

DateTime DateTime::Now()
{
	return DateTime::Convert(std::chrono::system_clock::now());
}

DateTime DateTime::MakeDateTime(int year, int month, int day, int hour, int mintue, int second)
{
	tm time_map;
	time_map.tm_year = year - 1900;
	time_map.tm_mon = month - 1;
	time_map.tm_mday = day;
	time_map.tm_hour = hour;
	time_map.tm_min = mintue;
	time_map.tm_sec = second;
	return Convert(std::chrono::system_clock::from_time_t(mktime(&time_map)));
}

TimePointS DateTime::Convert(const std::chrono::time_point<std::chrono::system_clock>& tps)
{
	return std::move(std::chrono::time_point_cast<DURATION_TYPE_SECOND>(tps));
}

DateTime DateTime::GetZeroClock() const
{
	time_t tt = this->Timestamp();
	tm tm_temp;
#ifdef _WIN32
	localtime_s(&tm_temp, &tt);
#else
	localtime_r(&tt, &tm_temp);
#endif
	tm_temp.tm_sec = 0;
	tm_temp.tm_min = 0;
	tm_temp.tm_hour = 0;
	return mktime(&tm_temp);
}

int DateTime::GetDiffDays(const DateTime& dt) const
{
	return static_cast<int>(abs(this->GetZeroClock().Timestamp() - dt.GetZeroClock().Timestamp()) / (3600 * 24));
}