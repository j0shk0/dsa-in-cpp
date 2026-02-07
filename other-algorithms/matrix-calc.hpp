#pragma once
#include <experimental/simd>
#include <iostream>
#include <omp.h>
#include <vector>

template<typename T>
concept simd_compatible = requires(T a) { std::experimental::native_simd<T>{a}; };

template<simd_compatible T>
std::vector<std::vector<T>> transpose(const std::vector<std::vector<T>> &mat) {
    const size_t m = mat.size();
    const size_t n = mat[0].size();
    std::vector<std::vector<int>> output_mat(n, std::vector<T>(m));
    for (size_t i = 0; i < m; i++) {
        for (size_t j = 0; j < n; j++) {
            output_mat[j][i] = mat[i][j];
        }
    }
    return output_mat;
}

template<simd_compatible T>
std::vector<std::vector<T>> add_simd_padding(const std::vector<std::vector<T>> &mat) {
    constexpr size_t SIMD_SIZE = std::experimental::native_simd<T>::size();
    const size_t m = mat.size();
    const size_t n = mat[0].size();
    const size_t mPadded = ((m + SIMD_SIZE - 1) / SIMD_SIZE) * SIMD_SIZE;
    const size_t nPadded = ((n + SIMD_SIZE - 1) / SIMD_SIZE) * SIMD_SIZE;
    std::vector<std::vector<T>> output_mat(mPadded, std::vector<T>(nPadded));
    for (auto i = 0; i < mat.size(); i++) {
        std::copy(mat[i].begin(), mat[i].end(), output_mat[i].begin());
    }
    return output_mat;
}

// This function enables the user to perform simple multiplications of two
// quadratic matrices utilizing SIMD. Non-quadratic Matrices are not promised to work because I didn't test them yet.
// It is expected that rMat is already transposed. This means values that would normally be in the column of rMat are
// placed in rows (inner std::vectors). there is a transpose function that can do this operation for you.
template<simd_compatible T>
std::vector<std::vector<T>> matrix_prod(const std::vector<std::vector<T>> &lMat,
                                        const std::vector<std::vector<T>> &rMat) {
    // Get initial dimensions.
    const auto lm = lMat.size();
    const auto ln = lMat[0].size();
    const auto rm = rMat.size();
    const auto rn = rMat[0].size();

    if (ln == 0 || rn == 0 || lm == 0 || rm == 0) throw std::invalid_argument("Null dimension detected.");
    if (ln != rn)
        throw std::invalid_argument(
                "Matrices have incompatible dimensions. Make sure to read the "
                "documentation.");

    constexpr size_t SIMD_SIZE = std::experimental::native_simd<T>::size();

    // Add padding to ensure compatibility with the SIMD length.
    const auto paddedLMat = add_simd_padding<T>(lMat);
    const auto paddedRMat = add_simd_padding<T>(rMat);

    // Perform multiplication
    std::vector output_mat(lm, std::vector<T>(rm));
#pragma omp parallel for collapse(2)
    for (auto i = 0; i < lm; i++) {
        for (auto j = 0; j < rm; j++) {
            for (auto k = 0; k < ln; k += SIMD_SIZE) {
                const std::experimental::native_simd<T> lRow{&paddedLMat[i][k], std::experimental::element_aligned};
                const std::experimental::native_simd<T> rCol{&paddedRMat[j][k], std::experimental::element_aligned};
#pragma omp atomic
                output_mat[i][j] += std::experimental::reduce(lRow * rCol);
            }
        }
    }
    return output_mat;
}
