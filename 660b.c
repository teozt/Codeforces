#include <stack>
#include <vector>
#include <iostream>
#include <utility>

int main() {
	std::vector<std::pair<std::stack<unsigned>,std::stack<unsigned>>> seats;

	unsigned row;
	unsigned passengers;

	std::cin >> row >> passengers;
	
	if (passengers<=row) {
		for (auto i=1u; i<=passengers; ++i) {
			std::cout << i << " ";
		}
		return 0;
	}
		
	// Init seats
	for (auto i=0u; i<row; ++i) {
		seats.push_back(std::make_pair(std::stack<unsigned> {}, std::stack<unsigned> {}));
	}

	// Populate passengers
	bool nowLeft = true;
	auto curr_row = 0u;
	for (auto i=1u; i<=passengers; ++i) {
		if (nowLeft) {
			seats[curr_row].first.push(i);	
			nowLeft = false;
		}
		else {
			seats[curr_row].second.push(i);
			nowLeft = true;
			++curr_row;
		}	
		if (curr_row==row) {
			curr_row = 0u;
		}
	}

	// Print leaving sequence
	for (auto i=0u; i<row; ++i) {
		while(!seats[i].first.empty()) {
			std::cout << seats[i].first.top();
			std::cout << " ";
			seats[i].first.pop();
		}
		while(!seats[i].second.empty()) {
			std::cout << seats[i].second.top();
			std::cout << " ";
			seats[i].second.pop();
		}

	}

}
