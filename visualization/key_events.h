/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:12:00 by khrechen          #+#    #+#             */
/*   Updated: 2017/10/17 16:27:01 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_EVENTS_H
# define KEY_EVENTS_H

# define KEY_PRESS		2
# define KEY_RELEASE	3
# define MOTION_NOTIFY	6
# define DESTROY_NOTIFY	17

# define POINTER_MOTION_MASK	(1L << 6)
# define STRUCTURE_NOTIFY_MASK	(1L << 17)
# define KEY_PRESS_MASK			(1L << 0)
# define KEY_RELEASE_MASK		(1L << 1)

#endif
