/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:35:38 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/12 19:02:25 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <fstream>

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

std::string     fill_background()
{
    std::ofstream   file("env/background.env");
    
    file.open()
    
    file.close();
    
}

void    print_env(void)
{
    int x;
    int y = 1;
    int i = 0;
	int	height;
	int	width;

    start_color();
	init_color(COLOR_YELLOW, 220, 220, 220);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    bkgdset(COLOR_PAIR(1));
    box(stdscr, 0, 0);
    getmaxyx(stdscr, height, width);
    while (++y < HEIGHT - 1)
    {
        x = 1;
        while (++x < WIDTH)
        {
            i = rand() % 100;
            wmove(stdscr, y, x);
            if (i < 4)
                waddch(stdscr, '+' | COLOR_PAIR(2));
            else if (i > 98)
                waddch(stdscr, ACS_DEGREE | COLOR_PAIR(2));
            x++;
        }
        y++;
    }
    mvwprintw(stdscr, 1, 1, "time:");
	mvwprintw(stdscr, 1, 10, "|");
	mvwprintw(stdscr, 2, 1, "---------");
	wmove(stdscr, 2, 10);
	waddch(stdscr, ACS_LRCORNER);
    wrefresh(stdscr);
}

int main()
{
    int timer = 120;

    srand(time(NULL));
	
	initscr();
	noecho();
	cbreak(); /* Line buffering disabled. pass on everything */
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
    print_env();
	while(wgetch(stdscr) != 27 && timer > 0)
	{
        print_env();
        mvwprintw(stdscr, 1, 7, "%i", timer);
        wrefresh(stdscr);
        werase(stdscr);
        timer--;
        sleep(1);
	}
	wclear(stdscr);
	wrefresh(stdscr);
	endwin();
	return 0;
}