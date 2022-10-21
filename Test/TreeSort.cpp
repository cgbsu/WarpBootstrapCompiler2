import Warp.Utilities;
/*
#include <catch2/catch_test_macros.hpp>
using namespace Warp::Utilities;

template<auto... CompileTimeValueParameterConstants>
constexpr auto toRuntimeValues(Sequence<CompileTimeValueParameterConstants...>) 
		-> std::array<size_t, sizeof...(CompileTimeValueParameterConstants)>
{
	return std::array<size_t, sizeof...(CompileTimeValueParameterConstants)>{
			CompileTimeValueParameterConstants...
		};
}
	
constexpr static const auto minimum = [](auto left, auto right) { return left < right; };


//template<auto... InOrderParameterConstants, auto... JumbledParameterConstants>
//constexpr static auto shuffleSequence(
//		Sequence<InOrderParameterConstants...>, 
//		Sequence<JumbledParameterConstants...>
//	)
//{
//
//}

TEST_CASE(
		"CompileTimeTreeSort sorts an unordered list of unique elements", 
		"[compile-time-tree-sort]"
	)
{
	{
		using X = decltype(treeSortMakeTree<minimum, ConstantBinaryTreeRootType>(
				std::index_sequence<14, 5, 82, 1, 10, 2, 6, 18, 17, 3, 30, 16>()
			));
		std::cout << X::toString() << "\n";
		constexpr auto result = treeSort<minimum>(
				std::index_sequence<14, 5, 82, 1, 10, 2, 6, 18, 17, 3, 30, 16>()
			);
		std::cout << decltype(result)::toString() << "\n";
		constexpr std::array expected{1u, 2u, 3u, 5u, 6u, 10u, 14u, 16u, 17u, 18u, 30u, 82u};
		//REQUIRE(toRuntimeValues(result) == expected);
	}
}
*/

