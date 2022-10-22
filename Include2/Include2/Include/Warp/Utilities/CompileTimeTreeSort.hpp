module;
	#include <Warp/Common.hpp>
module Warp.Utilities:CompileTimeTreeSort;

//import Warp.Utilities:Templates;
//import Warp.Utilities:Sequence;
import :ConstantBinaryTree;

export namespace Warp::Utilities
{
	template<
	        auto CompareParameterConstant, 
	        size_t CurrentParameterConstant, 
	        typename BinaryTreeParameterType
	    >
	consteval static auto treeSortInsert()
	{
	    if constexpr(isNullOptType<BinaryTreeParameterType> == true)
	        return ConstantBinaryTreeRootType::template newRoot<CurrentParameterConstant>;
	    else  if constexpr(BinaryTreeParameterType::rootIsNullOpt == true)
	        return BinaryTreeParameterType::template newRoot<CurrentParameterConstant>;
	    else
	    {
	        constexpr bool isLeft = CompareParameterConstant(
	                CurrentParameterConstant, 
	                BinaryTreeParameterType::root
	            );
	        if constexpr(isLeft == true)
	        {
	            return BinaryTreeParameterType::template newLeft<
	                    treeSortInsert<
	                            CompareParameterConstant, 
	                            CurrentParameterConstant, 
	                            decltype(BinaryTreeParameterType::left)
	                        >()
	                >;
	        }
	        else
	        {
	            return BinaryTreeParameterType::template newRight<
	                    treeSortInsert<
	                            CompareParameterConstant, 
	                            CurrentParameterConstant, 
	                            decltype(BinaryTreeParameterType::right)
	                        >()
	                >;
	        }
	    }
	}
	
	template<
	        auto CompareParameterConstant, 
	        typename BinaryTreeParameterType, 
	        size_t... ToSortParameterConstants
	    >
	consteval static auto treeSortMakeTree(
	        std::index_sequence<ToSortParameterConstants...> toSort
	    )
	{
	    if constexpr(sizeof...(ToSortParameterConstants) < 1) {
	        return BinaryTreeParameterType();
	    }
	    else
	    {
	        using SequenceHelperType = decltype(SequenceTakeOneHelper(toSort));
	        using NextTreeType = decltype(
	                treeSortInsert<
	                        CompareParameterConstant, 
	                        SequenceHelperType::first, 
	                        BinaryTreeParameterType
	                    >()
	            );
	        return treeSortMakeTree<CompareParameterConstant, NextTreeType>(
	                SequenceHelperType::nextSequence
	            );
	    }
	}
	
	template<
	        auto CompareParameterConstant, 
	        size_t... ToSortParameterConstants
	    >
	consteval static auto treeSort(
	        std::index_sequence<ToSortParameterConstants...> toSort
	    )
	{
	    using TreeType = decltype(
	            treeSortMakeTree<
	                CompareParameterConstant, 
	                ConstantBinaryTreeRootType 
	            >(toSort)
	        );
	    return TreeType::flatten();
	}
}

