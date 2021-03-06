/*
 * RPrefs.java
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
package org.rstudio.studio.client.workbench.prefs.model;

import com.google.gwt.core.client.JavaScriptObject;

public class RPrefs extends JavaScriptObject
{
   protected RPrefs() {}

   public static native final RPrefs createEmpty() /*-{
      var prefs = new Object();
      this.general_prefs = new Object();
      this.history_prefs = new Object();
      this.packages_prefs = new Object();
      this.projects_prefs = new Object();
      this.source_control_prefs = new Object();
      return prefs;
   }-*/;
   
   public native final GeneralPrefs getGeneralPrefs() /*-{
      return this.general_prefs;
   }-*/;
   
   public native final void setGeneralPrefs(GeneralPrefs generalPrefs) /*-{
      this.general_prefs = generalPrefs;
   }-*/;

   public native final HistoryPrefs getHistoryPrefs() /*-{
      return this.history_prefs;
   }-*/;
   
   public native final void setHistoryPrefs(HistoryPrefs historyPrefs) /*-{
      this.history_prefs = historyPrefs;
   }-*/;
   
   public native final PackagesPrefs getPackagesPrefs() /*-{
      return this.packages_prefs;
   }-*/;

   public native final void setPackagesPrefs(PackagesPrefs packagesPrefs) /*-{
      this.packages_prefs = packagesPrefs;
   }-*/;
   
   public native final ProjectsPrefs getProjectsPrefs() /*-{
      return this.projects_prefs;
   }-*/;

   public native final void setProjectsPrefs(ProjectsPrefs projectsPrefs) /*-{
      this.projects_prefs = projectsPrefs;
   }-*/;
   
   public native final SourceControlPrefs getSourceControlPrefs() /*-{
      return this.source_control_prefs;
   }-*/;

   public native final void setSourceControlPrefs(
                                 SourceControlPrefs sourceControlPrefs) /*-{
      this.source_control_prefs = sourceControlPrefs;
   }-*/;
}
