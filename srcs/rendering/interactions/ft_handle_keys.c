/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabik <ysabik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 11:13:51 by ysabik            #+#    #+#             */
/*   Updated: 2024/03/17 11:14:38 by ysabik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

/**
 * @brief Check if a key is pressed --> move of the player if needed.
 * 
 * @param cub 	The game structure
*/
void	ft_handle_keys(t_cub *cub)
{
	if (cub->keys.forward)
		ft_move_forward(cub);
	if (cub->keys.backward)
		ft_move_backward(cub);
	if (cub->keys.rot_left)
		cub->orientation -= ROT_SPEED;
	if (cub->keys.rot_right)
		cub->orientation += ROT_SPEED;
	if (cub->orientation > 2 * PI)
		cub->orientation -= 2 * PI;
	else if (cub->orientation < 0)
		cub->orientation += 2 * PI;
}
