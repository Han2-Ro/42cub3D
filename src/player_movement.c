#include "../includes/cub3d.h"
#include <X11/X.h>

// double	valid_x_arr(t_cb *cb, double x, double y, double distance)
// {
// 	if (cb->map.arr[(int)(x + distance)][(int)y] == 3)
// 	{
// 		return ;
// 	}
// }

// plus distance, is there a field - distance

// void	valid_x_ll(t_cb *cb)//check if correcty field,
		then if walk distance is fine, if not, add reminder
// {
// 	t_valid_cords	*temp;

//     printf("walking: %f, %f\n", cb->player.input.x, cb->player.input.y);
// 	// x 1,1
// 	temp = cb->cords;
// 	while (temp)
// 	{
// 		if ((cb->player.input.x + cb->player.input.x < temp->x + 2
				|| cb->player.input.x >= temp->x) && (cb->player.input.y
				+ cb->player.input.y < temp->y + 2
// 				|| cb->player.input.y >= temp->y))
// 		{
// 			if (cb->player.input.x + cb->player.input.x > temp->x + 2)
// 				cb->player.pos.x = (cb->player.input.x + cb->player.input.x)
					- (temp->x + 2);
// 			else
// 				cb->player.pos.x += cb->player.input.x;
// 			if (cb->player.input.y + cb->player.input.y > temp->y + 2)
// 				cb->player.pos.y = (cb->player.input.y + cb->player.input.y)
					- (temp->y + 2);
// 			else
// 				cb->player.pos.y += cb->player.input.y;
//             return ;
// 		}
// 		temp = temp->next;
// 	}
// 	// player pos stays same
// }

void	valid_x_ll(t_cb *cb)
{
	t_valid_cords	*temp;

	// printf("walking: %f, %f\n", cb->player.input.x, cb->player.input.y);
	// x 1,1
	temp = cb->cords;
	while (temp)
	{
		if (((cb->player.pos.x + cb->player.input.x) > temp->x)
			&& (cb->player.pos.x + cb->player.input.x) < temp->x + 1
			&& (cb->player.pos.y >= temp->y && cb->player.pos.y <= temp->y + 1))
		{
			break ;
		}
		temp = temp->next;
		if (!temp)
		{
			if (cb->player.input.x < 0)
				cb->player.input.x = -1 * (cb->player.pos.x
						- floor(cb->player.pos.x));
			else
				cb->player.input.x = (ceil(cb->player.pos.x)
						- cb->player.pos.x);
		}
	}
	temp = cb->cords;
	while (temp)
	{
		if (((cb->player.pos.y + cb->player.input.y) > temp->y)
			&& (cb->player.pos.y + cb->player.input.y) < temp->y + 1
			&& (cb->player.pos.x >= temp->x && cb->player.pos.x <= temp->x + 1))
			break ;
		temp = temp->next;
		if (!temp)
		{
			if (cb->player.input.y < 0)
				cb->player.input.y = -1 * (cb->player.pos.y
						- floor(cb->player.pos.y));
			else
				cb->player.input.y = (ceil(cb->player.pos.y)
						- cb->player.pos.y);
		}
	}
	// printf("changed walking: %f, %f\n", cb->player.input.x,
		cb->player.input.y);
	cb->player.pos.x += cb->player.input.x;
	cb->player.pos.y += cb->player.input.y;
}

// void	new_player_pos(t_cb *cb)
// {

// }

void	player_walk(t_cb *cb)
{
	cb->player.input = rotate(cb->player.input, cb->player.rot * -1);
	// cb->player.pos.x += cb->player.input.x;
	// cb->player.pos.y += cb->player.input.y;
	valid_x_ll(cb);
}