#pragma once
#include <chrono>
#include "time_define.h"

template<typename DurationType = DURATION_TYPE_SECOND>
class Stopwatch
{
public:
	Stopwatch() = default;
	~Stopwatch() = default;

	void Start()
	{
		this->Reset();
		this->is_running_ = true;
	}

	long long Stop()
	{
		this->elapsed_ = std::chrono::duration_cast<DurationType>(std::chrono::steady_clock::now() - this->time_point_).count();
		this->is_running_ = false;
		return this->Elapsed();
	}

	long long Seek() const
	{
		return this->is_running_ ? std::chrono::duration_cast<DurationType>(std::chrono::steady_clock::now() - this->time_point_).count() : 0;
	}

	long long Restart()
	{
		long long elapsed = this->Seek();
		this->Start();
		return elapsed;
	}

	void Reset()
	{
		this->is_running_ = false;
		this->elapsed_ = 0;
		this->time_point_ = std::chrono::steady_clock::now();
	}

	long long Elapsed() const
	{
		return this->is_running_ ? 0 : this->elapsed_;
	}

	bool IsRunning() const { return this->is_running_; }

private:
	bool is_running_{ false };
	std::chrono::time_point<std::chrono::steady_clock> time_point_{ std::chrono::steady_clock::now() };
	long long elapsed_{ 0 };
};

