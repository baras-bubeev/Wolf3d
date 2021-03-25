/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpowder <mpowder@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:15:36 by mpowder           #+#    #+#             */
/*   Updated: 2021/03/23 21:13:34 by mpowder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_file_header(int fd, t_mlx *mlx)
{
    unsigned int    file_size;
    unsigned int    reserved;
    unsigned int    offset;

    file_size = mlx->cfg.r[0] * mlx->cfg.r[1] * 4 + 54;
    reserved = 0;
    offset = 54;
    write(fd, "BM", 2);
    write(fd, &file_size, 4);
    write(fd, &reserved, 4);
    write(fd, &offset, 4);
}

static void ft_info_header(int fd, t_mlx *mlx)
{
    unsigned int    header_size;
    unsigned short  planes;
    unsigned short  bpp;
    unsigned int    reserved;

    header_size = 40;
    planes = 1;
    bpp = 32;
    reserved = 0;
    write(fd, &header_size, 4);
    write(fd, &mlx->cfg.r[0], 4);
    write(fd, &mlx->cfg.r[1], 4);
    write(fd, &planes, 2);
    write(fd, &bpp, 2);
    write(fd, &reserved, 4);
    write(fd, &reserved, 4);
    write(fd, &reserved, 4);
    write(fd, &reserved, 4);
    write(fd, &reserved, 4);
    write(fd, &reserved, 4);
}

static void ft_image(int fd, t_mlx *mlx)
{
    int i;

    i = mlx->cfg.r[1] + 1;
    while (--i >= 0)
        write(fd, (unsigned char *)(mlx->img.addr + i *
        mlx->img.line_len), mlx->img.line_len);
}

void    ft_screen(t_mlx *mlx)
{
    int fd;

    if ((fd = open("image.bmp", O_WRONLY | O_CREAT | O_TRUNC, 755)) == -1)
        ft_exit(-1, CREATE_ERROR);
    ft_file_header(fd, mlx);
    ft_info_header(fd, mlx);
    ft_image(fd, mlx);
	(close(fd) < 0) ? ft_exit(-1, CLOSE_ERROR) : 0;
    write(1, "\"image.bmp\" created!\n", 22);
}