using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Office.Tools.Ribbon;

namespace AddIn {
  public partial class Ribbon : OfficeRibbon {
    public Ribbon() {
      InitializeComponent();
    }
    private void Ribbon_Load(object sender, RibbonUIEventArgs e) {
    }
    private void toggleTaskPlaneButton_Click(object sender, RibbonControlEventArgs e) {
      Globals.ThisAddIn.togglePaneVisibility();
    }
    private void sendButton_Click(object sender, RibbonControlEventArgs e) {
    }
  }
}
