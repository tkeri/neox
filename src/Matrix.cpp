//TODO: license

#include "Matrix.h"
#include <sstream>
#include <string>

namespace neox {

Matrix::Matrix(const int rows, const int cols)
    : m_rows(rows)
    , m_cols(cols)
    , m_data(cols, std::vector<int>(rows))
{
}

const int Matrix::rows() const
{
    return m_rows;
}

const int Matrix::cols() const
{
    return m_cols;
}

const std::string Matrix::dump() const
{
    std::stringstream ss;

    for(uint c = 0; c < m_data.size(); c++) {
        for(uint r = 0; r < m_data[0].size(); r++) {
            ss << " " << m_data[c][r];
        }
        ss << std::endl;
    }

    return ss.str();
}

} // namespace neox
