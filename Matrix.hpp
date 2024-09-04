#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_


#include <array>

template<typename _Ty, std::size_t ..._Sizes> struct _matrix_type;
template<typename _Ty> struct _matrix_type<_Ty> {using t = _Ty;};
template<typename _Ty, std::size_t _Size, std::size_t ..._Sizes> struct _matrix_type<_Ty, _Size, _Sizes...> {
    using t = std::array<typename _matrix_type<_Ty, _Sizes...>::t, _Size>;
};

template<typename _Ty, std::size_t ..._Sizes> using Matrix = typename _matrix_type<_Ty, _Sizes...>::t;


template<std::size_t ..._Sizes> using Matrixu = Matrix<unsigned, _Sizes...>;
template<std::size_t ..._Sizes> using Matrixi = Matrix<int, _Sizes...>;
template<std::size_t ..._Sizes> using Matrixf = Matrix<float, _Sizes...>;


#endif