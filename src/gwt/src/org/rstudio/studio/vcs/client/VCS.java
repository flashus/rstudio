package org.rstudio.studio.vcs.client;


import org.rstudio.core.client.Debug;

import com.google.gwt.core.client.EntryPoint;
import com.google.gwt.dom.client.Document;


public class VCS implements EntryPoint
{  
   public void onModuleLoad() 
   {
      

      Document.get().getBody().getStyle().setBackgroundColor("#e1e2e5");

      
      Debug.log(VCSGinjector.INSTANCE.getCommands().toString());
      
   }
}

