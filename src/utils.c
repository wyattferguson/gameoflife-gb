#include "utils.h"

/**
 * @brief Genereate random unsigned 8 bit integer
 *
 * @param low minimum 8 bit value
 * @param high max 8 bit value
 * @return UINT8
 */
UINT8 rand_num(UINT8 low, UINT8 high) {
    return low + rand() % (high + 1 - low);
}