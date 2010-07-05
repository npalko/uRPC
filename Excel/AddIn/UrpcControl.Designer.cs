namespace AddIn {
  partial class UrpcControl {
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
      this.groupBox1 = new System.Windows.Forms.GroupBox();
      this.trackBar1 = new System.Windows.Forms.TrackBar();
      this.button1 = new System.Windows.Forms.Button();
      this.label1 = new System.Windows.Forms.Label();
      this.groupBox1.SuspendLayout();
      ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).BeginInit();
      this.SuspendLayout();
      // 
      // groupBox1
      // 
      this.groupBox1.Controls.Add(this.label1);
      this.groupBox1.Controls.Add(this.button1);
      this.groupBox1.Controls.Add(this.trackBar1);
      this.groupBox1.Location = new System.Drawing.Point(3, 3);
      this.groupBox1.Name = "groupBox1";
      this.groupBox1.Size = new System.Drawing.Size(200, 144);
      this.groupBox1.TabIndex = 0;
      this.groupBox1.TabStop = false;
      this.groupBox1.Text = "groupBox1";
      // 
      // trackBar1
      // 
      this.trackBar1.Location = new System.Drawing.Point(6, 19);
      this.trackBar1.Name = "trackBar1";
      this.trackBar1.Size = new System.Drawing.Size(188, 42);
      this.trackBar1.TabIndex = 0;
      this.trackBar1.Scroll += new System.EventHandler(this.trackBar1_Scroll);
      // 
      // button1
      // 
      this.button1.Location = new System.Drawing.Point(6, 67);
      this.button1.Name = "button1";
      this.button1.Size = new System.Drawing.Size(75, 23);
      this.button1.TabIndex = 1;
      this.button1.Text = "button1";
      this.button1.UseVisualStyleBackColor = true;
      this.button1.Click += new System.EventHandler(this.button1_Click);
      // 
      // label1
      // 
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(87, 72);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(35, 13);
      this.label1.TabIndex = 2;
      this.label1.Text = "label1";
      this.label1.Click += new System.EventHandler(this.label1_Click);
      // 
      // UrpcControl
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.Controls.Add(this.groupBox1);
      this.Name = "UrpcControl";
      this.Size = new System.Drawing.Size(209, 150);
      this.groupBox1.ResumeLayout(false);
      this.groupBox1.PerformLayout();
      ((System.ComponentModel.ISupportInitialize)(this.trackBar1)).EndInit();
      this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.GroupBox groupBox1;
    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Button button1;
    private System.Windows.Forms.TrackBar trackBar1;
  }
}
