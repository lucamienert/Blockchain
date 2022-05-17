#include <blockchain.h>

/**
 * @brief Construct a new BC::Blockchain::Blockchain object
 * 
 */
BC::Blockchain::Blockchain(uint32_t diff)
{
    this->chain.emplace_back(BC::Block(0, "Genesis Block"));
    this->diff = diff;
}

/**
 * @brief Adds a Block to the Blockchain
 * 
 * @param block 
 */
void BC::Blockchain::addBlock(BC::Block block)
{
    block.prevHash = getLastBlock().hash;
    block.mine(this->diff);
    this->chain.push_back(block);
}

/**
 * @brief returns the Last Block of the chain
 * 
 * @return BC::Block 
 */
inline BC::Block BC::Blockchain::getLastBlock() const
{
    return this->chain.back();
}