#pragma once

#include <type_traits>
#include <utility>

namespace ServerCore
{


////////////////////////////////////////////////////////////////
///  Check if a member function with a specific name exists  ///
////////////////////////////////////////////////////////////////
template <typename T, typename Func, typename = void>
struct has_member_function : std::false_type
{
};

template <typename T, typename Func>
struct has_member_function<T, Func, std::void_t<decltype(std::declval<Func>()(std::declval<T>()))>>
    : std::true_type
{
};

template <typename T, auto Func>
struct has_member_func
{
    template <typename U, typename = void>
    struct has_member_function_pointer : std::false_type
    {
    };

    template <typename U>
    struct has_member_function_pointer<U, std::void_t<decltype((std::declval<U>().*Func)())>>
        : std::true_type
    {
    };

    static constexpr bool value =
        std::is_member_function_pointer_v<decltype(Func)>
        ? has_member_function_pointer<T>::value
        : has_member_function<T, decltype(Func)>::value;
};

template <typename T, auto FuncName>
inline constexpr bool has_member_function_v = has_member_func<T, FuncName>::value;


////////////////////////////////////////////////////////////////
///  Check if a member variable with a specific name exists  ///
////////////////////////////////////////////////////////////////
template <auto MemberPtr>
struct has_member_variable
{
private:
    template <typename T, typename = std::void_t<decltype(std::declval<T>().*MemberPtr)>>
    static std::true_type test(int);

    template <typename>
    static std::false_type test(...);

public:
    using type = decltype(test<typename std::remove_pointer<decltype(MemberPtr)>::type::class_type>(0));
    static constexpr bool value = type::value;
};

template <auto MemberPtr>
inline constexpr bool has_member_variable_v = has_member_variable<MemberPtr>::value;


///////////////////////////////////////////////////////////////////
///  Check if a member function with specific signature exists  ///
///////////////////////////////////////////////////////////////////

#include <functional>

template<typename T>
struct function_traits;

template<typename R, typename C, typename... Args>
struct function_traits<R(C::*)(Args...)> {
    using return_type = R;
    using args_type = std::tuple<Args...>;
};

template<typename T, auto Func, typename Ret, typename... Args>
concept HasMemberFunction =
std::is_same_v<typename function_traits<decltype(Func)>::return_type, Ret>&&
std::is_same_v<typename function_traits<decltype(Func)>::args_type, std::tuple<Args...>>;

template<typename T, auto Func, typename Ret, typename... Args>
struct has_member_func_with_signature {
    static constexpr bool value = HasMemberFunction<T, Func, Ret, Args...>;
};

template<typename T, auto Func, typename Ret, typename... Args>
inline constexpr bool has_member_func_with_signature_v = has_member_func_with_signature<T, Func, Ret, Args...>::value;

}
