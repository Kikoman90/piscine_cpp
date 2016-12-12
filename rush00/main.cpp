/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:35:38 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/12 14:45:43 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

#define HEIGHT height
#define WIDTH width

/*char    choices[5][10] = { 
			"Choice 1",
			"Choice 2",
			"Choice 3",
			"Choice 4",
			"Exit",
		  };
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);*/

//caracteres utiles pour vaisseaux: ACS_BTEE, ACS_BLOCK
//ACS_BULLET, ACS_CKBOARD, ACS_DEGREE, ACS_DIAMOND, ACS_GEQUAL, ACS_LEQUAL
//ACS_LLCORNER, ACS_LRCORNER, ACS_LTEE, ACS_NEQUAL, ACS_PI, ACS_PLMINUS
//caracteres aussi utiles pour armes: ACS_HLINE
/*en gros tout:ACS_RARROW              arrow pointing right
       ACS_RTEE                right tee
       ACS_S1                  scan line 1
       ACS_S3                  scan line 3
       ACS_S7                  scan line 7
       ACS_S9                  scan line 9
       ACS_STERLING            pound-sterling symbol
       ACS_TTEE                top tee
       ACS_UARROW              arrow pointing up
       ACS_ULCORNER            upper left-hand corner
       ACS_URCORNER            upper right-hand corner
       ACS_VLINE               vertical line*/

void    print_env(void)
{
    int x = 0;
    int y = 0;
    int i = 0;
	int	height;
	int	width;

    start_color();
	init_color(COLOR_BLACK, 100, 100, 100);
	init_color(COLOR_RED, 1000, 1000, 1000);
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_RED);
	clear();
    box(stdscr, 0, 0);
	wrefresh(stdscr);
    getmaxyx(stdscr, height, width);
    while (++y < HEIGHT)
    {
        x = 1;
        while (++x < WIDTH)
        {
            i = rand() % 100;
            wmove(stdscr, y, x);
            if (i < 4)
                waddch(stdscr, '+' | A_DIM | COLOR_PAIR(2));
            else if (i > 98)
                waddch(stdscr, ACS_DEGREE | A_DIM | COLOR_PAIR(2));
            x++;
        }
        y++;
    }
	mvwprintw(stdscr, 1, 4, "|");
	mvwprintw(stdscr, 2, 1, "---");
	wmove(stdscr, 2, 4);
	waddch(stdscr, ACS_LRCORNER);
    wrefresh(stdscr);
	wmove(stdscr, 1, 1);
}

int main()
{
    //int timer = 120;

    srand(time(NULL));
	
	initscr();
	noecho();
	cbreak(); /* Line buffering disabled. pass on everything */
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
    
	//menu_win = newwin(HEIGHT, WIDTH, starty, startx);
    //print  a string at (1, 1): mvprintw(1, 1, "string");
    print_env();
	while(wgetch(stdscr) != 27)/* && timer > 0)*/
	{
		;
        //wprintw(stdscr, "%i", timer);
        //wrefresh(stdscr);
        //werase(stdscr);
        //timer--;
        //sleep(1);
	}
	wclear(stdscr);
	wrefresh(stdscr);
	endwin();
	return 0;
}

/*wattron(menu_win, A_REVERSE); 
mvwprintw(menu_win, y, x, "%s", choices[i]);
wattroff(menu_win, A_REVERSE);*/