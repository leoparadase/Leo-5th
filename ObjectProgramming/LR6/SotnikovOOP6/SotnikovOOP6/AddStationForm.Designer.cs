
namespace SotnikovOOP6
{
    partial class AddStationForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.labelChangeID = new System.Windows.Forms.Label();
            this.labelChangeName = new System.Windows.Forms.Label();
            this.labelChangeLine = new System.Windows.Forms.Label();
            this.labelChangeCategory = new System.Windows.Forms.Label();
            this.textBoxID = new System.Windows.Forms.TextBox();
            this.textBoxName = new System.Windows.Forms.TextBox();
            this.textBoxLine = new System.Windows.Forms.TextBox();
            this.textBoxCategory = new System.Windows.Forms.TextBox();
            this.checkBoxIsTech = new System.Windows.Forms.CheckBox();
            this.buttonApplyChanges = new System.Windows.Forms.Button();
            this.labelDialog = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // labelChangeID
            // 
            this.labelChangeID.AutoSize = true;
            this.labelChangeID.Location = new System.Drawing.Point(31, 73);
            this.labelChangeID.Name = "labelChangeID";
            this.labelChangeID.Size = new System.Drawing.Size(21, 13);
            this.labelChangeID.TabIndex = 0;
            this.labelChangeID.Text = "ID:";
            // 
            // labelChangeName
            // 
            this.labelChangeName.AutoSize = true;
            this.labelChangeName.Location = new System.Drawing.Point(31, 112);
            this.labelChangeName.Name = "labelChangeName";
            this.labelChangeName.Size = new System.Drawing.Size(38, 13);
            this.labelChangeName.TabIndex = 1;
            this.labelChangeName.Text = "Name:";
            // 
            // labelChangeLine
            // 
            this.labelChangeLine.AutoSize = true;
            this.labelChangeLine.Location = new System.Drawing.Point(31, 151);
            this.labelChangeLine.Name = "labelChangeLine";
            this.labelChangeLine.Size = new System.Drawing.Size(30, 13);
            this.labelChangeLine.TabIndex = 2;
            this.labelChangeLine.Text = "Line:";
            // 
            // labelChangeCategory
            // 
            this.labelChangeCategory.AutoSize = true;
            this.labelChangeCategory.Location = new System.Drawing.Point(31, 190);
            this.labelChangeCategory.Name = "labelChangeCategory";
            this.labelChangeCategory.Size = new System.Drawing.Size(52, 13);
            this.labelChangeCategory.TabIndex = 3;
            this.labelChangeCategory.Text = "Category:";
            // 
            // textBoxID
            // 
            this.textBoxID.Location = new System.Drawing.Point(91, 70);
            this.textBoxID.Name = "textBoxID";
            this.textBoxID.Size = new System.Drawing.Size(41, 20);
            this.textBoxID.TabIndex = 4;
            // 
            // textBoxName
            // 
            this.textBoxName.Location = new System.Drawing.Point(91, 109);
            this.textBoxName.Name = "textBoxName";
            this.textBoxName.Size = new System.Drawing.Size(85, 20);
            this.textBoxName.TabIndex = 5;
            // 
            // textBoxLine
            // 
            this.textBoxLine.Location = new System.Drawing.Point(91, 148);
            this.textBoxLine.Name = "textBoxLine";
            this.textBoxLine.Size = new System.Drawing.Size(41, 20);
            this.textBoxLine.TabIndex = 6;
            // 
            // textBoxCategory
            // 
            this.textBoxCategory.Location = new System.Drawing.Point(91, 187);
            this.textBoxCategory.Name = "textBoxCategory";
            this.textBoxCategory.Size = new System.Drawing.Size(41, 20);
            this.textBoxCategory.TabIndex = 7;
            // 
            // checkBoxIsTech
            // 
            this.checkBoxIsTech.AutoSize = true;
            this.checkBoxIsTech.Location = new System.Drawing.Point(34, 226);
            this.checkBoxIsTech.Name = "checkBoxIsTech";
            this.checkBoxIsTech.Size = new System.Drawing.Size(87, 17);
            this.checkBoxIsTech.TabIndex = 8;
            this.checkBoxIsTech.Text = "Tech Station";
            this.checkBoxIsTech.UseVisualStyleBackColor = true;
            this.checkBoxIsTech.CheckedChanged += new System.EventHandler(this.checkBoxIsTech_CheckedChanged);
            // 
            // buttonApplyChanges
            // 
            this.buttonApplyChanges.Anchor = System.Windows.Forms.AnchorStyles.Bottom;
            this.buttonApplyChanges.Location = new System.Drawing.Point(73, 273);
            this.buttonApplyChanges.Name = "buttonApplyChanges";
            this.buttonApplyChanges.Size = new System.Drawing.Size(79, 29);
            this.buttonApplyChanges.TabIndex = 9;
            this.buttonApplyChanges.Text = "Apply";
            this.buttonApplyChanges.UseVisualStyleBackColor = true;
            this.buttonApplyChanges.Click += new System.EventHandler(this.buttonApplyChanges_Click);
            // 
            // labelDialog
            // 
            this.labelDialog.AutoSize = true;
            this.labelDialog.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelDialog.Location = new System.Drawing.Point(30, 25);
            this.labelDialog.Name = "labelDialog";
            this.labelDialog.Size = new System.Drawing.Size(165, 13);
            this.labelDialog.TabIndex = 10;
            this.labelDialog.Text = "Change station\'s properties:";
            // 
            // AddStationForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(225, 314);
            this.Controls.Add(this.labelDialog);
            this.Controls.Add(this.buttonApplyChanges);
            this.Controls.Add(this.checkBoxIsTech);
            this.Controls.Add(this.textBoxCategory);
            this.Controls.Add(this.textBoxLine);
            this.Controls.Add(this.textBoxName);
            this.Controls.Add(this.textBoxID);
            this.Controls.Add(this.labelChangeCategory);
            this.Controls.Add(this.labelChangeLine);
            this.Controls.Add(this.labelChangeName);
            this.Controls.Add(this.labelChangeID);
            this.Name = "AddStationForm";
            this.Text = "Modify Station";
            this.Load += new System.EventHandler(this.AddStationForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelChangeID;
        private System.Windows.Forms.Label labelChangeName;
        private System.Windows.Forms.Label labelChangeLine;
        private System.Windows.Forms.Label labelChangeCategory;
        private System.Windows.Forms.TextBox textBoxID;
        private System.Windows.Forms.TextBox textBoxName;
        private System.Windows.Forms.TextBox textBoxLine;
        private System.Windows.Forms.TextBox textBoxCategory;
        private System.Windows.Forms.CheckBox checkBoxIsTech;
        private System.Windows.Forms.Button buttonApplyChanges;
        private System.Windows.Forms.Label labelDialog;
    }
}