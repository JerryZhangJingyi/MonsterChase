#include "JobSystem.h"

template <typename T, size_t capacity> class ThreadBuffer
{
public:
	//Push item
	bool push_back(const T& item)
	{
		bool result = false;
		lock.lock();
		size_t next = (head + 1) % capacity;
		if (next != tail)
		{
			data[head] = item;
			head = next;
			result = true;
		}
		lock.unlock();
		return result;
	}

	//Get item
	bool pop_front(T& item)
	{
		bool result = false;
		lock.lock();
		if (tail != head)
		{
			item = data[tail];
			tail = (tail + 1) % capacity;
			result = true;
		}
		lock.unlock();
		return result;
	}

private:
	T data[capacity];
	size_t head = 0;
	size_t tail = 0;
	std::mutex lock;
};

namespace _JobSystem
{
	uint32_t numThreads = 0;    
	ThreadBuffer<std::function<void()>, 256> jobPool;
	std::condition_variable wakeCondition;
	std::mutex wakeMutex;
	uint64_t currentLabel = 0;
	std::atomic<uint64_t> finishedLabel;

	void Initialize()
	{
		finishedLabel.store(0);
		auto numCores = std::thread::hardware_concurrency();

		numThreads = std::max(1u, numCores);

		for (uint32_t threadID = 0; threadID < numThreads; ++threadID)
		{
			std::thread worker([] {

				std::function<void()> job; 
				while (true)
				{
					if (jobPool.pop_front(job))
					{
						//execute job
						job(); 
						finishedLabel.fetch_add(1); 
					}
					else
					{
						std::unique_lock<std::mutex> lock(wakeMutex);
						wakeCondition.wait(lock);
					}
				}

				});

			worker.detach(); 
		}
	}

	void poll()
	{
		wakeCondition.notify_one(); 
		std::this_thread::yield();
	}

	void Execute(const std::function<void()>& job)
	{
		currentLabel += 1;

		while (!jobPool.push_back(job)) { poll(); }

		wakeCondition.notify_one(); // wake one thread
	}

	bool IsBusy()
	{
		return finishedLabel.load() < currentLabel;
	}

	void Wait()
	{
		while (IsBusy()) { poll(); }
	}

}

