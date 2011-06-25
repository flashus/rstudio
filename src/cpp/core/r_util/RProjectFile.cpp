/*
 * RProjectFile.cpp
 *
 * Copyright (C) 2009-11 by RStudio, Inc.
 *
 * This program is licensed to you under the terms of version 3 of the
 * GNU Affero General Public License. This program is distributed WITHOUT
 * ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
 * AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
 *
 */

#include <core/r_util/RProjectFile.hpp>

#include <core/Error.hpp>
#include <core/FilePath.hpp>
#include <core/FileSerializer.hpp>

namespace core {
namespace r_util {

Error writeDefaultProjectFile(const FilePath& filePath)
{
   std::string p;
   p = "# R project config file\n"
       "# http://www.rstudio.org/docs/r_project_config\n"
       "#\n";

   return writeStringToFile(filePath, p, string_utils::LineEndingNative);
}

} // namespace r_util
} // namespace core 


