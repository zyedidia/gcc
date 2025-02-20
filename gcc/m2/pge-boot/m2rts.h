/* m2rts.h provides a C interface to M2RTS.mod.

Copyright (C) 2019-2024 Free Software Foundation, Inc.
Contributed by Gaius Mulley <gaius.mulley@southwales.ac.uk>.

This file is part of GNU Modula-2.

GNU Modula-2 is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GNU Modula-2 is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#ifdef M2_MC
/* These type definitions match those used by mc, they are defined differently
   to satisfy -Wodr when building from the mc translated versions of m2
   source.  */
#include "GM2RTS.h"
#else
/* These type definitions match those used by cc1gm2, they will be the same
   sizeof as those above (and also for all their dependants).  */
typedef void (*M2RTS_ArgCVEnvP) (int, char **, char **);
typedef void (*PROC) (void);
#endif

#define M2RTS_RegisterModule_Cstr(MODNAME,LIBNAME,init,fini,dep) \
  M2RTS_RegisterModule (reinterpret_cast <void *> (const_cast <char *> (MODNAME)), \
			reinterpret_cast <void *> (const_cast <char *> (LIBNAME)), \
			init, fini, dep)

extern "C" void M2RTS_RequestDependant (const void *modulename, const void *dependancy);
extern "C" void M2RTS_RegisterModule (void *modulename, void *libname,
				      M2RTS_ArgCVEnvP init, M2RTS_ArgCVEnvP fini, PROC dependencies);
extern "C" void _M2_M2RTS_init (void);

extern "C" void M2RTS_ConstructModules (const void *,
					int argc, char *argv[], char *envp[]);
extern "C" void M2RTS_Terminate (void);
extern "C" void M2RTS_DeconstructModules (void);

extern "C" void M2RTS_Halt (const char *, const char *, const char *, int) __attribute__ ((noreturn));
