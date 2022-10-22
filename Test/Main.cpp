//import Warp.Utilities:Templates;
//import Warp.Utilities:Sequence;
//import Warp.Utilities:ConstantBinaryTree;
import Warp.Utilities;

using namespace Warp::Utilities;

constexpr static const auto minimum = [](auto left, auto right) { return left < right; };

int main(int argc, char* argv[])
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
	hi2();
	return 0;
}

