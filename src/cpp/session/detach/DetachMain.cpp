/*
 * PostbackMain.cpp
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

#include <windows.h>

#include <iostream>

#include <core/Error.hpp>
#include <core/FilePath.hpp>
#include <core/system/Process.hpp>
#include <core/Log.hpp>
#include <core/StringUtils.hpp>

using namespace core ;

int runDetached(LPWSTR pCommand)
{
   /*
   core::system::ProcessOptions options;
   options.detachProcess = true;
   core::system::ProcessResult result;
   core::system::runCommand(
         string_utils::utf8ToSystem(string_utils::wideToUtf8(pCommand)),
         options,
         &result);

   // These are out of order. Oh well.
   std::cout << result.stdOut;
   std::cerr << result.stdErr;

   return result.exitStatus;
   */

   LPWSTR pCmd = ::wcsdup(pCommand);

   STARTUPINFOW si;
   PROCESS_INFORMATION pi;
   si.cb=sizeof(STARTUPINFO);
   GetStartupInfoW(&si);

//   si.wShowWindow=SW_HIDE;
//   si.dwFlags=STARTF_USESHOWWINDOW;

   LPTSTR pEnv = NULL;
   DWORD dwFlags = CREATE_UNICODE_ENVIRONMENT;

   //DETACHED_PROCESS make ssh recognize that it has no console to launch askpass to input password.
   dwFlags |= DETACHED_PROCESS | CREATE_NEW_PROCESS_GROUP;

   memset(&pi, 0, sizeof(PROCESS_INFORMATION));

   if(!CreateProcessW(NULL,pCmd, NULL,NULL,TRUE,dwFlags,pEnv,NULL,&si,&pi))
   {
         return EXIT_FAILURE;
   }

   if (::WaitForSingleObject(pi.hProcess, INFINITE) != WAIT_OBJECT_0)
      return EXIT_FAILURE;

   DWORD result;
   if (!GetExitCodeProcess(pi.hProcess, &result))
      return EXIT_FAILURE;

   return result;
}

int main(int argc, char * const argv[]) 
{
   LPWSTR pCmdLine = ::GetCommandLineW();
   ::FreeConsole();
   const int STATE_START = 0;
   const int STATE_IN_QUOTED_ARG = 1;
   const int STATE_IN_BACKSLASH = 2;
   const int STATE_IN_UNQUOTED_ARG = 3;
   const int STATE_DONE_WITH_ARG = 4;

   int state = STATE_START;

   while (true)
   {
      wchar_t c = *(pCmdLine++);

      if (c == 0)
         return EXIT_FAILURE;

      switch(state)
      {
      case STATE_START:
         switch (c)
         {
         case L' ':
         case L'\t':
            state = STATE_START;
            continue;
         case L'"':
            state = STATE_IN_QUOTED_ARG;
            continue;
         default:
            state = STATE_IN_UNQUOTED_ARG;
            continue;
         }
         break;
      case STATE_IN_QUOTED_ARG:
         switch (c)
         {
         case L'"':
            state = STATE_DONE_WITH_ARG;
            continue;
         case L'\\':
            state = STATE_IN_BACKSLASH;
            continue;
         default:
            state = STATE_IN_QUOTED_ARG;
            continue;
         }
         break;
      case STATE_IN_BACKSLASH:
         state = STATE_IN_QUOTED_ARG;
         continue;
      case STATE_IN_UNQUOTED_ARG:
         switch (c)
         {
         case L' ':
         case L'\t':
            state = STATE_DONE_WITH_ARG;
            continue;
         default:
            state = STATE_IN_UNQUOTED_ARG;
            continue;
         }
         break;
      case STATE_DONE_WITH_ARG:
         switch (c)
         {
         case L' ':
         case L'\t':
            state = STATE_DONE_WITH_ARG;
            continue;
         default:
            // Un-eat the current character
            pCmdLine--;
            return runDetached(pCmdLine);
         }
         break;
      }

      std::cerr << "Programmer error" << std::endl;
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}

