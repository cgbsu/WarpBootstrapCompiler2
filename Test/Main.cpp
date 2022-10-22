import Warp.Common;
import Warp.Utilities;

using namespace Warp::Utilities;

//#define CATCH_CONFIG_MAIN
//#include <catch2/catch_session.hpp>

constexpr static const auto minimum = [](auto left, auto right) { return left < right; };

int main(int argc, char* argv[]) {
{
	using X = decltype(treeSortMakeTree<minimum, ConstantBinaryTreeRootType>(
			std::index_sequence<14, 5, 82, 1, 10, 2, 6, 18, 17, 3, 30, 16>()
		));
	std::cout << X::toString() << "\n";
	constexpr auto result = treeSort<minimum>(
			std::index_sequence<14, 5, 82, 1, 10, 2, 6, 18, 17, 3, 30, 16>()
		);
	std::cout << decltype(result)::toString() << "\n";
}

	//  // your setup ...
	//
	//  int result = Catch::Session().run( argc, argv );
	//
	//  // your clean-up...
	//
	//  return result;
//}

