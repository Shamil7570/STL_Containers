#ifndef ITERAOR_TRAITS_HPP
#define ITERAOR_TRAITS_HPP

#include <cstddef>
#include <iterator>
#include <type_traits>


namespace ft{
    
    template<typename Iter>
	struct iterator_traits{
		typedef typename Iter::difference_type		difference_type;
        typedef typename Iter::value_type           value_type;
        typedef typename Iter::pointer              pointer;
        typedef typename Iter::reference            reference;
        typedef typename Iter::iterator_category    iterator_category;
	};

    template<class T>
    struct iterator_traits<T*>{
        typedef std::ptrdiff_t                          difference_type;
        typedef T                                       value_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef std::random_access_iterator_tag         iterator_category;
    };

    template<typename T>
	struct iterator_traits<const T*> {
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};

    template<typename InputIterator>
	typename iterator_traits<InputIterator*>::difference_type distance(InputIterator first, InputIterator last) {
		return (last - first);
	}

    template <class T> 	 struct is_integral                     : public std::false_type {};
    template <>          struct is_integral<bool>               : public std::true_type {};
    template <>          struct is_integral<char>               : public std::true_type {};
    template <>          struct is_integral<signed char>        : public std::true_type {};
    template <>          struct is_integral<unsigned char>      : public std::true_type {};
    template <>          struct is_integral<wchar_t>            : public std::true_type {};
    template <>          struct is_integral<char16_t>           : public std::true_type {};
    template <>          struct is_integral<char32_t>           : public std::true_type {};
    template <>          struct is_integral<short>              : public std::true_type {};
    template <>          struct is_integral<unsigned short>     : public std::true_type {};
    template <>          struct is_integral<int>                : public std::true_type {};
    template <>          struct is_integral<unsigned int>       : public std::true_type {};
    template <>          struct is_integral<long>               : public std::true_type {};
    template <>          struct is_integral<unsigned long>      : public std::true_type {};
    template <>          struct is_integral<long long>          : public std::true_type {};
    template <>          struct is_integral<unsigned long long> : public std::true_type {};
    template <>          struct is_integral<__int128_t>         : public std::true_type {};
    template <>          struct is_integral<__uint128_t>        : public std::true_type {};

    template<bool Cond, class T = void> 
    struct enable_if {};

    template<class T>
     struct enable_if<true, T> { typedef T type; };   
}

#endif