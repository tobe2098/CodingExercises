#pragma once
template<typename T, typename... Args>// (a parameter pack representing a variable number of types)
auto makeVector(Args&&... args) {//This is the function declaration, taking a parameter pack args of forwarding references (Args&&). Forwarding references allow perfect forwarding of arguments.
	std::vector<T> vec;
	vec.reserve(sizeof...(Args));//This is an operator in C++ used specifically with parameter packs. It's similar to the sizeof operator, which gives the size in bytes of a type or an object. However, sizeof... operates on parameter packs and returns the number of arguments in the pack.
	(vec.emplace_back(std::forward<Args>(args)), ...);//std::forward is used to perfectly forward each argument, preserving its value category (lvalue or rvalue).
	return vec;
}