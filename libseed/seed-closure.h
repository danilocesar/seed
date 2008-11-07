/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * seed-builtins.h
 * Copyright (C) Robert Carr 2008 <carrr@rpi.edu>
 *
 * libseed is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libseed is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _SEED_CLOSURE_H_
#define _SEED_CLOSURE_H_

#include "seed-private.h"

typedef struct _SeedClosure {
	GClosure closure;
	JSObjectRef function;
	JSObjectRef object;
	JSObjectRef this;
} SeedClosure;

typedef struct _SeedNativeClosure
{
		GICallableInfo * info;
		JSValueRef function;
		
		ffi_closure * closure;
		ffi_cif * cif;
} SeedNativeClosure;

extern JSClassRef seed_native_callback_class;

SeedNativeClosure * seed_make_native_closure(GICallableInfo * info,
					JSValueRef function);
SeedClosure * seed_make_gclosure(JSObjectRef function,
								 JSObjectRef this);

void seed_closures_init();

#endif