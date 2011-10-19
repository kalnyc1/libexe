/*
 * The internal definitions
 *
 * Copyright (c) 2011, Joachim Metz <jbmetz@users.sourceforge.net>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBEXE_INTERNAL_DEFINITIONS_H )
#define _LIBEXE_INTERNAL_DEFINITIONS_H

#include <common.h>
#include <byte_stream.h>

#define LIBEXE_ENDIAN_BIG				_BYTE_STREAM_ENDIAN_BIG
#define LIBEXE_ENDIAN_LITTLE				_BYTE_STREAM_ENDIAN_LITTLE

/* Define HAVE_LOCAL_LIBEXE for local use of libexe
 */
#if !defined( HAVE_LOCAL_LIBEXE )
#include <libexe/definitions.h>

/* The definitions in <libexe/definitions.h> are copied here
 * for local use of libexe
 */
#else
#define LIBEXE_VERSION					20111018

/* The version string
 */
#define LIBEXE_VERSION_STRING				"20111018"

/* The access flags definitions
 * bit 1        set to 1 for read access
 * bit 2        set to 1 for write access
 * bit 3-8      not used
 */
enum LIBEXE_ACCESS_FLAGS
{
	LIBEXE_ACCESS_FLAG_READ				= 0x01,
/* Reserved: not supported yet */
	LIBEXE_ACCESS_FLAG_WRITE			= 0x02
};

/* The file access macros
 */
#define LIBEXE_OPEN_READ				( LIBEXE_ACCESS_FLAG_READ )
/* Reserved: not supported yet */
#define LIBEXE_OPEN_WRITE				( LIBEXE_ACCESS_FLAG_WRITE )
/* Reserved: not supported yet */
#define LIBEXE_OPEN_READ_WRITE				( LIBEXE_ACCESS_FLAG_READ | LIBEXE_ACCESS_FLAG_WRITE )

/* The event type definitions
 */
enum LIBEXE_EVENT_TYPES
{
	LIBEXE_EVENT_TYPE_ERROR				= 0x0001,
	LIBEXE_EVENT_TYPE_WARNING			= 0x0002,
	LIBEXE_EVENT_TYPE_INFORMATION			= 0x0004,
	LIBEXE_EVENT_TYPE_AUDIT_SUCCESS			= 0x0008,
	LIBEXE_EVENT_TYPE_AUDIT_FAILURE			= 0x0010,
};

#endif

#endif

