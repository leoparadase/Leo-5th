
namespace SotnikovOOP6
{
    partial class StationsListForm
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.StationsListBox1 = new System.Windows.Forms.ListBox();
            this.buttonOpenFile = new System.Windows.Forms.Button();
            this.buttonAddNew = new System.Windows.Forms.Button();
            this.buttonDelete = new System.Windows.Forms.Button();
            this.buttonSave = new System.Windows.Forms.Button();
            this.buttonChange = new System.Windows.Forms.Button();
            this.buttonOK = new System.Windows.Forms.Button();
            this.labelID = new System.Windows.Forms.Label();
            this.labelName = new System.Windows.Forms.Label();
            this.labelLine = new System.Windows.Forms.Label();
            this.labelCategory = new System.Windows.Forms.Label();
            this.textBoxID = new System.Windows.Forms.TextBox();
            this.textBoxName = new System.Windows.Forms.TextBox();
            this.textBoxLine = new System.Windows.Forms.TextBox();
            this.textBoxCategory = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // StationsListBox1
            // 
            this.StationsListBox1.FormattingEnabled = true;
            this.StationsListBox1.Location = new System.Drawing.Point(14, 15);
            this.StationsListBox1.Name = "StationsListBox1";
            this.StationsListBox1.Size = new System.Drawing.Size(185, 290);
            this.StationsListBox1.TabIndex = 0;
            this.StationsListBox1.SelectedValueChanged += new System.EventHandler(this.StationsListBox1_SelectedValueChanged);
            // 
            // buttonOpenFile
            // 
            this.buttonOpenFile.Location = new System.Drawing.Point(265, 185);
            this.buttonOpenFile.Name = "buttonOpenFile";
            this.buttonOpenFile.Size = new System.Drawing.Size(64, 24);
            this.buttonOpenFile.TabIndex = 1;
            this.buttonOpenFile.Text = "Open File";
            this.buttonOpenFile.UseVisualStyleBackColor = true;
            this.buttonOpenFile.Click += new System.EventHandler(this.buttonOpenFile_Click);
            // 
            // buttonAddNew
            // 
            this.buttonAddNew.Location = new System.Drawing.Point(265, 231);
            this.buttonAddNew.Name = "buttonAddNew";
            this.buttonAddNew.Size = new System.Drawing.Size(64, 24);
            this.buttonAddNew.TabIndex = 2;
            this.buttonAddNew.Text = "Add new";
            this.buttonAddNew.UseVisualStyleBackColor = true;
            this.buttonAddNew.Click += new System.EventHandler(this.buttonAddNew_Click);
            // 
            // buttonDelete
            // 
            this.buttonDelete.Location = new System.Drawing.Point(265, 277);
            this.buttonDelete.Name = "buttonDelete";
            this.buttonDelete.Size = new System.Drawing.Size(64, 24);
            this.buttonDelete.TabIndex = 3;
            this.buttonDelete.Text = "Delete";
            this.buttonDelete.UseVisualStyleBackColor = true;
            this.buttonDelete.Click += new System.EventHandler(this.buttonDelete_Click);
            // 
            // buttonSave
            // 
            this.buttonSave.Location = new System.Drawing.Point(365, 185);
            this.buttonSave.Name = "buttonSave";
            this.buttonSave.Size = new System.Drawing.Size(64, 24);
            this.buttonSave.TabIndex = 4;
            this.buttonSave.Text = "Save";
            this.buttonSave.UseVisualStyleBackColor = true;
            this.buttonSave.Click += new System.EventHandler(this.buttonSave_Click);
            // 
            // buttonChange
            // 
            this.buttonChange.Location = new System.Drawing.Point(365, 231);
            this.buttonChange.Name = "buttonChange";
            this.buttonChange.Size = new System.Drawing.Size(64, 24);
            this.buttonChange.TabIndex = 5;
            this.buttonChange.Text = "Change";
            this.buttonChange.UseVisualStyleBackColor = true;
            this.buttonChange.Click += new System.EventHandler(this.buttonChange_Click);
            // 
            // buttonOK
            // 
            this.buttonOK.Location = new System.Drawing.Point(365, 277);
            this.buttonOK.Name = "buttonOK";
            this.buttonOK.Size = new System.Drawing.Size(64, 24);
            this.buttonOK.TabIndex = 6;
            this.buttonOK.Text = "OK";
            this.buttonOK.UseVisualStyleBackColor = true;
            this.buttonOK.Click += new System.EventHandler(this.buttonOK_Click);
            // 
            // labelID
            // 
            this.labelID.AutoSize = true;
            this.labelID.Location = new System.Drawing.Point(255, 27);
            this.labelID.Name = "labelID";
            this.labelID.Size = new System.Drawing.Size(21, 13);
            this.labelID.TabIndex = 7;
            this.labelID.Text = "ID:";
            // 
            // labelName
            // 
            this.labelName.AutoSize = true;
            this.labelName.Location = new System.Drawing.Point(255, 66);
            this.labelName.Name = "labelName";
            this.labelName.Size = new System.Drawing.Size(38, 13);
            this.labelName.TabIndex = 8;
            this.labelName.Text = "Name:";
            // 
            // labelLine
            // 
            this.labelLine.AutoSize = true;
            this.labelLine.Location = new System.Drawing.Point(255, 105);
            this.labelLine.Name = "labelLine";
            this.labelLine.Size = new System.Drawing.Size(33, 13);
            this.labelLine.TabIndex = 9;
            this.labelLine.Text = "Line: ";
            // 
            // labelCategory
            // 
            this.labelCategory.AutoSize = true;
            this.labelCategory.Location = new System.Drawing.Point(255, 144);
            this.labelCategory.Name = "labelCategory";
            this.labelCategory.Size = new System.Drawing.Size(52, 13);
            this.labelCategory.TabIndex = 10;
            this.labelCategory.Text = "Category:";
            // 
            // textBoxID
            // 
            this.textBoxID.Location = new System.Drawing.Point(342, 24);
            this.textBoxID.Name = "textBoxID";
            this.textBoxID.ReadOnly = true;
            this.textBoxID.Size = new System.Drawing.Size(95, 20);
            this.textBoxID.TabIndex = 11;
            // 
            // textBoxName
            // 
            this.textBoxName.Location = new System.Drawing.Point(342, 63);
            this.textBoxName.Name = "textBoxName";
            this.textBoxName.ReadOnly = true;
            this.textBoxName.Size = new System.Drawing.Size(95, 20);
            this.textBoxName.TabIndex = 12;
            // 
            // textBoxLine
            // 
            this.textBoxLine.Location = new System.Drawing.Point(342, 102);
            this.textBoxLine.Name = "textBoxLine";
            this.textBoxLine.ReadOnly = true;
            this.textBoxLine.Size = new System.Drawing.Size(95, 20);
            this.textBoxLine.TabIndex = 13;
            // 
            // textBoxCategory
            // 
            this.textBoxCategory.Location = new System.Drawing.Point(342, 141);
            this.textBoxCategory.Name = "textBoxCategory";
            this.textBoxCategory.ReadOnly = true;
            this.textBoxCategory.Size = new System.Drawing.Size(95, 20);
            this.textBoxCategory.TabIndex = 14;
            // 
            // StationsListForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(499, 329);
            this.Controls.Add(this.textBoxCategory);
            this.Controls.Add(this.textBoxLine);
            this.Controls.Add(this.textBoxName);
            this.Controls.Add(this.textBoxID);
            this.Controls.Add(this.labelCategory);
            this.Controls.Add(this.labelLine);
            this.Controls.Add(this.labelName);
            this.Controls.Add(this.labelID);
            this.Controls.Add(this.buttonOK);
            this.Controls.Add(this.buttonChange);
            this.Controls.Add(this.buttonSave);
            this.Controls.Add(this.buttonDelete);
            this.Controls.Add(this.buttonAddNew);
            this.Controls.Add(this.buttonOpenFile);
            this.Controls.Add(this.StationsListBox1);
            this.Name = "StationsListForm";
            this.Text = "Sotnikov Metro System";
            this.Activated += new System.EventHandler(this.StationsListForm_Activated);
            this.Load += new System.EventHandler(this.StationsListForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox StationsListBox1;
        private System.Windows.Forms.Button buttonOpenFile;
        private System.Windows.Forms.Button buttonAddNew;
        private System.Windows.Forms.Button buttonDelete;
        private System.Windows.Forms.Button buttonSave;
        private System.Windows.Forms.Button buttonChange;
        private System.Windows.Forms.Button buttonOK;
        private System.Windows.Forms.Label labelID;
        private System.Windows.Forms.Label labelName;
        private System.Windows.Forms.Label labelLine;
        private System.Windows.Forms.Label labelCategory;
        private System.Windows.Forms.TextBox textBoxID;
        private System.Windows.Forms.TextBox textBoxName;
        private System.Windows.Forms.TextBox textBoxLine;
        private System.Windows.Forms.TextBox textBoxCategory;
    }
}

