/*
 * PreferencesDialogResources.java
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
package org.rstudio.studio.client.workbench.prefs.views;

import com.google.gwt.resources.client.ClientBundle;
import com.google.gwt.resources.client.CssResource;
import com.google.gwt.resources.client.ImageResource;

public interface PreferencesDialogResources extends ClientBundle
{
   public interface Styles extends CssResource
   {
      String panelContainer();
      String paneLayoutTable();
      String themeChooser();
      String usingVcsHelp();
      String viewSshKey();
      String newSection();
      String encodingChooser();
   }

   @Source("PreferencesDialog.css")
   Styles styles();

   ImageResource iconAppearance();
   ImageResource iconPanes();
}
