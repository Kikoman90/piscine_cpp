/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <fsidler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:35:38 by fsidler           #+#    #+#             */
/*   Updated: 2016/12/10 17:44:36 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ncurses.h>
#include <time.h>

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
    int height;
    int width;

    //start_color();
    box(stdscr, 0, 0);
    getmaxyx(stdscr, height, width);
    while (++y < HEIGHT)
    {
        x = 1;
        while (++x < WIDTH)
        {
            i = rand() % 100;
            wmove(stdscr, y, x); // ou move(y, x); meme chose ;)
            if (i < 4)
                waddch(stdscr, '+' | A_DIM);
            else if (i > 98)
                waddch(stdscr, ACS_DEGREE | A_DIM);        
            x++;
        }
        y++;
    }
    wrefresh(stdscr);
}

int main()
{
	//int highlight = 1;
	//int choice = 0;
	int c;

    srand(time(NULL));
	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
    
	//menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(stdscr, TRUE);
    //print  a string: mvprintw(1, 0, "Use arrow keys to go up and down, Press enter to select a choice");
	refresh();
    print_env();
	//print_menu(stdscr, highlight);
	while((c = wgetch(stdscr)) != 27)
	{
        ;
        /*switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else 
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
			default:
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_menu(stdscr, highlight);
		if(choice != 0) //User did a choice come out of the infinite loop
	    {
            mvprintw(3, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
			break;
        }*/
	}
	clrtoeol();
	refresh();
	endwin();
	return 0;
}

/*void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;	

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) High light the present choice
		{	wattron(menu_win, A_REVERSE); 
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}*/