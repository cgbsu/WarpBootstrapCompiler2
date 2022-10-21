#ifndef WARP__BOOTSTRAP__COMPILER__PARSING__INCLUDE__GUARD__TERMS__HPP
#define WARP__BOOTSTRAP__COMPILER__PARSING__INCLUDE__GUARD__TERMS__HPP
//#include <Warp/Utilities.hpp>
//
//namespace Warp::Parsing
//{
//	using namespace Warp::Utilities;
//
//	template<typename LeftParameterType, typename RightParameterType>
//	concept EqualityComparibleConcept = requires(
//			LeftParameterType left, RightParameterType right) {
//		left == right;
//	};
//
//	template<auto LeftParameterConstant, auto RightParameterConstant>
//	requires(EqualityComparibleConcept<
//			decltype(LeftParameterConstant), 
//			decltype(RightParameterConstant)
//		> == true)
//	consteval static bool are_equal_if_comparible() {
//		return (LeftParameterConstant == RightParameterConstant);
//	}
//
//	template<auto, auto>
//	consteval static bool are_equal_if_comparible() {
//		return false;
//	}
//
//	template<
//			auto QueryParameterConstant, 
//			auto... TagParameterConstants, 
//			size_t... IndexParameterConstants
//		>
//	consteval static const size_t tagIndexImplementation(
//			std::index_sequence<IndexParameterConstants>
//		)
//	{
//		constexpr const bool tagMatched[] = {
//				are_equal_if_comparible<
//						TagParameterConstants, 
//						QueryParameterConstant
//					>(),  ...
//			};
//		return (enabledValue<
//				IndexParameterConstants + 1, 
//				0, 
//				tagMatched[IndexParameterConstants]
//			> + ...);
//	}
//
//	template<auto QueryParameterConstant, auto... TagParameterConstants>
//	consteval static const size_t tagIndex()
//	{
//		return tagIndexImplementation<
//				QueryParameterConstant, 
//				TagParameterConstants...
//			>(std::make_index_sequence<sizeof...(TagParameterConstants)>);
//	}
//
//	template<auto... TermTagParameterConstants>
//	struct TermLevel
//	{
//		template<auto QueryParameterConstant>
//		consteval static const bool termIndex()
//		{
//			return tagIndex<
//					QueryParameterConstant, 
//					TermTagParameterConstants...
//				>();
//		}
//
//		template<auto QueryParameterConstant>
//		consteval static const bool hasTerm()
//		{
//			return (are_equal_if_comparible<
//					TermTagParameterConstants, 
//					QueryParameterConstant
//				>() || ...);
//		}
//	};
//
//	template<
//			auto TrueParameterConstant, 
//			auto FalseParameterConstant, 
//			bool EnableParameterConstant = true
//		>
//	struct EnableValue {
//		constexpr static const auto value = TrueParameterConstant;
//	};
//
//	template<
//			auto TrueParameterConstant, 
//			auto FalseParameterConstant
//		>
//	struct EnableValue<TrueParameterConstant, FalseParameterConstant, false> {
//		constexpr static const auto value = FalseParameterConstant;
//	};
//
//	template<
//			auto TrueParameterConstant, 
//			auto FalseParameterConstant, 
//			bool EnableParameterConstant
//		>
//	constexpr static const auto enabledValue = EnableValue<
//			TrueParameterConstant, 
//			FalseParameterConstant, 
//			EnableParameterConstant
//		>::value;
//	
//	template<
//			template<auto> typename TermResolverParameterTemplate, 
//			typename... TermLevelParameterTypes
//		>
//	struct Terms
//	{
//		template<auto QueryParameterConstant, size_t... IndexParameterConstants>
//		consteval static const size_t getTermImplementation(
//				std::index_sequence<IndexParameterConstants...>
//			)
//		{
//			constexpr const bool termAvailible[] = {
//					TermLevelParameterTypes::template hasTerm<
//							QueryParameterConstant
//						>()...
//				};
//			return (enabledValue<
//					IndexParameterConstants + 1, 
//					0, 
//					termAvailible[IndexParameterConstants]
//				> + ...);
//		}
//
//		template<auto QueryParameterConstant>
//		consteval static const auto getTerm()
//		{
//			constexpr const size_t termIndex = getTermImplementation<QueryParameterConstant>(
//					std::make_index_sequence<sizeof...(TermLevelParameterTypes)>()
//				);
//			static_assert(termIndex != 0, "Term does not exist in terms");
//			return TermResolverParameterTemplate<QueryParameterConstant>
//						::template termWithPrecident<termIndex>;
//		}
//
//	};
//}

#endif // WARP__BOOTSTRAP__COMPILER__PARSING__INCLUDE__GUARD__TERMS__HPP

