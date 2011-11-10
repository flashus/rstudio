package org.rstudio.studio.vcs.client;



import com.google.gwt.core.client.GWT;
import com.google.gwt.inject.client.GinModules;
import com.google.gwt.inject.client.Ginjector;

@GinModules(VCSGinModule.class)
public interface VCSGinjector extends Ginjector
{
   public static final VCSGinjector INSTANCE = GWT.create(VCSGinjector.class);

   Commands getCommands();
}