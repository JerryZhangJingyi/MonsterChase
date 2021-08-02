#pragma once
#include <algorithm>
#include <atomic> 
#include <thread>
#include <condition_variable>   
#include <sstream>
#include <assert.h>
#include <functional>


namespace _JobSystem
{
	//create worker thread
	void Initialize();

	//add a job
	void Execute(const std::function<void()>& job);

	//check thread
	bool IsBusy();

	//wait for thread
	void Wait();
}
