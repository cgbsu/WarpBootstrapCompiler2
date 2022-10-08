#ifndef WARP__BOOTSTRAP__COMPILER__UTILITIES__INCLUDE__GUARD__TEMPLATES__HPP
#define WARP__BOOTSTRAP__COMPILER__UTILITIES__INCLUDE__GUARD__TEMPLATES__HPP
#include <Warp/Common.hpp>

namespace Warp::Utilities
{
	template<typename ToCleanParameterType>
	using CleanType = std::remove_reference_t<std::decay_t<ToCleanParameterType>>;

	template<typename CanidateParameterType>
	constinit static const auto isNullOptType = std::is_same_v<CleanType<CanidateParameterType>, std::nullopt_t>;
	
	template<auto CanidateParameterConstant>
	constinit static const auto constantIsNullOptType 
			= std::is_same_v<CleanType<decltype(CanidateParameterConstant)>, std::nullopt_t>;
	
	template<typename CanidateParameterType>
	concept NotNullOptConcept = isNullOptType<CanidateParameterType> == false;
	
	template<typename CanidateParameterType>
	concept NullOptConcept = isNullOptType<CanidateParameterType> == true;
}

#endif // WARP__BOOTSTRAP__COMPILER__UTILITIES__INCLUDE__GUARD__TEMPLATES__HPP

