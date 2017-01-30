#ifndef Matrix_h
#define Matrix_h

#include <ostream>
#include <vector>
#include <string>

namespace neox {

class Matrix {
public:
    Matrix(const int rows = 1, const int cols = 1);

    const int rows() const;
    const int cols() const;

    const std::string dump() const;

    std::vector<int>& operator[](std::size_t idx) { return m_data[idx]; }
    const std::vector<int>& operator[](std::size_t idx) const { return m_data[idx]; }
private:
    int m_rows;
    int m_cols;
    std::vector<std::vector<int>> m_data;

};

} // namespace neox

inline std::ostream& operator<<(std::ostream& os, const neox::Matrix& obj)
{
    os << obj.dump();
    return os;
}

#endif // Matrix_h
