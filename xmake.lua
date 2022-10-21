set_languages("c++23")

add_requires("conan::ctpg/1.3.7", {alias = "ctpg"})
add_requires("conan::crc_cpp/1.1.0", {alias = "crc_cpp"})
add_requires("conan::catch2/3.0.1", {alias = "catch2"})

target("test")
	set_kind("binary")
	add_files("Source/*.cpp")
	add_files("Test/*.cpp")
	add_includedirs("Include")
	add_includedirs("Include/ThirdParty/constexpr-random/include")
	add_packages("ctpg", "crc_cpp", "catch2")
	set_policy("build.c++.modules", true)

