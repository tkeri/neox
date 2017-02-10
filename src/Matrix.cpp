//TODO: license

#include "Matrix.h"
#include <sstream>
#include <string>

namespace neox {

Matrix::Matrix(const int rows, const int cols)
    : m_data(rows, std::vector<int>(cols))
{
}

const std::size_t Matrix::rows() const
{
    return m_data.size();
}

const std::size_t Matrix::cols() const
{
    return m_data[0].size();
}

const std::string Matrix::dump() const
{
    std::stringstream ss;

    for(std::size_t r = 0; r < rows(); r++) {
        for(std::size_t c = 0; c < cols(); c++) {
            ss << " " << m_data[r][c];
        }
        ss << std::endl;
    }
    return ss.str();
}

void Matrix::transpose()
{
    std::vector<std::vector<int>> transp(cols(), std::vector<int>(rows()));

    for(std::size_t r = 0; r < rows(); r++) {
        for(std::size_t c = 0; c < cols(); c++) {
            transp[c][r] = m_data[r][c];
        }
    }

    m_data = transp;
}

const bool Matrix::symmetry() const
{
    if (!this->square())
        return false;

    for(std::size_t r = 0; r < rows(); r++) {
        for(std::size_t c = 0; c < cols(); c++) {
            if (m_data[r][c] != m_data[c][r])
                return false;
        }
    }

    return true;
}

const bool Matrix::square() const
{
    return rows() == cols();
}

const bool Matrix::diag() const
{
    if (!this->square())
        return false;

    for(std::size_t r = 0; r < rows(); r++) {
        for(std::size_t c = 0; c < cols(); c++) {
            if (r != c && m_data[r][c] != 0)
                return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Matrix& obj)
{
    os << obj.dump();
    return os;
}

bool operator==(const Matrix& lhs, const Matrix& rhs)
{
    if (lhs.rows() != rhs.rows() || lhs.cols() != rhs.cols())
        return false;

    for (std::size_t r = 0; r < lhs.rows(); ++r) {
        if (lhs[r] != rhs[r])
            return false;
    }

    return true;
}

bool operator!=(const Matrix& lhs, const Matrix& rhs)
{
    return !(lhs == rhs);
}

} // namespace neox
