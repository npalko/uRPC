namespace AddIn {
  partial class Ribbon {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary> 
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing) {
      if (disposing && (components != null)) {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Component Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent() {
      this.tab1 = new Microsoft.Office.Tools.Ribbon.RibbonTab();
      this.group1 = new Microsoft.Office.Tools.Ribbon.RibbonGroup();
      this.toggleTaskPlaneButton = new Microsoft.Office.Tools.Ribbon.RibbonButton();
      this.sendButton = new Microsoft.Office.Tools.Ribbon.RibbonButton();
      this.tab1.SuspendLayout();
      this.group1.SuspendLayout();
      this.SuspendLayout();
      // 
      // tab1
      // 
      this.tab1.ControlId.ControlIdType = Microsoft.Office.Tools.Ribbon.RibbonControlIdType.Office;
      this.tab1.Groups.Add(this.group1);
      this.tab1.Label = "TabAddIns";
      this.tab1.Name = "tab1";
      // 
      // group1
      // 
      this.group1.Items.Add(this.toggleTaskPlaneButton);
      this.group1.Items.Add(this.sendButton);
      this.group1.Label = "uRPC";
      this.group1.Name = "group1";
      // 
      // toggleTaskPlaneButton
      // 
      this.toggleTaskPlaneButton.Label = "Toggle Task Plane";
      this.toggleTaskPlaneButton.Name = "toggleTaskPlaneButton";
      this.toggleTaskPlaneButton.Click += new System.EventHandler<Microsoft.Office.Tools.Ribbon.RibbonControlEventArgs>(this.toggleTaskPlaneButton_Click);
      // 
      // sendButton
      // 
      this.sendButton.Label = "Send!";
      this.sendButton.Name = "sendButton";
      this.sendButton.Click += new System.EventHandler<Microsoft.Office.Tools.Ribbon.RibbonControlEventArgs>(this.sendButton_Click);
      // 
      // Ribbon
      // 
      this.Name = "Ribbon";
      this.RibbonType = "Microsoft.Excel.Workbook";
      this.Tabs.Add(this.tab1);
      this.Load += new System.EventHandler<Microsoft.Office.Tools.Ribbon.RibbonUIEventArgs>(this.Ribbon_Load);
      this.tab1.ResumeLayout(false);
      this.tab1.PerformLayout();
      this.group1.ResumeLayout(false);
      this.group1.PerformLayout();
      this.ResumeLayout(false);

    }

    #endregion

    internal Microsoft.Office.Tools.Ribbon.RibbonTab tab1;
    internal Microsoft.Office.Tools.Ribbon.RibbonGroup group1;
    internal Microsoft.Office.Tools.Ribbon.RibbonButton toggleTaskPlaneButton;
    internal Microsoft.Office.Tools.Ribbon.RibbonButton sendButton;
  }

  partial class ThisRibbonCollection : Microsoft.Office.Tools.Ribbon.RibbonReadOnlyCollection {
    internal Ribbon Ribbon {
      get { return this.GetRibbon<Ribbon>(); }
    }
  }
}
