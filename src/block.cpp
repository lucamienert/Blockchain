#include <block.h>

/**
 * @brief Construct a new BC::Block::Block object
 * 
 * @param index 
 * @param data 
 */
BC::Block::Block(uint32_t index, const std::string &data) : index(index), data(data)
{
    this->nonce = 0;
    this->time = std::time(nullptr);
    this->hash = calculateHash(); 
}

/**
 * @brief Calculates the Sha256 Alogrithm with the parameters
 * 
 * @return std::string 
 */
inline std::string BC::Block::calculateHash() const
{
    std::stringstream ss;
    ss << this->index << this->prevHash << this->time << this->nonce;

    return BC::sha256(ss.str());
}

/**
 * @brief Mines a Block
 * 
 * @param diff 
 */
void BC::Block::mine(uint32_t diff)
{
    char str[diff + 1];

    for(uint32_t i = 0; i < diff; ++i)
        str[i] = '0';

    str[diff] = '\0';

    std::string cppString(str);

    do
    {
        this->nonce++;
        this->hash = calculateHash();
    } 
    while(this->hash.substr(0, diff) != cppString);

    std::cout << this->hash << std::endl;
}