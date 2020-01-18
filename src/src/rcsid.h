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

/*
 * $Id: rcsid.h 280 2006-03-09 19:44:48Z bas $
 */
#define PKG_VER " $Package: " PACKAGE " $ $Version: " VERSION " $ "
#if defined(NO_RCSID) || defined(lint)
# define RCSID(x)		/* empty */
#else
# if __STDC__
/*
 * This function is never called from anywhere, but it calls itself
 * recursively only to fool gcc to not generate warnings :-).
 */
static const char *rcsid (const char *);
# define RCSID(x) \
	static const char *rcsid(const char *s) { \
		return rcsid(x); }
#else /* ! __STDC__ */
# define RCSID(x) \
	static char *rcsid(s) char *s; { \
		return rcsid(x); }
#endif /* ! __STDC__ */
#endif
