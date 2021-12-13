#include <iostream>
#include <future>
#include <mutex>

std::mutex cout_mutex;




unsigned int getThreadId()
{
	static std::mutex mutex_t;
	static unsigned int number = 0;
	thread_local unsigned int threadID = [&]() {std::lock_guard<std::mutex> lock(mutex_t);	return ++number; }();							// przyjmuje wartość "mutex" na czas działania lambdy, a potem jest zwalniany
																																			//  Zamek std::lock_guard<std::mutex> lock(cout_mutex mut) zajmuje mutex_zmienna w swoim konstruktorze,
																																			//  a zwalnia go w destruktorze.
	return threadID;
}




void func_1(std::string x)
{
	std::lock_guard<std::mutex> lock(cout_mutex);
	std::cout << getThreadId() << " " << x << "\n"; // wypisuje wygenerowane ID wątku i string
}




int func_2_async(std::launch async, unsigned int numberOfCalls)
{
	if (numberOfCalls > 0)
	{
		auto x = std::async(async, func_2_async, async, --numberOfCalls);
		x.get();
	}

	func_1 ("watek");
	return 0;
}




int main()
{
	//TEST DZIAŁANIA FUNKCJI Z POLITYKAMI std::launch::async i std::launch::deferred

	std::cout << "std::launch::async: \n";
	std::async(std::launch::async, func_2_async, std::launch::async, 5);


	std::cout << "\n std::launch::deferred: \n";
	auto x = std::async(std::launch::async, func_2_async, std::launch::deferred, 5);	
}

