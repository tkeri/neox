#ifndef Matrix_h
#define Matrix_h

#include <ostream>
#include <vector>
#include <string>

namespace neox {

class Matrix {
public:
    Matrix(const int rows = 1, const int cols = 1);

    const std::size_t rows() const;
    const std::size_t cols() const;

    const std::string dump() const;
    void transpose();
    const bool symmetry() const;
    const bool square() const;
    const bool diag() const;

    std::vector<int>& operator[](std::size_t idx) { return m_data[idx]; }
    const std::vector<int>& operator[](std::size_t idx) const { return m_data[idx]; }


private:
    std::vector<std::vector<int>> m_data;

};

} // namespace neox

inline std::ostream& operator<<(std::ostream& os, const neox::Matrix& obj)
{
    os << obj.dump();
    return os;
}

#endif // Matrix_h
