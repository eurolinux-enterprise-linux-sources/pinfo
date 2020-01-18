/* Copyright(C) 1991, 94, 95, 96, 97, 98 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or(at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* orginal from glibc 2.1 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "rcsid.h"
RCSID("$Id: sigblock.c 9 2005-06-01 17:49:24Z bas $")

#ifndef HAVE_SIGBLOCK

#include <errno.h>
#include <signal.h>
#include "sigblock.h"

/* Block signals in MASK, returning the old mask.  */
int
sigblock(int mask)
{
	register int sig;
	sigset_t set, oset;

	if (sigemptyset(&set) < 0)
		return -1;

	if (sizeof(mask) == sizeof(set))
		*(int *) &set = mask;
	else if (sizeof(unsigned long int) == sizeof(set))
		*(unsigned long int *) &set =(unsigned int) mask;
	else
		for (sig = 1; sig < NSIG && sig <= sizeof(mask) * 8; ++sig)
			if ((mask & sigmask(sig)) && sigaddset(&set, sig) < 0)
				return -1;

	if (sigprocmask(SIG_BLOCK, &set, &oset) < 0)
		return -1;

	if (sizeof(mask) == sizeof(oset))
		mask = *(int *) &oset;
	else if (sizeof(unsigned long int) == sizeof(oset))
		mask = *(unsigned long int *) &oset;
	else
		for (sig = 1, mask = 0; sig < NSIG && sig <= sizeof(mask) * 8; ++sig)
			if (sigismember(&oset, sig))
				mask |= sigmask(sig);

	return mask;
}

#endif /* HAVE_SIGBLOCK */
