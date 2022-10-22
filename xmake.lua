set_languages("c++23")

add_requires("conan::ctpg/1.3.7", {alias = "ctpg"})
add_requires("conan::crc_cpp/1.1.0", {alias = "crc_cpp"})
add_requires("conan::catch2/3.0.1", {alias = "catch2"})

--target("Warp.Common")
--	set_kind("static")
--	add_files("Source/Common.mpp")
--	set_policy("build.c++.modules", true)
--target_end()

--target("Warp.Utilities")
--	set_kind("static")
--	add_files("Source/Utilities/*.mpp", "Source/Utilities.mpp")
--	add_includedirs("Include/")
--	add_includedirs("Include/ThirdParty/constexpr-random/include")
--	add_deps("Warp.Common");
--	add_packages("ctpg", "crc_cpp")
--	set_policy("build.c++.modules", true)
--target_end()

target("test")
	set_kind("binary")
	add_files("Source/Utilities/*.mpp", "Source/*.mpp", "Test/*.cpp")
	add_packages("ctpg", "catch2", "crc_cpp")
	--add_deps("Warp.Common");
	add_includedirs("Include/ThirdParty/constexpr-random/include")
	set_policy("build.c++.modules", true)
target_end()

