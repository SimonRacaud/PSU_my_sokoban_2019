/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** player management
*/

#include "my_sokoban.h"

int player_check_and_move(map_t *map, int key)
{
    int dst = get_destination(map, map->player_pos, key);
    int box_status = 0;

    if (dst == -1)
        return EXIT_SUCCESS;
    if (is_box_pos(dst, map->box_pos, map->nb_box))
        box_status = box_check_and_move(map, dst, key);
    if (map->map[dst] != '#') {
        if (box_status != -1)
            map->player_pos = dst;
    }
    if (box_status == EXIT_WIN || box_status == EXIT_FAIL)
        return box_status;
    return EXIT_SUCCESS;
}
