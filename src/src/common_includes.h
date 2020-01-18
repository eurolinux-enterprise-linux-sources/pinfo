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

#ifndef __COMMON_INCLUDES_H
#define __COMMON_INCLUDES_H

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

#ifdef HAVE_CONFIG_H
 #include "config.h"
#endif

#include CURSES_H_NAME

/* fall back to using 'E' is curses doesn't support the end key */ 
#ifndef CURSES_KEY_END
 #define KEY_END	'E'
#endif
/* quick hack;
 * really should replace all the NO_COLOR_CURSES checks 
 * by CURSES_COLORS
 */
#ifndef CURSES_COLORS
 #define NO_COLOR_CURSES
#endif


#include "localestuff.h"

#include "rcsid.h"
#include "datatypes.h"
#include "filehandling_functions.h"
#include "video.h"
#include "menu_and_note_utils.h"
#include "mainfunction.h"
#include "utils.h"
#include "signal_handler.h"
#include "colors.h"
#include "regexp_search.h"
#include "manual.h"
#include "parse_config.h"
#include "keyboard.h"
#include "initializelinks.h"
#include "printinfo.h"

/*
 * Readline isn't safe for nonlinux terminals (i.e. vt100)
 * But if you have readline linked with ncurses you may enable readline with
 * ./configure --with-readline
 *
 */
#ifndef HAS_READLINE
#include "readlinewrapper.h"
#endif /* HAS_READLINE */

#ifndef HAVE_SIGBLOCK
#include "sigblock.h"
#endif

/* I hear voices, that it is needed by RH5.2 ;) */
#define _REGEX_RE_COMP
#endif
