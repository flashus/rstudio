#
# CMakeLists.txt
#
# Copyright (C) 2009-11 by RStudio, Inc.
#
# This program is licensed to you under the terms of version 3 of the
# GNU Affero General Public License. This program is distributed WITHOUT
# ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
# MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
# AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
#
#

project (DETACH)

# include files
file(GLOB_RECURSE DETACH_HEADER_FILES "*.h*")

# source files
set(DETACH_SOURCE_FILES
   DetachMain.cpp
)

# set include directories
include_directories(
   ${Boost_INCLUDE_DIRS}
   ${CORE_SOURCE_DIR}/include
   ${SESSION_SOURCE_DIR}/include
)

# define executable
add_executable(detach ${DETACH_SOURCE_FILES} ${DETACH_HEADER_FILES})

# set link dependencies
target_link_libraries(detach
   rstudio-core
)

# installation rules
install(TARGETS detach DESTINATION ${RSTUDIO_INSTALL_BIN})



