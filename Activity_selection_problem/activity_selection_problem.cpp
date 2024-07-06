/*

Author: Aditya Upadhye

*/ 


#include <iostream>
#include <map>
#include <vector>


bool check_start_time(const int& start_time)
{

	if (start_time < 0)
		return false;
	else 
		return true;
}


bool check_finish_time(const int& start_time, const int& finish_time)
{

	if (finish_time <= start_time)
		return false;
	else 
		return true;

}


void activity_selector(const std::multimap<int, int>& act_list,const std::multimap<int, int>& act_count)
{


	std::vector<int> selected_activities;

	int prev_ft = act_list.begin() -> second;

	auto itr_act_count = act_count.begin();

	for (auto key: act_list)
	{

		if (key.second >= prev_ft)
		{

			selected_activities.push_back(itr_act_count -> second);
			prev_ft = key.first;
		}


		itr_act_count++; 
        }

	if (selected_activities.size())
		std::cout << "The following activities will be selected: " << std::endl;

	for (auto& no : selected_activities)
	{
		std::cout << no << " ";

	}
	std::cout << std::endl;

}


int main()
{

	std::multimap<int, int> activity_list;
	std::multimap<int, int> activity_no;

	int act_count = 0;

	std::cout << "Enter the no of activities: " << std::endl;
	std::cin >> act_count;
	int act_no = 1;

	while (act_count)
	{

		int start_time = -1;
		int finish_time = -1;

		std::cout << "Enter the start time: " << std::endl;
		std::cin >> start_time;

		while (!check_start_time(start_time))
		{

			std::cout << "Enter a valid start time: " << std::endl;
			std::cin >> start_time;

		}


		while (!check_finish_time(start_time, finish_time))
		{

			std::cout << "Enter a valid finish time: " << std::endl;
			std::cin >> finish_time;

		}

		activity_list.insert({finish_time, start_time});
		activity_no.insert({finish_time, act_no});
		act_count--;
		++act_no;

	}

	activity_selector(activity_list, activity_no);

	return 0;

}
