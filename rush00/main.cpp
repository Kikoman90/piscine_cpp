/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:35:38 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/09 15:41:15 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <stdio.h>

int     main(void)
{
    int x = 10;
    int y = 10;
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, y, x);
    WINDOW *win = newwin(40, 40, y, x);
    //wmove(win, 20, 20);
    //waddch(win, 15);
    wrefresh(win);
    //delwin(win);
    //endwin();
    return 0;
}
