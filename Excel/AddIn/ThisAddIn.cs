using System;
using System.Collections.Generic;
using System.Text;
using Excel = Microsoft.Office.Interop.Excel;
using Office = Microsoft.Office.Core;

namespace AddIn {
  public partial class ThisAddIn {
    public void togglePaneVisibility() {
      pane.Visible = !pane.Visible;
    }
    private UrpcControl urpcControl;
    private Microsoft.Office.Tools.CustomTaskPane pane; // application-level custom task plane
    private void ThisAddIn_Startup(object sender, System.EventArgs e) {
      urpcControl = new UrpcControl();
      pane = CustomTaskPanes.Add(urpcControl, "uRPC");

      Application.WindowActivate += 
        new Excel.AppEvents_WindowActivateEventHandler(
          Application_WindowActivate);
    }
    private void Application_WindowActivate(Excel.Workbook Wb, Excel.Window Wn) {
      // called whenever a different workbook is selected
      // modelControl.UpdateWorkbookName(Wb.Name);

      // whever we switch worksheets, move the worksheet values into
      // the toggle
    }
    private void ThisAddIn_Shutdown(object sender, System.EventArgs e) {
    }

    #region VSTO generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InternalStartup() {
      this.Startup += new System.EventHandler(ThisAddIn_Startup);
      this.Shutdown += new System.EventHandler(ThisAddIn_Shutdown);
    }

    #endregion
  }
}
