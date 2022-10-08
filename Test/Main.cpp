#include <Warp/Utilities/CompileTimeRandom.hpp>

using namespace Warp::Utilities;

int main(int argc, char** args)
{
	constexpr auto nums = randomRange<0, 10, 100>();
	for(size_t ii = 0; ii < 100; ++ii)
		std::cout << nums[ii] << "\n";
	return 0;
}

