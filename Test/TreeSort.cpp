#include <Warp/Utilities/CompileTimeTreeSort.hpp>

#include <catch2/catch_test_macros.hpp>
using namespace Warp::Utilities;

template<auto... CompileTimeValueParameterConstants>
constexpr auto toRuntimeValues() 
		-> std::array<size_t, sizeof...(CompileTimeValueParameterConstants)>
{
	return std::array<size_t, sizeof...(CompileTimeValueParameterConstants)>{
			CompileTimeValueParameterConstants...
		};
}
	
TEST_CASE(
		"CompileTimeTreeSort sorts an unordered list of unique elements", 
		"[compile-time-tree-sort]"
	)
{
	//{
	//	constexpr auto result = treeSort<std::min>(
	//			std::index_sequence<14, 5, 82, 1, 10, 2, 6, 18, 17, 3, 30, 16>
	//		);
	//	constexpr std::array<size_t> expected{1, 2, 3, 5, 6, 10, 14, 16, 17, 18, 30, 82};

	//}
}

