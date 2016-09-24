/*
 * Library section type testing program
 *
 * Copyright (C) 2011-2016, Joachim Metz <joachim.metz@gmail.com>
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

#include <common.h>
#include <file_stream.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "exe_test_libcerror.h"
#include "exe_test_libcstring.h"
#include "exe_test_libexe.h"
#include "exe_test_macros.h"
#include "exe_test_memory.h"
#include "exe_test_unused.h"

/* Tests the libexe_section_initialize function
 * Returns 1 if successful or 0 if not
 */
int exe_test_section_initialize(
     void )
{
	libcerror_error_t *error             = NULL;
	libexe_section_t *section = NULL;
	int result                           = 0;

	/* Test libexe_section_initialize
	 */
	result = libexe_section_initialize(
	          &section,
	          &error );

	EXE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        EXE_TEST_ASSERT_IS_NOT_NULL(
         "section",
         section );

        EXE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libexe_section_free(
	          &section,
	          &error );

	EXE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        EXE_TEST_ASSERT_IS_NULL(
         "section",
         section );

        EXE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libexe_section_initialize(
	          NULL,
	          &error );

	EXE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        EXE_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	section = (libexe_section_t *) 0x12345678UL;

	result = libexe_section_initialize(
	          &section,
	          &error );

	EXE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        EXE_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	section = NULL;

#if defined( HAVE_EXE_TEST_MEMORY )

	/* Test libexe_section_initialize with malloc failing
	 */
	exe_test_malloc_attempts_before_fail = 0;

	result = libexe_section_initialize(
	          &section,
	          &error );

	if( exe_test_malloc_attempts_before_fail != -1 )
	{
		exe_test_malloc_attempts_before_fail = -1;
	}
	else
	{
		EXE_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		EXE_TEST_ASSERT_IS_NULL(
		 "section",
		 section );

		EXE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libexe_section_initialize with memset failing
	 */
	exe_test_memset_attempts_before_fail = 0;

	result = libexe_section_initialize(
	          &section,
	          &error );

	if( exe_test_memset_attempts_before_fail != -1 )
	{
		exe_test_memset_attempts_before_fail = -1;
	}
	else
	{
		EXE_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		EXE_TEST_ASSERT_IS_NULL(
		 "section",
		 section );

		EXE_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_EXE_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( section != NULL )
	{
		libexe_section_free(
		 &section,
		 NULL );
	}
	return( 0 );
}

/* Tests the libexe_section_free function
 * Returns 1 if successful or 0 if not
 */
int exe_test_section_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libexe_section_free(
	          NULL,
	          &error );

	EXE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        EXE_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc EXE_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] EXE_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc EXE_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] EXE_TEST_ATTRIBUTE_UNUSED )
#endif
{
	EXE_TEST_UNREFERENCED_PARAMETER( argc )
	EXE_TEST_UNREFERENCED_PARAMETER( argv )

	EXE_TEST_RUN(
	 "libexe_section_initialize",
	 exe_test_section_initialize() )

	EXE_TEST_RUN(
	 "libexe_section_free",
	 exe_test_section_free() )

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

