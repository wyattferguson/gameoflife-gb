#include "utils.h"

/**
 * @brief Genereate random unsigned 8 bit integer
 *
 * @param low minimum 8 bit value
 * @param high max 8 bit value
 * @return UINT8
 */
uint8_t rand_num(uint8_t low, uint8_t high) { return low + rand() % (high + 1 - low); }


/**
 * @brief Generate a seed for rand() based on scanline value
 *
 */
void seed_rand(void){
    // Accumulate entropy each frame so seed differs even when
    // LY_REG/DIV_REG return the same values every frame.
    static UINT16 seed = 0;
    seed += LY_REG;
    seed ^= (UINT16)DIV_REG << 8;
    initrand(seed);
}