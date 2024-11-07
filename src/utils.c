#include "utils.h"

/**
 * @brief Genereate random unsigned 8 bit integer
 *
 * @param low minimum 8 bit value
 * @param high max 8 bit value
 * @return UINT8
 */
uint8_t rand_num(uint8_t low, uint8_t high) { return low + rand() % (high + 1 - low); }