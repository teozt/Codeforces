#include <iostream>
#include <vector>

unsigned gcd(unsigned a, unsigned b);
unsigned findCoPrime(unsigned a, unsigned b);

int main() {

	unsigned num_ele;
	
	std::cin >> num_ele;

	std::vector<unsigned> array;
	
	for (auto i=0u; i<num_ele; ++i) {
		unsigned temp;
		std::cin >> temp;
		array.emplace_back(temp);
	}

	if (num_ele==1u) {
		std::cout << 0 << std::endl;
		std::cout << array[0];
		return 0;
	
	}

	// Check co-prime
	auto curr_ele = 0u;
	while (1) {
		if (gcd(array[curr_ele],array[curr_ele+1])==1u) {
			++ curr_ele;
		}
		else {
			auto new_ele = findCoPrime(array[curr_ele],array[curr_ele+1]);			
			array.insert(array.begin()+curr_ele+1, new_ele);
			curr_ele = curr_ele + 2u;
		}	

		if (curr_ele == array.size()-1) {
			break;
		}

	}

	std::cout << array.size()-num_ele << std::endl;
	for (auto i=0u; i<array.size(); ++i) {
		std::cout << array[i] << " ";
	}
	
}

unsigned gcd(unsigned a, unsigned b) {
	unsigned c;
	while (a!=0u) {
		c = a;
		a = b%a;
		b = c;
	}

	return b;

}

unsigned findCoPrime(unsigned a, unsigned b) {
	if (a!=b) {
		return 1u;
	}
	else {
		bool plus = true;
		auto trial = a+1u;
		if (trial>1e9) {
			trial -= 2u;
			plus = false;
		}
		while (1) {
			if (gcd(a,trial)==1u) {
				return trial;
			}
			if (plus) {
				++trial;
			}
			else {
				--trial;
			}
		}

	}
//	unsigned diff;
//	if (a<b) {
//		diff = b -a;
//	}
//	else if(a>b) {
//		diff = a - b;
//		auto c = a;
//		a = b;
//		b = c;
//	}
//	else {
//		while (1) {
//			auto curr_trial = a+1;
//			if (gcd(a,curr_trial) == 1u) {
//				return curr_trial;
//			}
//		}
//	}
//
//	for (auto trial=1u; trial<diff; ++trial) {
//		if (gcd(a+trial,b)==1u && gcd(a,b-trial)==1u) {
//			return a+trial;
//		}
//	}
//
//	std::cout << "Should not have reached here" << std::endl;
//	std::exit(5);
}	
