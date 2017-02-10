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

void Matrix::transpose()
{
    const int cols = m_data.size();
    const int rows = m_data[0].size();

    std::vector<std::vector<int>> transp(rows, std::vector<int>(cols));

    for(uint c = 0; c < m_data.size(); c++) {
        for(uint r = 0; r < m_data[0].size(); r++) {
            transp[r][c] = m_data[c][r];
        }
    }

    m_data = transp;
}

const bool Matrix::symmetry() const
{
    if (!this->square())
        return false;

    for(uint r = 0; r < m_data[0].size(); r++) {
        for(uint c = 0; c < m_data.size(); c++) {
            if (m_data[r][c] != m_data[c][r])
                return false;
        }
    }

    return true;
}

const bool Matrix::square() const
{
    return m_data.size() == m_data[0].size();
}

const bool Matrix::diag() const
{
    if (!this->square())
        return false;

    for(uint r = 0; r < m_data[0].size(); r++) {
        for(uint c = 0; c < m_data.size(); c++) {
            if (c != r && m_data[r][c] != 0)
                return false;
        }
    }
    return true;
}

} // namespace neox
