#include <Warp/Common.hpp>

#ifndef WARP__BOOTSTRAP__COMPILER__UTILITIES__INCLUDE__GUARD__STRINGS__HPP
#define WARP__BOOTSTRAP__COMPILER__UTILITIES__INCLUDE__GUARD__STRINGS__HPP
namespace Warp::Utilities
{
	template<const auto& StringParameterConstant, size_t IndexParameterConstant = 0>
	consteval size_t stringLength()
	{
		if constexpr(StringParameterConstant[IndexParameterConstant] != '\0')
			return stringLength<StringParameterConstant, IndexParameterConstant + 1>();
		else
			return IndexParameterConstant;
	}

	template<char... CharacterParameterConstants>
	struct TemplateString {
		constexpr static const size_t length = sizeof...(CharacterParameterConstants);
		constexpr static const char array[length] = { CharacterParameterConstants... };
	};

	template<
			const auto& StringParameterConstant, 
			size_t IndexParameterConstant, 
			size_t LengthParameterConstant, 
			char... CharacterParameterConstants
		>
	consteval auto toTemplateString()
	{
		if constexpr(IndexParameterConstant == LengthParameterConstant)
		{
			return toTemplateString<
					StringParameterConstant, 
					IndexParameterConstant + 1,
					LengthParameterConstant, 
					CharacterParameterConstants..., 
					StringParameterConstant[IndexParameterConstant]
				>();
		}
		else
			return TemplateString<CharacterParameterConstants...>{}; 
	}

	template<const auto& StringParameterConstant>
	using TemplateStringType = decltype(toTemplateString<
			StringParameterConstant, 
			0, 
			stringLength<StringParameterConstant>()
		>);

	template<size_t LengthParameterConstant>
	constexpr const auto& copyArray(const auto (&from)[LengthParameterConstant], auto (&to)[LengthParameterConstant])
	{
		for(size_t ii = 0; ii < LengthParameterConstant; ++ii)
			to[ii] = from[ii];
		return to;
	}

	template<size_t FromLengthParameterConstant, size_t ToLengthParameterConstant>
	requires(ToLengthParameterConstant > FromLengthParameterConstant)
	constexpr const auto& copyArray(const auto (&from)[FromLengthParameterConstant], auto (&to)[ToLengthParameterConstant])
	{
		for(size_t ii = 0; ii < FromLengthParameterConstant; ++ii)
			to[ii] = from[ii];
		return to;
	}

	template<size_t LengthParameterConstant>
	struct FixedString
	{
		char string[LengthParameterConstant];
		constexpr static const size_t size = LengthParameterConstant;
		constexpr FixedString(const auto (&string_)[LengthParameterConstant]) { copyArray(string_, string); }
		operator std::string_view() {
			return std::string_view{string};
		}
	};
}
#endif // WARP__BOOTSTRAP__COMPILER__UTILITIES__INCLUDE__GUARD__STRINGS__HPP

