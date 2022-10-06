#include <Warp/Parsing.hpp>

using namespace Warp::Parsing;
using namespace Warp::Utilities;

enum class TestTag
{
	A, 
	B, 
	C, 
	D
};

template<TestTag Tag>
struct TestTerm {};

template<>
struct TestTerm<TestTag::A>
{
	template<int PrecedenceParameterConstant>
	constexpr static const auto termWithPrecident = CharTerm<
			'A', 
			ctpg::associativity::no_assoc, 
			PrecedenceParameterConstant
		>::term;
};

template<>
struct TestTerm<TestTag::B>
{
	template<int PrecedenceParameterConstant>
	constexpr static const auto termWithPrecident = StringTerm<
			"secondTerm", 
			ctpg::associativity::no_assoc, 
			PrecedenceParameterConstant
		>::term;
};

template<>
struct TestTerm<TestTag::C>
{
	template<int PrecedenceParameterConstant>
	constexpr static const auto termWithPrecident = StringTerm<
			"thirdTerm", 
			ctpg::associativity::no_assoc, 
			PrecedenceParameterConstant
		>::term;
};

template<>
struct TestTerm<TestTag::D>
{
	template<int PrecedenceParameterConstant>
	constexpr static const auto termWithPrecident = CharTerm<
			'D', 
			ctpg::associativity::no_assoc, 
			PrecedenceParameterConstant
		>::term;
};

int main(int argc, char** args)
{
	using TermsType = Terms<TestTerm, TermLevel<TestTag::A, TestTag::D, TestTag::B>, TermLevel<TestTag::C>>;
	const auto a = TermsType::getTerm<TestTag::A>();
	const auto b = TermsType::getTerm<TestTag::B>();
	const auto c = TermsType::getTerm<TestTag::C>();
	const auto d = TermsType::getTerm<TestTag::D>();
	std::cout << a.get_precedence() << "\n";
	std::cout << b.get_precedence() << "\n";
	std::cout << c.get_precedence() << "\n";
	std::cout << d.get_precedence() << "\n";
	return 0;
}

