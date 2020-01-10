/***************************************************************************
 *  Pinfo is a ncurses based lynx style info documentation browser
 *
 *  Copyright (C) 1999  Przemek Borys <pborys@dione.ids.pl>
 *  Copyright (C) 2005  Bas Zoetekouw <bas@debian.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of version 2 of the GNU General Public License as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301
 *  USA
 ***************************************************************************/
#include "common_includes.h"

RCSID("$Id: signal_handler.c 280 2006-03-09 19:44:48Z bas $")

#include <termios.h>
#include <sys/ioctl.h>

void
handle_crash(int signum)
{
	closeprogram();
	fprintf(stderr, "Caught signal %d, bye!\n", signum);
	if (signum == SIGSEGV)
		perror("pinfo: crash with");
	exit(1);
}

void
handle_window_resize(int signum)
{
	winchanged = 1;
	ungetch(keys.refresh_1);
	signal(SIGWINCH, handle_window_resize);
}

void
signal_handler()
{
	sigset_t sigs;
	
	signal(SIGINT, handle_crash);	/* handle ^C */
	signal(SIGTERM, handle_crash);	/* handle soft kill */
	signal(SIGSEGV, handle_crash);	/* handle seg. fault */
	signal(SIGHUP, handle_crash);	/* handle hup signal */
#ifdef SIGWINCH
	signal(SIGWINCH, handle_window_resize);
#endif
	/* block broken pipe signal */
	sigemptyset(&sigs);
	sigaddset(&sigs, SIGPIPE);
	sigprocmask(SIG_BLOCK, &sigs, NULL);
}
