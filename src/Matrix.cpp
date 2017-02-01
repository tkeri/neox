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
//TODO: square test
const int Matrix::symmetry() const
{
    for(uint c = m_data.size() - 1; m_data.size() >= 0; c--) {
        for(uint r = 0; r < m_data[0].size(); r++) {
            if (m_data[r][c] != m_data[c][r]) {
                return 0;
            }
            else {
                return 1;
            }
        }
    }
//TODO: ?
    return 0;
}

const int Matrix::square() const
{
    if (m_data.size() == m_data[0].size())
        return 1;
    else
        return 0;
}

//TODO: determinant
const int Matrix::determinant() const
{

    return 0;
}


} // namespace neox
