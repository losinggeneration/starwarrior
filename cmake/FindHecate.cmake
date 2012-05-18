# Locate Hecate library
# This module defines
# HECATE_LIBRARY, the name of the library to link against
# HECATE_FOUND, if false, do not try to link to hecate
# HECATE_INCLUDE_DIR, where to find hecate/hecate.h
#
#
# Created by Harley Laue. This was influenced by FindSDL_gfx.cmake
# Original by David Demelier, which was influenced by the FindSDL_mixer.cmake

#=============================================================================
# Copyright 2005-2009 Kitware, Inc.
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
# (To distribute this file outside of CMake, substitute the full
#  License text for the above reference.)

FIND_PATH(HECATE_INCLUDE_DIR hecate.h
	HINTS
	$ENV{HECATEDIR}
	PATH_SUFFIXES include
	PATHS
	~/Library/Frameworks
	/Library/Frameworks
	/usr/local/include/hecate
	/usr/include/hecate
	/usr/local/include
	/usr/include
	/sw/include/hecate # Fink
	/sw/include
	/opt/local/include/hecate # DarwinPorts
	/opt/local/include
	/opt/csw/include/hecate # Blastwave
	/opt/csw/include
	/opt/include/hecate
	/opt/include
)

FIND_LIBRARY(HECATE_LIBRARY
	NAMES hecate
	HINTS
	$ENV{HECATEDIR}
	PATH_SUFFIXES lib64 lib
	PATHS
	~/Library/Frameworks
	/Library/Frameworks
	/usr/local
	/usr
	/sw
	/opt/local
	/opt/csw
	/opt
)

SET(HECATE_FOUND "NO")
IF(HECATE_LIBRARY AND HECATE_INCLUDE_DIR)
	SET(HECATE_FOUND "YES")
ENDIF(HECATE_LIBRARY AND HECATE_INCLUDE_DIR)
