#pragma once

#define DURATION_TYPE_NANOSECOND	std::chrono::nanoseconds
#define DURATION_TYPE_MICROSECOND	std::chrono::microseconds
#define DURATION_TYPE_MILLISECOND		std::chrono::milliseconds
#define DURATION_TYPE_SECOND				std::chrono::seconds
#define DURATION_TYPE_MINUTE				std::chrono::minutes
#define DURATION_TYPE_HOUR					std::chrono::hours
#define DURATION_TYPE_DAY						std::chrono::duration<int, std::ratio<3600*24>>
#define DURATION_TYPE_WEEK					std::chrono::duration<int, std::ratio<3600*24*7>>
