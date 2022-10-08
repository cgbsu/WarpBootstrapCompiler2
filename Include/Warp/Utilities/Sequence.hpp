#ifndef WARP__BOOTSTRAP__COMPILER__UTILITIES__INCLUDE__GUARD__SEQUENCE__HPP
#define WARP__BOOTSTRAP__COMPILER__UTILITIES__INCLUDE__GUARD__SEQUENCE__HPP

#include <Warp/Common.hpp>

namespace Warp::Utilities
{
	template<auto... SequenceParameterConstants>
	struct Sequence
	{
	    template<template<auto...> typename InjectIntoParameterTemplate>
	    using InjectedType = InjectIntoParameterTemplate<SequenceParameterConstants...>;

	    template<template<auto...> typename InjectIntoParameterTemplate>
		constexpr static auto inject(auto... additionalArguments)
		{
			return InjectionFunctionParameterConstant<
					SequenceParameterConstants...
				>(additionalArguments...);
		}
	
	    template<auto... NewSequenceParameterConstants>
	    using MergeType = Sequence<
	            SequenceParameterConstants..., 
	            NewSequenceParameterConstants...
	        >;
	
	    template<auto... NewSequenceParameterConstants>
	    constexpr static const auto merge(Sequence<NewSequenceParameterConstants...>) {
	        return Sequence<
	                SequenceParameterConstants..., 
	                NewSequenceParameterConstants...
	            >();
	    }
	
	    template<auto... NewSequenceParameterConstants>
	    constexpr static const auto merged = Sequence<
	            SequenceParameterConstants..., 
	            NewSequenceParameterConstants...
	        >();
	
	    template<auto... NewSequenceParameterConstants>
	    constexpr static const auto prepended = Sequence<
	            NewSequenceParameterConstants..., 
	            SequenceParameterConstants... 
	        >();
	    static void print() {
	        (std::cout << "Sequence: " << ... << SequenceParameterConstants);
	    }
	};
	
	template<size_t FirstParameterConstant, size_t... SequenceParmaterConstants>
	struct SequenceTakeOneHelper
	{
	    constinit static const size_t first = FirstParameterConstant;
	    constexpr static const auto nextSequence 
				= std::index_sequence<SequenceParmaterConstants...>{};
	    consteval SequenceTakeOneHelper() noexcept {}
	    consteval SequenceTakeOneHelper(std::index_sequence<
				FirstParameterConstant, 
				SequenceParmaterConstants...
			>) noexcept {}
	};
}

#endif // WARP__BOOTSTRAP__COMPILER__UTILITIES__INCLUDE__GUARD__SEQUENCE__HPP

